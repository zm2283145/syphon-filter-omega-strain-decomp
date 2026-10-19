#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DE7F0;
extern void* D_0052AF48;
extern void* D_0052AF50;
void StaticInit_GuiKeyboardFactory(void) {
    D_0052AF50 = &D_004DE7F0;
    D_0052AF48 = "GuiKeyboard";
    FreeList_Push(&D_0052AF48);
}
