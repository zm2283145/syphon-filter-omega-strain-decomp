/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of WidgetChild: only the slots used here are named (vtable offset in comments). */
struct WidgetChild {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void Sleep(); /* +0x20 */
};

typedef struct GuiWidget { int unk0; WidgetChild* child; } GuiWidget;

extern char D_004BF0C8[];
extern "C" void func_00416D10(GuiWidget* self, const char* name);

/* Forwards Sleep to the child widget (virtual +0x20), then posts the D_004BF0C8 event to self. */
extern "C" void GuiWidget_OnSleep(GuiWidget* self)
{
    self->child->Sleep();
    func_00416D10(self, D_004BF0C8);
}
