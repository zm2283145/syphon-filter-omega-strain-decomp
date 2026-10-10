/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct WidgetChild {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06();
    virtual void GainFocus(); /* +0x24 */
};

typedef struct GuiWidget { int unk0; WidgetChild* child; } GuiWidget;

extern char D_004BF0D0[];
extern "C" void func_00416D10(GuiWidget* self, const char* name);

/* Notifies the child widget (virtual +0x24), then posts the D_004BF0D0 event to self. */
extern "C" void GuiWidget_OnGainFocus(GuiWidget* self)
{
    self->child->GainFocus();
    func_00416D10(self, D_004BF0D0);
}
