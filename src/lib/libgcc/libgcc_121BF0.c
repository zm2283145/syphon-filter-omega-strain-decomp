/*
 * lib/libgcc: 2 files, 00121BF0-00121C10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00121BF0 */
#include "types.h"

extern int strtol(int, int, int);

int atol(int a0) {
    return strtol(a0, 0, 10);
}
/* merge_units: end func_00121BF0 */

/* merge_units: begin func_00121C10 */
extern int func_00125FE8(int, int, int);

int func_00121C10(int a0, int a1, int a2) {
    return func_00125FE8(a1, a0, a2);
}
/* merge_units: end func_00121C10 */
