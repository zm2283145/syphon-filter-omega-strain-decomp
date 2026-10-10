/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct WidgetChild {
    virtual void v00(); virtual void v01();
    virtual void Method10(); /* +0x10 */
};

typedef struct GuiWidget {
    int unk0;
    WidgetChild* child; /* +0x04 */
    char pad08[0x20 - 8];
    int handle;  /* +0x20 */
    void* unk24; /* +0x24 */
} GuiWidget;

extern char D_00571DC0[];
extern "C" void func_003E8EB0(void* p);
extern "C" void func_00412CF0(void* mgr, int handle);

/* Notifies the child (virtual +0x10); if a handle (+0x20) is held, releases it (func_003E8EB0 on +0x24, func_00412CF0) and resets it to -1. */
extern "C" void func_00417870(GuiWidget* self)
{
    self->child->Method10();
    if (self->handle != -1) {
    if (self->unk24)
    func_003E8EB0(self->unk24);
    func_00412CF0(D_00571DC0, self->handle);
    self->handle = -1;
    }
}
