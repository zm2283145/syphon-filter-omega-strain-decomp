#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DF620;
extern void* D_00533850;
extern void* D_00533858;
void StaticInit_GuiObjectivesFactory(void) {
    D_00533858 = &D_004DF620;
    D_00533850 = "GuiObjectives";
    AbstractWidgetClassRep_AddClassRep(&D_00533850);
}
