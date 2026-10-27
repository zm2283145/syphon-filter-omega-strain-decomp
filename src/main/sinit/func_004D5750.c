#include "types.h"
int Script_cSKYBOX_GOBJ_Disable();
int Script_cSKYBOX_GOBJ_Enable();
int cSKYBOX_GOBJ_SOBJ_init();
int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc();
int cScriptBase_addClass();
extern char D_00493880;
extern int D_00542C98;
extern int D_00542CA0;
extern int D_00542CA8;
extern int D_00542CB0;
void StaticInit_skybox(void) {
    D_00542C98 = cScriptBase_addClass("cSKYBOX_GOBJ", cSKYBOX_GOBJ_SOBJ_init, 0, 1);
    D_00542CA0 = D_00542C98;
    D_00542CA8 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_00542C98, Script_cSKYBOX_GOBJ_Enable, &D_00493880, "Enable", 1, &D_00542C98);
    D_00542CB0 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_00542C98, Script_cSKYBOX_GOBJ_Disable, &D_00493880, "Disable", 1, &D_00542C98);
}
