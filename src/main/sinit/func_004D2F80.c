#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DD560;
extern void* D_005063B8;
extern void* D_005063C0;
void func_004D2F80(void) {
    D_005063C0 = &D_004DD560;
    D_005063B8 = "GuiCommandCenter";
    FreeList_Push(&D_005063B8);
}
