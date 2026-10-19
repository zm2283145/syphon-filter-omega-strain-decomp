#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DECA0;
extern void* D_005331F8;
extern void* D_00533200;
void StaticInit_GuiDossiersFactory(void) {
    D_00533200 = &D_004DECA0;
    D_005331F8 = "GuiDossiers";
    FreeList_Push(&D_005331F8);
}
