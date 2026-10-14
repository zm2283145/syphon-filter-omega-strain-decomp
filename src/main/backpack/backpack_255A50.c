/*
 * main/backpack: range (6 files, 00255A50-00255F10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00255A50 */
#pragma push /* merge_units */
#pragma cplusplus on
/* WorldInv_AddArmor: count a spawn request; on first activation register the object and create its proxy */
struct Pt1SpProxy { char pad[0x94]; int id; };
struct Pt1SpObj {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void SetActive(int on);
    char pad4[0xC - 4];
    int id;
    char pad10[0x2E4 - 0x10];
    int requests;
    int reqA;
    int reqB;
    char pad2F0[0x2FC - 0x2F0];
    Pt1SpProxy* proxy;
};
extern "C" {
extern void* D_004FFBD0;
void Object_Register(Pt1SpObj* o);
Pt1SpProxy* Hotbox_CreateRuntime(void* mgr, Pt1SpObj* o, int a, int b);
}
extern "C" void WorldInv_AddArmor(Pt1SpObj* o, int a, int b)
{
    if (!a)
        return;
    if (o->requests++ == 0) {
        o->reqA = a;
        o->reqB = b;
    }
    if (o->proxy)
        return;
    o->SetActive(1);
    Object_Register(o);
    if (o->proxy)
        return;
    o->proxy = Hotbox_CreateRuntime(D_004FFBD0, o, 0, 1);
    o->proxy->id = o->id;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255A50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255A50 */

/* merge_units: begin func_00255AF0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Link {
    char pad00[0x94];
    int owner;
};

struct Entry {
    int amount[4];
    int extra[4];
    int item;
    int n;
};

struct Slot {
    unsigned char kind;
    Entry e[5];
    int count;
    unsigned char flag;
};

struct BP {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a); /* +0x5C */
    char pad04[0x0C - 0x04];
    int unk0C;
    char pad10[0x64 - 0x10];
    Slot slots[3];
    char pad2E0[0x2FC - 0x2E0];
    Link* link;
};

extern "C" {
#if 0 /* merge_units */
extern int D_004FFBD0;
#endif /* merge_units */
#define D_004FFBD0 (*(int*)&D_004FFBD0) /* merge_units */

int WeaponInv_SlotOfItem(int id);
#if 0 /* merge_units */
void Object_Register(BP* self);
#endif /* merge_units */
#define Object_Register(a0) (Object_Register((Pt1SpObj *)(a0))) /* merge_units */

#if 0 /* merge_units */
Link* Hotbox_CreateRuntime(int manager, BP* bp, int a2, int a3);
#endif /* merge_units */
#define Hotbox_CreateRuntime(a0, a1, a2, a3) ((Link *)Hotbox_CreateRuntime((void *)(a0), (Pt1SpObj *)(a1), (a2), (a3))) /* merge_units */

}

static inline void CreateLink(BP* bp) {
    if (bp->link == 0) {
        bp->link = Hotbox_CreateRuntime(D_004FFBD0, bp, 0, 1);
        bp->link->owner = bp->unk0C;
    }
}

extern "C" void func_00255AF0(BP* bp, int item, int amount, int extra, unsigned char flag) {
    int kind = WeaponInv_SlotOfItem(item);
    unsigned char k = kind;
    int found = -1;
    int i;
    if (k == 4 && amount == 0)
        return;
    for (i = 0; i < 3; i++) {
        if (bp->slots[i].count || bp->slots[i].flag) {
            if (bp->slots[i].kind == k) {
                found = i;
                break;
            }
        } else if (found < 0) {
            found = i;
        }
    }
    if (found >= 0) {
        Slot* s = &bp->slots[found];
        bool done = false;
        Entry* e = s->e;
        int j = 0;
        for (; !done && j < s->count; j++, e++) {
            if (e->item == item) {
                if (k == 4) {
                    e->amount[0] += amount;
                } else {
                    e->amount[e->n] = amount;
                    e->extra[e->n] = extra;
                    e->n++;
                }
                done = true;
            }
        }
        if (!done) {
            e->item = item;
            e->extra[0] = extra;
            e->amount[0] = amount;
            e->n = 1;
            s->kind = kind;
            s->count++;
            if (flag)
                s->flag = flag;
        }
    }
    if (bp->link == 0) {
        bp->Method5C(1);
        Object_Register(bp);
        CreateLink(bp);
    }
}
#undef D_004FFBD0 /* merge_units */
#undef Object_Register /* merge_units */
#undef Hotbox_CreateRuntime /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255AF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255AF0 */

