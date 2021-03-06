/***********************************************************************
 * $Id:: sys_mmu_cmd_group.c 3430 2010-05-07 17:39:08Z usb10132        $
 *
 * Project: Command processor for peek, poke, dump, and fill
 *
 * Description:
 *     Processes commands from the command prompt
 *
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only  
 * which provides customers with programming information regarding the  
 * products. This software is supplied "AS IS" without any warranties.  
 * NXP Semiconductors assumes no responsibility or liability for the 
 * use of the software, conveys no license or title under any patent, 
 * copyright, or mask work right to the product. NXP Semiconductors 
 * reserves the right to make changes in the software without 
 * notification. NXP Semiconductors also make no representation or 
 * warranty that such application will be suitable for the specified 
 * use without further testing or modification. 
 **********************************************************************/

#include "lpc_arm922t_cp15_driver.h"
#include "lpc_string.h"
#include "startup.h"
#include "s1l_cmds.h"
#include "s1l_sys_inf.h"

/* dcache command */
BOOL_32 cmd_dcache(void);
static UNS_32 cmd_dcache_plist[] =
{
	(PARSE_TYPE_STR), /* The "dcache" command */
	(PARSE_TYPE_DEC | PARSE_TYPE_END)
};
static CMD_ROUTE_T core_dcache_cmd =
{
	(UNS_8 *) "dcache",
	cmd_dcache,
	(UNS_8 *) "Enables, disables, or flushes data cache",
	(UNS_8 *) "dcache [0(disable), 1(enable), 2(flush)]",
	cmd_dcache_plist,
	NULL
};

/* icache command */
BOOL_32 cmd_icache(void);
static UNS_32 cmd_icache_plist[] =
{
	(PARSE_TYPE_STR), /* The "icache" command */
	(PARSE_TYPE_DEC | PARSE_TYPE_END)
};
static CMD_ROUTE_T core_icache_cmd =
{
	(UNS_8 *) "icache",
	cmd_icache,
	(UNS_8 *) "Enables or disables instruction cache",
	(UNS_8 *) "icache [0(disable), 1(enable)]",
	cmd_icache_plist,
	NULL
};

/* inval command */
BOOL_32 cmd_inval(void);
static UNS_32 cmd_inval_plist[] =
{
	(PARSE_TYPE_STR | PARSE_TYPE_END) /* The "inval" command */
};
static CMD_ROUTE_T core_inval_cmd =
{
	(UNS_8 *) "inval",
	cmd_inval,
	(UNS_8 *) "Flushes data cache and invalidates instruction cache",
	(UNS_8 *) "inval",
	cmd_inval_plist,
	NULL
};

/* mmuenab command */
BOOL_32 cmd_mmuenab(void);
static UNS_32 cmd_mmuenab_plist[] =
{
	(PARSE_TYPE_STR), /* The "mmuenab" command */
	(PARSE_TYPE_DEC | PARSE_TYPE_END)
};
static CMD_ROUTE_T core_mmuenab_cmd =
{
	(UNS_8 *) "mmuenab",
	cmd_mmuenab,
	(UNS_8 *) "Enables or disables the MMU",
	(UNS_8 *) "mmuenab [0(disable), 1(enable)]",
	cmd_mmuenab_plist,
	NULL
};

/* map command */
BOOL_32 cmd_map(void);
static UNS_32 cmd_map_plist[] =
{
	(PARSE_TYPE_STR), /* The "map" command */
	(PARSE_TYPE_HEX),
	(PARSE_TYPE_HEX),
	(PARSE_TYPE_DEC),
	(PARSE_TYPE_DEC | PARSE_TYPE_END),
};
static CMD_ROUTE_T core_map_cmd =
{
	(UNS_8 *) "map",
	cmd_map,
	(UNS_8 *) "Maps a range of physical address sections to virtual addresses",
	(UNS_8 *) "map [virt hex addr][phy hex addr][sections][0(uncached), 1(cached), 2(unmap)]",
	cmd_map_plist,
	NULL
};

