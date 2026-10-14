/*
 * main/GuiEquipmentModify: 13 files, 002C1E00-002C26A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C1E00 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_array_member_dtor.h"

/* Destructor: vector and array members, optionally delete. */
DEFINE_VECTOR_ARRAY_MEMBER_DTOR(func_002C1E00)
#pragma pop /* merge_units */
/* merge_units: end func_002C1E00 */

/* merge_units: begin func_002C1EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_002C1EA0, func_001AF8E0)
#pragma pop /* merge_units */
/* merge_units: end func_002C1EA0 */

/* merge_units: begin func_002C1F00 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_002C1F00)
#pragma pop /* merge_units */
/* merge_units: end func_002C1F00 */

/* merge_units: begin func_002C1FF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* Vector end(). */
int* func_002C1FF0(PtrVec* v) {
    return v->data + v->count;
}

void func_002C2010(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* Vector data pointer. */
int* func_002C2020(PtrVec* v) {
    return v->data;
}

int** func_002C2030(PtrVec* v) {
    return &v->data;
}

/* Vector push_back. */
int func_002C2040(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_002C1FF0 */

/* merge_units: begin func_002C2060 */
#pragma push /* merge_units */
typedef struct Obj2C20 {
    char pad00[0xC];
    unsigned char flag; /* 0x0C */
} Obj2C20;

extern void func_00290B90(Obj2C20* self, int* src, unsigned char flag);
extern void func_001396D0(Obj2C20* self, int value);

/* Constructor: base init, copies *src and stores the flag byte. */
Obj2C20* func_002C2060(Obj2C20* self, int* src, unsigned char flag) {
    func_00290B90(self, src, flag);
    func_001396D0(self, *src);
    self->flag = flag;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C2060 */

/* merge_units: begin func_002C20B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_002C20B0)
#pragma pop /* merge_units */
/* merge_units: end func_002C20B0 */

/* merge_units: begin func_002C21A0 */
#pragma push /* merge_units */
#include "loose02_types.h"

extern void* D_004FFD30;                    /* weapon definition table */
extern GuiEquipmentModifyObj* D_0051EE10;   /* GuiEquipmentModify instance */
extern WeaponDefL2* WeaponDb_Get(void* table, int id);
extern int func_002BF4B0(GuiEquipmentModifyObj* screen, WeaponLinkL2* link, int arg);

Rel* func_002C21A0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Applies the attachment of the currently selected weapon (or its linked record). */
void func_002C21C0(void) {
    GuiEquipmentModifyObj* screen;
    WeaponLinkL2* link;
    WeaponDefL2* def;
    int index;

    screen = D_0051EE10;
    if (screen->unk84 != 0 && screen->unk8C != 0) {
        index = screen->weaponIndex;
        link = 0;
        if (index < screen->weaponCount) {
            link = WeaponDb_Get(D_004FFD30, screen->weaponIds[index])->attachment;
        }
        if (link != 0 && D_0051EE10->unkD4 != 0) {
            def = WeaponDb_Get(D_004FFD30, link->weaponId);
            if (def->kind == 7) {
                link = def->link;
            }
            if (link != 0) {
                func_002BF4B0(D_0051EE10, link, D_0051EE10->unkD4);
            }
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002C21A0 */

/* merge_units: begin func_002C2290 */
#pragma push /* merge_units */
typedef struct { char p0[0x40A]; short h40A; } O2C2290;
typedef struct { char p0[0x2470]; O2C2290* arr[1]; } P2C2290;
typedef struct { char p0[0x4C]; P2C2290* p4C; char p50[0x34]; int f84; int f88; char p8C[0x44]; int fD0; char pD4[0x28]; int fFC; } G2C2290;
typedef struct { char p0[0xF0]; unsigned char kind; char pF1[0x2B]; O2C2290* alt; } W2C2290;
#if 0 /* merge_units */
extern G2C2290* D_0051EE10;
#endif /* merge_units */
#define D_0051EE10 (*(G2C2290 **)&D_0051EE10) /* merge_units */

#if 0 /* merge_units */
extern W2C2290* WeaponDb_Get(void* db, int id);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((W2C2290 *)WeaponDb_Get((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_002BF4B0(G2C2290* g, O2C2290* o, int v);
#endif /* merge_units */
#define func_002BF4B0(a0, a1, a2) ((void)func_002BF4B0((GuiEquipmentModifyObj *)(a0), (WeaponLinkL2 *)(a1), (a2))) /* merge_units */

/* Applies the current (or alternate-mode) weapon of the active slot. */
void func_002C2290(void)
{
    G2C2290* g = D_0051EE10;
    if (g->f84) {
        O2C2290* o;
        if (g->f88 != g->fFC) o = g->p4C->arr[g->f88];
        else o = g->p4C->arr[0];
        if (o && g->fD0) {
            W2C2290* w = WeaponDb_Get(D_004FFD30, o->h40A);
            if (w->kind == 7) o = w->alt;
            if (o) func_002BF4B0(D_0051EE10, o, D_0051EE10->fD0);
        }
    }
}
#undef D_0051EE10 /* merge_units */
#undef WeaponDb_Get /* merge_units */
#undef func_002BF4B0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C2290 */

/* merge_units: begin func_002C2340 */
#pragma push /* merge_units */
extern int func_002BFA90(GuiEquipmentModifyObj* screen);

int func_002C2340(void) {
    return func_002BFA90(D_0051EE10);
}

void func_002C2350(void) {
}

void func_002C2360(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_002C2340 */

/* merge_units: begin func_002C2370 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "v4_asm_copy.h"
struct V2C2370 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q2C2370 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub2C2370 { char pad[0x10]; Q2C2370 pos; };
struct T2C2370 { V2C2370 v; char pad4[0xC]; Sub2C2370 sub; char pad40[0x20]; unsigned char b50; };
struct A2C2370 { char pad[0x50]; T2C2370* t; char pad54[0x10]; float heading; };
extern "C" {
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A2C2370* a, float dt);
}
extern "C" void func_002C2370(A2C2370* a, float dt)
{
    T2C2370* t = a->t;
    Q2C2370 p;
    if (t->b50)
        t->v.v20();
    Sub2C2370* s = (Sub2C2370*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}
#pragma pop /* merge_units */
/* merge_units: end func_002C2370 */

/* merge_units: begin func_002C23F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "name_tree_find.h"

/* Find a name key in a tree; end() when absent. */
DEFINE_NAME_TREE_FIND(func_002C23F0)
#pragma pop /* merge_units */
/* merge_units: end func_002C23F0 */

/* merge_units: begin func_002C2510 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_init_range.h"

struct VRElem20 { float a; float b; unsigned char c; int d; int e; };
extern "C" { char D_004AC620[] = "vector length error\n"; }
DEFINE_VECTOR_INIT_RANGE(func_002C2510, VRElem20, 0x4CCCCC, D_004AC620, D_0049ED58, 0x5C)
#pragma pop /* merge_units */
/* merge_units: end func_002C2510 */

/* merge_units: begin func_002C26A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_find.h"

/* Find a key in a tree; end() when absent. */
DEFINE_TREE_FIND(func_002C26A0, func_0013C310)
#pragma pop /* merge_units */
/* merge_units: end func_002C26A0 */
