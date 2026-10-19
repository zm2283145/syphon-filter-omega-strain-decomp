#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E1920;
extern void* D_00586270;
extern void* D_00586278;
void StaticInit_GuiMapScreenFactory(void) {
    D_00586278 = &D_004E1920;
    D_00586270 = "GuiMapScreen";
    FreeList_Push(&D_00586270);
}
