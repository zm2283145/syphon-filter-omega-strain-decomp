#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DDBF8;
extern void* D_005065B0;
extern void* D_005065B8;
void StaticInit_GuiNetContacts(void) {
    D_005065B8 = &D_004DDBF8;
    D_005065B0 = "GuiMissionList";
    AbstractWidgetClassRep_AddClassRep(&D_005065B0);
}
