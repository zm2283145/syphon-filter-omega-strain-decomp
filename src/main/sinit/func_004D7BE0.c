#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E15C0;
extern void* D_005860B0;
extern void* D_005860B8;
void func_004D7BE0(void) {
    D_005860B8 = &D_004E15C0;
    D_005860B0 = "GuiSubTitleDisplay";
    FreeList_Push(&D_005860B0);
}
