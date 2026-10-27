/*
 * Libs/SFOLib/Source/gui: 4 files, 004143D0-00414410
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004143D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_48(PtrVec* a, PtrVec* b) {
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
static inline void merge_flush_func_004143D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004143D0 */

/* merge_units: begin func_00414410 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

static inline void Assign414410(ShortStr* self, const ShortStr* src)
{
    bool selfLong = ShortStr_IsLong(self);
    if (!selfLong && !ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR(self, 0, selfLong ? self->u.l.length : ShortStr_ShortLen(self), src);
    }
}

extern "C" void func_00414410(ShortStr* first, unsigned int n, const ShortStr* value)
{
    for (; n != 0; --n, ++first) {
        Assign414410(first, value);
    }
}
static inline void merge_flush_func_00414410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00414410 */

/* merge_units: begin func_004144D0 */
#pragma push /* merge_units */
#pragma cplusplus on

static inline void Assign4144D0(ShortStr* self, const ShortStr* src)
{
    bool selfLong = ShortStr_IsLong(self);
    if (!selfLong && !ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR(self, 0, selfLong ? self->u.l.length : ShortStr_ShortLen(self), src);
    }
}

extern "C" ShortStr* std_copy_backward_cString_copy_backward(ShortStr* first, ShortStr* last, ShortStr* result)
{
    while (first < last) {
        Assign4144D0(--result, --last);
    }
    return result;
}
static inline void merge_flush_func_004144D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004144D0 */

/* merge_units: begin func_004145A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "release_buffer_call_dtor.h"

extern "C" { char D_004BEF90[] = "allocator.hh"; }
DEFINE_RELEASE_BUFFER_CALL_DTOR(std_vector_deleter_cString_dtor, std_vector_deleter_cString_clear,opDelete_cStringP_int_bool_charP_etc,D_004BEF90)
static inline void merge_flush_func_004145A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004145A0 */
