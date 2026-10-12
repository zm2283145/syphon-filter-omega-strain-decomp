#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DF620;
extern void* D_00533850;
extern void* D_00533858;
void func_004D4E50(void) {
    D_00533858 = &D_004DF620;
    D_00533850 = "GuiObjectives";
    FreeList_Push(&D_00533850);
}
