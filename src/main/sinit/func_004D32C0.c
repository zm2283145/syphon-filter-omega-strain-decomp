#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DDCC0;
extern void* D_005065D8;
extern void* D_005065E0;
void StaticInit_GuiNetAgencyCell(void) {
    D_005065E0 = &D_004DDCC0;
    D_005065D8 = "GuiChatWindow";
    AbstractWidgetClassRep_AddClassRep(&D_005065D8);
}
