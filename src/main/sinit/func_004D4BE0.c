#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DEDC0;
extern void* D_00533218;
extern void* D_00533220;
void StaticInit_GuiRanks(void) {
    D_00533220 = &D_004DEDC0;
    D_00533218 = "GuiRanks";
    AbstractWidgetClassRep_AddClassRep(&D_00533218);
}
