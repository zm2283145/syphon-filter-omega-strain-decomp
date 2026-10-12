#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DDE40;
extern void* D_005065F8;
extern void* D_00506600;
void func_004D3320(void) {
    D_00506600 = &D_004DDE40;
    D_005065F8 = "GuiZeusShell";
    FreeList_Push(&D_005065F8);
}
