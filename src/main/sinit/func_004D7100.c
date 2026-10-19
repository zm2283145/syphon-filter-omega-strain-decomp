#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E0940;
extern void* D_00571FC8;
extern void* D_00571FD0;
void StaticInit_GuiCanvasFactory(void) {
    D_00571FD0 = &D_004E0940;
    D_00571FC8 = "GuiCanvas";
    FreeList_Push(&D_00571FC8);
}
