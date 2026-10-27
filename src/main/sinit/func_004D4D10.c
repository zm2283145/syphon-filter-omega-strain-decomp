#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DF120;
extern void* D_005335B0;
extern void* D_005335B8;
void StaticInit_GuiPersonnelScreen(void) {
    D_005335B8 = &D_004DF120;
    D_005335B0 = "GuiPersonnelScreen";
    AbstractWidgetClassRep_AddClassRep(&D_005335B0);
}
