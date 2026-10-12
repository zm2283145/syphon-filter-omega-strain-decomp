#include "types.h"
int Script_cPARTICLE_GOBJ_ScaleBBox();
int Script_cPARTICLE_GOBJ_Disable();
int Script_cPARTICLE_GOBJ_Enable();
int ScriptType_cPARTICLE_GOBJ_Init();
int ScriptType_cVUM_GOBJ_Init();
int Script_RegisterNative();
int Script_RegisterType();
extern char D_00493880;
extern char D_00493890;
extern int D_0053B4F0;
extern int D_0053B4F8;
extern int D_0053B500;
extern int D_0053B508;
extern int D_0053B510;
extern int D_0053B518;
extern int D_0053B520;
void func_004D5390(void) {
    D_0053B4F0 = Script_RegisterType("cVUM_GOBJ", ScriptType_cVUM_GOBJ_Init, 0, 1);
    D_0053B4F8 = D_0053B4F0;
    D_0053B500 = Script_RegisterType("cPARTICLE_GOBJ", ScriptType_cPARTICLE_GOBJ_Init, 0, 1);
    D_0053B508 = D_0053B500;
    D_0053B510 = Script_RegisterNative(D_0053B500, Script_cPARTICLE_GOBJ_Enable, &D_00493880, "Enable", 1, &D_0053B500);
    D_0053B518 = Script_RegisterNative(D_0053B500, Script_cPARTICLE_GOBJ_Disable, &D_00493880, "Disable", 1, &D_0053B500);
    D_0053B520 = Script_RegisterNative(D_0053B500, Script_cPARTICLE_GOBJ_ScaleBBox, &D_00493880, "ScaleBBox", 2, &D_0053B500, &D_00493890);
}
