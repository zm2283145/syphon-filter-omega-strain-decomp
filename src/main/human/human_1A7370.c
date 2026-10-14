/*
 * main/human: range (3 files, 001A7370-001A7440)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vc_copy.h"
#include "vu0_quat_rot.h"

/* merge_units: begin func_001A7370 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* func_001A7370(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(b)
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
        sqc2 vf6, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7370 */

/* merge_units: begin func_001A73C0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_73C0;
typedef struct { char pad[0xB0]; void* root; } Obj_73C0;
extern int Root_GetParent(void* r);
extern void Root_RefreshWorldCache(void* r);
extern char* Root_Identity(void* r);
#pragma push
#pragma opt_propagation off
V4_73C0* func_001A73C0(Obj_73C0* o, V4_73C0* out)
{
    void* r = o->root;
    V4_73C0* v;
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        v = (V4_73C0*)Root_Identity(r);
        asm { .set reorder } /* empty barrier keeps the then-arm separate (known trick) */
    } else {
        v = (V4_73C0*)(Root_Identity(r) + 0x50);
    }
    VCopyFF(out, v);
    asm {
        lqc2 vf1, 0x0(out)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(out)
    }
    return out;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A73C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A73C0 */

/* merge_units: begin func_001A7440 */
#pragma push /* merge_units */
typedef struct { V4 rot; V4 pos; } P;
typedef struct { char pad[0xB0]; void* root; } Obj;
static inline V4* CopyVec(V4* d, V4* s) { *d = *s; return d; }
static inline P* PCopy(P* d, P* s) { CopyVec(&d->rot, &s->rot); CopyVec(&d->pos, &s->pos); return d; }
static inline P* PInvert(P* p) {
    VU0_NEG3(p, p)
    { V4* b; V4* a; a = &p->pos; b = &p->pos; VU0_NEG3(a, b) }
    /* empty barrier: changes block scheduling so the then-arm's call arg lands in the jal delay slot */
    { V4* v; asm { .set reorder } v = &p->pos; VU0_QROT(v, p, v) }
    return p;
}
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
/* Copies the parent's world placement into out and inverts it in place. */
P* Root_GetParentInverse(Obj* o, P* out)
{
    void* r = o->root;
    P* v;
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        v = (P*)Root_Identity(r);
        asm { .set reorder }
    } else {
        v = (P*)(Root_Identity(r) + 0x50);
    }
    PCopy(out, v);
    PInvert(out);
    return out;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A7440(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A7440 */
