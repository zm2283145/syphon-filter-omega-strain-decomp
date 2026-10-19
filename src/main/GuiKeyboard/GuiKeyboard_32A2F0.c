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
DEFINE_RELEASE_BUFFER_CALL_DTOR(func_0032A2F0, func_0032A280,func_0032A370,D_004B8890)
#pragma pop /* merge_units */
/* merge_units: end func_0032A2F0 */

/* merge_units: begin func_0032A370 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element (member at +0x4C, then base), then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_0034F7A0(void* self, short flags);
void* String_Dtor_138350(void* self, short flags);
void* func_00328470(void* self, short flags);
void func_0032A370(void* allocation, int pool, int destroy, char* file, int line);
}
void func_0032A370(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation) {
            func_00328470((char*)allocation + 0xC, -1);
            String_Dtor_138350(allocation, -1);
        }
    }
    Mem_Free(pool, allocation, file, line);
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
