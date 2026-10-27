#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DD690;
extern void* D_00506468;
extern void* D_00506470;
void StaticInit_GuiOnlineConnect(void) {
    D_00506470 = &D_004DD690;
    D_00506468 = "GuiOnlineConnect";
    AbstractWidgetClassRep_AddClassRep(&D_00506468);
}
