
#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "UMMComponent.c"
#include "PRM1Component.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;
extern int GlobalLevelI_ABC[];
extern int GlobalLevelUL_ABC[];
extern int GlobalLevelUF_ABC[];

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern int   WideCmdRTBuffer[];
extern int   tempLog[];
extern int offsetSPVCmdPRM1;//смещение для SPV PRM1

void  logicUMM(int idxC)
{
//логика компонента
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //таймера компонента в конфигурации
    int tmpOffsetIO   =
                cnfCOMPONENT[idxC].offsetIOCmd;    //IO команды
    int tmpOffsetENA  =
                cnfCOMPONENT[idxC].offsetENACmd;    //ENA команды
    int tmpOffsetUSpv =
                cnfCOMPONENT[idxC].offsetUstSpv;    //уставки SPV

    //int tmpOffsetTL   =
      //          cnfCOMPONENT[idxC].offsetTLCmd;    //TL команды

//напряж UMAX1 FAZ
  detectorLevelUP3F(GlobalLevelUF_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_UMAX1_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_UMAX1_UMM,
                                     tmpOffsetUSpv+SPV_OUTAF_UMAX1);
//напряж UMAX2 FAZ
  detectorLevelUP3F(GlobalLevelUF_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_UMAX2_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_UMAX2_UMM,
                                     tmpOffsetUSpv+SPV_OUTAF_UMAX2);

//напряж UMAX1 LIN
  detectorLevelUP3F(GlobalLevelUL_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_UMAX1_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_UMAX1_UMM,
                                     tmpOffsetUSpv+SPV_OUTAL_UMAX1);
//напряж UMAX2 LIN
  detectorLevelUP3F(GlobalLevelUL_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_UMAX2_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_UMAX2_UMM,
                                     tmpOffsetUSpv+SPV_OUTAL_UMAX2);

//напряж UMIN1 FAZ
  detectorLevelDOWN3F(GlobalLevelUF_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_UMIN1_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_UMIN1_UMM,
                                     tmpOffsetUSpv+SPV_OUTAF_UMIN1);
//напряж UMIN2 FAZ
  detectorLevelDOWN3F(GlobalLevelUF_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_UMIN2_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_UMIN2_UMM,
                                     tmpOffsetUSpv+SPV_OUTAF_UMIN2);
//напряж UMIN1 LIN
  detectorLevelDOWN3F(GlobalLevelUL_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_UMIN1_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_UMIN1_UMM,
                                     tmpOffsetUSpv+SPV_OUTAL_UMIN1);
//напряж UMIN2 LIN
  detectorLevelDOWN3F(GlobalLevelUL_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_UMIN2_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_UMIN2_UMM,
                                     tmpOffsetUSpv+SPV_OUTAL_UMIN2);
//int tt1 = SPV_UST(SPVSRABUST_IBLOK1_UMM);
//int tt2 = SPV_UST(SPVVOZVUST_IBLOK1_UMM);
//ток блок UMIN1
  detectorLevelUP3F(GlobalLevelI_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_IBLOK1_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_IBLOK1_UMM,
                                     tmpOffsetUSpv+SPV_OUTIA_UMIN1);
//ток блок UMIN2
  detectorLevelUP3F(GlobalLevelI_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_IBLOK2_UMM,
                                     tmpOffsetUSpv+SPVVOZVUST_IBLOK2_UMM,
                                     tmpOffsetUSpv+SPV_OUTIA_UMIN2);

 int LocalPO_UMAX1_LIN_ILI = (  
                              SPV_UST(SPV_OUTAL_UMAX1) |
                              SPV_UST(SPV_OUTBL_UMAX1) |
                              SPV_UST(SPV_OUTCL_UMAX1) 
                              );
 int LocalPO_UMAX1_LIN_I = (  
                              SPV_UST(SPV_OUTAL_UMAX1) &
                              SPV_UST(SPV_OUTBL_UMAX1) &
                              SPV_UST(SPV_OUTCL_UMAX1) 
                              );
 int LocalPO_UMAX1_FAZ_ILI = (  
                              SPV_UST(SPV_OUTAF_UMAX1) |
                              SPV_UST(SPV_OUTBF_UMAX1) |
                              SPV_UST(SPV_OUTCF_UMAX1) 
                              );
 int LocalPO_UMAX1_FAZ_I = (  
                              SPV_UST(SPV_OUTAF_UMAX1) &
                              SPV_UST(SPV_OUTBF_UMAX1) &
                              SPV_UST(SPV_OUTCF_UMAX1) 
                              );

 int LocalPO_UMAX2_LIN_ILI = (  
                              SPV_UST(SPV_OUTAL_UMAX2) |
                              SPV_UST(SPV_OUTBL_UMAX2) |
                              SPV_UST(SPV_OUTCL_UMAX2) 
                              );
 int LocalPO_UMAX2_LIN_I = (  
                              SPV_UST(SPV_OUTAL_UMAX2) &
                              SPV_UST(SPV_OUTBL_UMAX2) &
                              SPV_UST(SPV_OUTCL_UMAX2) 
                              );
 int LocalPO_UMAX2_FAZ_ILI = (  
                              SPV_UST(SPV_OUTAF_UMAX2) |
                              SPV_UST(SPV_OUTBF_UMAX2) |
                              SPV_UST(SPV_OUTCF_UMAX2) 
                              );
 int LocalPO_UMAX2_FAZ_I = (  
                              SPV_UST(SPV_OUTAF_UMAX2) &
                              SPV_UST(SPV_OUTBF_UMAX2) &
                              SPV_UST(SPV_OUTCF_UMAX2) 
                              );

		// UMAX1 И ИЛИ
 int tmp1 =     ENA_LOGIC(ENA_UMAX1_2);
 int LocalPO_UMAX1_LIN = LocalPO_UMAX1_LIN_I;
 if(tmp1)
    LocalPO_UMAX1_LIN = LocalPO_UMAX1_LIN_ILI;
		// UMAX2 И ИЛИ
 int tmp2 =     ENA_LOGIC(ENA_UMAX2_2);
 int LocalPO_UMAX2_LIN = LocalPO_UMAX2_LIN_I;
 if(tmp2)
    LocalPO_UMAX2_LIN = LocalPO_UMAX2_LIN_ILI;

 //tmp1 =     ENA_LOGIC(ENA_UMAX1_2);
 int LocalPO_UMAX1_FAZ = LocalPO_UMAX1_FAZ_I;
 if(tmp1)
    LocalPO_UMAX1_FAZ = LocalPO_UMAX1_FAZ_ILI;
		// UMAX2 И ИЛИ
// tmp1 =     ENA_LOGIC(ENA_UMAX2_2);
 int LocalPO_UMAX2_FAZ = LocalPO_UMAX2_FAZ_I;
 if(tmp2)
    LocalPO_UMAX2_FAZ = LocalPO_UMAX2_FAZ_ILI;

		// UMAX1 ФАЗ ЛИН
 tmp1 =     ENA_LOGIC(ENA_UMAX1_3);
 int LocalPO_UMAX1 = LocalPO_UMAX1_FAZ;
 if(tmp1)
     LocalPO_UMAX1 = LocalPO_UMAX1_LIN;
		// UMAX2 ФАЗ ЛИН
 tmp2 =     ENA_LOGIC(ENA_UMAX2_3);
 int LocalPO_UMAX2 = LocalPO_UMAX2_FAZ;
 if(tmp2)
     LocalPO_UMAX2 = LocalPO_UMAX2_LIN;

		// UMIN1 ФАЗ ЛИН 
 tmp1 =     ENA_LOGIC(ENA_UMIN1_3);
 int locUMIN1_UAB_OR_UA = SPV_UST(SPV_OUTAF_UMIN1);
 int locUMIN1_UBC_OR_UB = SPV_UST(SPV_OUTBF_UMIN1);
 int locUMIN1_UCA_OR_UC = SPV_UST(SPV_OUTCF_UMIN1);
 if(tmp1){
     locUMIN1_UAB_OR_UA = SPV_UST(SPV_OUTAL_UMIN1);
     locUMIN1_UBC_OR_UB = SPV_UST(SPV_OUTBL_UMIN1);
     locUMIN1_UCA_OR_UC = SPV_UST(SPV_OUTCL_UMIN1);
         }//if

		// UMIN2 ФАЗ ЛИН 
 tmp1 =     ENA_LOGIC(ENA_UMIN2_3);
 int locUMIN2_UAB_OR_UA = SPV_UST(SPV_OUTAF_UMIN2);
 int locUMIN2_UBC_OR_UB = SPV_UST(SPV_OUTBF_UMIN2);
 int locUMIN2_UCA_OR_UC = SPV_UST(SPV_OUTCF_UMIN2);
 if(tmp1){
     locUMIN2_UAB_OR_UA = SPV_UST(SPV_OUTAL_UMIN2);
     locUMIN2_UBC_OR_UB = SPV_UST(SPV_OUTBL_UMIN2);
     locUMIN2_UCA_OR_UC = SPV_UST(SPV_OUTCL_UMIN2);
         }//if

 int LocalUBLOK_LIN_A =
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAL_U025) |// &
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025) |//^1) &
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025) ;//)^1;//^1);
 int LocalUBLOK_LIN_B =
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBL_U025)  |//&
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025) |//^1) &
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025);//)^1;//^1);
 int LocalUBLOK_LIN_C =
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCL_U025) |//&
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025) |//^1) &
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025);//)^1;//^1);

 int LocalUBLOK_LIN =
          LocalUBLOK_LIN_A |
          LocalUBLOK_LIN_B |
          LocalUBLOK_LIN_C;

 int LocalUBLOK_FAZ_A =
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025);//^1;
 int LocalUBLOK_FAZ_B =
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025);//^1;
 int LocalUBLOK_FAZ_C =
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025);//^1;

 int LocalUBLOK_FAZ =
          LocalUBLOK_FAZ_A |
          LocalUBLOK_FAZ_B |
          LocalUBLOK_FAZ_C;

		// UMIN1 ФАЗ ЛИН 
 tmp1 =     ENA_LOGIC(ENA_UMIN1_3);
 int LocalUMIN1_UBLOK = LocalUBLOK_FAZ;
 if(tmp1)
     LocalUMIN1_UBLOK = LocalUBLOK_LIN;

		// UMIN2 ФАЗ ЛИН 
 tmp1 =     ENA_LOGIC(ENA_UMIN2_3);
 int LocalUMIN2_UBLOK = LocalUBLOK_FAZ;
 if(tmp1)
     LocalUMIN2_UBLOK = LocalUBLOK_LIN;

