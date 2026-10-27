/*
 * main/GuiEquipmentModify: 6 files, 002C3FF0-002C4380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C3FF0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "string_compare_range.h"

/* String compare of a substring against a buffer. */
extern "C" { char D_004AC680[] = "string compare: pos > len"; }
DEFINE_STRING_COMPARE_RANGE(String_Compare_2C3FF0, D_004AC680)
#pragma pop /* merge_units */
/* merge_units: end func_002C3FF0 */

/* merge_units: begin func_002C4120 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
DEFINE_VECTOR_RELEASE_DTOR(func_002C4120, std_vector_deleter_cSkaSliderValue_clear, opDelete_cSkaSliderValueP_int_bool_charP_etc, D_0049ECD8)
#pragma pop /* merge_units */
/* merge_units: end func_002C4120 */

/* merge_units: begin func_002C41A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_002C41A0, cSplinedMotion_Scalar0To1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002C41A0 */

/* merge_units: begin func_002C4280 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR(func_002C4280, std_vector_deleter_cSkaSwitchValue_clear)
#pragma pop /* merge_units */
/* merge_units: end func_002C4280 */

/* merge_units: begin func_002C4370 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Vector clear (count = 0). */
void func_002C4370(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C4370 */

/* merge_units: begin func_002C4380 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; } G3E_002C4380;
typedef struct { int vt; int count; G3E_002C4380* data; } G3A_002C4380;
extern void cSkaSliderValue_dtor(G3E_002C4380* p, int x);
void func_002C4380(G3A_002C4380* a) {
    G3E_002C4380* begin = a->data;
    G3E_002C4380* p = begin + a->count;
    while (begin < p) {
        p--;
        cSkaSliderValue_dtor(p, -1);
    }
    a->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C4380 */
