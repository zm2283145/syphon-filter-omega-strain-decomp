#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DECA0;
extern void* D_005331F8;
extern void* D_00533200;
void StaticInit_GuiDossiers(void) {
    D_00533200 = &D_004DECA0;
    D_005331F8 = "GuiDossiers";
    AbstractWidgetClassRep_AddClassRep(&D_005331F8);
}
