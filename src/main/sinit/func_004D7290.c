#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E0CF8;
extern void* D_00572158;
extern void* D_00572160;
void StaticInit_guiTextListWidget(void) {
    D_00572160 = &D_004E0CF8;
    D_00572158 = "GuiTextListWidget";
    AbstractWidgetClassRep_AddClassRep(&D_00572158);
}
