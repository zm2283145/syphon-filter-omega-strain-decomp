#include "types.h"
int __register_global_object();
int Script_SetTexture();
int Script_DecTexture();
int Script_IncTexture();
int XLib_dtor();
int XLib_ctor();
int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern char D_00493880;
extern char D_00493888;
extern char D_00493898;
extern char D_005381E0;
extern char g_Video;
extern int D_00539310;
extern int D_00539318;
extern int D_00539320;
void StaticInit_xlib(void) {
    XLib_ctor(&g_Video);
    __register_global_object(&g_Video, XLib_dtor, &D_005381E0);
    D_00539310 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_IncTexture, &D_00493880, "IncTexture", 1, &D_00493898);
    D_00539318 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_DecTexture, &D_00493880, "DecTexture", 1, &D_00493898);
    D_00539320 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetTexture, &D_00493880, "SetTexture", 2, &D_00493898, &D_00493888);
}
