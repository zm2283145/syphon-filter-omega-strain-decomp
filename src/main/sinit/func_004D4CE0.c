#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DF090;
extern void* D_005335A0;
extern void* D_005335A8;
void StaticInit_GuiPersonnelMenuFactory(void) {
    D_005335A8 = &D_004DF090;
    D_005335A0 = "GuiPersonnelMenu";
    FreeList_Push(&D_005335A0);
}
