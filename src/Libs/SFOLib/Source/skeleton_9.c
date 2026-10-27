/*
 * Libs/SFOLib/Source/skeleton: 3 files, 003AA4E0-003AA5B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AA4E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_list_cSkeletonDataBankEntryPtr_end_void_2(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cSkeletonDataBankEntryPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cSkeletonDataBankEntryPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003AA4E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA4E0 */

/* merge_units: begin func_003AA510 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize an array of 0x1D0-byte elements: grow with fill, or erase the tail. */
struct Elem_3AA510 { unsigned char b[0x1D0]; };
struct Arr_3AA510;
extern "C" {
void std_vector_imp_cBone_insert(Arr_3AA510* a, Elem_3AA510* pos, unsigned int n, const Elem_3AA510& fill);
void std_vector_imp_cBone_erase(Arr_3AA510* a, Elem_3AA510* first, Elem_3AA510* last);
}
struct Arr_3AA510 {
    int pad0;
    unsigned int count;
    Elem_3AA510* data;
    unsigned int size() const { return count; }
    Elem_3AA510* begin() { return data; }
    Elem_3AA510* end() { return data + count; }
};

extern "C" void std_vector_imp_cBone_resize(Arr_3AA510* a, unsigned int n, const Elem_3AA510& fill)
{
    if (a->size() < n)
        std_vector_imp_cBone_insert(a, a->end(), n - a->size(), fill);
    else if (n < a->size())
        std_vector_imp_cBone_erase(a, a->begin() + n, a->end());
}
static inline void merge_flush_func_003AA510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA510 */

/* merge_units: begin func_003AA5B0 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } D6Scale;
typedef struct { int unk0; unsigned int count; D6Scale* data; } D6Scales;
extern void std_vector_imp_cBoneScale_insert(D6Scales* s, D6Scale* at, unsigned int n, int v);
extern void std_vector_imp_cBoneScale_erase(D6Scales* s, D6Scale* from, D6Scale* to, int v);
#pragma opt_common_subs off
void std_vector_imp_cBoneScale_resize(D6Scales* s, unsigned int n, int v)
{
    unsigned int c = s->count;
    D6Scale* d;
    if (c < n) {
        std_vector_imp_cBoneScale_insert(s, &s->data[s->count], n - c, v);
    } else if (n < c) {
        d = s->data;
        std_vector_imp_cBoneScale_erase(s, &d[n], &d[s->count], v);
    }
}
#pragma opt_common_subs reset
static inline void merge_flush_func_003AA5B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA5B0 */
