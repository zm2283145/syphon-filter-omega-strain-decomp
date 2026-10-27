/*
 * SFOGame/Source/GuiSlideShow: 4 files, 003283F0-00328510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003283F0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" void operator_delete(void*);
extern "C" void String_Dtor(void*, short);
extern "C" void std_vector_deleter_Slide_dtor(void*, short);
extern "C" void* GuiSlideShow_Section_dtor(void* self, short del)
{
    if (self) {
        char* m = (char*)self + 0xC;
        if (m) {
            if (m) {
                if (m) std_vector_deleter_Slide_dtor(m, 0);
            }
        }
        if (self) String_Dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003283F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003283F0 */

/* merge_units: begin func_00328470 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nested_null_dtor.h"

DEFINE_NESTED_NULL_DTOR3(cArray_Slide_dtor, std_vector_deleter_Slide_dtor)
static inline void merge_flush_func_00328470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00328470 */

/* merge_units: begin func_003284E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern Rel* std_vector_imp_Slide_ctor(Rel* r);

/* Owning vector constructor. */
OwnedRel* cArray_Slide_ctor(OwnedRel* self) {
    std_vector_imp_Slide_ctor(&self->vec);
    self->owned = 1;
    return self;
}
static inline void merge_flush_func_003284E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003284E0 */

/* merge_units: begin func_00328510 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_NESTED_NULL_DTOR2(std_vector_Slide_dtor, std_vector_deleter_Slide_dtor)
static inline void merge_flush_func_00328510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00328510 */
