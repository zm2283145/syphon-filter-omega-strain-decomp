#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DEE50;
extern void* D_00533228;
extern void* D_00533230;
void StaticInit_GuiOmegaStrainFactory(void) {
    D_00533230 = &D_004DEE50;
    D_00533228 = "GuiOmegaStrain";
    FreeList_Push(&D_00533228);
}
