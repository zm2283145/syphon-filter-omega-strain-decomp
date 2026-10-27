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
extern int GuiAgentDirectoryWidget_UpdateNameList(GuiSaveAgentWidget* self);
extern int GuiWidget_onWake(GuiWidget* self);
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiSaveAgentWidget vtable slot 5: own update, then the base widget's. */
int GuiAgentDirectoryWidget_onWake(GuiSaveAgentWidget* self) {
    GuiAgentDirectoryWidget_UpdateNameList(self);
    return GuiWidget_onWake(&self->base.base);
}

/* GuiSaveAgentWidget constructor (GuiItem constructor inlined). */
GuiSaveAgentWidget* GuiAgentDirectoryWidget_ctor(GuiSaveAgentWidget* self, unsigned char arg) {
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
DEFINE_VTABLE_BASE_DTOR(GuiSaveAgentWidget_dtor, D_004E1220, GuiWidget_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00293770 */

/* merge_units: begin func_002937D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable3_base_dtor.h"

/* Three-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void GuiAgentLoad_onInput();
extern "C" void GuiAgentLoad_onMessage();
extern "C" void GuiAgentLoad_onWake();
extern "C" void GuiAgentDirectoryWidget_onAdvanceTime();
extern "C" void GuiAgentLoad_GetClassName();
extern "C" void GuiAgentLoad_IsClass();
extern "C" void GuiSaveAgentWidget_SaveDone();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onLoseFocus();
extern "C" void GuiWidget_onGainFocus();
extern "C" void GuiWidget_onRender();
extern "C" void GuiWidget_onSleep();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_onAdd();
extern "C" void GuiWidget_Load();
extern void * const D_004DD400[];
void* GuiWidget_dtor(void* self, short deleteFlag);
}
extern "C" Vtable3Object* GuiAgentLoad_dtor(Vtable3Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD400);
        if (self) {
            self->vtable = D_004DD460;
            if (self) {
                self->vtable = D_004E1220;
                GuiWidget_dtor(self, 0);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD400[24] = { (void*)0x0, (void*)0x0, (void*)GuiAgentLoad_dtor, (void*)GuiWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiAgentLoad_onWake, (void*)GuiWidget_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiAgentLoad_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiAgentDirectoryWidget_onAdvanceTime, (void*)GuiAgentLoad_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiAgentLoad_GetClassName, (void*)GuiAgentLoad_IsClass, (void*)GuiSaveAgentWidget_SaveDone };
#pragma pop /* merge_units */
/* merge_units: end func_002937D0 */
