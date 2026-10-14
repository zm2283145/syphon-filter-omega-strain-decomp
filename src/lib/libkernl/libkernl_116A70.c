/*
 * lib/libkernl: 3 files, 00116A70-00116A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00116A70 */
#include "types.h"
extern void func_00116A00(unsigned int, int, int, int);

void func_00116A70(int a0, int a1, int a2, int a3)
{
    func_00116A00(0xB0001000, a0, a2, a3);
}
/* merge_units: end func_00116A70 */

/* merge_units: begin func_00116A80 */
void func_00116A80(int a0, int a1, int a2, int a3)
{
    func_00116A00(0xB0001010, a0, a2, a3);
}
/* merge_units: end func_00116A80 */

/* merge_units: begin func_00116A90 */
void func_00116A90(int a0, int a1, int a2, int a3)
{
    func_00116A00(0xB0001020, a0, a2, a3);
}
/* merge_units: end func_00116A90 */
