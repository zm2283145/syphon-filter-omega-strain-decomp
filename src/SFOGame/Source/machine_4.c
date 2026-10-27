/*
 * SFOGame/Source/machine: 1 file, 00166650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00166650 */
#pragma push /* merge_units */
#include "types.h"
extern int D_0048A038;
extern void VBLANKInterruptHandler(void);
extern int AddIntcHandler(int id, void (*fn)(void), int arg);
extern void EnableIntc(int id);
/* Register handler 2 and start it. */
void RegisterVBLANKHandler(void)
{
    D_0048A038 = AddIntcHandler(2, VBLANKInterruptHandler, 0);
    EnableIntc(2);
}
static inline void merge_flush_func_00166650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00166650 */
