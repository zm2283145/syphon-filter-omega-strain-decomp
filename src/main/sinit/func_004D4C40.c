#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DEF58;
extern char D_004DEF68;
extern void* D_00533238;
extern void* D_00533240;
extern void* D_00533248;
extern void* D_00533250;
void StaticInit_GuiMissionStatisticsFactories(void) {
    D_00533240 = &D_004DEF68;
    D_00533238 = "GuiMissionStatList";
    FreeList_Push(&D_00533238);
    D_00533250 = &D_004DEF58;
    D_00533248 = "GuiMissionStatistics";
    FreeList_Push(&D_00533248);
}
