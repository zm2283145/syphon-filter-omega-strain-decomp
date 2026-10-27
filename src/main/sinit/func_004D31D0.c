#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DDA30;
extern void* D_00506580;
extern void* D_00506588;
void StaticInit_GuiMessageBox(void) {
    D_00506588 = &D_004DDA30;
    D_00506580 = "GuiMessageBox";
    AbstractWidgetClassRep_AddClassRep(&D_00506580);
}
