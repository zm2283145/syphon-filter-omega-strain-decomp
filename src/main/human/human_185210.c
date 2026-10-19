/*
 * main/human: range (3 files, 00185210-00185330)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

/* merge_units: begin func_00185210 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetSetFlagMsg_dtor, D_004DA9D0, D_004DCF10, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00185210 */

/* merge_units: begin func_00185280 */
#pragma push /* merge_units */
#pragma cplusplus on
#define B7V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
struct B7_GObj {
    char pad0[0x4C];
    int type;
};
struct B7_Human {
    B7V8(a) B7V8(b) B7V8(c) B7V8(d) B7V8(e) B7V8(f) B7V8(g) B7V8(h)
    virtual unsigned char GetState(); /* +0x108 */
    char pad4[0x33BC - 4];
    float health;
};
extern "C" B7_GObj* GObj_IdentityB(int id);
extern "C" int g_HumanActorClassKey;
extern "C" void Global_ShockToDeath(B7_Human* o, float a, float b, int c, int d);
extern "C" int Script_ShockToDeath(int* args)
{
    B7_GObj* o = GObj_IdentityB(args[0]);
    if (o && o->type == g_HumanActorClassKey) {
        B7_Human* h = (B7_Human*)o;
        unsigned char s = h->GetState();
        bool dying = (s == 2 || s == 3);
        if (!dying && h->health < 0.0f) {
            Global_ShockToDeath(h, 0.5f, 10000.0f, 1, 1);
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185280 */

/* merge_units: begin func_00185330 */
#pragma push /* merge_units */
typedef struct { char pad[0x3524]; void* weapons; } H_185330;
typedef struct { char pad[0x30]; H_185330* player; } G_185330;
extern G_185330* g_LocalPlayer;
extern void WeaponInv_ClearSlots(void* w);
extern void WeaponInv_Add(void* w, int id, int a, int b, int c, int d);
extern int WeaponInv_SlotOfItem(int id);
extern void WeaponInv_Equip(void* w, int slot);
int Script_SetPlayerWeapons(int* args)
{
    volatile int b;
    volatile int a;
    int pa;
    int pb;
    void* w;
    b = args[1];
    pb = b;
    a = args[0];
    pa = a;
    w = g_LocalPlayer->player->weapons;
    WeaponInv_ClearSlots(w);
    if (pa > -1) WeaponInv_Add(w, pa, 1, 0, 1, 0);
    if (pb > -1) {
        WeaponInv_Add(w, pb, 1, 0, 1, 0);
        if (pa < 0) pa = pb;
    }
    if (pa >= 0) WeaponInv_Equip(w, WeaponInv_SlotOfItem(pa));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185330 */
