/*
 * Libs/SFOLib/Source/ska: 3 files, 003AACC0-003AAEE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AACC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_38(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
static inline void merge_flush_func_003AACC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AACC0 */

/* merge_units: begin func_003AAD00 */
#pragma push /* merge_units */
typedef struct Vec3AD { float x; float y; float z; } Vec3AD;
typedef struct { int capacity; int count; Vec3AD *data; } Vec3ADVector;
Vec3AD *std_vector_imp_cBoneScale_erase(Vec3ADVector *v, Vec3AD *first, Vec3AD *last)
{
    Vec3AD *end;
    Vec3AD *s;
    Vec3AD *d;
    if (first == last)
        return first;
    end = v->data + v->count;
    if (end - last != 0) {
        d = first;
        s = last;
        while (s < end) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
            s++;
            d++;
        }
    }
    v->count -= last - first;
    return first;
}
static inline void merge_flush_func_003AAD00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AAD00 */

/* merge_units: begin func_003AAEE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_t.h"
struct E_003AAEE0 { float x, y, z; };
extern "C" { char D_004BCD30[] = "allocator.hh"; }
DEFINE_VECTOR_INSERT_FILL_T(std_vector_imp_cBoneScale_insert, E_003AAEE0, 0x800000, 0x400000, D_004BCD10, D_004BCD30, 0x5C, std_swap_vectordeleterR_vectordeleterR_39, std_vector_deleter_cBone_dtor)
static inline void merge_flush_func_003AAEE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AAEE0 */
