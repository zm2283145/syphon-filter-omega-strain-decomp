#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E1280;
extern void* D_005839B8;
extern void* D_005839C0;
void StaticInit_GuiSaveAgentWidgetFactory(void) {
    D_005839C0 = &D_004E1280;
    D_005839B8 = "GuiSaveAgentWidget";
    FreeList_Push(&D_005839B8);
}
