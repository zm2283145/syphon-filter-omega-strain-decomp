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
