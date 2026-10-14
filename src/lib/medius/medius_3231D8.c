/*
 * lib/medius: 2 files, 003231D8-00323248
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003231D8 */
extern int D_004E1D50;
extern void func_003232E0(void);
int func_003231D8(int mode)
{
    int ret = 0;
    switch (mode) {
    case 0:
    case 1:
        D_004E1D50 = mode;
        break;
    case 2:
        D_004E1D50 = mode;
        func_003232E0();
        break;
    case 3:
        D_004E1D50 = mode;
        break;
    default:
        D_004E1D50 = 0;
        ret = -1;
        break;
    }
    return ret;
}
/* merge_units: end func_003231D8 */

/* merge_units: begin func_00323248 */
#include "types.h"

int func_00323248(void) { return D_004E1D50; }
/* merge_units: end func_00323248 */
