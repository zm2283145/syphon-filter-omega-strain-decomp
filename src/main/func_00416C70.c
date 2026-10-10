/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct WidgetChild {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void Activate(); /* +0x14 */
};

typedef struct GuiWidget { int unk0; WidgetChild* child; } GuiWidget;

extern char D_004BF0F0[];
extern "C" void func_00416D10(GuiWidget* self, const char* name);

/* Notifies the child widget (virtual +0x14), then posts the D_004BF0F0 event to self. */
extern "C" void GuiWidget_OnActivate(GuiWidget* self)
{
    self->child->Activate();
    func_00416D10(self, D_004BF0F0);
}
