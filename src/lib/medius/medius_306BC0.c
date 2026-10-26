/*
 * lib/medius: 2 files, 00306BC0-00306BD8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00306BC0 */
#include "types.h"

extern int rt_time_elapsed_secs(int, int);

int rt_time_platform_fast_elapsed_secs(int a0, int a1) {
    return rt_time_elapsed_secs(a0, a1);
}
/* merge_units: end func_00306BC0 */

/* merge_units: begin func_00306BD8 */
extern int rt_time_elapsed_msecs(int, int);

int rt_time_platform_fast_elapsed_msecs(int a0, int a1) {
    return rt_time_elapsed_msecs(a0, a1);
}
/* merge_units: end func_00306BD8 */
