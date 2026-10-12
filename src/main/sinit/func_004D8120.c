#include "types.h"
extern void FreeList_Push(void*);
extern char D_004E18A0;
extern void* D_00586260;
extern void* D_00586268;
void func_004D8120(void) {
    D_00586268 = &D_004E18A0;
    D_00586260 = "GuiEndGameStatistics";
    FreeList_Push(&D_00586260);
}
