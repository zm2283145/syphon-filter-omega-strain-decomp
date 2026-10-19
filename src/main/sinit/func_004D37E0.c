#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DE770;
extern void* D_0052AF38;
extern void* D_0052AF40;
void StaticInit_GuiSlideShowFactory(void) {
    D_0052AF40 = &D_004DE770;
    D_0052AF38 = "GuiSlideShow";
    FreeList_Push(&D_0052AF38);
}
