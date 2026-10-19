#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DDCC0;
extern void* D_005065D8;
extern void* D_005065E0;
void StaticInit_GuiChatWindowFactory(void) {
    D_005065E0 = &D_004DDCC0;
    D_005065D8 = "GuiChatWindow";
    FreeList_Push(&D_005065D8);
}
