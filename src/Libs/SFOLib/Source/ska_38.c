/*
 * Libs/SFOLib/Source/ska: 7 files, 003B2540-003B26F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B2540 */
#pragma push /* merge_units */
#include "types.h"
typedef struct SkV4 { __int128 q; } SkV4;
typedef struct SkClip { unsigned int type; char p4[0x10]; unsigned char ux, uy, uz; char p17[0x11]; int has; char p2c[4]; SkV4 base; float off[4]; } SkClip;
extern signed char D_004E1D88;
extern SkV4 D_004E1D90;
#pragma peephole off
#pragma opt_propagation off
SkV4 cSkaAnimData_RootOffsetFromFirstFrameTranslation(SkClip* c) {
    if (c->type < 2) {
        if (!D_004E1D88) {
            ((int*)&D_004E1D90)[0] = 0;
            D_004E1D88 = 1;
            ((int*)&D_004E1D90)[1] = 0;
            ((int*)&D_004E1D90)[2] = 0;
            ((int*)&D_004E1D90)[3] = 0;
        }
        return D_004E1D90;
    }
    if (c->type == 2) return c->base;
    {
        SkV4 r; __int128* zp = &r.q; *zp = 0;
        if (c->has) {
            if (c->ux) ((float*)&r)[0] = c->off[0];
            if (c->uy) ((float*)&r)[1] = c->off[1];
            if (c->uz) ((float*)&r)[2] = c->off[2];
        }
        return r;
    }
}
#pragma opt_propagation reset
#pragma peephole reset
static inline void merge_flush_func_003B2540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2540 */

/* merge_units: begin func_003B2630 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

void* cVector_Z_void_2(char* self) {
    return self + 8;
}

/* Clip root-motion axis Z flag set. */
int cSkaAnimData_RootHasDeltaTranslationZ(SkaClipFlags* clip) {
    return 0U < clip->axisZ;
}

void* cVector_Y_void_2(char* self) {
    return self + 4;
}

/* Clip root-motion axis Y flag set. */
int cSkaAnimData_RootHasDeltaTranslationY(SkaClipFlags* clip) {
    return 0U < clip->axisY;
}

/* Clip root-motion axis X flag set. */
int cSkaAnimData_RootHasDeltaTranslationX(SkaClipFlags* clip) {
    return 0U < clip->axisX;
}

void* cVector_X_void_2(void* self) {
    return self;
}

Iter16* cSkaAnimDataFrame_ConstIterator_opInc(Iter16* it) {
    it->p += 16;
    return it;
}
static inline void merge_flush_func_003B2630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B2630 */

/* merge_units: begin func_003B26B0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cSkaAnim_LerpXYZ(V4* a, V4* b, V4* c, V4* d, V4* e) {
    asm {
        lqc2 vf1, 0x0(c)
        lqc2 vf2, 0x0(d)
        lqc2 vf3, 0x0(e)
        vmulax.xyz ACC, vf2, vf3x
        vmaddy.xyz vf4, vf1, vf3y
        vaddx.w vf4, vf1, vf0x
        sqc2 vf4, 0x0(b)
    }
}
static inline void merge_flush_func_003B26B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B26B0 */

/* merge_units: begin func_003B26D0 */
#pragma push /* merge_units */
int cSkaAnimDataFrame_ConstIterator_Vector(char* self) {
    return *(int*)(self + 0);
}
static inline void merge_flush_func_003B26D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B26D0 */

/* merge_units: begin func_003B26E0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
typedef __int128 Q128;
Q128 *cVector_SetZero(Q128 *arg0) {
    *arg0 = 0;
    return arg0;
}
static inline void merge_flush_func_003B26E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B26E0 */

/* merge_units: begin func_003B26F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


int cPointer_cSkaAnimData_opCast_constcSkaAnimDataPtr(char* self) {
    return *(int*)(self + 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B26F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B26F0 */

/* merge_units: begin func_003B2700 */
#pragma push /* merge_units */
typedef struct SkaClip {
    char pad[0x40];
    int grouping;
} SkaClip;

typedef struct GroupingPair {
    SkaClip* clip;
    int grouping;
} GroupingPair;

/* Fills (clip, grouping); clip is NULL unless the clip's grouping is -1. */
void cSkaAnim_PlaybackGroupId(GroupingPair* out, SkaClip* clip) {
    out->clip = clip->grouping == -1 ? clip : 0;
    out->grouping = clip->grouping;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B2700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B2700 */
