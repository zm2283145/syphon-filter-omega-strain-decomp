#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E0B20;
extern void* D_00572108;
extern void* D_00572110;
void StaticInit_guiTextWidget(void) {
    D_00572110 = &D_004E0B20;
    D_00572108 = "GuiTextWidget";
    AbstractWidgetClassRep_AddClassRep(&D_00572108);
}
