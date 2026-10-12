#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DED30;
extern void* D_00533208;
extern void* D_00533210;
void func_004D4BB0(void) {
    D_00533210 = &D_004DED30;
    D_00533208 = "GuiRatings";
    FreeList_Push(&D_00533208);
}
