#include "types.h"
int func_003D8740();
int func_003D8A30();
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
    D_0055A258 = func_003D8A30("cursorFlashRate", (int)&D_00493960, &D_00493888);
    D_0055A260 = func_003D8A30("cursorFlashDiv", (int)&D_00493968, &D_00493888);
    D_0055A268 = func_003D8A30("cursorOff", (int)&D_00493978, &D_00493888);
    D_0055A270 = func_003D8740(Script_SetCursorChar, &D_00493880, "SetCursorChar", 1, &D_00493898);
}
