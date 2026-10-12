#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DEDC0;
extern void* D_00533218;
extern void* D_00533220;
void func_004D4BE0(void) {
    D_00533220 = &D_004DEDC0;
    D_00533218 = "GuiRanks";
    FreeList_Push(&D_00533218);
}