/* merge_units: begin func_00255CF0 */
#pragma push /* merge_units */
#pragma cplusplus on


struct BP_00255CF0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a); /* +0x5C */
    char pad04[0x0C - 0x04];
    int unk0C;
    char pad10[0x64 - 0x10];
    signed char slot;
    char pad65[0x134 - 0x65];
    unsigned char unk134;
    char pad135[0x2F1 - 0x135];
    unsigned char unk2F1;
    char pad2F2[0x2FC - 0x2F2];
    Link* link;
    char pad300[0x30C - 0x300];
    int unk30C;
};

extern "C" {
#if 0 /* merge_units */
extern int D_004FFBD0;
#endif /* merge_units */
#define D_004FFBD0 (*(int*)&D_004FFBD0) /* merge_units */

#if 0 /* merge_units */
void Object_Register(BP_00255CF0* self);
#endif /* merge_units */
#define Object_Register(a0) (Object_Register((Pt1SpObj *)(a0))) /* merge_units */

#if 0 /* merge_units */
Link* Hotbox_CreateRuntime(int manager, BP_00255CF0* bp, int a2, int a3);
#endif /* merge_units */
#define Hotbox_CreateRuntime(a0, a1, a2, a3) ((Link *)Hotbox_CreateRuntime((void *)(a0), (Pt1SpObj *)(a1), (a2), (a3))) /* merge_units */

}

static inline void CreateLink_00255CF0(BP_00255CF0* bp) {
    if (bp->link == 0) {
        bp->link = Hotbox_CreateRuntime(D_004FFBD0, bp, 0, 1);
        bp->link->owner = bp->unk0C;
    }
}

extern "C" void func_00255CF0(BP_00255CF0* bp, int item) {
    signed char s = WeaponInv_SlotOfItem(item);
    bp->unk134 = 1;
    bp->slot = s;
    if (bp->link == 0) {
        bp->Method5C(1);
        Object_Register(bp);
        CreateLink_00255CF0(bp);
    }
    bp->unk2F1 = 1;
    bp->unk30C = 0;
}
#undef D_004FFBD0 /* merge_units */
#undef Object_Register /* merge_units */
#undef Hotbox_CreateRuntime /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255CF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255CF0 */

/* merge_units: begin func_00255D90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tgt {
    char pad0[0xC];
    int serial;
    char pad10[0x2C - 0x10];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x3469 - 0x2F];
    unsigned char b3469;
};
struct Hnd {
    Tgt* target;
    int serial;
    Tgt* Get() { Tgt* t = target; bool ok = !t || t->serial == serial; return ok ? t : 0; }
};
struct Obj {
    char pad0[0x300];
    Hnd h;
};
extern "C" bool func_00255D90(Obj* o)
{
    bool r = 0;
    if (o->h.Get()) {
        Tgt* t = o->h.Get();
        bool v = t->b2D && t->b2C && !t->b2E && t->b3469;
        if (v)
            r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255D90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255D90 */

/* merge_units: begin func_00255E50 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tgt_00255E50 {
    char pad0[0xC];
    int serial;
    char pad10[0x2C - 0x10];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x3468 - 0x2F];
    unsigned char b3469;
};
struct Hnd_00255E50 {
    Tgt_00255E50* target;
    int serial;
    Tgt_00255E50* Get() { Tgt_00255E50* t = target; bool ok = !t || t->serial == serial; return ok ? t : 0; }
};
struct Obj_00255E50 {
    char pad0[0x300];
    Hnd_00255E50 h;
};
extern "C" bool func_00255E50(Obj_00255E50* o)
{
    bool r = 0;
    if (o->h.Get()) {
        Tgt_00255E50* t = o->h.Get();
        bool v = t->b2D && t->b2C && !t->b2E && t->b3469;
        if (v)
            r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255E50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255E50 */

/* merge_units: begin func_00255F10 */
#pragma push /* merge_units */
typedef struct { char pad[0x134]; unsigned char b134; char pad2[0x2F1 - 0x135]; unsigned char b2F1; unsigned char b2F2; } Obj255F;
extern void func_00255F60(Obj255F* s);
extern void func_00254990(Obj255F* s);
void func_00255F10(Obj255F* s) {
    func_00255F60(s);
    func_00254990(s);
    s->b2F2 = 0;
    if (s->b2F1) {
        s->b134 = 0;
        s->b2F1 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255F10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255F10 */
