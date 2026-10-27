/*
 * SFOGame/Source/gameFrontEnd: 1 file, 002CA9B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CA9B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}
extern "C" void sfo_free(void* p)
{
    AllocGuard g;
    char f[] = "sfo_malloc: should only be used in rtime lib";
    cMemMan_Deallocate(2, p, f, 0);
}
static inline void merge_flush_func_002CA9B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CA9B0 */
