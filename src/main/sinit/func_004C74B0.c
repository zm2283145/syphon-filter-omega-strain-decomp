#include "types.h"
int Script_LoadAnimation();
int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern char D_00493880;
extern char D_00493898;
extern int D_004EF090;
void StaticInit_Loader(void) {
    D_004EF090 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_LoadAnimation, &D_00493880, "LoadAnimation", 1, &D_00493898);
}
