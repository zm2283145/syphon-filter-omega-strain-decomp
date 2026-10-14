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
extern int func_0041EFA0(GuiWidget* self);
extern void GuiWidget_ctor(GuiWidget* self);

/* GuiSaveAgentWidget vtable slot 5: own update, then the base widget's. */
int func_002936E0(GuiSaveAgentWidget* self) {
    AgentOpen_BuildSlotList(self);
    return func_0041EFA0(&self->base.base);
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
DEFINE_VTABLE_BASE_DTOR(func_00293770, D_004E1220, func_0041F370)
#pragma pop /* merge_units */
/* merge_units: end func_00293770 */

/* merge_units: begin func_002937D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable3_base_dtor.h"

/* Three-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void func_00292AD0();
extern "C" void func_00292B90();
extern "C" void func_00292DD0();
extern "C" void func_00293660();
extern "C" void func_00293850();
extern "C" void func_00293860();
extern "C" void func_00293890();
extern "C" void func_0041D400();
extern "C" void func_0041D5C0();
extern "C" void func_0041D780();
extern "C" void func_0041D8C0();
extern "C" void func_0041E230();
extern "C" void func_0041E2B0();
extern "C" void func_0041E330();
extern "C" void func_0041E470();
extern "C" void func_0041EBF0();
extern "C" void func_0041F070();
extern "C" void func_0041F080();
extern "C" void func_0041F090();
extern "C" void func_0041F150();
extern "C" void func_0041F210();
extern void * const D_004DD400[];
void* func_0041F370(void* self, short deleteFlag);
}
extern "C" Vtable3Object* func_002937D0(Vtable3Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DD400);
        if (self) {
            self->vtable = D_004DD460;
            if (self) {
                self->vtable = D_004E1220;
                func_0041F370(self, 0);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DD400[24] = { (void*)0x0, (void*)0x0, (void*)func_002937D0, (void*)func_0041F150, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00292DD0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00292AD0, (void*)func_0041E470, (void*)func_0041E230, (void*)func_00293660, (void*)func_00292B90, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00293850, (void*)func_00293860, (void*)func_00293890 };
#pragma pop /* merge_units */
/* merge_units: end func_002937D0 */
