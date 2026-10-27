#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DD100;
extern const char* D_00506320;
extern void* D_00506328;
void StaticInit_GuiTitleScreen(void) {
    D_00506328 = &D_004DD100;
    D_00506320 = "GuiTitleScreen";
    AbstractWidgetClassRep_AddClassRep(&D_00506320);
}