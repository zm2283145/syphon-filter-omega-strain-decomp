#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E0E38;
extern void* D_00572178;
extern void* D_00572180;
void StaticInit_guiTextArrayWidget(void) {
    D_00572180 = &D_004E0E38;
    D_00572178 = "GuiTextArrayWidget";
    AbstractWidgetClassRep_AddClassRep(&D_00572178);
}
