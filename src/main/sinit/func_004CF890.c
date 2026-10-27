#include "types.h"
extern char Script_SetInfoBarFont[];
extern char D_00493880[];
extern char D_004EE538[];
extern int D_004F7D48;
extern char D_0048AE48[];
extern char D_00493888[];
extern int D_004F7D50;
extern char Script_SetInterfaceTextColor[];
extern char D_00493890[];
extern int D_004F7D80;
extern char Script_SetNVInterfaceTextColor[];
extern int D_004F7D88;
extern int D_004F7DB8;
extern char* D_004F7DC0;
extern char cNetTimerMsg_NetReceive[];
extern char D_004F7DC8[];
extern int D_004F7DD0;
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern int cScriptBase_registerGlobalVar();
extern int cNetMsg_RegisterMsg();
void StaticInit_hud(void)
{
    D_004F7D48 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetInfoBarFont, D_00493880, "SetInfoBarFont", 1, D_004EE538);
    D_004F7D50 = cScriptBase_registerGlobalVar("NightVisionMaskFrames", (int)D_0048AE48, D_00493888);
    D_004F7D80 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetInterfaceTextColor, D_00493880, "SetInterfaceTextColor", 4, D_00493888, D_00493888, D_00493888, D_00493890);
    D_004F7D88 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetNVInterfaceTextColor, D_00493880, "SetNVInterfaceTextColor", 4, D_00493888, D_00493888, D_00493888, D_00493890);
    D_004F7DB8 = -1;
    D_004F7DC0 = "cNetTimerMsg";
    D_004F7DD0 = cNetMsg_RegisterMsg(cNetTimerMsg_NetReceive, D_004F7DC8, "cNetTimerMsg");
}
