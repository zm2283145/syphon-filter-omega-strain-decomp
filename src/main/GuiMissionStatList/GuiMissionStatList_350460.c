/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatList constructor (vtable ((char*)D_004DEEE0)).
 */

#include "loose03_types.h"

/* GuiMissionStatList vtable */
extern void GuiMissionStatList_GetClassName();
extern void GuiMissionStatList_Draw();
extern void func_00350500();
extern void func_00350570();
extern void GuiWidget_FocusPrev();
extern void GuiWidget_FocusNext();
extern void GuiWidget_FocusLast();
extern void GuiWidget_FocusFirst();
extern void GuiWidget_BubbleActivate();
extern void GuiWidget_Update();
extern void GuiWidget_OnEvent();
extern void GuiWidget_ClearFlag4();
extern void GuiWidget_SetFlag4();
extern void GuiWidget_Deinit();
extern void func_0041F210();
extern void func_004235C0();
extern void func_004235E0();
extern void func_00423610();
extern void func_00423660();
extern void GuiArrayWidget_Draw();
extern void GuiArrayWidget_OnInput();
extern void GuiArrayWidget_OnLoseFocus();
extern void GuiArrayWidget_OnGainFocus();
extern void GuiTextArrayWidget_Sleep();
extern void GuiTextArrayWidget_Wake();
extern void GuiTextArrayWidget_Init();
extern void GuiTextArrayWidget_SetDims();
void * const D_004DEEE0[30] = { (void*)0x0, (void*)0x0, (void*)func_00350500, (void*)GuiTextArrayWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiTextArrayWidget_Wake, (void*)GuiTextArrayWidget_Sleep, (void*)GuiArrayWidget_OnGainFocus, (void*)GuiArrayWidget_OnLoseFocus, (void*)GuiArrayWidget_OnInput, (void*)GuiArrayWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiMissionStatList_GetClassName, (void*)func_00350570, (void*)GuiTextArrayWidget_SetDims, (void*)func_00423660, (void*)func_00423610, (void*)GuiMissionStatList_Draw, (void*)func_004235E0, (void*)func_004235C0, (void*)0x0 };
extern int guiTextArrayWidget_ctor(GuiMissionStatList*);

/* GuiMissionStatList constructor: default layout values. */
GuiMissionStatList* GuiMissionStatList_ctor(GuiMissionStatList* self) {
    int flags;

    guiTextArrayWidget_ctor(self);
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
