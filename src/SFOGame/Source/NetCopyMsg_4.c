/*
 * SFOGame/Source/NetCopyMsg: 5 files, 002C5D90-002C5F20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C5D90 */
#pragma push /* merge_units */
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
typedef struct { float x, y, z; } V3_2C5D90;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_2C5D90;
typedef struct {
    V3_2C5D90 a; char pC[4];
    V4_2C5D90 q;
    signed char c20; char p21[3];
    float f24, f28, f2C, f30, f34;
    unsigned char b38, b39, b3A, b3B, b3C;
} S2C5D90;
/* Member-wise copy (assignment operator). */
S2C5D90* cTargetAwareness_opAssign(S2C5D90* d, S2C5D90* s)
{
    { float x = s->a.x; float y = s->a.y; d->a.x = x; d->a.y = y; d->a.z = s->a.z; }
    VCopyF(&d->q, &s->q);
    d->c20 = s->c20;
    d->f24 = s->f24; d->f28 = s->f28; d->f2C = s->f2C; d->f30 = s->f30; d->f34 = s->f34;
    d->b38 = s->b38; d->b39 = s->b39; d->b3A = s->b3A; d->b3B = s->b3B; d->b3C = s->b3C;
    return d;
}
static inline void merge_flush_func_002C5D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C5D90 */

/* merge_units: begin func_002C5E20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

/* Rec1C copy (assignment). */
Rec1C* cPathTransfer_opAssign(Rec1C* dst, Rec1C* src) {
    Q q;
    int unk10;
    int unk14;
    int unk18;

    q = src->q;
    dst->q = q;
    unk10 = src->unk10;
    dst->unk10 = unk10;
    unk14 = src->unk14;
    dst->unk14 = unk14;
    unk18 = src->unk18;
    dst->unk18 = unk18;
    return dst;
}
static inline void merge_flush_func_002C5E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C5E20 */

/* merge_units: begin func_002C5E50 */
#pragma push /* merge_units */
/* peephole off keeps the unfolded addiu+lq/sq 0(reg) quad copies */
#pragma peephole off

typedef struct {
    Q q0, q1, q2, q3;
    float f40, f44;
    int i48, i4C, i50, i54, i58, i5C;
    unsigned char b60;
} Rec64;

/* Rec64 copy (assignment). */
Rec64* cPathNavigatorTransfer_opAssign(Rec64* dst, Rec64* src) {
    Q q0; Q q1; Q q2; Q q3;
    float f40, f44;
    int i48, i4C, i50, i54, i58, i5C;
    unsigned char b60;

    q0 = src->q0; dst->q0 = q0;
    q1 = src->q1; dst->q1 = q1;
    q2 = src->q2; dst->q2 = q2;
    q3 = src->q3; dst->q3 = q3;
    f40 = src->f40; dst->f40 = f40;
    f44 = src->f44; dst->f44 = f44;
    i48 = src->i48; dst->i48 = i48;
    i4C = src->i4C; dst->i4C = i4C;
    i50 = src->i50; dst->i50 = i50;
    i54 = src->i54; dst->i54 = i54;
    i58 = src->i58; dst->i58 = i58;
    i5C = src->i5C; dst->i5C = i5C;
    b60 = src->b60; dst->b60 = b60;
    return dst;
}
static inline void merge_flush_func_002C5E50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C5E50 */

/* merge_units: begin func_002C5EE0 */
#pragma push /* merge_units */
/* Rec22 copy (assignment). */
Rec22* cAiTargetTransfer_opAssign(Rec22* dst, Rec22* src) {
    Q q;
    float unk10;
    float unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char unk21;

    q = src->q;
    dst->q = q;
    unk10 = src->unk10;
    dst->unk10 = unk10;
    unk14 = src->unk14;
    dst->unk14 = unk14;
    unk18 = src->unk18;
    dst->unk18 = unk18;
    unk1C = src->unk1C;
    dst->unk1C = unk1C;
    unk20 = src->unk20;
    dst->unk20 = unk20;
    unk21 = src->unk21;
    dst->unk21 = unk21;
    return dst;
}
static inline void merge_flush_func_002C5EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C5EE0 */

/* merge_units: begin func_002C5F20 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on

struct V4Q_5F20 {
    float x, y, z, w;
    V4Q_5F20& operator=(const V4Q_5F20& o) { __int128 q; const V4Q_5F20* s = &o; asm volatile { lq q, 0(s)
 sq q, 0(this) } return *this; }
} __attribute__((aligned(16)));

struct Fl_5F20 {
    float v;
    Fl_5F20& operator=(const Fl_5F20& o) { float f; const Fl_5F20* s = &o; Fl_5F20* t = this; asm volatile { lwc1 f, 0(s)
 swc1 f, 0(t) } return *this; }
};

struct Rec5F20 {
    float f00;
    int f04;
    int f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    float f58;
    int arr[9];
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    V4Q_5F20 qA0;
    Fl_5F20 fB0;
    int fB4;
    int fB8;
    int fBC;
    int fC0;
    int fC4;
    float fC8;
    int fCC;
    int fD0;
    int fD4;
    int fD8;
    signed char fDC;
    signed char fDD;
    signed char fDE;
    signed char fDF;
    signed char fE0;
    unsigned char fE1;
    float fE4;
};

extern "C" Rec5F20* cNpcTransfer_opAssign(Rec5F20* d, Rec5F20* s)
{
    int i;

    d->f00 = s->f00;
    d->f04 = s->f04;
    d->f08 = s->f08;
    d->f0C = s->f0C;
    d->f10 = s->f10;
    d->f14 = s->f14;
    d->f18 = s->f18;
    d->f1C = s->f1C;
    d->f20 = s->f20;
    d->f24 = s->f24;
    d->f28 = s->f28;
    d->f2C = s->f2C;
    d->f30 = s->f30;
    d->f34 = s->f34;
    d->f38 = s->f38;
    d->f3C = s->f3C;
    d->f40 = s->f40;
    d->f44 = s->f44;
    d->f48 = s->f48;
    d->f4C = s->f4C;
    d->f50 = s->f50;
    d->f54 = s->f54;
    d->f58 = s->f58;
    for (i = 0; i < 9; i++)
        d->arr[i] = s->arr[i];
    d->f80 = s->f80;
    d->f84 = s->f84;
    d->f88 = s->f88;
    d->f8C = s->f8C;
    d->f90 = s->f90;
    d->f94 = s->f94;
    d->qA0 = s->qA0;
    d->fB0 = s->fB0;
    d->fB4 = s->fB4;
    d->fB8 = s->fB8;
    d->fBC = s->fBC;
    d->fC0 = s->fC0;
    d->fC4 = s->fC4;
    d->fC8 = s->fC8;
    d->fCC = s->fCC;
    d->fD0 = s->fD0;
    d->fD4 = s->fD4;
    d->fD8 = s->fD8;
    d->fDC = s->fDC;
    d->fDD = s->fDD;
    d->fDE = s->fDE;
    d->fDF = s->fDF;
    d->fE0 = s->fE0;
    d->fE1 = s->fE1;
    d->fE4 = s->fE4;
    return d;
}

#pragma pop
static inline void merge_flush_func_002C5F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C5F20 */
