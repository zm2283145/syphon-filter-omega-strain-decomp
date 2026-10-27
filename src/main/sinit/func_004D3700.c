#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DE6D0;
extern void* D_0052AF00;
extern void* D_0052AF08;
void StaticInit_GuiCharacterDisplay(void) {
    D_0052AF08 = &D_004DE6D0;
    D_0052AF00 = "GuiCharacterDisplay";
    AbstractWidgetClassRep_AddClassRep(&D_0052AF00);
}
