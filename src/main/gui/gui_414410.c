/*
 * main/gui: 3 files, 00414410-004145A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00414410 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "short_string_assign.h"

static inline void Assign414410(ShortStr* self, const ShortStr* src)
{
    bool selfLong = ShortStr_IsLong(self);
    if (!selfLong && !ShortStr_IsLong(src)) {
        *self = *src;
    } else {
        func_0013D710(self, 0, selfLong ? self->u.l.length : ShortStr_ShortLen(self), src);
    }
}

extern "C" void func_00414410(ShortStr* first, unsigned int n, const ShortStr* value)
{
    for (; n != 0; --n, ++first) {
        Assign414410(first, value);
    }
}
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
        func_0013D710(self, 0, selfLong ? self->u.l.length : ShortStr_ShortLen(self), src);
    }
}

extern "C" ShortStr* func_004144D0(ShortStr* first, ShortStr* last, ShortStr* result)
{
    while (first < last) {
        Assign4144D0(--result, --last);
    }
    return result;
}
#pragma pop /* merge_units */
/* merge_units: end func_004144D0 */

/* merge_units: begin func_004145A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "release_buffer_call_dtor.h"

extern "C" { char D_004BEF90[] = "allocator.hh"; }
DEFINE_RELEASE_BUFFER_CALL_DTOR(func_004145A0, func_00413F20,func_00414620,D_004BEF90)
#pragma pop /* merge_units */
/* merge_units: end func_004145A0 */
