#include "types.h"
int __register_global_object();
int cSubclassId_dtor();
int Script_cFireObj_Disable();
int Script_cFireObj_Enable();
int cFireObj_SOBJ_init();
int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc();
int cScriptBase_addClass();
extern char D_00493880;
extern char D_004F82F8;
extern void* D_004F8308;
extern int D_004F8310;
extern int D_004F8318;
extern int D_004F8320;
extern int D_004F8328;
void StaticInit_fire(void) {
    D_004F8308 = "FIRE";
    __register_global_object(&D_004F8308, cSubclassId_dtor, &D_004F82F8);
    D_004F8310 = cScriptBase_addClass("cFireObj", cFireObj_SOBJ_init, 0, 1);
    D_004F8318 = D_004F8310;
    D_004F8320 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004F8310, Script_cFireObj_Enable, &D_00493880, "Enable", 1, &D_004F8310);
    D_004F8328 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004F8310, Script_cFireObj_Disable, &D_00493880, "Disable", 1, &D_004F8310);
}
