/*
 * SFOGame/Source/GuiMissionStatistics: 2 files, 003503D0-00350460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003503D0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef struct Source { int unk0; int count; } Source;

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void SetCount(int n, int total); /* +0x5C */
    char pad04[0xC0 - 4];
    Source* source;   /* +0xC0 */
    int entries[11];  /* +0xC4 */
};

extern "C" void GuiArrayWidget_SetSelected(Widget* self, int a, int b);
extern "C" void GuiArrayWidget_SetColumnWidth(Widget* self, int index, int value);

/* Binds a data source (+0xC0), sets the list to 11 entries via virtual +0x5C, resets it and fills entries from the +0xC4 table (walked with a stepping base pointer). */
extern "C" void GuiMissionStatList_SetMissionStats(Widget* self, Source* source)
{
    Widget* p;
    int i;
    self->source = source;
    self->SetCount(11, source ? source->count : 0);
    GuiArrayWidget_SetSelected(self, 0, 0);
    for (i = 0, p = self; i < 11; i++, p = (Widget*)((char*)p + 4))
        GuiArrayWidget_SetColumnWidth(self, i, p->entries[0]);
}
static inline void merge_flush_func_003503D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003503D0 */

/* merge_units: begin GuiMissionStatList_350460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatList constructor (vtable ((char*)D_004DEEE0)).
 */

#include "loose03_types.h"

/* GuiMissionStatList vtable */
extern void GuiMissionStatList_GetClassName();
extern void GuiMissionStatList_onElementRender();
extern void GuiMissionStatList_dtor();
extern void GuiMissionStatList_IsClass();
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_FindFirstFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onAdvanceTime();
extern void GuiWidget_onMessage();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_onRemove();
extern void GuiWidget_Load();
extern void GuiArrayWidget_onElementLoseFocus();
extern void GuiArrayWidget_onElementGainFocus();
extern void GuiArrayWidget_onRowRender();
extern void GuiArrayWidget_onColumnRender();
extern void GuiArrayWidget_onRender();
extern void GuiArrayWidget_onInput();
extern void GuiArrayWidget_onLoseFocus();
extern void GuiArrayWidget_onGainFocus();
extern void GuiTextArrayWidget_onSleep();
extern void GuiTextArrayWidget_onWake();
extern void GuiTextArrayWidget_onAdd();
extern void GuiTextArrayWidget_SetSize();
void * const D_004DEEE0[30] = { (void*)0x0, (void*)0x0, (void*)GuiMissionStatList_dtor, (void*)GuiTextArrayWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiTextArrayWidget_onWake, (void*)GuiTextArrayWidget_onSleep, (void*)GuiArrayWidget_onGainFocus, (void*)GuiArrayWidget_onLoseFocus, (void*)GuiArrayWidget_onInput, (void*)GuiArrayWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiMissionStatList_GetClassName, (void*)GuiMissionStatList_IsClass, (void*)GuiTextArrayWidget_SetSize, (void*)GuiArrayWidget_onColumnRender, (void*)GuiArrayWidget_onRowRender, (void*)GuiMissionStatList_onElementRender, (void*)GuiArrayWidget_onElementGainFocus, (void*)GuiArrayWidget_onElementLoseFocus, (void*)0x0 };
extern int GuiTextArrayWidget_ctor(GuiMissionStatList*);

/* GuiMissionStatList constructor: default layout values. */
GuiMissionStatList* GuiMissionStatList_ctor(GuiMissionStatList* self) {
    int flags;

    GuiTextArrayWidget_ctor(self);
    self->base.vtable = ((char*)D_004DEEE0);
    self->unkC4 = 110;
    self->unkC8 = 45;
    self->unkCC = 45;
    self->unkD0 = 15;
    self->unkD4 = 50;
    self->unkD8 = 50;
    self->unkDC = 20;
    self->unkE0 = 80;
    self->unkE4 = 30;
    self->unkE8 = 80;
    self->unkEC = 0;
    self->unkC0 = 0;
    self->unk58 = 2;
    /* base.flags |= 0x80; raw offsets kept: field access emits lh instead of lhu */
    flags = *(unsigned short*)((char*)self + 0x14);
    flags = flags | 0x80;
    *(short*)((char*)self + 0x14) = flags;
    return self;
}
static inline void merge_flush_GuiMissionStatList_350460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiMissionStatList_350460 */
