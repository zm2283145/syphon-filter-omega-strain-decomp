#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DD4C0;
extern char D_004DD4D0;
extern void* D_00506398;
extern void* D_005063A0;
extern void* D_005063A8;
extern void* D_005063B0;
void func_004D2F10(void) {
    D_005063A0 = &D_004DD4D0;
    D_00506398 = "GuiAgentLoad";
    FreeList_Push(&D_00506398);
    D_005063B0 = &D_004DD4C0;
    D_005063A8 = "GuiAgentSave";
    FreeList_Push(&D_005063A8);
}
