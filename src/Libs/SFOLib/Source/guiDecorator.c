/*
 * Libs/SFOLib/Source/guiDecorator: 2 files, 00416830-00416A00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00416830 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00416830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416830 */

/* merge_units: begin func_00416A00 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int operator_delete(char * );                          
extern void GuiDecorator_Load();
extern void GuiDecorator_onAdd();
extern void GuiAbstractInterface_dtor();
extern void GuiDecorator_onRemove();
extern void GuiDecorator_onWake();
extern void GuiDecorator_onSleep();
extern void GuiDecorator_onActivate();
extern void GuiDecorator_onDeactivate();
extern void GuiDecorator_onGainFocus();
extern void GuiDecorator_onLoseFocus();
extern void GuiDecorator_onInput();
extern void GuiDecorator_onRender();
extern void GuiDecorator_onAction();
extern void GuiDecorator_onMessage();
extern void GuiDecorator_onAdvanceTime();
extern void * const D_004E0960[];
extern void * const D_004E09B0[];
extern int D_00572130;

char * GuiDecorator_dtor(char * arg0, long long arg1) {
    char * temp_v0;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E0960));
        temp_v0 = (char *)(F_(arg0, 0x4, int));
        if (temp_v0 != NULL) {
            F_(temp_v0, 0x44, int) = (int)(temp_v0);
        }
        if (arg0 != NULL) {
            F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E09B0));
            D_00572130 -= 1;
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E0960[20] = { (void*)0x0, (void*)0x0, (void*)GuiDecorator_dtor, (void*)GuiDecorator_onAdd, (void*)GuiDecorator_onRemove, (void*)GuiDecorator_onActivate, (void*)GuiDecorator_onDeactivate, (void*)GuiDecorator_onWake, (void*)GuiDecorator_onSleep, (void*)GuiDecorator_onGainFocus, (void*)GuiDecorator_onLoseFocus, (void*)GuiDecorator_onInput, (void*)GuiDecorator_onRender, (void*)GuiDecorator_onAction, (void*)GuiDecorator_onAdvanceTime, (void*)GuiDecorator_onMessage, (void*)GuiDecorator_Load, (void*)0x0, (void*)0x0, (void*)0x0 };
void * const D_004E09B0[16] = { (void*)0x0, (void*)0x0, (void*)GuiAbstractInterface_dtor, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_00416A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416A00 */
