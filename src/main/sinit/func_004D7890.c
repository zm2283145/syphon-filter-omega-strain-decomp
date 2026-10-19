#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E0FA0;
extern void* D_00583928;
extern void* D_00583930;
void StaticInit_GuiScrollBarWidgetFactory(void) {
    D_00583930 = &D_004E0FA0;
    D_00583928 = "GuiScrollBarWidget";
    FreeList_Push(&D_00583928);
}
