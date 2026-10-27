#include "types.h"
extern int D_004A7540, D_004A7548, D_004A7550, D_004A7558;
extern int D_004A7560, D_004A7568, D_004A7570, D_004A7578;
extern int D_004A7580, D_004A7588, D_004A7590, D_004A7598;
extern char D_004A7830[], D_004A7850[], D_004A7870[], D_004A7890[], D_004A78B0[], D_004A78D0[];
extern char D_004A78F0[], D_004A7900[], D_004A7918[], D_004A7930[], D_004A7948[];
extern char D_004A7958[], D_004A7960[], D_004A7968[];
extern char D_0048AE58, D_0048AE60, D_0048AE68, D_0048AE70, D_0048AE78, D_0048AE80;
extern char D_0048AED0, D_0048AED8, D_0048AEE0;
extern char D_00493888[], D_00493890[];
extern int D_004F7DE0, D_004F7DE8, D_004F7DF0, D_004F7DF8, D_004F7E00, D_004F7E08;
extern int D_004F7E30, D_004F7E38, D_004F7E40;
extern char* D_004F7E48;
extern int D_004F7E50, D_004F7E58, D_004F7E60, D_004F7E68;
extern signed char D_004EA0C8;
extern char* g_LosCheckService;
extern char cMenuChoiceMsg_SOBJ_init[];
extern char Script_cMenuChoiceMsg_Choice[];
extern char Script_cMenuChoiceMsg_Who[];
extern int cScriptBase_registerGlobalVar();
extern int cScriptBase_addClass();
extern int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc();
extern int* cMenuChoiceMsg_SOBJ_getClassId(void);
extern char* cSystem_SOBJ_getClassId(void);

void StaticInit_playerControls(void)
{
    D_004A7540 = 0x3F91361E;
    D_004A7548 = 0x3F61A840;
    D_004A7550 = 0x3E800000;
    D_004A7558 = 0x3E4CCCCD;
    D_004F7DE0 = cScriptBase_registerGlobalVar(D_004A7830, (int)&D_0048AE58, D_00493890);
    D_004F7DE8 = cScriptBase_registerGlobalVar(D_004A7850, (int)&D_0048AE60, D_00493890);
    D_004F7DF0 = cScriptBase_registerGlobalVar(D_004A7870, (int)&D_0048AE68, D_00493890);
    D_004F7DF8 = cScriptBase_registerGlobalVar(D_004A7890, (int)&D_0048AE70, D_00493890);
    D_004F7E00 = cScriptBase_registerGlobalVar(D_004A78B0, (int)&D_0048AE78, D_00493890);
    D_004F7E08 = cScriptBase_registerGlobalVar(D_004A78D0, (int)&D_0048AE80, D_00493890);
    D_004A7560 = 0x3F5F66F3;
    D_004A7568 = 0x401C61AA;
    D_004A7570 = 0xBD84410B;
    D_004A7578 = 0x3F9C61AA;
    D_004A7580 = 0x3E4CCCCD;
    D_004A7588 = 0x40400000;
    D_004A7590 = 0x3F000000;
    D_004A7598 = 0x3F400000;
    D_004F7E30 = cScriptBase_registerGlobalVar(D_004A78F0, (int)&D_0048AED0, D_00493888);
    D_004F7E38 = cScriptBase_registerGlobalVar(D_004A7900, (int)&D_0048AED8, D_00493890);
    D_004F7E40 = cScriptBase_registerGlobalVar(D_004A7918, (int)&D_0048AEE0, D_00493890);
    D_004F7E48 = D_004A7930;
    D_004F7E50 = cScriptBase_addClass(D_004A7948, cMenuChoiceMsg_SOBJ_init, 1, 0);
    D_004F7E58 = *cMenuChoiceMsg_SOBJ_getClassId();
    D_004F7E60 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cMenuChoiceMsg_SOBJ_getClassId(), Script_cMenuChoiceMsg_Choice, D_00493888, D_004A7958, 1, cMenuChoiceMsg_SOBJ_getClassId());
    D_004F7E68 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*cMenuChoiceMsg_SOBJ_getClassId(), Script_cMenuChoiceMsg_Who, cSystem_SOBJ_getClassId(), D_004A7960, 1, cMenuChoiceMsg_SOBJ_getClassId());
    if (!D_004EA0C8) {
        g_LosCheckService = D_004A7968;
        D_004EA0C8 = 1;
    }
}


