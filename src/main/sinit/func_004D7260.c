#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E0C60;
extern void* D_00572148;
extern void* D_00572150;
void StaticInit_guiButtonWidget(void) {
    D_00572150 = &D_004E0C60;
    D_00572148 = "GuiButtonWidget";
    AbstractWidgetClassRep_AddClassRep(&D_00572148);
}
