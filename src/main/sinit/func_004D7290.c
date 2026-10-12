#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E0CF8;
extern void* D_00572158;
extern void* D_00572160;
void func_004D7290(void) {
    D_00572160 = &D_004E0CF8;
    D_00572158 = "GuiTextListWidget";
    FreeList_Push(&D_00572158);
}
