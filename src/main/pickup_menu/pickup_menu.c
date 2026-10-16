/*
 * main/pickup_menu: 2 files, 00251040-00251060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00251040 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "pickup_menu_types.h"

extern char D_004F7E70[]; /* text colour (Vec4f; set by sinit and backpack Global_SetPickupTextColor) */
extern float func_003D0810(PickupMenu* text, char* color);

/* Applies the pickup-menu text colour to a model's text object (model +0x74),
 * setting the two flags at +0x10/+0x11 first. */
float PickupMenuEntry_SetPickupColor(PickupMenu* text) {
    text->unk10 = 1;
    text->unk11 = 1;
    return func_003D0810(text, D_004F7E70);
}
#pragma pop /* merge_units */
/* merge_units: end func_00251040 */

/* merge_units: begin func_00251060 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* Interface model instance (0x80 bytes, made by func_003EF010); +0x74 is its text object. */
struct PickupMenuModel { char pad[0x74]; int text; };
/* The pickup menu: one or two interface models (the second is only made when
 * t == 0), each paired with a 0x68-byte game object (WeaponPreview_ctor). */
struct PickupMenuObj {
    signed char kind;        /* 0x00 */
    char pad1[3];
    int id;                  /* 0x04 */
    int x8;                  /* 0x08 cleared */
    void* obj1;              /* 0x0C game object for model1 */
    void* obj2;              /* 0x10 game object for model2 */
    PickupMenuModel* model1; /* 0x14 */
    PickupMenuModel* model2; /* 0x18 */
};
extern "C" {
extern int D_004F7E90; /* interface model template of the first panel */
extern int D_004F7E98; /* interface model template of the second panel */
extern int D_0048AEF8;
extern char D_004A7998[]; /* "pickup_menu.cc" */
void* Mem_Alloc(int pool, int size, char* file, int line);
PickupMenuModel* func_003EF010(int tmpl);
void func_003F45A0(float t, PickupMenuModel* m);
void func_003F44E0(float t, PickupMenuModel* m);
#if 0 /* merge_units */
void PickupMenuEntry_SetPickupColor(int x);
#endif /* merge_units */
#define PickupMenuEntry_SetPickupColor(a0) ((void)PickupMenuEntry_SetPickupColor((PickupMenu *)(a0))) /* merge_units */

void* WeaponPreview_ctor(void* obj);
void func_003EEBE0(int node, int visible, int recurse); /* show/hide a model tree */
}
/* Sets up the pickup menu: instantiates the panel model(s) and their game objects. */
extern "C" void PickupMenu_AddEntry(PickupMenuObj* s, signed char kind, int id, int t)
{
    void* p;
    s->kind = kind;
    s->id = id;
    s->x8 = 0;
    s->model1 = func_003EF010(D_004F7E90);
    func_003F45A0(t, s->model1);
    func_003F44E0(t + D_0048AEF8, s->model1);
    PickupMenuEntry_SetPickupColor(s->model1->text);
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x68, D_004A7998, 0x352);
    }
    if (p)
        p = WeaponPreview_ctor(p);
    s->obj1 = p;
    if (t) {
        func_003EEBE0(D_004F7E98, 0, 1);
        return;
    }
    func_003EEBE0(D_004F7E98, 1, 1);
    s->model2 = func_003EF010(D_004F7E98);
    func_003F45A0(t, s->model2);
    func_003F44E0(t + D_0048AEF8, s->model2);
    PickupMenuEntry_SetPickupColor(s->model2->text);
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x68, D_004A7998, 0x35D);
    }
    if (p)
        p = WeaponPreview_ctor(p);
    s->obj2 = p;
}
#undef PickupMenuEntry_SetPickupColor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00251060 */
