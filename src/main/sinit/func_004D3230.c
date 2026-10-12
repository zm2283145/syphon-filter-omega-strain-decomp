#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DDB60;
extern void* D_005065A0;
extern void* D_005065A8;
void func_004D3230(void) {
    D_005065A8 = &D_004DDB60;
    D_005065A0 = "GuiOnlineOptions";
    FreeList_Push(&D_005065A0);
}
