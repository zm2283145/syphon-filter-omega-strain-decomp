#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DD4C0;
extern char D_004DD4D0;
extern void* D_00506398;
extern void* D_005063A0;
extern void* D_005063A8;
extern void* D_005063B0;
void StaticInit_GuiAgentLoad(void) {
    D_005063A0 = &D_004DD4D0;
    D_00506398 = "GuiAgentLoad";
    AbstractWidgetClassRep_AddClassRep(&D_00506398);
    D_005063B0 = &D_004DD4C0;
    D_005063A8 = "GuiAgentSave";
    AbstractWidgetClassRep_AddClassRep(&D_005063A8);
}
