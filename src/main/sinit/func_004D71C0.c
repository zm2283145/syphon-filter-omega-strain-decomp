#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E0B20;
extern void* D_00572108;
extern void* D_00572110;
void func_004D71C0(void) {
    D_00572110 = &D_004E0B20;
    D_00572108 = "GuiTextWidget";
    FreeList_Push(&D_00572108);
}
