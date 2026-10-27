/*
 * Libs/SFOLib/Source/nellymoser_wrapper: 1 file, 0042C960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042C960 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" void* cMemMan_Allocate(int, int, char*, int);
extern "C" void* sfo_calloc(int n, int m) {
    AllocGuard g;
    char msg[] = "sfo_malloc: should only be used in rtime lib";
    return cMemMan_Allocate(2, n * m, msg, 0);
}
static inline void merge_flush_func_0042C960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042C960 */
