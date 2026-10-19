#include "types.h"
int Script_SetLocation();
int cGOBJ_GetScriptTypeKeyPtr();
int Script_RegisterNative_2();
int FreeList_Push();
extern char D_00493880;
extern char D_00493898;
extern char D_004DDEC0;
extern void* D_00506608;
extern void* D_00506610;
extern int D_00506618;
void StaticInit_GuiQuickChat(void) {
    D_00506610 = &D_004DDEC0;
    D_00506608 = "GuiQuickChat";
    FreeList_Push(&D_00506608);
    D_00506618 = Script_RegisterNative_2(Script_SetLocation, &D_00493880, "SetLocation", 2, cGOBJ_GetScriptTypeKeyPtr(), &D_00493898);
}
