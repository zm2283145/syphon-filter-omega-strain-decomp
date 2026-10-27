#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DD7A0;
extern void* D_00506498;
extern void* D_005064A0;
void StaticInit_GuiMissionSetup(void) {
    D_005064A0 = &D_004DD7A0;
    D_00506498 = "GuiMissionSetup";
    AbstractWidgetClassRep_AddClassRep(&D_00506498);
}
