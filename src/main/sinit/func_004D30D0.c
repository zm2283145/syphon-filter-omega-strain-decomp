#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DD710;
extern void* D_00506478;
extern void* D_00506480;
void func_004D30D0(void) {
    D_00506480 = &D_004DD710;
    D_00506478 = "GuiOnlineOfflineSelect";
    FreeList_Push(&D_00506478);
}
