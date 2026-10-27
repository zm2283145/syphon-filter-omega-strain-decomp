#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DD710;
extern void* D_00506478;
extern void* D_00506480;
void StaticInit_GuiOnlineOfflineSelect(void) {
    D_00506480 = &D_004DD710;
    D_00506478 = "GuiOnlineOfflineSelect";
    AbstractWidgetClassRep_AddClassRep(&D_00506478);
}
