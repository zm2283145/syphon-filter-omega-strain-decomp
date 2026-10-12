#include "types.h"
extern void FreeList_Push(void*);
extern int D_004C0100;
extern int D_004C0104;
extern int D_004C0108;
extern int D_004C010C;
extern char D_004E10A0;
extern void* D_00583948;
extern void* D_00583950;
void func_004D78F0(void) {
    D_004C0100 = 1065353216;
    D_00583950 = &D_004E10A0;
    D_00583948 = "GuiMLTextWidget";
    D_004C0104 = 1065353216;
    D_004C0108 = 1065353216;
    D_004C010C = 1065353216;
    FreeList_Push(&D_00583948);
}
