#include "types.h"
int cNetMsg_RegisterMsg();
int Script_EnableSuperJump_2();
int Script_EnableSuperJump();
int func_00326C00();
int cGOBJ_SOBJ_getClassId();
int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern char D_00493878;
extern char D_00493880;
extern void* D_0052AF10;
extern char D_0052AF18;
extern int D_0052AF20;
extern int D_0052AF28;
extern int D_0052AF30;
void StaticInit_enableSuperJumpMsg(void) {
    D_0052AF10 = "cEnableSuperJumpMsg";
    D_0052AF20 = cNetMsg_RegisterMsg(func_00326C00, &D_0052AF18, "cEnableSuperJumpMsg");
    D_0052AF28 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_EnableSuperJump, &D_00493880, "EnableSuperJump", 1, cGOBJ_SOBJ_getClassId());
    D_0052AF30 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_EnableSuperJump_2, &D_00493880, "EnableSuperJump", 2, cGOBJ_SOBJ_getClassId(), &D_00493878);
}