//-------------UMIN1-----------

//L1
  tmp1 =
     locUMIN1_UAB_OR_UA &
     locUMIN1_UBC_OR_UB &
     locUMIN1_UCA_OR_UC &
     // UMIN1 LIN И ИЛИ
     (ENA_LOGIC(ENA_UMIN1_2)^1);

//L2
  tmp2 =
     locUMIN1_UAB_OR_UA |
     locUMIN1_UBC_OR_UB |
     locUMIN1_UCA_OR_UC;
//L4
  int  tmp3 = 
         tmp2 &
         (
	  // UMIN1 LIN И ИЛИ
          ENA_LOGIC(ENA_UMIN1_2)
         );

//L6
  int  tmp4 =
          tmp1 |
          tmp3;

//L7
  tmp1 =
        LocalUMIN1_UBLOK &
	// UMIN1 блок U
        ENA_LOGIC(ENA_UMIN1_5) &
	(
	// UMIN1 блок I UBLOK
	ENA_LOGIC(ENA_UMIN1_4)^1
	);

//L8
  tmp2 =
        (
        SPV_UST(SPV_OUTIA_UMIN1) | SPV_UST(SPV_OUTIB_UMIN1) | SPV_UST(SPV_OUTIC_UMIN1)//)^1;
        ) &
	// UMIN1 блок I UBLOK
	ENA_LOGIC(ENA_UMIN1_4);
