/*
 * main/GuiKeyboard: 4 files, 0032A2F0-0032A4F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032A2F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "release_buffer_call_dtor.h"

extern "C" { char D_004B8890[] = "allocator.hh"; }
DEFINE_RELEASE_BUFFER_CALL_DTOR(std_vector_deleter_Section_dtor, std_vector_deleter_Section_clear,opDelete_SectionP_int_bool_charP_etc,D_004B8890)
#pragma pop /* merge_units */
/* merge_units: end func_0032A2F0 */

/* merge_units: begin func_0032A370 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element (member at +0x4C, then base), then cMemMan_Deallocate under the guard. */
extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void* cArray_StatsRequirement_dtor(void* self, short flags);
void* String_Dtor_138350(void* self, short flags);
void* cArray_Slide_dtor(void* self, short flags);
void opDelete_SectionP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line);
}
void opDelete_SectionP_int_bool_charP_etc(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation) {
            cArray_Slide_dtor((char*)allocation + 0xC, -1);
            String_Dtor_138350(allocation, -1);
        }
    }
    cMemMan_Deallocate(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032A370 */

/* merge_units: begin func_0032A460 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_copy_ctor.h"

/* Copy-construct a string. */
DEFINE_SHORT_STRING_COPY_CTOR(func_0032A460)
#pragma pop /* merge_units */
/* merge_units: end func_0032A460 */

/* merge_units: begin func_0032A4F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"

/* Replace a range of a string with another string. */
DEFINE_SHORT_STRING_REPLACE(func_0032A4F0)
#pragma pop /* merge_units */
/* merge_units: end func_0032A4F0 */
