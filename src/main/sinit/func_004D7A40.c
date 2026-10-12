#include "types.h"
extern void FreeList_Push(void*);
extern int D_004C0390;
extern int D_004C0394;
extern int D_004C0398;
extern int D_004C039C;
extern char D_004E1200;
extern void* D_005839A8;
extern void* D_005839B0;
void func_004D7A40(void) {
    D_004C0390 = 0;
    D_004C0398 = 0;
    D_004C0394 = 1065353216;
    D_005839B0 = &D_004E1200;
    D_005839A8 = "GuiWeaponDisplay";
    D_004C039C = 0;
    FreeList_Push(&D_005839A8);
}
