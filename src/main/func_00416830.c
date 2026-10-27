/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#pragma exceptions off
#include "types.h"

/* Vtable slot at +off is virtual index (off - 8) / 4. */
struct GuiVObj {
    virtual void V08(); virtual void V0C(); virtual void V10(); virtual void V14(); virtual void V18();
    virtual void V1C(); virtual void V20(); virtual void V24(); virtual void V28();
    virtual void V2C(); virtual void V30(); virtual void V34(); virtual void V38();
    virtual void V3C();
};

struct GuiVHolder { int f0; GuiVObj* obj; char pad[0x3C]; GuiVHolder* owner; };
/* Forwards to virtual +0x0C of the object at +4. */
extern "C" void GuiDecorator_onAdd(GuiVHolder* h)
{
    h->obj->V0C();
}

/* Forwards to virtual +0x10 of the object at +4. */
extern "C" void GuiDecorator_onRemove(GuiVHolder* h)
{
    h->obj->V10();
}

/* Forwards to virtual +0x1C of the object at +4. */
extern "C" void GuiDecorator_onWake(GuiVHolder* h)
{
    h->obj->V1C();
}

/* Forwards to virtual +0x20 of the object at +4. */
extern "C" void GuiDecorator_onSleep(GuiVHolder* h)
{
    h->obj->V20();
}

/* Forwards to virtual +0x14 of the object at +4. */
extern "C" void GuiDecorator_onActivate(GuiVHolder* h)
{
    h->obj->V14();
}

/* Forwards to virtual +0x18 of the object at +4. */
extern "C" void GuiDecorator_onDeactivate(GuiVHolder* h)
{
    h->obj->V18();
}

/* Forwards to virtual +0x24 of the object at +4. */
extern "C" void GuiDecorator_onGainFocus(GuiVHolder* h)
{
    h->obj->V24();
}

/* Forwards to virtual +0x28 of the object at +4. */
extern "C" void GuiDecorator_onLoseFocus(GuiVHolder* h)
{
    h->obj->V28();
}

/* Forwards to virtual +0x2C of the object at +4. */
extern "C" void GuiDecorator_onInput(GuiVHolder* h)
{
    h->obj->V2C();
}

/* Forwards to virtual +0x30 of the object at +4. */
extern "C" void GuiDecorator_onRender(GuiVHolder* h)
{
    h->obj->V30();
}

/* Forwards to virtual +0x34 of the object at +4. */
extern "C" void GuiDecorator_onAction(GuiVHolder* h)
{
    h->obj->V34();
}

/* Forwards to virtual +0x3C of the object at +4. */
extern "C" void GuiDecorator_onMessage(GuiVHolder* h)
{
    h->obj->V3C();
}

/* Forwards to virtual +0x38 of the object at +4. */
extern "C" void GuiDecorator_onAdvanceTime(GuiVHolder* h)
{
    h->obj->V38();
}

/* Replaces the object at +4, pointing the old and new objects' +0x44 back-links. */
extern "C" void GuiDecorator_Decorate(GuiVHolder* h, GuiVHolder* o)
{
    if (h->obj) ((GuiVHolder*)h->obj)->owner = (GuiVHolder*)h->obj;
    h->obj = (GuiVObj*)o;
    if (h->obj) ((GuiVHolder*)h->obj)->owner = h;
}

