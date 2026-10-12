#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E0C60;
extern void* D_00572148;
extern void* D_00572150;
void func_004D7260(void) {
    D_00572150 = &D_004E0C60;
    D_00572148 = "GuiButtonWidget";
    FreeList_Push(&D_00572148);
}
