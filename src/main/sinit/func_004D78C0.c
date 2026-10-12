#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E1020;
extern void* D_00583938;
extern void* D_00583940;
void func_004D78C0(void) {
    D_00583940 = &D_004E1020;
    D_00583938 = "GuiBitmapWidget";
    FreeList_Push(&D_00583938);
}
