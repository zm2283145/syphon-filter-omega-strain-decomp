/*
 * main/GuiNetJoinMission: 2 files, 002A9240-002A9340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A9240 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Obj: only the slots used here are named (vtable offset in comments). */
struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(const char* type); /* +0x58 */
};

typedef struct Screen {
    char pad[0x160];
    Obj* item0; /* +0x160 */
    Obj* item1; /* +0x164 */
    Obj* item2; /* +0x168 */
} Screen;

extern char D_004A9870[];
extern "C" char D_004AB648[];
extern "C" char D_004AB658[];
extern "C" char D_004AB668[];
static void * const dat_0048BBB0[2] = { (void*)D_004AB648, (void*)0x0 };
static void * const dat_0048BBB8[2] = { (void*)D_004AB658, (void*)0x0 };
static void * const dat_0048BBC0[2] = { (void*)D_004AB668, (void*)0x0 };
extern "C" void func_0033F250(Screen* self);
extern "C" Obj* GuiWidget_FindChildByName(Screen* self, const char* name);

/* Returns obj when it is a D_004A9870-type widget, else 0. */
static inline Obj* AsLabel(Obj* obj)
{
    if (obj == 0 || !obj->IsA(D_004A9870))
        obj = 0;
    return obj;
}

/* Screen init: base init, then looks up the three named child widgets (kept only if D_004A9870-type). */
extern "C" void func_002A9240(Screen* self)
{
    func_0033F250(self);
    self->item0 = AsLabel(GuiWidget_FindChildByName(self, (*(const char**)dat_0048BBB0)));
    self->item1 = AsLabel(GuiWidget_FindChildByName(self, (*(const char**)dat_0048BBB8)));
    self->item2 = AsLabel(GuiWidget_FindChildByName(self, (*(const char**)dat_0048BBC0)));
}
#pragma pop /* merge_units */
/* merge_units: end func_002A9240 */

/* merge_units: begin func_002A9340 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern char D_004DDA50[];   /* GuiNetJoinMission vtable */
extern GuiMenuScreen* GuiMenuScreen_ctor(GuiMenuScreen* self);

/* GuiNetJoinMission constructor. */
GuiNetListScreen* GuiNetJoinMission_ctor(GuiNetListScreen* self) {
    GuiMenuScreen_ctor(&self->base);
    self->base.base.base.base.vtable = D_004DDA50;
    self->base.base.screenId = 2;
    self->unk160 = 0;
    self->unk164 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002A9340 */
