#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DE770;
extern void* D_0052AF38;
extern void* D_0052AF40;
void StaticInit_GuiSlideShow(void) {
    D_0052AF40 = &D_004DE770;
    D_0052AF38 = "GuiSlideShow";
    AbstractWidgetClassRep_AddClassRep(&D_0052AF38);
}
