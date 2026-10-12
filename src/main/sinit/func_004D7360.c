#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E0E38;
extern void* D_00572178;
extern void* D_00572180;
void func_004D7360(void) {
    D_00572180 = &D_004E0E38;
    D_00572178 = "GuiTextArrayWidget";
    FreeList_Push(&D_00572178);
}
