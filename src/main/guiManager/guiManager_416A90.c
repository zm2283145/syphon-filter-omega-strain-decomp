/*
 * main/guiManager: 8 files, 00416A90-00416CC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00416A90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004E0960[];         /* derived vtable */
extern char D_004E09B0[];         /* GUI root vtable */
extern int D_00572130;            /* GUI object instance counter */

/* Constructor of a direct GuiObject subclass. */
GuiObject* func_00416A90(GuiObject* self) {
    self->vtable = D_004E09B0;
    D_00572130 = D_00572130 + 1;
    self->vtable = D_004E0960;
    self->unk04 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00416A90 */

/* merge_units: begin func_00416AD0 */
#pragma push /* merge_units */
extern void operator_delete(void* allocation);

/* Restore the base vtable, release the instance count, and optionally delete. */
GuiObject* func_00416AD0(GuiObject* self, short deleteFlag) {
    if (self != 0) {
        self->vtable = D_004E09B0;
        D_00572130--;
        if (deleteFlag > 0) {
            operator_delete(self);
        }
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00416AD0 */

/* merge_units: begin func_00416B30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of WidgetChild: only the slots used here are named (vtable offset in comments). */
struct WidgetChild {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void Wake(); /* +0x1C */
};

typedef struct GuiWidget_00416B30 { int unk0; WidgetChild* child; } GuiWidget_00416B30;

extern "C" void GuiInterfaceDecorator_FireEvent(GuiWidget_00416B30* self, const char* name);

/* Wakes the child widget (virtual at +0x1C), then posts the "onWake" event to self. */
extern "C" void GuiWidget_OnWake(GuiWidget_00416B30* self)
{
    self->child->Wake();
    GuiInterfaceDecorator_FireEvent(self, "onWake");
}
#pragma pop /* merge_units */
/* merge_units: end func_00416B30 */

/* merge_units: begin func_00416B80 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of WidgetChild: only the slots used here are named (vtable offset in comments). */
struct WidgetChild_00416B80 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void Sleep(); /* +0x20 */
};

typedef struct GuiWidget_00416B80 { int unk0; WidgetChild_00416B80* child; } GuiWidget_00416B80;

#if 0 /* merge_units */
extern "C" void GuiInterfaceDecorator_FireEvent(GuiWidget_00416B80* self, const char* name);
#endif /* merge_units */
#define GuiInterfaceDecorator_FireEvent(a0, a1) (GuiInterfaceDecorator_FireEvent((GuiWidget_00416B30 *)(a0), (a1))) /* merge_units */


/* Forwards Sleep to the child widget (virtual +0x20), then posts the "onSleep" event to self. */
extern "C" void GuiWidget_OnSleep(GuiWidget_00416B80* self)
{
    self->child->Sleep();
    GuiInterfaceDecorator_FireEvent(self, "onSleep");
}
#undef GuiInterfaceDecorator_FireEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416B80 */

/* merge_units: begin func_00416BD0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct WidgetChild_00416BD0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06();
    virtual void GainFocus(); /* +0x24 */
};

typedef struct GuiWidget_00416BD0 { int unk0; WidgetChild_00416BD0* child; } GuiWidget_00416BD0;

#if 0 /* merge_units */
extern "C" void GuiInterfaceDecorator_FireEvent(GuiWidget_00416BD0* self, const char* name);
#endif /* merge_units */
#define GuiInterfaceDecorator_FireEvent(a0, a1) (GuiInterfaceDecorator_FireEvent((GuiWidget_00416B30 *)(a0), (a1))) /* merge_units */


/* Notifies the child widget (virtual +0x24), then posts the "onGainFocus" event to self. */
extern "C" void GuiWidget_OnGainFocus(GuiWidget_00416BD0* self)
{
    self->child->GainFocus();
    GuiInterfaceDecorator_FireEvent(self, "onGainFocus");
}
#undef GuiInterfaceDecorator_FireEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416BD0 */

/* merge_units: begin func_00416C20 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of WidgetChild: only the slots used here are named (vtable offset in comments). */
struct WidgetChild_00416C20 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07();
    virtual void LoseFocus(); /* +0x28 */
};

typedef struct GuiWidget_00416C20 { int unk0; WidgetChild_00416C20* child; } GuiWidget_00416C20;

#if 0 /* merge_units */
extern "C" void GuiInterfaceDecorator_FireEvent(GuiWidget_00416C20* self, const char* name);
#endif /* merge_units */
#define GuiInterfaceDecorator_FireEvent(a0, a1) (GuiInterfaceDecorator_FireEvent((GuiWidget_00416B30 *)(a0), (a1))) /* merge_units */


/* Forwards LoseFocus to the child widget (virtual +0x28), then posts the "onLoseFocus" event to self. */
extern "C" void GuiWidget_OnLoseFocus(GuiWidget_00416C20* self)
{
    self->child->LoseFocus();
    GuiInterfaceDecorator_FireEvent(self, "onLoseFocus");
}
#undef GuiInterfaceDecorator_FireEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416C20 */

/* merge_units: begin func_00416C70 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct WidgetChild_00416C70 {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void Activate(); /* +0x14 */
};

typedef struct GuiWidget_00416C70 { int unk0; WidgetChild_00416C70* child; } GuiWidget_00416C70;

#if 0 /* merge_units */
extern "C" void GuiInterfaceDecorator_FireEvent(GuiWidget_00416C70* self, const char* name);
#endif /* merge_units */
#define GuiInterfaceDecorator_FireEvent(a0, a1) (GuiInterfaceDecorator_FireEvent((GuiWidget_00416B30 *)(a0), (a1))) /* merge_units */


/* Notifies the child widget (virtual +0x14), then posts the "onActivate" event to self. */
extern "C" void GuiWidget_OnActivate(GuiWidget_00416C70* self)
{
    self->child->Activate();
    GuiInterfaceDecorator_FireEvent(self, "onActivate");
}
#undef GuiInterfaceDecorator_FireEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416C70 */

/* merge_units: begin func_00416CC0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of WidgetChild: only the slots used here are named (vtable offset in comments). */
struct WidgetChild_00416CC0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void Deactivate(); /* +0x18 */
};

typedef struct GuiWidget_00416CC0 { int unk0; WidgetChild_00416CC0* child; } GuiWidget_00416CC0;

#if 0 /* merge_units */
extern "C" void GuiInterfaceDecorator_FireEvent(GuiWidget_00416CC0* self, const char* name);
#endif /* merge_units */
#define GuiInterfaceDecorator_FireEvent(a0, a1) (GuiInterfaceDecorator_FireEvent((GuiWidget_00416B30 *)(a0), (a1))) /* merge_units */


/* Forwards Deactivate to the child widget (virtual +0x18), then posts the "onDeactivate" event to self. */
extern "C" void GuiWidget_OnDeactivate(GuiWidget_00416CC0* self)
{
    self->child->Deactivate();
    GuiInterfaceDecorator_FireEvent(self, "onDeactivate");
}
#undef GuiInterfaceDecorator_FireEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416CC0 */
