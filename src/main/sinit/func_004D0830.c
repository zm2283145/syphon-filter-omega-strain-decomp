#include "types.h"
int __register_global_object();
int func_00144930();
int Script_cFireObj_Disable();
int Script_cFireObj_Enable();
int ScriptType_cFireObj_Init();
int func_003D84F0();
int Script_RegisterType();
extern char D_00493880;
extern char D_004F82F8;
extern void* D_004F8308;
extern int D_004F8310;
extern int D_004F8318;
extern int D_004F8320;
extern int D_004F8328;
void func_004D0830(void) {
    D_004F8308 = "FIRE";
    __register_global_object(&D_004F8308, func_00144930, &D_004F82F8);
    D_004F8310 = Script_RegisterType("cFireObj", ScriptType_cFireObj_Init, 0, 1);
    D_004F8318 = D_004F8310;
    D_004F8320 = func_003D84F0(D_004F8310, Script_cFireObj_Enable, &D_00493880, "Enable", 1, &D_004F8310);
    D_004F8328 = func_003D84F0(D_004F8310, Script_cFireObj_Disable, &D_00493880, "Disable", 1, &D_004F8310);
}
