#include "types.h"
extern void FreeList_Push(void*);
extern char D_004DDA30;
extern void* D_00506580;
extern void* D_00506588;
void func_004D31D0(void) {
    D_00506588 = &D_004DDA30;
    D_00506580 = "GuiMessageBox";
    FreeList_Push(&D_00506580);
}
