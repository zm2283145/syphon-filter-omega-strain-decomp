#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DD190;
extern void* D_00506368;
extern void* D_00506370;
void StaticInit_GuiAccountLogin(void) {
    D_00506370 = &D_004DD190;
    D_00506368 = "GuiAccountLogin";
    AbstractWidgetClassRep_AddClassRep(&D_00506368);
}
