#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E0FA0;
extern void* D_00583928;
extern void* D_00583930;
void StaticInit_guiScrollBarWidget(void) {
    D_00583930 = &D_004E0FA0;
    D_00583928 = "GuiScrollBarWidget";
    AbstractWidgetClassRep_AddClassRep(&D_00583928);
}
