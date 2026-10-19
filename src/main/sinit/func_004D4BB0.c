#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DED30;
extern void* D_00533208;
extern void* D_00533210;
void StaticInit_GuiRatingsFactory(void) {
    D_00533210 = &D_004DED30;
    D_00533208 = "GuiRatings";
    FreeList_Push(&D_00533208);
}
