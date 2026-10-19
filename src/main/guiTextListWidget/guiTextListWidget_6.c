/*
 * main/guiTextListWidget: 2 files, 00424BC0-00424C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiTextListWidget_424BC0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(void* type); /* +0x58 */
};

extern "C" char D_004BF698[];
static void * const dat_00494140[2] = { (void*)D_004BF698, (void*)0x0 };
extern "C" char D_004BF6A8[];
static void * const dat_00494148[2] = { (void*)D_004BF6A8, (void*)0x0 };
extern char D_004AAE00[];
extern "C" void GuiWidget_Init(void* self);
extern "C" Widget* GuiWidget_FindChildBySubstring(void* self, int id);
typedef struct Screen { char pad[0x88]; Widget* unk88; /* +0x88 */ Widget* unk8C; /* +0x8C */ } Screen;

/* GuiWidget_Init, then caches the (*(int*)dat_00494140) child at +0x8C if it is of type D_004AAE00 (virtual +0x58), else 0, and the D_00494148 child at +0x88. */
extern "C" void GuiArrayWidget_Init(Screen* self)
{
    Widget* child;
    GuiWidget_Init(self);
    child = GuiWidget_FindChildBySubstring(self, (*(int*)dat_00494140));
    if (!child || !child->IsA(D_004AAE00))
    child = 0;
    self->unk8C = child;
    self->unk88 = GuiWidget_FindChildBySubstring(self, (*(int*)dat_00494148));
}
#pragma pop /* merge_units */
/* merge_units: end guiTextListWidget_424BC0 */

/* merge_units: begin guiTextListWidget_424C50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern char D_004E0D20[];         /* GuiWidget424C50 vtable */
extern int PtrVec_PushBack_1C1080(L4OwnedVec*, void*);
extern int func_001C10A0(L4OwnedVec*);
extern GuiWidget* GuiWidget_ctor(GuiWidget*);

/* Constructor of a GuiWidget subclass holding a vector seeded with one entry. */
GuiWidget424C50* GuiArrayWidget_ctor(GuiWidget424C50* self) {
    L4OwnedVec* vec;

    GuiWidget_ctor(&self->base);
    vec = &self->unk60;
    self->base.vtable = D_004E0D20;
    func_001C10A0(vec);
    vec->owned = 1;
    self->unk58 = 0;
    self->unk48 = 1;
    self->unk4C = 1;
    self->unk50 = 0;
    self->unk54 = 0;
    self->unk5C = 24;
    PtrVec_PushBack_1C1080(vec, "<");
    self->unk70 = self->unk48;
    self->unk74 = self->unk4C;
    self->unk78 = self->unk50;
    self->unk7C = self->unk54;
    self->unk82 = 0;
    self->unk84 = 0;
    self->unk81 = 0;
    self->unk80 = 0;
    self->unk88 = 0;
    self->unk8C = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end guiTextListWidget_424C50 */
