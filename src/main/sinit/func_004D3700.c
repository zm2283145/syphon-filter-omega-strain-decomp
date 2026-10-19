#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DE6D0;
extern void* D_0052AF00;
extern void* D_0052AF08;
void StaticInit_GuiCharacterDisplayFactory(void) {
    D_0052AF08 = &D_004DE6D0;
    D_0052AF00 = "GuiCharacterDisplay";
    FreeList_Push(&D_0052AF00);
}
