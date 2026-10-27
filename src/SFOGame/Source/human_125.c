/*
 * SFOGame/Source/human: 5 files, 001B7580-001B7940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B7580 */
#pragma push /* merge_units */
#include "types.h"

int func_001B7580(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = a1 & 255;
    v0 = 0 + 1;
    cond = v1 != v0;
    v0 = 0 + -1;
    if (cond) goto L001B75A0;
    *(int*)(char*)a0 = v0;
    *(int*)((char*)a0 + 4) = v0;
    goto L001B75A8;
L001B75A0:;
    *(int*)(char*)a0 = 0;
    *(int*)((char*)a0 + 4) = 0;
L001B75A8:;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_001B7580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B7580 */

/* merge_units: begin func_001B75B0 */
#pragma push /* merge_units */
#include "prio_bitset.h"
PB_DEFINE(PS_1B75B0, 2)
typedef struct { int a; int b; } Pair_1B75B0;
typedef struct { PS_1B75B0 ps; Pair_1B75B0 q; } O_1B75B0;
static inline int* Second_1B75B0(Pair_1B75B0* q) { return &q->b; }

O_1B75B0* func_001B75B0(O_1B75B0* o, int v)
{
    int i;
    PS_1B75B0* p = &o->ps;
    /* (int) cast stops MW folding &o->q + 4 into one addiu (retail keeps both) */
    int* qb = Second_1B75B0((Pair_1B75B0*)(int)&o->q);
    p->w[0] = 0;
    p->w[1] = 0;
    o->q.a = 0;
    o->q.b = 0;
    PS_1B75B0_Set(p, 0);
    for (i = 1; i < 32U; i++) PS_1B75B0_Clr(p, i);
    PS_1B75B0_Set(p, v);
    PB_FIND_TOP(PS_1B75B0, p, i, 32)
    o->q.a = 0;
    *qb = 0;
    return o;
}
static inline void merge_flush_func_001B75B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B75B0 */

/* merge_units: begin func_001B78F0 */
#pragma push /* merge_units */
int cBitArray_8_ctor(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = a1 & 255;
    v0 = 0 + 1;
    cond = v1 != v0;
    v0 = 0 + -1;
    if (cond) goto L001B7908;
    *(int*)(char*)a0 = v0;
    goto L001B7910;
L001B7908:;
    *(int*)(char*)a0 = 0;
L001B7910:;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_001B78F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B78F0 */

/* merge_units: begin func_001B7920 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

void cSplinedMotion_cVector_SetDamp(char* self, float value) {
    *(float*)(self + 80) = value;
}

void cSplinedMotion_float_SetDamp(CurveChannel* self, float value) {
    self->damping = value;
}
static inline void merge_flush_func_001B7920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B7920 */

/* merge_units: begin func_001B7940 */
#pragma push /* merge_units */
typedef struct { unsigned char flag; char pad[3]; float t; } K_1B7940;
typedef struct { int cap; int count; K_1B7940* data; } KV_1B7940;
typedef struct { char pad[0x20]; char chan[0x38]; KV_1B7940 keys; } O_1B7940;
extern void std_vector_imp_cTargetZRotationStackSlot_insert(KV_1B7940* v, K_1B7940* pos, int n, K_1B7940* k);
extern K_1B7940* cArray_cTargetZRotationStackSlot_Back(KV_1B7940* v);
extern void cSplinedMotion_float_SetTargetVal(void* chan, float* t);
extern void cSplinedMotion_float_RestartTransition(void* chan, float d);
int cHumanMotionParams_PushTargetZRotationOnStack(O_1B7940* o, float t, float d)
{
    K_1B7940 k;
    k.t = t;
    k.flag = 1;
    std_vector_imp_cTargetZRotationStackSlot_insert(&o->keys, o->keys.data + o->keys.count, 1, &k);
    cSplinedMotion_float_SetTargetVal(o->chan, &cArray_cTargetZRotationStackSlot_Back(&o->keys)->t);
    cSplinedMotion_float_RestartTransition(o->chan, d);
    return o->keys.count - 1;
}
static inline void merge_flush_func_001B7940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B7940 */
