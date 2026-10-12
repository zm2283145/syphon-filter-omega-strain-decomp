#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DDCA0;
extern void* D_005065C8;
extern void* D_005065D0;
void func_004D3290(void) {
    D_005065D0 = &D_004DDCA0;
    D_005065C8 = "GuiNetContacts";
    FreeList_Push(&D_005065C8);
}
