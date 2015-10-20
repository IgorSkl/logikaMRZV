/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2006
 *
 *    File name   : ttbl.c
 *    Description : MMU Translation tables
 *
 *    History :
 *    1. Date        : Sep, 19 2006
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *        The physical memory map is:
 *
 *      0x00000000
 *                  |---------------------------|
 *      0x0000003F  |       iRAM  Vectors       |
 *                  |---------------------------|
 *      0x00000040  |           iRAM            |
 *                  |      RW Nocached          |
 *      0x03FFFFFF  |---------------------------|
 *      0x04000000  |     DMA Dummy Area        |
 *                  |      RW Nocached          |
 *                  |---------------------------|
 *      0x08000000  |      iRAM   (mirror)      |
 *                  |       RW Nocached         |
 *      0x0BFFFFFF  |---------------------------|
 *                  |                           |
 *                  ~                           ~
 *                  |                           |
 *                  |---------------------------|
 *      0x20000000  |          AHB ch 5         |
 *                  |        RW Nocached        |
 *      0x200BFFFF  |---------------------------|
 *                  |                           |
 *                  ~                           ~
 *                  |                           |
 *                  |---------------------------|
 *      0x30000000  |          AHB ch 6         |
 *                  |        RW Nocached        |
 *      0x31FFFFFF  |---------------------------|
 *                  |                           |
 *                  ~                           ~
 *                  |                           |
 *                  |---------------------------|
 *      0x40000000  |          AHB ch 7         |
 *                  |        RW Nocached        |
 *      0x400FFFFF  |---------------------------|
 *                  |                           |
 *                  ~                           ~
 *      0xE1000000  |                           |
 *                  |---------------------------|
 *                  |                           |
 *                  |  SRAM RO  cached 128kB    |
 *      0xE101FFFF  |                           |
 *      0xE1020000  |---------------------------|
 *                  |                           |
 *                  |  SRAM RO  No cached 128kB |
 *      0xE103FFFF  |                           |
 *      0xE1040000  |---------------------------|
 *                  |                           |
 *                  |  SDRAM RW  cached 128kB   |
 *      0xE105FFFF  |                           |
 *      0xE1060000  |---------------------------|
 *                  |                           |
 *                  |  SDRAM RW  No cached 128kB|
 *      0xE107FFFF  |                           |
 *      0x81000000  |---------------------------|
 *
 *    $Revision: 30870 $
 **************************************************************************/
#include "ttbl.h"

#pragma segment="MMU_TT"

#pragma location="MMU_TT"
#pragma data_alignment=16384
__no_init Int32U L1Table[L1_ENTRIES_NUMB];

#pragma location="MMU_TT"
#pragma data_alignment=2048
__no_init Int32U L2Coarses1[L2_CP_ENTRIES_NUMB];

#pragma location="MMU_TT"
#pragma data_alignment=2048
__no_init Int32U L2Coarses2[L2_CP_ENTRIES_NUMB];

//#pragma location="MMU_TT"
//#pragma data_alignment=2048
//__no_init Int32U L2Coarses3[L2_CP_ENTRIES_NUMB];


const TtSectionBlock_t TtSB[] =
{
  // L1
  // 192 MB RW section no cached (iRAM DMA dummy area)
  L1_SECTIONS_ENTRY(    192,0x00000000,0x00000000 ,3,1,0,0),
  //   1 MB RW coarse table (AHB ch 5)
  L1_COARSES_PAGE_ENTRY(  1,0x20000000,(Int32U)L2Coarses1  ,1    ),
  //  32 MB RW section no cached (AHB ch 6)
  L1_SECTIONS_ENTRY(     32,0x30000000,0x30000000        ,3,1,0,0),
  //   1 MB RW section no cached (AHB ch 7)
  L1_SECTIONS_ENTRY(      1,0x40000000,0x40000000        ,3,1,0,0),
  //   1 MB Flash section cached (EMC0)
  L1_SECTIONS_ENTRY(      1,0xE0000000,0xE0000000        ,2,1,1,0),
  //   1 MB Flash section no cached (EMC0)
  L1_SECTIONS_ENTRY(      1,0xE0100000,0xE0100000        ,2,1,0,0),
  //   1 MB Flash section cached (EMC0)
//  L1_COARSES_PAGE_ENTRY(  1,0xE0000000,(Int32U)L2Coarses2  ,0    ),
  //   1 MB SRAM coarse table (EMC1)
  L1_COARSES_PAGE_ENTRY(  1,0xE1000000,(Int32U)L2Coarses2  ,1    ),
  //   4 MB RW section no cached (EMC2)
  L1_SECTIONS_ENTRY(      4,0xE2000000,0xE2000000        ,3,1,0,0),
  //  16 MB RW section no cached (EMC3)
  L1_SECTIONS_ENTRY(     16,0xE3000000,0xE3000000        ,3,1,0,0),
  TSB_INVALID,
  // L2 coarse table 12 * 64kB = 768kB
  L2_CT_LARGE_PAGE_ENTRY(12,0x20000000,0x20000000,3,3,3,3,0,0),
  TSB_INVALID,
//  // L2 coarse table 8 * 64kB = 512kB
//  L2_CT_LARGE_PAGE_ENTRY(8,0xE0000000,0xE0000000,2,2,2,2,1,0),
//  L2_CT_LARGE_PAGE_ENTRY(8,0xE0080000,0xE0080000,2,2,2,2,0,0),
//  TSB_INVALID,
  // L2 coarse table 127 * 4kB = 508kB
  L2_CT_SMALL_PAGE_ENTRY(127,0xE1000000,0xE1000000,2,2,2,2,1,0),
  // L2 coarse table 1 * 4kB = 4kB
  L2_CT_SMALL_PAGE_ENTRY(1 ,0xE107F000,0xE107F000,2,2,2,2,0,0),
  // L2 coarse table 127 * 4kB = 508kB
  L2_CT_SMALL_PAGE_ENTRY(127,0xE1080000,0xE1080000,3,3,3,3,1,1),
  // L2 coarse table 1 * 4kB = 4kB
  L2_CT_SMALL_PAGE_ENTRY(1 ,0xE10FF000,0xE10FF000,3,3,3,3,0,0),
  TSB_INVALID
};

const TtTableBlock_t TtTB[] =
{
  {L1Table,TableL1},
  {L2Coarses1,TableL2_Coarse},
  {L2Coarses2,TableL2_Coarse},
//  {L2Coarses3,TableL2_Coarse},
  TTB_INVALID
};