//L9
 int  LocalPO_UMIN1 = 
        tmp4 &
        (
         tmp1^1
        )&
        (
         tmp2^1
        );


//-------------UMIN2-----------

//L1
  tmp1 =
     locUMIN2_UAB_OR_UA &
     locUMIN2_UBC_OR_UB &
     locUMIN2_UCA_OR_UC &
     // UMIN2 LIN И ИЛИ
     (ENA_LOGIC(ENA_UMIN2_2)^1);

//L2
  tmp2 =
     locUMIN2_UAB_OR_UA |
     locUMIN2_UBC_OR_UB |
     locUMIN2_UCA_OR_UC;
//L4
  tmp3 = 
         tmp2 &
         (
	  // UMIN2 LIN И ИЛИ
          ENA_LOGIC(ENA_UMIN2_2)
         );

//L6
  tmp4 =
          tmp1 |
          tmp3;

//L7
  tmp1 =
        LocalUMIN2_UBLOK &
	// UMIN2 блок U
        ENA_LOGIC(ENA_UMIN2_5) &
	(
	// UMIN2 блок I UBLOK
	ENA_LOGIC(ENA_UMIN2_4)^1
	);

//L8
  tmp2 =
        (
        SPV_UST(SPV_OUTIA_UMIN2) | SPV_UST(SPV_OUTIB_UMIN2) | SPV_UST(SPV_OUTIC_UMIN2)//)^1;
        ) &
	// UMIN2 блок I UBLOK
	ENA_LOGIC(ENA_UMIN2_4);
//L9
 int  LocalPO_UMIN2 = 
        tmp4 &
        (
         tmp1^1
        )&
        (
         tmp2^1
        );


