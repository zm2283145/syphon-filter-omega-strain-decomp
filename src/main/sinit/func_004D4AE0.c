#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DEAF0;
extern void* D_005331C0;
extern void* D_005331C8;
void StaticInit_GuiAgentModify(void) {
    D_005331C8 = &D_004DEAF0;
    D_005331C0 = "GuiAgentModify";
    AbstractWidgetClassRep_AddClassRep(&D_005331C0);
}
