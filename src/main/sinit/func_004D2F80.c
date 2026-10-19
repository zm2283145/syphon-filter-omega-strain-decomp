#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DD560;
extern void* D_005063B8;
extern void* D_005063C0;
void StaticInit_GuiCommandCenterFactory(void) {
    D_005063C0 = &D_004DD560;
    D_005063B8 = "GuiCommandCenter";
    FreeList_Push(&D_005063B8);
}
