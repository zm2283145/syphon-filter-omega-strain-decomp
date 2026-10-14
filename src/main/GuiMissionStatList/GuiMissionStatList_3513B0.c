/*
 * main/GuiMissionStatList: 3 files, 003513B0-00351520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003513B0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_release_dtor.h"

extern "C" { char D_004BACA8[] = "allocator.hh"; }
DEFINE_VECTOR_RELEASE_DTOR(func_003513B0, func_00351320, func_00351430, D_004BACA8)
#pragma pop /* merge_units */
/* merge_units: end func_003513B0 */

/* merge_units: begin func_00351430 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element (member at +0x4C, then base), then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_0034F7A0(void* self, short flags);
void* func_00138350(void* self, short flags);
void func_00351430(void* allocation, int pool, int destroy, char* file, int line);
}
void func_00351430(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation) {
            func_0034F7A0((char*)allocation + 0x4C, -1);
            func_00138350(allocation, -1);
        }
    }
    Mem_Free(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_00351430 */

/* merge_units: begin func_00351520 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"

/* Replace a range of a string with another string. */
DEFINE_SHORT_STRING_REPLACE(func_00351520)
#pragma pop /* merge_units */
/* merge_units: end func_00351520 */
