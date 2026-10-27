#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E1120;
extern void* D_00583958;
extern void* D_00583960;
void StaticInit_guiSliderWidget(void) {
    D_00583960 = &D_004E1120;
    D_00583958 = "GuiSliderWidget";
    AbstractWidgetClassRep_AddClassRep(&D_00583958);
}
