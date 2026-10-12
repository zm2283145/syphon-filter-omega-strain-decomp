#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DDAD0;
extern void* D_00506590;
extern void* D_00506598;
void func_004D3200(void) {
    D_00506598 = &D_004DDAD0;
    D_00506590 = "GuiNetJoinMission";
    FreeList_Push(&D_00506590);
}
