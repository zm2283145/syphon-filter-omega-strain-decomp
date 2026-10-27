#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DDB60;
extern void* D_005065A0;
extern void* D_005065A8;
void StaticInit_GuiMissionList(void) {
    D_005065A8 = &D_004DDB60;
    D_005065A0 = "GuiOnlineOptions";
    AbstractWidgetClassRep_AddClassRep(&D_005065A0);
}
