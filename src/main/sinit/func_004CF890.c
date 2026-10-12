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
extern char func_00245750[];
extern char D_004F7DC8[];
extern int D_004F7DD0;
extern int Script_RegisterNative_2();
extern int Script_RegisterVariable();
extern int func_002824D0();
void func_004CF890(void)
{
    D_004F7D48 = Script_RegisterNative_2(Script_SetInfoBarFont, D_00493880, "SetInfoBarFont", 1, D_004EE538);
    D_004F7D50 = Script_RegisterVariable("NightVisionMaskFrames", (int)D_0048AE48, D_00493888);
    D_004F7D80 = Script_RegisterNative_2(Script_SetInterfaceTextColor, D_00493880, "SetInterfaceTextColor", 4, D_00493888, D_00493888, D_00493888, D_00493890);
    D_004F7D88 = Script_RegisterNative_2(Script_SetNVInterfaceTextColor, D_00493880, "SetNVInterfaceTextColor", 4, D_00493888, D_00493888, D_00493888, D_00493890);
    D_004F7DB8 = -1;
    D_004F7DC0 = "cNetTimerMsg";
    D_004F7DD0 = func_002824D0(func_00245750, D_004F7DC8, "cNetTimerMsg");
}
