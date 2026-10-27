#include "types.h"
int Script_cPARTICLE_GOBJ_ScaleBBox();
int Script_cPARTICLE_GOBJ_Disable();
int Script_cPARTICLE_GOBJ_Enable();
int cPARTICLE_GOBJ_SOBJ_init();
int cVUM_GOBJ_SOBJ_init();
int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc();
int cScriptBase_addClass();
extern char D_00493880;
extern char D_00493890;
extern int D_0053B4F0;
extern int D_0053B4F8;
extern int D_0053B500;
extern int D_0053B508;
extern int D_0053B510;
extern int D_0053B518;
extern int D_0053B520;
void StaticInit_gameobj(void) {
    D_0053B4F0 = cScriptBase_addClass("cVUM_GOBJ", cVUM_GOBJ_SOBJ_init, 0, 1);
    D_0053B4F8 = D_0053B4F0;
    D_0053B500 = cScriptBase_addClass("cPARTICLE_GOBJ", cPARTICLE_GOBJ_SOBJ_init, 0, 1);
    D_0053B508 = D_0053B500;
    D_0053B510 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_0053B500, Script_cPARTICLE_GOBJ_Enable, &D_00493880, "Enable", 1, &D_0053B500);
    D_0053B518 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_0053B500, Script_cPARTICLE_GOBJ_Disable, &D_00493880, "Disable", 1, &D_0053B500);
    D_0053B520 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_0053B500, Script_cPARTICLE_GOBJ_ScaleBBox, &D_00493880, "ScaleBBox", 2, &D_0053B500, &D_00493890);
}
