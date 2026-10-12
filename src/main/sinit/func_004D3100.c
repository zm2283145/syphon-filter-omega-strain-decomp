#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DD7A0;
extern void* D_00506498;
extern void* D_005064A0;
void func_004D3100(void) {
    D_005064A0 = &D_004DD7A0;
    D_00506498 = "GuiMissionSetup";
    FreeList_Push(&D_00506498);
}
