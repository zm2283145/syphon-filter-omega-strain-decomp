/*
 * SFOGame/Source/human: 3 files, 001926C0-00192740
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001926C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(int*, int, int);
extern int std_vector_imp_cTimedEvent_insert(PtrVec*, char*, int, int);

/* Tree iterator dereference: value stored at node +0x30. */
char* cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(Iter* it) {
    return (char*)it->p + 48;
}

/* Tree lookup wrapper returning the found iterator through out. */
void cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(int* out) {
    int it[1];
    int a1, a2;

    std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(it, a1, a2);
    *out = it[0];
}

/* push_back for a vector of 20-byte elements. */
int cArray_cTimedEvent_PushBackActual(PtrVec* v, int value) {
    char* data = (char*)v->data;
    int count = v->count;

    return std_vector_imp_cTimedEvent_insert(v, data + count * 20, 1, value);
}

int* cSkaAnimEvent_ctor_char_cSystemR(int* pair, int first, int second) {
    pair[0] = first;
    pair[1] = second;
    return pair;
}
static inline void merge_flush_func_001926C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001926C0 */

/* merge_units: begin func_00192740 */
#pragma push /* merge_units */
float Math_Clampf(float x, float lo, float hi) {
    float r;
    asm { max.s r, x, lo
 min.s r, r, hi }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00192740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00192740 */

/* merge_units: begin func_00192750 */
#pragma push /* merge_units */
typedef struct { float lo; float hi; unsigned char flag; } R_2750;
static inline float fmax_2750(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline float fmin_2750(float a, float b) { float r; asm { min.s r, a, b } return r; }
static inline float Clamp_2750(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
/* set a [lo,hi] range and clamp it into [0,1] (flag: clamp both independently) */
R_2750* cSkaTimeSpan_Normalized_ctor_float_float_bool(R_2750* r, float lo, float hi, unsigned char flag)
{
    r->lo = lo;
    r->hi = hi;
    r->flag = flag;
    if (r->flag) r->hi = Clamp_2750(r->hi, 0.0f, 1.0f); else r->hi = Clamp_2750(r->hi, r->lo, 1.0f);
    if (r->flag) r->lo = Clamp_2750(r->lo, 0.0f, 1.0f); else r->lo = Clamp_2750(r->lo, 0.0f, r->hi);
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00192750(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00192750 */