/* mmuinfo command */
static BOOL_32 cmd_mmuinfo(void);
static UNS_32 cmd_mmuinfo_plist[] =
{
	(PARSE_TYPE_STR | PARSE_TYPE_END) /* The "mmuinfo" command */
};
static CMD_ROUTE_T core_mmuinfo_cmd =
{
	(UNS_8 *) "mmuinfo",
	cmd_mmuinfo,
	(UNS_8 *) "Dumps page table and MMU info",
	(UNS_8 *) "mmuinfo",
	cmd_mmuinfo_plist,
	NULL
};

/* MMU group */
static GROUP_LIST_T mmu_group =
{
	(UNS_8 *) "mmu", /* mmu group */
	(UNS_8 *) "MMU command group",
	NULL,
	NULL
};

static UNS_8 enabled_msg [] =" enabled";
static UNS_8 disabled_msg [] =" disabled";
static UNS_8 dcache_msg[] = "Data cache";
static UNS_8 icache_msg[] = "Instruction cache";
static UNS_8 pagetab_msg[] = "Page table at address: ";
static UNS_8 slist_msg[] = "Type        Virt       Phy        fl Size";
static UNS_8 mmu_msg [] ="MMU";
static UNS_8 cpage_msg[] = "Coarse page:";
static UNS_8 fpage_msg[] = "Fine page  :";
static UNS_8 sect_msg[] =  "Section    :";
static UNS_8 mbytes_msg[] = "M";
static UNS_8 map1_err_msg[] =
	"Error : section addresses must be aligned on a 32-bit boundary";
static UNS_8 map2_err_msg[] =
	"Error : Number of sections exceeds address range of device";
static UNS_8 phya_msg[] = "Virtual address ";
static UNS_8 mapped_msg[] = " mapped to physical address ";
static UNS_8 unmapped_msg[] = " unmapped from physical address ";
static UNS_8 cached_msg[] = " (cached)";
static UNS_8 inval_msg[] = " invalidated";
static UNS_8 caches_msg [] ="Caches";
static UNS_8 flushed_msg[] = " flushed";

/***********************************************************************
 *
 * Function: show_section
 *
 * Purpose: Display section information
 *
 * Processing:
 *     See function.
 *
 * Parameters:
 *     mmu_reg   : MMU settings for this section
 *     virt_addr : Starting virtual address for this section
 *     segs      : Number of 1M segments for this section
 *
 * Outputs: None
 *
 * Returns: Nothing
 *
 * Notes: None
 *
 **********************************************************************/
static void show_section(UNS_32 mmu_reg,
						 UNS_32 virt_addr,
						 UNS_32 segs) 
{
	UNS_8 straddr [16];
	UNS_32 mmu_phy;

	if ((mmu_reg & ARM922T_L1D_TYPE_PG_SN_MASK) !=
		ARM922T_L1D_TYPE_FAULT) 
	{
		if ((mmu_reg & ARM922T_L1D_TYPE_PG_SN_MASK) ==
			ARM922T_L1D_TYPE_CPAGE) 
		{
			term_dat_out(cpage_msg);
		}
		else if ((mmu_reg & ARM922T_L1D_TYPE_PG_SN_MASK) ==
			ARM922T_L1D_TYPE_FPAGE) 
		{
			term_dat_out(fpage_msg);
		}
		else
		{
			term_dat_out(sect_msg);
		}

		/* Compute virtual address */
		str_makehex(straddr, virt_addr, 8);
		term_dat_out(straddr);
		term_dat_out((UNS_8 *) " ");

		/* Compute mapped physical address */
		if ((mmu_reg & ARM922T_L1D_TYPE_PG_SN_MASK) ==
		ARM922T_L1D_TYPE_SECTION) 
		{
			mmu_phy = mmu_reg & 0xFFF00000;
		}
		else 
		{
			/* Don't compute addresses for non-sections */
			mmu_phy = 0;
		}
		str_makehex(straddr, mmu_phy, 8);
		term_dat_out(straddr);
		term_dat_out((UNS_8 *) " ");

		/* MMU flags */
		if ((mmu_reg & ARM922T_L1D_BUFFERABLE) != 0) 
		{
			term_dat_out((UNS_8 *) "b");
		}
		else 
		{
			term_dat_out((UNS_8 *) " ");
		}
		if ((mmu_reg & ARM922T_L1D_CACHEABLE) != 0) 
		{
			term_dat_out((UNS_8 *) "c");
		}
		else 
		{
			term_dat_out((UNS_8 *) " ");
		}
		term_dat_out((UNS_8 *) " ");

		/* Displays used megabytes */
		str_makedec(straddr, segs);
		term_dat_out(straddr);
		term_dat_out_crlf(mbytes_msg);
	}
}

