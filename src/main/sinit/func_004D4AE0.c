#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DEAF0;
extern void* D_005331C0;
extern void* D_005331C8;
void StaticInit_GuiAgentModifyFactory(void) {
    D_005331C8 = &D_004DEAF0;
    D_005331C0 = "GuiAgentModify";
    FreeList_Push(&D_005331C0);
}
