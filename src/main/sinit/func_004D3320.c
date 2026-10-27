#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DDE40;
extern void* D_005065F8;
extern void* D_00506600;
void StaticInit_GuiZeusShell(void) {
    D_00506600 = &D_004DDE40;
    D_005065F8 = "GuiZeusShell";
    AbstractWidgetClassRep_AddClassRep(&D_005065F8);
}
