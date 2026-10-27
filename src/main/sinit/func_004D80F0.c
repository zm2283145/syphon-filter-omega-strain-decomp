#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E1820;
extern void* D_00586250;
extern void* D_00586258;
void StaticInit_GuiEndGameObjectivesFactory(void) {
    D_00586258 = &D_004E1820;
    D_00586250 = "GuiEndGameObjectives";
    AbstractWidgetClassRep_AddClassRep(&D_00586250);
}
