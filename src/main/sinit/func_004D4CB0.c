#include "types.h"
extern char D_004BAF80[];
extern void ConcreteWidgetClassRep_GuiAchievementScreen_Create();
static void* D_004DF000[] = { 0, 0, (void*)ConcreteWidgetClassRep_GuiAchievementScreen_Create };
extern char D_00533548[];
extern char D_00533550[];
extern void AbstractWidgetClassRep_AddClassRep();
void StaticInit_GuiAchievementScreen(void)
{
    *(int*)D_00533550 = (int)D_004DF000;
    *(int*)D_00533548 = (int)D_004BAF80;
    AbstractWidgetClassRep_AddClassRep((int)D_00533548);
}
