#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004E18A0;
extern void* D_00586260;
extern void* D_00586268;
void StaticInit_GuiEndGameStatisticsFactory(void) {
    D_00586268 = &D_004E18A0;
    D_00586260 = "GuiEndGameStatistics";
    AbstractWidgetClassRep_AddClassRep(&D_00586260);
}
