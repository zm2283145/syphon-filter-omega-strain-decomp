#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DDCA0;
extern void* D_005065C8;
extern void* D_005065D0;
void StaticInit_GuiChatWindow(void) {
    D_005065D0 = &D_004DDCA0;
    D_005065C8 = "GuiNetContacts";
    AbstractWidgetClassRep_AddClassRep(&D_005065C8);
}
