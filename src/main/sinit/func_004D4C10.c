#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004DEE50;
extern void* D_00533228;
extern void* D_00533230;
void StaticInit_GuiOmegaStrain(void) {
    D_00533230 = &D_004DEE50;
    D_00533228 = "GuiOmegaStrain";
    AbstractWidgetClassRep_AddClassRep(&D_00533228);
}
