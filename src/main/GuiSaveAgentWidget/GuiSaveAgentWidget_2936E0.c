/*
 * main/GuiSaveAgentWidget: 3 files, 002936E0-002937D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002936E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern char D_004DD460[];   /* GuiSaveAgentWidget vtable */
extern char D_004E1220[];   /* GuiItem vtable */
extern int AgentOpen_BuildSlotList(GuiSaveAgentWidget* self);
extern int GuiWidget_BaseWake(GuiWidget* self);
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiSaveAgentWidget vtable slot 5: own update, then the base widget's. */
int func_002936E0(GuiSaveAgentWidget* self) {
    AgentOpen_BuildSlotList(self);
    return GuiWidget_BaseWake(&self->base.base);
}

/* GuiSaveAgentWidget constructor (GuiItem constructor inlined). */
GuiSaveAgentWidget* GuiSaveAgentWidget_ctor(GuiSaveAgentWidget* self, unsigned char arg) {
    GuiWidget_ctor(&self->base.base);
    self->base.base.vtable = D_004E1220;
    self->base.unk48 = -2;
    self->base.base.vtable = D_004DD460;
    self->unk78 = 10.0f;
    self->unk7C = arg;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002936E0 */

/* merge_units: begin func_00293770 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_00293770, D_004E1220, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_00293770 */

/* merge_units: begin func_002937D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable3_base_dtor.h"

/* Three-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiAgentLoad_HandleInput();
extern "C" void GuiAgentLoad_HandleEvent();
extern "C" void GuiAgentLoad_Wake();
extern "C" void GuiAgentLoad_Update();
extern "C" void GuiAgentLoad_GetClassName();
extern "C" void func_00293860();
extern "C" void func_00293890();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_BubbleType1();
extern "C" void GuiWidget_BubbleType0();
extern "C" void GuiWidget_Draw();
extern "C" void GuiWidget_BaseSleep();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void GuiWidget_Init();
extern "C" void func_0041F210();
extern void * const D_004DD400[];
void* GuiWidget_Destroy(void* self, short deleteFlag);
}
extern "C" Vtable3Object* func_002937D0(Vtable3Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD400);
        if (self) {
            self->vtable = D_004DD460;
            if (self) {
                self->vtable = D_004E1220;
                GuiWidget_Destroy(self, 0);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD400[24] = { (void*)0x0, (void*)0x0, (void*)func_002937D0, (void*)GuiWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiAgentLoad_Wake, (void*)GuiWidget_BaseSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiAgentLoad_HandleInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiAgentLoad_Update, (void*)GuiAgentLoad_HandleEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiAgentLoad_GetClassName, (void*)func_00293860, (void*)func_00293890 };
#pragma pop /* merge_units */
/* merge_units: end func_002937D0 */
