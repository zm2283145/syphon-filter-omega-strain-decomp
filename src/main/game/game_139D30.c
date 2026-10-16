/*
 * main/game: 2 files, 00139D30-00139DF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00139D30 */
#pragma push /* merge_units */
#include "types.h"
#include "loose00_types.h"

typedef struct S00139D30 {
    Vec4 a;                 /* 0x00 */
    Vec4 b;                 /* 0x10 */
    unsigned char c;        /* 0x20 */
    int d;                  /* 0x24 */
    int e;                  /* 0x28 */
    LosResult r;            /* 0x30 */
    int w0, w1, w2, w3;     /* 0xD0 */
} S00139D30;

extern int Vec4_Assign(Vec4*, Vec4*);
extern int func_00139B00(LosHitInfo*, LosHitInfo*);

/* GCC-style volatile lq/sq quad copy (c57da idiom) */
static inline void V4_Copy(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void R_Copy(LosResult* dst0, const LosResult* src) {
    LosResult* dst = dst0;
    dst->status = src->status;
    Vec4_Assign(&dst->point, (Vec4*)&src->point);
    func_00139B00(&dst->hit, (LosHitInfo*)&src->hit);
    dst->unk90 = src->unk90;
}
S00139D30* func_00139D30(S00139D30* d, S00139D30* s) {
    V4_Copy(&d->a, &s->a);
    V4_Copy(&d->b, &s->b);
    d->c = s->c;
    d->d = s->d;
    d->e = s->e;
    R_Copy(&d->r, &s->r);
    d->w0 = s->w0;
    d->w1 = s->w1;
    d->w2 = s->w2;
    d->w3 = s->w3;
    return d;
}
#pragma pop /* merge_units */
/* merge_units: end func_00139D30 */

/* merge_units: begin func_00139DF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
extern "C" { char D_0049AE20[] = "allocator.hh"; }
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00139DF0, func_0013B260, D_0049AE20)
#pragma pop /* merge_units */
/* merge_units: end func_00139DF0 */
