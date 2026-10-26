/*
 * lib/libkernl: 3 files, 00116A70-00116A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00116A70 */
#include "types.h"
extern void SetT2(unsigned int, int, int, int);

void SetT2_COUNT(int a0, int a1, int a2, int a3)
{
    SetT2(0xB0001000, a0, a2, a3);
}
/* merge_units: end func_00116A70 */

/* merge_units: begin func_00116A80 */
void SetT2_MODE(int a0, int a1, int a2, int a3)
{
    SetT2(0xB0001010, a0, a2, a3);
}
/* merge_units: end func_00116A80 */

/* merge_units: begin func_00116A90 */
void SetT2_COMP(int a0, int a1, int a2, int a3)
{
    SetT2(0xB0001020, a0, a2, a3);
}
/* merge_units: end func_00116A90 */
