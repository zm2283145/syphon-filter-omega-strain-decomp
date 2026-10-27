/*
 * SFOGame/Source/humanCollision: 3 files, 001E9250-001E9300
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E9250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_001E9250(PtrVec* v) {
    return v->data + v->count;
}

void func_001E9270(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* func_001E9280(PtrVec* v) {
    return v->data;
}
static inline void merge_flush_func_001E9250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9250 */

/* merge_units: begin func_001E9290 */
#pragma push /* merge_units */
typedef struct { char pad0[2]; unsigned char valid; char pad1[0x6D]; int mask; char pad2[0x2C]; } HgSlot;
typedef struct { char pad0[0x3E0]; HgSlot slots[7]; } HgActor;
int cHumanCollisionRoutine_CanClimbUpFromHang(HgActor* a)
{
    HgSlot* s;
    s = &a->slots[6];
    if (s->valid) {
        return ((s->mask >> 4) & 1) != 0;
    }
    s = &a->slots[5];
    if (s->valid) {
        return ((s->mask >> 4) & 1) != 0;
    }
    s = &a->slots[3];
    if (s->valid) {
        return ((s->mask >> 4) & 1) != 0;
    }
    return 0;
}
static inline void merge_flush_func_001E9290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9290 */

/* merge_units: begin func_001E9300 */
#pragma push /* merge_units */
#include "vu0_addeq.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_9300;
typedef struct { char p0[0x40]; V_9300 a; char p50[0x20]; V_9300 b; char p80[0x2F0 - 0x80]; V_9300 c; V_9300 d; } Act_9300;
/* shift both teleport lanes and two positions by dv (VU0 adds) */
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cHumanCollisionRoutine_Move(Act_9300* act, V_9300* dv)
{
    V_9300 t;
    {
        /* by-value copy of the offset (VCopyF idiom: lq free, sq unfolded) */
        V_9300* td;
        __int128 q;
        asm { .set reorder; lq q, 0(dv) }
        td = &t;
        asm { sq q, 0(td) }
    }
    VU0_ADDEQ3(V_9300, &act->c, &t);
    VU0_ADDEQ3(V_9300, &act->d, &t);
    VU0_ADDEQ1(V_9300, &act->a, dv);
    VU0_ADDEQ1(V_9300, &act->b, dv);
}
#pragma pop
static inline void merge_flush_func_001E9300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E9300 */
