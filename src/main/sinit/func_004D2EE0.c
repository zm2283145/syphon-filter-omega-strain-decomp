#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DD380;
extern void* D_00506380;
extern void* D_00506388;
void StaticInit_GuiAgentCreate(void) {
    D_00506388 = &D_004DD380;
    D_00506380 = "GuiAgentCreate";
    AbstractWidgetClassRep_AddClassRep(&D_00506380);
}
