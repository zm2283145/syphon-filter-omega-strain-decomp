#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DD380;
extern void* D_00506380;
extern void* D_00506388;
void StaticInit_GuiAgentCreateFactory(void) {
    D_00506388 = &D_004DD380;
    D_00506380 = "GuiAgentCreate";
    FreeList_Push(&D_00506380);
}
