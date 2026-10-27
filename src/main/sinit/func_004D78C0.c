#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E1020;
extern void* D_00583938;
extern void* D_00583940;
void StaticInit_guiBitmapWidget(void) {
    D_00583940 = &D_004E1020;
    D_00583938 = "GuiBitmapWidget";
    AbstractWidgetClassRep_AddClassRep(&D_00583938);
}
