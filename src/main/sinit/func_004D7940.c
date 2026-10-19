#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E1120;
extern void* D_00583958;
extern void* D_00583960;
void StaticInit_GuiSliderWidgetFactory(void) {
    D_00583960 = &D_004E1120;
    D_00583958 = "GuiSliderWidget";
    FreeList_Push(&D_00583958);
}
