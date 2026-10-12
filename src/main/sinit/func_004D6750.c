#include "types.h"
int Script_RegisterNative_2();
int Script_RegisterVariable();
int Script_SetCursorChar();
extern char D_00493880;
extern char D_00493888;
extern char D_00493898;
extern char D_00493960;
extern char D_00493968;
extern char D_00493978;
extern int D_004BDF10;
extern int D_004BDF14;
extern int D_004BDF18;
extern int D_004BDF1C;
extern int D_0055A258;
extern int D_0055A260;
extern int D_0055A268;
extern int D_0055A270;
void func_004D6750(void) {
    D_004BDF10 = 1060320051;
    D_004BDF14 = 1045220557;
    D_004BDF18 = 1060320051;
    D_004BDF1C = 1056964608;
    D_0055A258 = Script_RegisterVariable("cursorFlashRate", (int)&D_00493960, &D_00493888);
    D_0055A260 = Script_RegisterVariable("cursorFlashDiv", (int)&D_00493968, &D_00493888);
    D_0055A268 = Script_RegisterVariable("cursorOff", (int)&D_00493978, &D_00493888);
    D_0055A270 = Script_RegisterNative_2(Script_SetCursorChar, &D_00493880, "SetCursorChar", 1, &D_00493898);
}
