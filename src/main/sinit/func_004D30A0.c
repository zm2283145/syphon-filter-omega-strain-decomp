#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DD690;
extern void* D_00506468;
extern void* D_00506470;
void func_004D30A0(void) {
    D_00506470 = &D_004DD690;
    D_00506468 = "GuiOnlineConnect";
    FreeList_Push(&D_00506468);
}
