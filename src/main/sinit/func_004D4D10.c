#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DF120;
extern void* D_005335B0;
extern void* D_005335B8;
void StaticInit_GuiPersonnelScreenFactory(void) {
    D_005335B8 = &D_004DF120;
    D_005335B0 = "GuiPersonnelScreen";
    FreeList_Push(&D_005335B0);
}
