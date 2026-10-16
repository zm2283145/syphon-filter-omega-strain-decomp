/*
 * main/human: range (4 files, 00190FF0-00191100)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00190FF0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00190FF0)
#pragma pop /* merge_units */
/* merge_units: end func_00190FF0 */

/* merge_units: begin func_00191040 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x; float y; unsigned char c; } A_191040;
typedef struct { int p; int q; } B_191040;
typedef struct { A_191040 a; B_191040 b; } P_191040;
P_191040* func_00191040(P_191040* d, A_191040* a, B_191040* b)
{
    A_191040 t;
    t = *a;
    d->a.x = t.x;
    d->a.y = t.y;
    d->a.c = t.c;
    d->b.p = b->p;
    d->b.q = b->q;
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00191040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00191040 */

/* merge_units: begin func_001910A0 */
#pragma push /* merge_units */
typedef struct RootObj RootObj;
extern void* Root_GetParent(RootObj* r);
extern void Root_RefreshWorldCache(RootObj* r);
extern char* Root_Identity(RootObj* r);
char* Root_ResolveWorldPlacement(RootObj* r) {
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        return Root_Identity(r);
    }
    return Root_Identity(r) + 0x50;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001910A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001910A0 */

/* merge_units: begin func_00191100 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } Plc;
typedef struct { int w[1]; } It;
static inline void QRot(V4* v, V4* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3(V4* s, V4* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct Nd { char pad[0x50]; Plc p; char pad70[0x30]; unsigned char bA0; char padA1[0xF]; int bB0; };
extern "C" {
#if 0 /* merge_units */
void* Root_GetParent(Nd* n);
#endif /* merge_units */
#define Root_GetParent(a0) (Root_GetParent((RootObj *)(a0))) /* merge_units */

Plc* Root_GetWorldPlacement(void* r);
void Transform_SetOrientation(Plc* d, Plc* s);
void Placement_Invert(Plc* p);
void func_00132840(V4* q);
void Quat_Multiply(V4* a, V4* b, V4* c);
void func_00132800(V4* d, V4* s);
int func_001913E0(Nd* n);
void* func_001913D0(Nd* n);
void func_001913C0(It* out, void* vec);
void func_001913A0(It* out, void* vec);
bool func_001912A0(It* a, It* b);
Nd** func_00191390(It* it);
void func_001912E0(Nd* n);
void func_001912C0(It* it);
}
static inline void Cp(Plc* d, Plc* s) { QC(&d->rot, &s->rot); QC(&d->pos, &s->pos); }
extern "C" void Root_SetWorldPlacement(Nd* self, Plc* src)
{
    { Plc* d = &self->p; QC(&d->rot, &src->rot); QC(&d->pos, &src->pos); }
    if (self->bB0) {
        Plc inv;
        V4 r;
        V4 m;
        Plc* p;
        Plc* ip;
        Transform_SetOrientation(&inv, Root_GetWorldPlacement(Root_GetParent(self)));
        Placement_Invert(&inv);
        ip = &inv;
        p = &self->p;
        func_00132840(&m);
        Quat_Multiply(&m, &ip->rot, &p->rot);
        func_00132800(&r, &m);
        { void* xx = &r; /* dead on purpose: retail keeps this addiu */ }
        QC(&p->rot, &r);
        V4* v = &p->pos;
        QRot(v, &ip->rot);
        VAdd3(&ip->pos, &p->pos);
    }
    self->bA0 = 1;
    if (func_001913E0(self)) {
        It it, end;
        func_001913C0(&it, func_001913D0(self));
        func_001913A0(&end, func_001913D0(self));
        for (; func_001912A0(&it, &end); func_001912C0(&it))
            func_001912E0(*func_00191390(&it));
    }
}
#undef Root_GetParent /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00191100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00191100 */
