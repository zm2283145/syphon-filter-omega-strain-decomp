#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DF590;
extern char D_004DF5A0;
extern void* D_00533830;
extern void* D_00533838;
extern void* D_00533840;
extern void* D_00533848;
void StaticInit_GuiAgentInfoFactories(void) {
    D_00533838 = &D_004DF5A0;
    D_00533830 = "GuiAgentDisplay";
    FreeList_Push(&D_00533830);
    D_00533848 = &D_004DF590;
    D_00533840 = "GuiAgentInfo";
    FreeList_Push(&D_00533840);
}
