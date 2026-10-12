#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DDBF8;
extern void* D_005065B0;
extern void* D_005065B8;
void func_004D3260(void) {
    D_005065B8 = &D_004DDBF8;
    D_005065B0 = "GuiMissionList";
    FreeList_Push(&D_005065B0);
}
