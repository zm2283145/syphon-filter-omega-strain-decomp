#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DD100;
extern const char* D_00506320;
extern void* D_00506328;
void StaticInit_GuiTitleScreenFactory(void) {
    D_00506328 = &D_004DD100;
    D_00506320 = "GuiTitleScreen";
    FreeList_Push(&D_00506320);
}