/*
 * main/game: range (2 files, 00136D40-00136DA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

/* merge_units: begin func_00136D40 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00136D40, func_00136600)
#pragma pop /* merge_units */
/* merge_units: end func_00136D40 */

/* merge_units: begin func_00136DA0 */
#pragma push /* merge_units */
extern unsigned char D_00533880;
extern int D_00533888;
void Alloc_Lock(int id);
void* func_00136DA0(void* self)
{
    if (D_00533880)
        Alloc_Lock(9);
    D_00533888++;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136DA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136DA0 */