/***********************************************************************
 *
 * Function: mmu_dumpinfo
 *
 * Purpose: Display MMU info
 *
 * Processing:
 *     Display the MMU information, including enable status, cache
 *     status, and page table.
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: TRUE if the command was processed, otherwise FALSE
 *
 * Notes: None
 *
 **********************************************************************/
static BOOL_32 mmu_dumpinfo(void) 
{
	UNS_32 segsz, last_mmu_reg, mmu_vrt, mmu_reg, mmu_vrtsav = 0, *pt;
	UNS_32 mlast_mmu_reg, mmmu_reg;
	int idx;
	UNS_8 hexaddr [16];

	term_dat_out(mmu_msg);
	if (cp15_mmu_enabled() == FALSE) 
	{
		term_dat_out_crlf(disabled_msg);
	}
	else 
	{
		term_dat_out_crlf(enabled_msg);

	    /* Get MMU control register word */
  		mmu_reg = cp15_get_mmu_control_reg();

		/* Instruction cache status */
		term_dat_out(icache_msg);
		if ((mmu_reg & ARM922T_MMU_CONTROL_I) == 0) 
		{
			term_dat_out_crlf(disabled_msg);
		}
		else 
		{
			term_dat_out_crlf(enabled_msg);
		}

		/* Data cache status */
		term_dat_out(dcache_msg);
		if ((mmu_reg & ARM922T_MMU_CONTROL_C) == 0) 
		{
			term_dat_out_crlf(disabled_msg);
		}
		else 
		{
			term_dat_out_crlf(enabled_msg);
		}

		term_dat_out(pagetab_msg);
		mmu_reg = (UNS_32) cp15_get_ttb();
		str_makehex(hexaddr, mmu_reg, 8);
		term_dat_out_crlf(hexaddr);
		term_dat_out_crlf(slist_msg);

		/* Process MMU table - assume that the physical and
		   virtual locations of table are the same */
		pt = (UNS_32 *) mmu_reg;
		mmu_vrt = 0x0;
		segsz = 0xFFFFFFFF;
		last_mmu_reg = mlast_mmu_reg = 0xFFFFFFFF;
		for (idx = 0; idx < 4096; idx++) 
		{
			mmu_reg = *pt;
			mmmu_reg = (mmu_reg & (ARM922T_L1D_TYPE_PG_SN_MASK |
				ARM922T_L1D_BUFFERABLE | ARM922T_L1D_CACHEABLE));
			segsz = segsz + 1;

			if ((last_mmu_reg != 0xFFFFFFFF) &&
				(mlast_mmu_reg != mmmu_reg))
			{
				show_section(last_mmu_reg, mmu_vrtsav, segsz);
				segsz = 0;
			}

			if (mlast_mmu_reg != mmmu_reg) 
			{
				mmu_vrtsav = mmu_vrt;
				last_mmu_reg = mmu_reg;
				mlast_mmu_reg = mmmu_reg;
			}

			pt++;
			mmu_vrt += 0x00100000;
		}
	}

	return TRUE;
}

/***********************************************************************
 *
 * Function: mmu_dumpmap
 *
 * Purpose: Map a virtual address range to a physical range
 *
 * Processing:
 *     From the input addresses and number of sections, generate the
 *     appropriate entries in the page table.
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: TRUE if the command was processed, otherwise FALSE
 *
 * Notes: None
 *
 **********************************************************************/
