#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DD560;
extern void* D_005063B8;
extern void* D_005063C0;
void StaticInit_GuiCommandCenter(void) {
    D_005063C0 = &D_004DD560;
    D_005063B8 = "GuiCommandCenter";
    AbstractWidgetClassRep_AddClassRep(&D_005063B8);
}
