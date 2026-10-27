#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E1280;
extern void* D_005839B8;
extern void* D_005839C0;
void StaticInit_GuiSaveAgentWidget(void) {
    D_005839C0 = &D_004E1280;
    D_005839B8 = "GuiSaveAgentWidget";
    AbstractWidgetClassRep_AddClassRep(&D_005839B8);
}
