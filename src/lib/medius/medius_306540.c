/*
 * lib/medius: 2 files, 00306540-00306558
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00306540 */
#include "types.h"

extern int rt_time_sleep_usecs_platform(int);

int rt_time_sleep_usecs(int a0) {
    return rt_time_sleep_usecs_platform(a0);
}
/* merge_units: end func_00306540 */

/* merge_units: begin func_00306558 */
extern int rt_time_platform_get_time_string(int);

int rt_time_get_time_string(int a0) {
    return rt_time_platform_get_time_string(a0);
}
/* merge_units: end func_00306558 */
