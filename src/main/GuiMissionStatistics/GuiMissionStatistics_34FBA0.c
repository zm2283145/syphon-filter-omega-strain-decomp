/*
 * main/GuiMissionStatistics: 5 files, 0034FBA0-0034FDE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034FBA0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
struct V34FBA0 { int cap; int count; int data; };
class W34FBA0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    virtual void f5C(int, int);
    char pad[0x84]; void* a88; char pad8C[0x34]; V34FBA0* aC0; int aC4[11];
};
struct S34FBA0 { char pad[0x6C]; W34FBA0* a6C; V34FBA0 v70; char pad7C[4]; int a80; };
extern "C" {
extern "C" char D_004BAA78[];
extern "C" char D_004BAA90[];
static void * const dat_00492BD0[2] = { (void*)D_004BAA78, (void*)0x0 };
static void * const dat_00492BD8[2] = { (void*)D_004BAA90, (void*)0x0 };
extern char D_004BAD80[];
void GuiPersonnelScreen_Init(S34FBA0* o);
void GuiMissionStatistics_BuildRows(S34FBA0* o);
W34FBA0* GuiWidget_FindChildByName(void* self, char* name);
void GuiArrayWidget_Select(void* w, int a, int b);
void GuiArrayWidget_ColumnWidth(void* w, int i, int v);
void GuiMissionStatistics_Init(S34FBA0* o);
}
static inline W34FBA0* cast34FBA0(W34FBA0* w)
{
    return (w && w->IsA(D_004BAD80)) ? w : 0;
}
void GuiMissionStatistics_Init(S34FBA0* o)
{
    GuiPersonnelScreen_Init(o);
    o->a80 = 0;
    GuiMissionStatistics_BuildRows(o);
    o->a6C = cast34FBA0(GuiWidget_FindChildByName(o, (*(char**)dat_00492BD0)));
    if (o->a6C) {
        W34FBA0* w;
        int i;
        o->a6C->a88 = GuiWidget_FindChildByName(o, (*(char**)dat_00492BD8));

        w = o->a6C;
        w->aC0 = &o->v70;
        w->f5C(0xB, &o->v70 ? o->v70.count : 0);
        GuiArrayWidget_Select(w, 0, 0);
        for (i = 0; i < 11; i++) GuiArrayWidget_ColumnWidth(w, i, w->aC4[i]);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0034FBA0 */

/* merge_units: begin func_0034FCB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatistics constructor (vtable D_004DEE70).
 */

#include "loose03_types.h"

extern char D_004DEE70[];       /* GuiMissionStatistics vtable */
extern int func_0034FE40(Member34FE40*);
extern int GuiPersonnelScreen_ctor(GuiMissionStatistics*);

/* GuiMissionStatistics constructor. */
GuiMissionStatistics* GuiMissionStatistics_ctor(GuiMissionStatistics* self) {
    Member34FE40* member;

    GuiPersonnelScreen_ctor(self);
    member = &self->unk70;
    self->base.base.vtable = D_004DEE70;
    func_0034FE40(member);
    member->unk0C = 1;
    self->unk6C = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0034FCB0 */

/* merge_units: begin func_0034FD10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "member_dtor_chain.h"

DEFINE_MEMBER_DTOR_CHAIN(func_0034FD10, func_003513B0)
#pragma pop /* merge_units */
/* merge_units: end func_0034FD10 */

/* merge_units: begin func_0034FD80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

DEFINE_BASE_DTOR_CHAIN(func_0034FD80, func_003513B0)
#pragma pop /* merge_units */
/* merge_units: end func_0034FD80 */

/* merge_units: begin func_0034FDE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_0034FDE0, D_004DF0B0, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_0034FDE0 */
