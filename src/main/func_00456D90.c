/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies before GuiSubTitleDisplay.cc (starts 0x00457AA0); gui widget code.
 */

#include "loose05_types.h"

/* vtable */
extern void func_00368620();
extern void func_0041D400();
extern void func_0041D5C0();
extern void func_0041D780();
extern void func_0041E230();
extern void func_0041E2B0();
extern void func_0041E330();
extern void func_0041E470();
extern void func_0041F070();
extern void func_0041F080();
extern void func_0041F090();
extern void func_0041F210();
extern void func_004566D0();
extern void func_00456830();
extern void func_00456A30();
extern void func_00456A60();
extern void func_00456AB0();
extern void func_00456BF0();
extern void func_004573C0();
extern void func_00457430();
extern void func_00457440();
void * const D_004E1430[24] = { (void*)0x0, (void*)0x0, (void*)func_004573C0, (void*)func_00456BF0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00456AB0, (void*)func_00456A30, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_004566D0, (void*)func_0041E470, (void*)func_0041E230, (void*)func_00368620, (void*)func_00456830, (void*)func_0041F210, (void*)func_00456A60, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00457430, (void*)func_00457440, (void*)0x0 };
extern int GuiObjectives_ctor(void* self, int a1, int a2);

/* Constructor: base built by GuiObjectives_ctor, fields cleared, flag bit 5 cleared. */
GuiWidget456D90* func_00456D90(GuiWidget456D90* self) {
    GuiObjectives_ctor(self, 1, 1);
    self->vtable = ((char*)D_004E1430);
    self->unk90 = 0;
    self->unk94 = 0;
    self->unk98 = 0;
    self->unk9C = 0;
    self->unkA0 = 0;
    self->unkA4 = 0;
    self->unkA8 = 0;
    self->flags &= ~0x20;
    return self;
}
