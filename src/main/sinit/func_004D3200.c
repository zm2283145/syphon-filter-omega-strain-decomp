#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DDAD0;
extern void* D_00506590;
extern void* D_00506598;
void StaticInit_GuiNetJoinMission(void) {
    D_00506598 = &D_004DDAD0;
    D_00506590 = "GuiNetJoinMission";
    AbstractWidgetClassRep_AddClassRep(&D_00506590);
}