/*
 int locIBlok = (SPV_UST(SPV_OUTIA_UMIN1) | SPV_UST(SPV_OUTIB_UMIN1) | SPV_UST(SPV_OUTIC_UMIN1))^1;

 int locIAL1 = SPV_UST(SPV_OUTAL_UMIN1)&locIBlok;//SPV_UST(SPV_OUTIA_UMIN1);
 int locIBL1 = SPV_UST(SPV_OUTBL_UMIN1)&locIBlok;//SPV_UST(SPV_OUTIB_UMIN1);
 int locICL1 = SPV_UST(SPV_OUTCL_UMIN1)&locIBlok;//SPV_UST(SPV_OUTIC_UMIN1);

 int locIAF1 = SPV_UST(SPV_OUTAF_UMIN1)&locIBlok;//SPV_UST(SPV_OUTIA_UMIN1);
 int locIBF1 = SPV_UST(SPV_OUTBF_UMIN1)&locIBlok;//SPV_UST(SPV_OUTIB_UMIN1);
 int locICF1 = SPV_UST(SPV_OUTCF_UMIN1)&locIBlok;//SPV_UST(SPV_OUTIC_UMIN1);

 int LocalPO_UMIN1_LIN_ILI_IBLOK = (
                              (locIAL1) |
                              (locIBL1) |
                              (locICL1)
                              );
 int LocalPO_UMIN1_LIN_I_IBLOK = (
                              (locIAL1) &
                              (locIBL1) &
                              (locICL1) 
                              );
 int LocalPO_UMIN1_FAZ_ILI_IBLOK = (  
                              (locIAF1) |
                              (locIBF1) |
                              (locICF1) 
                              );
 int LocalPO_UMIN1_FAZ_I_IBLOK = (  
                              (locIAF1) &
                              (locIBF1) &
                              (locICF1) 
                              );

 locIBlok = (SPV_UST(SPV_OUTIA_UMIN2) | SPV_UST(SPV_OUTIB_UMIN2) | SPV_UST(SPV_OUTIC_UMIN2))^1;

 int locIAL2 = SPV_UST(SPV_OUTAL_UMIN2)&locIBlok;//SPV_UST(SPV_OUTIA_UMIN2);
 int locIBL2 = SPV_UST(SPV_OUTBL_UMIN2)&locIBlok;//SPV_UST(SPV_OUTIB_UMIN2);
 int locICL2 = SPV_UST(SPV_OUTCL_UMIN2)&locIBlok;//SPV_UST(SPV_OUTIC_UMIN2);

 int locIAF2 = SPV_UST(SPV_OUTAF_UMIN2)&locIBlok;//SPV_UST(SPV_OUTIA_UMIN2);
 int locIBF2 = SPV_UST(SPV_OUTBF_UMIN2)&locIBlok;//SPV_UST(SPV_OUTIB_UMIN2);
 int locICF2 = SPV_UST(SPV_OUTCF_UMIN2)&locIBlok;//SPV_UST(SPV_OUTIC_UMIN2);

 int LocalPO_UMIN2_LIN_ILI_IBLOK = (  
                              (locIAL2) |
                              (locIBL2) |
                              (locICL2) 
                              );
 int LocalPO_UMIN2_LIN_I_IBLOK = (  
                              (locIAL2) &
                              (locIBL2) &
                              (locICL2)
                              );
 int LocalPO_UMIN2_FAZ_ILI_IBLOK = (  
                              (locIAF2) |
                              (locIBF2) |
                              (locICF2) 
                              );
 int LocalPO_UMIN2_FAZ_I_IBLOK = (  
                              (locIAF2) &
                              (locIBF2) &
                              (locICF2) 
                              );


 int LocalPO_UMIN1_LIN_ILI = (  
                              SPV_UST(SPV_OUTAL_UMIN1) |
                              SPV_UST(SPV_OUTBL_UMIN1) |
                              SPV_UST(SPV_OUTCL_UMIN1) 
                              );
 int LocalPO_UMIN1_LIN_I = (  
                              SPV_UST(SPV_OUTAL_UMIN1) &
                              SPV_UST(SPV_OUTBL_UMIN1) &
                              SPV_UST(SPV_OUTCL_UMIN1)
                              );
 int LocalPO_UMIN1_FAZ_ILI = (  
                              SPV_UST(SPV_OUTAF_UMIN1) |
                              SPV_UST(SPV_OUTBF_UMIN1) |
                              SPV_UST(SPV_OUTCF_UMIN1) 
                              );
 int LocalPO_UMIN1_FAZ_I = (  
                              SPV_UST(SPV_OUTAF_UMIN1) &
                              SPV_UST(SPV_OUTBF_UMIN1) &
                              SPV_UST(SPV_OUTCF_UMIN1) 
                              );

 int LocalPO_UMIN2_LIN_ILI = (  
                              SPV_UST(SPV_OUTAL_UMIN2) |
                              SPV_UST(SPV_OUTBL_UMIN2) |
                              SPV_UST(SPV_OUTCL_UMIN2)
                              );
 int LocalPO_UMIN2_LIN_I = (  
                              SPV_UST(SPV_OUTAL_UMIN2) &
                              SPV_UST(SPV_OUTBL_UMIN2) &
                              SPV_UST(SPV_OUTCL_UMIN2)
                              );
 int LocalPO_UMIN2_FAZ_ILI = (
                              SPV_UST(SPV_OUTAF_UMIN2) |
                              SPV_UST(SPV_OUTBF_UMIN2) |
                              SPV_UST(SPV_OUTCF_UMIN2) 
                              );
 int LocalPO_UMIN2_FAZ_I = (  
                              SPV_UST(SPV_OUTAF_UMIN2) &
                              SPV_UST(SPV_OUTBF_UMIN2) &
                              SPV_UST(SPV_OUTCF_UMIN2) 
                              );

 int LocalUBLOK_LIN_A =
          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAL_U025) |// &
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025) |//^1) &
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025) )^1;//^1);
 int LocalUBLOK_LIN_B =
          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBL_U025)  |//&
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025) |//^1) &
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025))^1;//^1);
 int LocalUBLOK_LIN_C =
          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCL_U025) |//&
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025) |//^1) &
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025))^1;//^1);

 int LocalUBLOK_FAZ_A =
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025)^1;
 int LocalUBLOK_FAZ_B =
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025)^1;
 int LocalUBLOK_FAZ_C =
          SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025)^1;

 int LocalPO_UMIN1_LIN_ILI_UBLOK = (  
                              (SPV_UST(SPV_OUTAL_UMIN1)&(LocalUBLOK_LIN_A)) |
                              (SPV_UST(SPV_OUTBL_UMIN1)&(LocalUBLOK_LIN_B)) |
                              (SPV_UST(SPV_OUTCL_UMIN1)&(LocalUBLOK_LIN_C)) 
                              );

 int LocalPO_UMIN1_LIN_I_UBLOK = (  
                              (SPV_UST(SPV_OUTAL_UMIN1)&(LocalUBLOK_LIN_A)) &
                              (SPV_UST(SPV_OUTBL_UMIN1)&(LocalUBLOK_LIN_B)) &
                              (SPV_UST(SPV_OUTCL_UMIN1)&(LocalUBLOK_LIN_C))
                              );
 int LocalPO_UMIN1_FAZ_ILI_UBLOK = (  
                              (SPV_UST(SPV_OUTAF_UMIN1)&LocalUBLOK_FAZ_A) |//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025)^1)) |
                              (SPV_UST(SPV_OUTBF_UMIN1)&LocalUBLOK_FAZ_B) |//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025)^1)) |
                              (SPV_UST(SPV_OUTCF_UMIN1)&LocalUBLOK_FAZ_C)//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025)^1)) 
                              );
 int LocalPO_UMIN1_FAZ_I_UBLOK = (  
                              (SPV_UST(SPV_OUTAF_UMIN1)&LocalUBLOK_FAZ_A) &//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025)^1)) &
                              (SPV_UST(SPV_OUTBF_UMIN1)&LocalUBLOK_FAZ_B) &//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025)^1)) &
                              (SPV_UST(SPV_OUTCF_UMIN1)&LocalUBLOK_FAZ_C)//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025)^1)) 
                              );

 int LocalPO_UMIN2_LIN_ILI_UBLOK = (  
                              (SPV_UST(SPV_OUTAL_UMIN2)&(LocalUBLOK_LIN_A)) |
                              (SPV_UST(SPV_OUTBL_UMIN2)&(LocalUBLOK_LIN_B)) |
                              (SPV_UST(SPV_OUTCL_UMIN2)&(LocalUBLOK_LIN_C))
                              );
 int LocalPO_UMIN2_LIN_I_UBLOK = (  
                              (SPV_UST(SPV_OUTAL_UMIN2)&(LocalUBLOK_LIN_A)) &
                              (SPV_UST(SPV_OUTBL_UMIN2)&(LocalUBLOK_LIN_B)) &
                              (SPV_UST(SPV_OUTCL_UMIN2)&(LocalUBLOK_LIN_C))
                              );
 int LocalPO_UMIN2_FAZ_ILI_UBLOK = (
                              (SPV_UST(SPV_OUTAF_UMIN2)&LocalUBLOK_FAZ_A) |//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025)^1)) |
                              (SPV_UST(SPV_OUTBF_UMIN2)&LocalUBLOK_FAZ_B) |//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025)^1)) |
                              (SPV_UST(SPV_OUTCF_UMIN2)&LocalUBLOK_FAZ_C)//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025)^1)) 
                              );
 int LocalPO_UMIN2_FAZ_I_UBLOK = (  
                              (SPV_UST(SPV_OUTAF_UMIN2)&LocalUBLOK_FAZ_A) &//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025)^1)) &
                              (SPV_UST(SPV_OUTBF_UMIN2)&LocalUBLOK_FAZ_B) &//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025)^1)) &
                              (SPV_UST(SPV_OUTCF_UMIN2)&LocalUBLOK_FAZ_C)//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025)^1)) 
                              );

 int LocalPO_UMIN1_LIN_ILI_IBLOK_UBLOK = (
                              ((locIAL1)&(LocalUBLOK_LIN_A)) |
                              ((locIBL1)&(LocalUBLOK_LIN_B)) |
                              ((locICL1)&(LocalUBLOK_LIN_C))
                              );
 int LocalPO_UMIN1_LIN_I_IBLOK_UBLOK = (
                              ((locIAL1)&(LocalUBLOK_LIN_A)) &
                              ((locIBL1)&(LocalUBLOK_LIN_B)) &
                              ((locICL1)&(LocalUBLOK_LIN_C)) 
                              );
 int LocalPO_UMIN1_FAZ_ILI_IBLOK_UBLOK = (  
                              ((locIAF1)&LocalUBLOK_FAZ_A) |//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025)^1)) |
                              ((locIBF1)&LocalUBLOK_FAZ_B) |//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025)^1)) |
                              ((locICF1)&LocalUBLOK_FAZ_C)//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025)^1)) 
                              );
 int LocalPO_UMIN1_FAZ_I_IBLOK_UBLOK = (  
                              ((locIAF1)&LocalUBLOK_FAZ_A) &//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025)^1)) &
                              ((locIBF1)&LocalUBLOK_FAZ_B) &//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025)^1)) &
                              ((locICF1)&LocalUBLOK_FAZ_C) //(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025)^1)) 
                              );

 int LocalPO_UMIN2_LIN_ILI_IBLOK_UBLOK = (
                              ((locIAL2)&(LocalUBLOK_LIN_A)) |
                              ((locIBL2)&(LocalUBLOK_LIN_B)) |
                              ((locICL2)&(LocalUBLOK_LIN_C))
                              );
 int LocalPO_UMIN2_LIN_I_IBLOK_UBLOK = (
                              ((locIAL2)&(LocalUBLOK_LIN_A)) &
                              ((locIBL2)&(LocalUBLOK_LIN_B)) &
                              ((locICL2)&(LocalUBLOK_LIN_C)) 
                              );
 int LocalPO_UMIN2_FAZ_ILI_IBLOK_UBLOK = (  
                              ((locIAF2)&LocalUBLOK_FAZ_A) |//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025)^1)) |
                              ((locIBF2)&LocalUBLOK_FAZ_A) |//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025)^1)) |
                              ((locICF2)&LocalUBLOK_FAZ_A)//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025)^1)) 
                              );
 int LocalPO_UMIN2_FAZ_I_IBLOK_UBLOK = (  
                              ((locIAF2)&LocalUBLOK_FAZ_A) &//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTAF_U025)^1)) &
                              ((locIBF2)&LocalUBLOK_FAZ_B) &//(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTBF_U025)^1)) &
                              ((locICF2)&LocalUBLOK_FAZ_C) //(SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTCF_U025)^1)) 
                              );

//-------------UMIN1-----------
		// UMIN1 LIN И ИЛИ
    tmp1 =     ENA_LOGIC(ENA_UMIN1_2);
 int LocalPO_UMIN1_LIN = LocalPO_UMIN1_LIN_I;
 if(tmp1)
    LocalPO_UMIN1_LIN = LocalPO_UMIN1_LIN_ILI;

		// UMIN1 FAZ И ИЛИ
    tmp1 =     ENA_LOGIC(ENA_UMIN1_2);
 int LocalPO_UMIN1_FAZ = LocalPO_UMIN1_FAZ_I;
 if(tmp1)
    LocalPO_UMIN1_FAZ = LocalPO_UMIN1_FAZ_ILI;

		// UMIN1 ФАЗ ЛИН
 tmp1 =     ENA_LOGIC(ENA_UMIN1_3);
 int LocalPO_UMIN1_LOC = LocalPO_UMIN1_FAZ;
 if(tmp1)
     LocalPO_UMIN1_LOC = LocalPO_UMIN1_LIN;
 
//IBLOK
		// UMIN1 LIN IBLOK И ИЛИ
    tmp1 =     ENA_LOGIC(ENA_UMIN1_2);
 int LocalPO_UMIN1_LIN_IBLOK = LocalPO_UMIN1_LIN_I_IBLOK;
 if(tmp1)
     LocalPO_UMIN1_LIN_IBLOK = LocalPO_UMIN1_LIN_ILI_IBLOK;

		// UMIN1 FAZ IBLOK И ИЛИ
    tmp1 =     ENA_LOGIC(ENA_UMIN1_2);
 int LocalPO_UMIN1_FAZ_IBLOK = LocalPO_UMIN1_FAZ_I_IBLOK;
 if(tmp1)
     LocalPO_UMIN1_FAZ_IBLOK = LocalPO_UMIN1_FAZ_ILI_IBLOK;

		// UMIN1 ФАЗ ЛИН IBLOK
 tmp1 =     ENA_LOGIC(ENA_UMIN1_3);
 int LocalPO_UMIN1_IBLOK = LocalPO_UMIN1_FAZ_IBLOK;
 if(tmp1)
     LocalPO_UMIN1_IBLOK = LocalPO_UMIN1_LIN_IBLOK;

// UMIN1 блок I 
 tmp1 =     ENA_LOGIC(ENA_UMIN1_4);
// int LocalPO_UMIN1_LOC = 
 if(tmp1)
     LocalPO_UMIN1_LOC = LocalPO_UMIN1_IBLOK;

//UBLOK
		// UMIN1 LIN И ИЛИ UBLOK
    tmp1 =     ENA_LOGIC(ENA_UMIN1_2);
 int LocalPO_UMIN1_LIN_UBLOK = LocalPO_UMIN1_LIN_I_UBLOK;
 if(tmp1)
    LocalPO_UMIN1_LIN_UBLOK = LocalPO_UMIN1_LIN_ILI_UBLOK;

		// UMIN1 FAZ И ИЛИ UBLOK
    tmp1 =     ENA_LOGIC(ENA_UMIN1_2);
 int LocalPO_UMIN1_FAZ_UBLOK = LocalPO_UMIN1_FAZ_I_UBLOK;
 if(tmp1)
    LocalPO_UMIN1_FAZ_UBLOK = LocalPO_UMIN1_FAZ_ILI_UBLOK;

		// UMIN1 ФАЗ ЛИН UBLOK
 tmp1 =     ENA_LOGIC(ENA_UMIN1_3);
 int LocalPO_UMIN1_LOC_UBLOK = LocalPO_UMIN1_FAZ_UBLOK;
 if(tmp1)
     LocalPO_UMIN1_LOC_UBLOK = LocalPO_UMIN1_LIN_UBLOK;

//IBLOK UBLOK
		// UMIN1 LIN IBLOK И ИЛИ UBLOK
    tmp1 =     ENA_LOGIC(ENA_UMIN1_2);
 int LocalPO_UMIN1_LIN_IBLOK_UBLOK = LocalPO_UMIN1_LIN_I_IBLOK_UBLOK;
 if(tmp1)
     LocalPO_UMIN1_LIN_IBLOK_UBLOK = LocalPO_UMIN1_LIN_ILI_IBLOK_UBLOK;

		// UMIN1 FAZ IBLOK И ИЛИ UBLOK
    tmp1 =     ENA_LOGIC(ENA_UMIN1_2);
 int LocalPO_UMIN1_FAZ_IBLOK_UBLOK = LocalPO_UMIN1_FAZ_I_IBLOK_UBLOK;
 if(tmp1)
     LocalPO_UMIN1_FAZ_IBLOK_UBLOK = LocalPO_UMIN1_FAZ_ILI_IBLOK_UBLOK;

		// UMIN1 ФАЗ ЛИН IBLOK UBLOK
 tmp1 =     ENA_LOGIC(ENA_UMIN1_3);
 int LocalPO_UMIN1_IBLOK_UBLOK = LocalPO_UMIN1_FAZ_IBLOK_UBLOK;
 if(tmp1)
     LocalPO_UMIN1_IBLOK_UBLOK = LocalPO_UMIN1_LIN_IBLOK_UBLOK;

// UMIN1 блок I UBLOK
 tmp1 =     ENA_LOGIC(ENA_UMIN1_4);
// int LocalPO_UMIN1_LOC = 
 if(tmp1)
     LocalPO_UMIN1_LOC_UBLOK = LocalPO_UMIN1_IBLOK_UBLOK;

	// UMIN1 блок U
 tmp1 =     ENA_LOGIC(ENA_UMIN1_5);
 if(tmp1 &
	(
	// UMIN1 блок I UBLOK
	ENA_LOGIC(ENA_UMIN1_4)^1
	)
    )
     LocalPO_UMIN1_LOC = LocalPO_UMIN1_LOC_UBLOK;

 int  LocalPO_UMIN1 = LocalPO_UMIN1_LOC;

//-------------UMIN2-----------
		// UMIN2 LIN И ИЛИ
    tmp1 =     ENA_LOGIC(ENA_UMIN2_2);
 int LocalPO_UMIN2_LIN = LocalPO_UMIN2_LIN_I;
 if(tmp1)
    LocalPO_UMIN2_LIN = LocalPO_UMIN2_LIN_ILI;

		// UMIN2 FAZ И ИЛИ
    tmp1 =     ENA_LOGIC(ENA_UMIN2_2);
 int LocalPO_UMIN2_FAZ = LocalPO_UMIN2_FAZ_I;
 if(tmp1)
    LocalPO_UMIN2_FAZ = LocalPO_UMIN2_FAZ_ILI;

		// UMIN2 ФАЗ ЛИН
 tmp1 =     ENA_LOGIC(ENA_UMIN2_3);
 int LocalPO_UMIN2_LOC = LocalPO_UMIN2_FAZ;
 if(tmp1)
     LocalPO_UMIN2_LOC = LocalPO_UMIN2_LIN;
 
//IBLOK
		// UMIN2 LIN IBLOK И ИЛИ
    tmp1 =     ENA_LOGIC(ENA_UMIN2_2);
 int LocalPO_UMIN2_LIN_IBLOK = LocalPO_UMIN2_LIN_I_IBLOK;
 if(tmp1)
     LocalPO_UMIN2_LIN_IBLOK = LocalPO_UMIN2_LIN_ILI_IBLOK;

		// UMIN2 FAZ IBLOK И ИЛИ
    tmp1 =     ENA_LOGIC(ENA_UMIN2_2);
 int LocalPO_UMIN2_FAZ_IBLOK = LocalPO_UMIN2_FAZ_I_IBLOK;
 if(tmp1)
     LocalPO_UMIN2_FAZ_IBLOK = LocalPO_UMIN2_FAZ_ILI_IBLOK;

		// UMIN2 ФАЗ ЛИН IBLOK
 tmp1 =     ENA_LOGIC(ENA_UMIN2_3);
 int LocalPO_UMIN2_IBLOK = LocalPO_UMIN2_FAZ_IBLOK;
 if(tmp1)
     LocalPO_UMIN2_IBLOK = LocalPO_UMIN2_LIN_IBLOK;

// UMIN2 блок I 
 tmp1 =     ENA_LOGIC(ENA_UMIN2_4);
 if(tmp1)
     LocalPO_UMIN2_LOC = LocalPO_UMIN2_IBLOK;

//
//UBLOK
		// UMIN2 LIN И ИЛИ UBLOK
    tmp1 =     ENA_LOGIC(ENA_UMIN2_2);
 int LocalPO_UMIN2_LIN_UBLOK = LocalPO_UMIN2_LIN_I_UBLOK;
 if(tmp1)
    LocalPO_UMIN2_LIN_UBLOK = LocalPO_UMIN2_LIN_ILI_UBLOK;

		// UMIN2 FAZ И ИЛИ UBLOK
    tmp1 =     ENA_LOGIC(ENA_UMIN2_2);
 int LocalPO_UMIN2_FAZ_UBLOK = LocalPO_UMIN2_FAZ_I_UBLOK;
 if(tmp1)
    LocalPO_UMIN2_FAZ_UBLOK = LocalPO_UMIN2_FAZ_ILI_UBLOK;

		// UMIN2 ФАЗ ЛИН UBLOK
 tmp1 =     ENA_LOGIC(ENA_UMIN2_3);
 int LocalPO_UMIN2_LOC_UBLOK = LocalPO_UMIN2_FAZ_UBLOK;
 if(tmp1)
     LocalPO_UMIN2_LOC_UBLOK = LocalPO_UMIN2_LIN_UBLOK;

//IBLOK UBLOK
		// UMIN1 LIN IBLOK И ИЛИ UBLOK
    tmp1 =     ENA_LOGIC(ENA_UMIN2_2);
 int LocalPO_UMIN2_LIN_IBLOK_UBLOK = LocalPO_UMIN2_LIN_I_IBLOK_UBLOK;
 if(tmp1)
     LocalPO_UMIN2_LIN_IBLOK_UBLOK = LocalPO_UMIN2_LIN_ILI_IBLOK_UBLOK;

		// UMIN1 FAZ IBLOK И ИЛИ UBLOK
    tmp1 =     ENA_LOGIC(ENA_UMIN2_2);
 int LocalPO_UMIN2_FAZ_IBLOK_UBLOK = LocalPO_UMIN2_FAZ_I_IBLOK_UBLOK;
 if(tmp1)
     LocalPO_UMIN2_FAZ_IBLOK_UBLOK = LocalPO_UMIN2_FAZ_ILI_IBLOK_UBLOK;

		// UMIN1 ФАЗ ЛИН IBLOK UBLOK
 tmp1 =     ENA_LOGIC(ENA_UMIN2_3);
 int LocalPO_UMIN2_IBLOK_UBLOK = LocalPO_UMIN2_FAZ_IBLOK_UBLOK;
 if(tmp1)
     LocalPO_UMIN2_IBLOK_UBLOK = LocalPO_UMIN2_LIN_IBLOK_UBLOK;

// UMIN2 блок I UBLOK
 tmp1 =     ENA_LOGIC(ENA_UMIN2_4);
 if(tmp1)
     LocalPO_UMIN2_LOC_UBLOK = LocalPO_UMIN2_IBLOK_UBLOK;

	// UMIN2 блок U
 tmp1 =     ENA_LOGIC(ENA_UMIN2_5);
 if(tmp1 &
	(
	// UMIN2 блок I UBLOK
	ENA_LOGIC(ENA_UMIN2_4)^1
	)
    )
     LocalPO_UMIN2_LOC = LocalPO_UMIN2_LOC_UBLOK;

 int  LocalPO_UMIN2 = LocalPO_UMIN2_LOC;
*/

    //*******UMM1********
    //L3 UMIN1
    LSIGNAL_TIMER(TIMER1_UMM)  = //UMIN1_TIM1
    //Сраб ПО UMIN1
    IO_LOGIC(IOCMD9_UMM) =
                  //Стат блок UMIN1
                 (IO_LOGIC(IOCMD3_UMM)^1) &
                 //Управл UMIN1
                 ENA_LOGIC(ENA_UMIN1_1) &
                 (
                 //L1
                 //ПО UMM1
                 (GlobalPO1 | LocalPO_UMIN1) |
                  //Пуск UMIN1
                  IO_LOGIC(IOCMDPUSK1_UMM)
                 );

 int tmp = 
 //таймер BO UMIN1
 LSIGNAL_TIMER(TIMER_BOUMIN1)  = 
        //UMIN1_TIM1
        PLOG_TIMER(TIMER1_UMM);

    //Сраб UMIN1
    IO_LOGIC(IOCMD10_UMM) =
         //таймер BO UMIN1
          ILOG_TIMER(TIMER_BOUMIN1)|tmp;

    //L4 UMIN2
    LSIGNAL_TIMER(TIMER2_UMM)  = //UMIN2_TIM1
    //Сраб ПО UMIN2
    IO_LOGIC(IOCMD11_UMM) =
                  //Стат блок UMIN2
                 (IO_LOGIC(IOCMD4_UMM)^1) &
                 //Управл UMIN2
                 ENA_LOGIC(ENA_UMIN2_1) &
                 (
                 //L2
                 //ПО UMM2
                 (GlobalPO2 | LocalPO_UMIN2) |
                  //Пуск UMIN2
                  IO_LOGIC(IOCMDPUSK2_UMM)
                 );

 tmp = 
 //таймер BO UMIN2
 LSIGNAL_TIMER(TIMER_BOUMIN2)  = 
        //UMIN2_TIM1
        PLOG_TIMER(TIMER2_UMM);

    //Сраб UMIN2
    IO_LOGIC(IOCMD12_UMM) =
         //таймер BO UMIN2
          ILOG_TIMER(TIMER_BOUMIN2)|tmp;

    int tt1 = IO_LOGIC(IOCMD12_UMM);
    int tt2=0;
    if(tt1==1){
      int tt2=1;
    }//if
      
      
    //L5 UMAX1
    LSIGNAL_TIMER(TIMER3_UMM)  = //UMAX1_TIM1
    //Сраб ПО UMAX1
    IO_LOGIC(IOCMD5_UMM) =
                  //Стат блок UMAX1
                 (IO_LOGIC(IOCMD1_UMM)^1) &
                 //Управл UMAX1
                 ENA_LOGIC(ENA_UMAX1_1) &
                 //ПО UMM1
                 (GlobalPO1 | LocalPO_UMAX1);

 tmp = 
 //таймер BO UMAX1
 LSIGNAL_TIMER(TIMER_BOUMAX1)  = 
        //UMAX1_TIM1
        PLOG_TIMER(TIMER3_UMM);

    //Сраб UMAX1
    IO_LOGIC(IOCMD6_UMM) =
         //таймер BO UMAX1
          ILOG_TIMER(TIMER_BOUMAX1)|tmp;

    //L6 UMAX2
    LSIGNAL_TIMER(TIMER4_UMM)  = //UMAX2_TIM1
    //Сраб ПО UMAX2
    IO_LOGIC(IOCMD7_UMM) =
                  //Стат блок UMAX2
                 (IO_LOGIC(IOCMD2_UMM)^1) &
                 //Управл UMAX2
                 ENA_LOGIC(ENA_UMAX2_1) &
                 //ПО UMM2
                 (GlobalPO2 | LocalPO_UMAX2);

 tmp = 
 //таймер BO UMAX2
 LSIGNAL_TIMER(TIMER_BOUMAX2)  = 
        //UMAX2_TIM1
        PLOG_TIMER(TIMER4_UMM);

    //Сраб UMAX2
    IO_LOGIC(IOCMD8_UMM) =
         //таймер BO UMAX2
          ILOG_TIMER(TIMER_BOUMAX2)|tmp;

}//logicUMM(int idxC)

