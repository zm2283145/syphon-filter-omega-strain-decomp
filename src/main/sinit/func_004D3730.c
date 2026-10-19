#include "types.h"
int NetMsgTable_Add();
int Script_EnableSuperJump_2();
int Script_EnableSuperJump();
int func_00326C00();
int cGOBJ_GetScriptTypeKeyPtr();
int Script_RegisterNative_2();
extern char D_00493878;
extern char D_00493880;
extern void* D_0052AF10;
extern char D_0052AF18;
extern int D_0052AF20;
extern int D_0052AF28;
extern int D_0052AF30;
void StaticInit_RegisterEnableSuperJump(void) {
    D_0052AF10 = "cEnableSuperJumpMsg";
    D_0052AF20 = NetMsgTable_Add(func_00326C00, &D_0052AF18, "cEnableSuperJumpMsg");
    D_0052AF28 = Script_RegisterNative_2(Script_EnableSuperJump, &D_00493880, "EnableSuperJump", 1, cGOBJ_GetScriptTypeKeyPtr());
    D_0052AF30 = Script_RegisterNative_2(Script_EnableSuperJump_2, &D_00493880, "EnableSuperJump", 2, cGOBJ_GetScriptTypeKeyPtr(), &D_00493878);
}
