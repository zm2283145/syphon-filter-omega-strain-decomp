#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DED30;
extern void* D_00533208;
extern void* D_00533210;
void StaticInit_GuiRatings(void) {
    D_00533210 = &D_004DED30;
    D_00533208 = "GuiRatings";
    AbstractWidgetClassRep_AddClassRep(&D_00533208);
}
