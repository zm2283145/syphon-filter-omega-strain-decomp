#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E15C0;
extern void* D_005860B0;
extern void* D_005860B8;
void StaticInit_GuiSubTitleDisplayFactory(void) {
    D_005860B8 = &D_004E15C0;
    D_005860B0 = "GuiSubTitleDisplay";
    AbstractWidgetClassRep_AddClassRep(&D_005860B0);
}