static BOOL_32 mmu_dumpmap(UNS_32 vrt,
						   UNS_32 phy,
						   UNS_32 sections,
						   UNS_32 cache) 
{
	BOOL_32 processed = FALSE;
	UNS_32 mmu_phy, mmu_vrt, tmp1 = 0, tmp2, *pt;
	UNS_8 hexaddr [16];

	/* Verify address boundaries are sectional */
	mmu_vrt = vrt & ~ARM922T_L2D_SN_BASE_MASK;
	mmu_phy = phy & ~ARM922T_L2D_SN_BASE_MASK;
	if ((mmu_vrt != 0) || (mmu_phy != 0)) 
	{
		term_dat_out_crlf(map1_err_msg);
	}
	else 
	{
		/* Verify that address range and section count will not
		   exceed address range of device */
		tmp1 = vrt >> 20;
		tmp1 = (tmp1 + sections) - 1;
		tmp2 = phy >> 20;
		tmp2 = (tmp2 + sections) - 1;
		if ((tmp1 < 4096) && (tmp2 < 4096)) 
		{
			/* Good address range and good section count */
			processed = TRUE;
		}
		else 
		{
			term_dat_out_crlf(map2_err_msg);
		}
	}
	
	/* Generate static part of MMU word */
	if (cache == 0) 
	{
		/* Section mapped with cache disabled */
		tmp1 = ARM922T_L1D_TYPE_SECTION;
	}
	else if (cache == 1)
	{
		/* Section mapped with cache enabled */
		tmp1 = (ARM922T_L1D_BUFFERABLE | ARM922T_L1D_CACHEABLE |
			ARM922T_L1D_TYPE_SECTION);
	}
	else if (cache == 2)
	{
		/* Section unmapped */
		tmp1 = ARM922T_L1D_TYPE_FAULT;
	}
	tmp1 |= ARM922T_L1D_AP_ALL;

	/* Offset into page table for virtual address */
	tmp2 = (vrt >> 20);
	pt = cp15_get_ttb() + tmp2;

	/* Loop until all sections are complete */
	while ((sections > 0) && (processed == TRUE)) 
	{
		/* Add in physical address */
		tmp2 = tmp1 | (phy & ARM922T_L2D_SN_BASE_MASK);

		/* Save new section descriptor for virtual address */
		*pt = tmp2;

		/* Output message shown the map */
		term_dat_out(phya_msg);
		str_makehex(hexaddr, phy, 8);
		term_dat_out(hexaddr);
		if (cache == 2) 
		{
			term_dat_out(unmapped_msg);
		}
		else 
		{
			term_dat_out(mapped_msg);
		}
		str_makehex(hexaddr, vrt, 8);
		term_dat_out(hexaddr);
		if (cache == 1) 
		{
			term_dat_out(cached_msg);
		}
		term_dat_out_crlf((UNS_8 *) "");

		/* Next section and page table entry*/
		phy += 0x00100000;
		vrt += 0x00100000;
		pt++;
		sections--;
	}

	return processed;
}

/***********************************************************************
 *
 * Function: cmd_mmuinfo
 *
 * Purpose: Display MMU information
 *
 * Processing:
 *     See function. 
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: TRUE if the command was processed, otherwise FALSE
 *
 * Notes: None
 *
 **********************************************************************/
static BOOL_32 cmd_mmuinfo(void) 
{
	mmu_dumpinfo();

	return TRUE;
}

/***********************************************************************
 *
 * Function: cmd_map
 *
 * Purpose: Map a physical address region to a virtual region
 *
 * Processing:
 *     See function. 
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: TRUE if the command was processed, otherwise FALSE
 *
 * Notes: None
 *
 **********************************************************************/
BOOL_32 cmd_map(void) 
{
	UNS_32 phy, virt, sects, ce = 0;

	/* Get arguments */
	virt = cmd_get_field_val(1);
	phy = cmd_get_field_val(2);
	sects = cmd_get_field_val(3);
	ce = cmd_get_field_val(4);

	if (ce <= 2) 
	{
		mmu_dumpmap(virt, phy, sects, ce);
	}

	return TRUE;
}

/***********************************************************************
 *
 * Function: cmd_inval
 *
 * Purpose: MMU cache flush and invalidate
 *
 * Processing:
 *     See function. 
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: TRUE if the command was processed, otherwise FALSE
 *
 * Notes: None
 *
 **********************************************************************/
