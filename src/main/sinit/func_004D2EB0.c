#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DD190;
extern void* D_00506368;
extern void* D_00506370;
void StaticInit_GuiAccountLoginFactory(void) {
    D_00506370 = &D_004DD190;
    D_00506368 = "GuiAccountLogin";
    FreeList_Push(&D_00506368);
}
