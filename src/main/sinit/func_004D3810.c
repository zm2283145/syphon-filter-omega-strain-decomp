#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DE7F0;
extern void* D_0052AF48;
extern void* D_0052AF50;
void StaticInit_GuiKeyboard(void) {
    D_0052AF50 = &D_004DE7F0;
    D_0052AF48 = "GuiKeyboard";
    AbstractWidgetClassRep_AddClassRep(&D_0052AF48);
}
