#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DDDC0;
extern void* D_005065E8;
extern void* D_005065F0;
void StaticInit_GuiNetAgencyCellFactory(void) {
    D_005065F0 = &D_004DDDC0;
    D_005065E8 = "GuiNetAgencyCell";
    FreeList_Push(&D_005065E8);
}
