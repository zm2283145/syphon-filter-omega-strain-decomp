#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DDDC0;
extern void* D_005065E8;
extern void* D_005065F0;
void StaticInit_GuiOnlineOptions(void) {
    D_005065F0 = &D_004DDDC0;
    D_005065E8 = "GuiNetAgencyCell";
    AbstractWidgetClassRep_AddClassRep(&D_005065E8);
}
