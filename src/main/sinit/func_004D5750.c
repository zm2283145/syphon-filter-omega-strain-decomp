#include "types.h"
int Script_cSKYBOX_GOBJ_Disable();
int Script_cSKYBOX_GOBJ_Enable();
int ScriptType_cSKYBOX_GOBJ_Init();
int Script_RegisterNative();
int Script_RegisterType();
extern char D_00493880;
extern int D_00542C98;
extern int D_00542CA0;
extern int D_00542CA8;
extern int D_00542CB0;
void func_004D5750(void) {
    D_00542C98 = Script_RegisterType("cSKYBOX_GOBJ", ScriptType_cSKYBOX_GOBJ_Init, 0, 1);
    D_00542CA0 = D_00542C98;
    D_00542CA8 = Script_RegisterNative(D_00542C98, Script_cSKYBOX_GOBJ_Enable, &D_00493880, "Enable", 1, &D_00542C98);
    D_00542CB0 = Script_RegisterNative(D_00542C98, Script_cSKYBOX_GOBJ_Disable, &D_00493880, "Disable", 1, &D_00542C98);
}