BOOL_32 cmd_inval(void) 
{
	dcache_flush();
	icache_inval();
	term_dat_out(caches_msg);
	term_dat_out(inval_msg);

	return TRUE;
}

/***********************************************************************
 *
 * Function: cmd_dcache
 *
 * Purpose: MMU data cache enable and disable
 *
 * Processing:
 *     If the value passed in the parser is 1, enable the data cache,
 *     otherwise disable the data cache.
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: TRUE if the command was processed, otherwise FALSE
 *
 * Notes: None
 *
 **********************************************************************/
BOOL_32 cmd_dcache(void) 
{
	UNS_32 cenable;
	UNS_8 *ppar;

	/* Get argument */
	cenable = cmd_get_field_val(1);

	switch (cenable)
	{
		case 0:
			dcache_flush();
			cp15_set_dcache(0);
			ppar = disabled_msg;
			break;

		case 1:
			cp15_invalidate_cache();
			cp15_set_dcache(1);
			ppar = enabled_msg;
			break;

		case 2:
		default:
			dcache_flush();
			ppar = flushed_msg;
			break;
	}

	term_dat_out(dcache_msg);
	term_dat_out_crlf(ppar);

	return TRUE;
}

/***********************************************************************
 *
 * Function: cmd_icache
 *
 * Purpose: MMU instruction cache enable and disable
 *
 * Processing:
 *     If the value passed in the parser is 1, enable the instruction
 *     cache, otherwise disable the instruction cache.
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: TRUE if the command was processed, otherwise FALSE
 *
 * Notes: None
 *
 **********************************************************************/
BOOL_32 cmd_icache(void)
{
	UNS_32 cenable;
	UNS_8 *ppar;

	/* Get argument */
	cenable = cmd_get_field_val(1);

	if (cenable == 1) 
	{
		dcache_flush();
		cp15_invalidate_cache();
		cp15_set_icache(1);
		ppar = enabled_msg;
	}
	else
	{
		cp15_set_icache(0);
		ppar = disabled_msg;
	}

	term_dat_out(icache_msg);
	term_dat_out_crlf(ppar);

	return TRUE;
}


/***********************************************************************
 *
 * Function: cmd_mmuenab
 *
 * Purpose: Enable or disable MMU
 *
 * Processing:
 *     See function. 
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: TRUE if the command was processed, otherwise FALSE
 *
 * Notes: None
 *
 **********************************************************************/
BOOL_32 cmd_mmuenab(void) 
{
	UNS_8 *ppar;
	UNS_32 cenable;

	term_dat_out_crlf((UNS_8 *) "Warning: Changing MMU status on "
		" cached and buffered code can cause system crashes.");

	/* Get argument */
	cenable = cmd_get_field_val(1);

	if (cenable == 1) 
	{
		if ((cp15_get_mmu_control_reg() & ARM922T_MMU_CONTROL_C) != 0)
		{
			cp15_invalidate_cache();
		}

		cp15_set_mmu(1);
		ppar = enabled_msg;
	}
	else
	{
		cp15_dcache_flush();
		cp15_write_buffer_flush();
		cp15_invalidate_cache();
		cp15_set_mmu(0);
		ppar = disabled_msg;
	}

	term_dat_out(mmu_msg);
	term_dat_out_crlf(ppar);

	return TRUE;
}

/***********************************************************************
 *
 * Function: mmu_cmd_group_init
 *
 * Purpose: Initialize MMU command group
 *
 * Processing:
 *     See function. 
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: Nothin
 *
 * Notes: None
 *
 **********************************************************************/
void mmu_cmd_group_init(void)
{
	/* Add MMU group */
	cmd_add_group(&mmu_group);

	/* Add commands to the MMU group */
	cmd_add_new_command(&mmu_group, &core_dcache_cmd);
	cmd_add_new_command(&mmu_group, &core_icache_cmd);
	cmd_add_new_command(&mmu_group, &core_inval_cmd);
	cmd_add_new_command(&mmu_group, &core_mmuenab_cmd);
	cmd_add_new_command(&mmu_group, &core_map_cmd);
	cmd_add_new_command(&mmu_group, &core_mmuinfo_cmd);
}
