

#define IO_LOGIC(offset)     WideCmdRTBuffer[tmpOffsetIO + offset]
#define IO_LOGICOUT(offset)  WideCmdRTBuffer[offset]
#define TL_LOGIC(offset)     tempLog[tmpOffsetTL + offset]
#define ENA_LOGIC(offset)    ENAcmd[tmpOffsetENA + offset]
#define ENA_LOGICOUT(offset) ENAcmd[offset]
#define SPV_UST(offset)      spvUSTAVKI[tmpOffsetUSpv + offset]
#define SPV_USTOUT(offset)   spvUSTAVKI[offset]

//определить триг по восх фронту
//set- сиг уст; clr- сиг сброса; old- память; out- выход
#define TRG_FRONT(set, clr, old, out)  if((set ^ TL_LOGIC(old) )&set)\
        TL_LOGIC(out)=1; \
        TL_LOGIC(old) = set;\
        if(clr^1) TL_LOGIC(out)=0;
//определить триг по восх фронту MMF
//set- сиг уст; clr- сиг сброса; old- память; out- выход
#define TRG_MMF(set, clr, old, out)  if((clr ^ TL_LOGIC(old) )&clr)\
        TL_LOGIC(out)=0; \
        TL_LOGIC(old) = clr;\
        if(set) TL_LOGIC(out)=1;
//определить EL триг по восх фронту
//set- сиг уст; old- память; out- выход
#define TRG_EL(set, old, out)  out = ((set ^ TL_LOGIC(old) )&set);\
        TL_LOGIC(old) = set;

//определить EL триг по восх фронту
//set- сиг уст; old- память; out- выход
#define TRGL_EL(set, old, out)  out = ((set ^ old )&set);\
          old = set;
//определить EL триг по падающему фронту
//set- сиг уст; old- память; out- выход
#define TRGL_ELDOWN(set, old, out)  out = ((set ^ old )&old);\
          old = set;

//32 int на зону ДЗ(4 точки по 8int на точку)
//в каждой ступени ДЗ по 2 зоны
//#define OFFZONA  0

//логика РЛ
#define IO_LOGIC_WL(offset)     WideCmdRTBuffer[tmpOffsetIO + offset]
#define IO_LOGICOUT_WL(offset)  WideCmdRTBuffer[offset]
#define TL_LOGIC_WL(offset)     tempLog_WL[tmpOffsetTL + offset]
#define ENA_LOGIC_WL(offset)    ENAcmd_WL[tmpOffsetENA + offset]
#define ENA_LOGICOUT_WL(offset) ENAcmd_WL[offset]
#define SPV_UST_WL(offset)      spvUSTAVKI_WL[tmpOffsetUSpv + offset]
#define SPV_USTOUT_WL(offset)   spvUSTAVKI_WL[offset]


