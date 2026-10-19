#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DEBF8;
extern char D_004DEC08;
extern void* D_005331D8;
extern void* D_005331E0;
extern void* D_005331E8;
extern void* D_005331F0;
void StaticInit_GuiNetMessagesFactories(void) {
    D_005331E0 = &D_004DEC08;
    D_005331D8 = "GuiNetMessageArray";
    FreeList_Push(&D_005331D8);
    D_005331F0 = &D_004DEBF8;
    D_005331E8 = "GuiNetMessages";
    FreeList_Push(&D_005331E8);
}
