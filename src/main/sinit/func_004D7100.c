#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E0940;
extern void* D_00571FC8;
extern void* D_00571FD0;
void StaticInit_guiCanvas(void) {
    D_00571FD0 = &D_004E0940;
    D_00571FC8 = "GuiCanvas";
    AbstractWidgetClassRep_AddClassRep(&D_00571FC8);
}
