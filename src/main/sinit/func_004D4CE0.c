#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DF090;
extern void* D_005335A0;
extern void* D_005335A8;
void StaticInit_GuiPersonnelMenu(void) {
    D_005335A8 = &D_004DF090;
    D_005335A0 = "GuiPersonnelMenu";
    AbstractWidgetClassRep_AddClassRep(&D_005335A0);
}
