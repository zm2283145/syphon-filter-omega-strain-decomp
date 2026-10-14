/*
 * main/npc: range (3 files, 0014B370-0014B470)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0014B370 */
#pragma push /* merge_units */
#pragma cplusplus on
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct KillActor_e8 {
    V4(v00) V4(v04) V4(v08) V4(v0C) V4(v10) V4(v14) V4(v18) V4(v1C)
    V4(v20) V4(v24) V4(v28) V4(v2C) V4(v30) V4(v34) V4(v38)
    virtual void v3C(); virtual void v3D();
    virtual void Damage(KillActor_e8*, int, int, int, int, int, float); /* 0x100 */
    virtual void v3F();
    virtual unsigned char GetState(); /* 0x108 */
    char pad4[0x3C];
    float health; /* 0x40 */
    char pad44[0x33A5 - 0x44];
    unsigned char flag33A5;
};
struct KillNPC_e8 { char pad[0x30]; KillActor_e8* actor; };
extern "C" void cNPC_Kill(KillNPC_e8* self)
{
    KillActor_e8* a = self->actor;
    if (a->GetState() != 3 || a->flag33A5) {
        KillActor_e8* b = self->actor;
        b->Damage(b, 2, 10, 0, 0, 0, (float)(int)a->health);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B370 */

/* merge_units: begin func_0014B410 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int id; } Item_B410;
typedef struct {
    char pad[0x90]; float f90;
    char pad2[0x141 - 0x94];
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1; unsigned char b5 : 3;
    char pad3[0x1C8 - 0x142];
    Item_B410* item; int itemId;
} NPC_B410;
void cNPC_v65(NPC_B410* self, Item_B410* item, int flag, float f)
{
    int none;
    int* p;
    self->item = item;
    if (item)
        p = &item->id;
    else {
        none = -1;
        p = &none;
    }
    self->itemId = *p;
    self->f90 = f;
    self->b4 = flag;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B410 */

/* merge_units: begin func_0014B470 */
#pragma push /* merge_units */
#pragma cplusplus on
#define B8V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
struct B8_NPC {
    B8V8(a) B8V8(b) B8V8(c) B8V8(d) B8V8(e) B8V8(f) B8V8(g) B8V8(h) B8V8(i) B8V8(j) B8V8(k) B8V8(l)
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6();
    virtual int GetWeapon();      /* +0x1A4 */
    virtual void m8();
    virtual void SetWeapon(int w); /* +0x1AC */
    char pad4[0x8C - 4];
    float f8C;
    char pad90[0x12C - 0x90];
    int prevWeapon;
    int fireMode;
    int fireTime;
};
extern "C" void cNPC_ForceWeaponFire(B8_NPC* npc, int mode, int weapon, float time) {
    if (weapon < 0 || weapon == npc->GetWeapon()) {
        npc->prevWeapon = -1;
    } else {
        npc->prevWeapon = npc->GetWeapon();
        npc->SetWeapon(weapon);
    }
    npc->fireMode = mode;
    if (time == 0.0f) {
        npc->fireTime = (int)npc->f8C;
    } else {
        npc->fireTime = (int)time;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B470 */
