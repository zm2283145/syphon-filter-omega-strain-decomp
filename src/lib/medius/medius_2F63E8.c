/*
 * lib/medius: 3 files, 002F63E8-002F6418
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F63E8 */
#include "types.h"

extern int rt_comm_platform_get_local_ip(float);

int rt_comm_get_local_ip(float f12) {
    return rt_comm_platform_get_local_ip(f12);
}
/* merge_units: end func_002F63E8 */

/* merge_units: begin func_002F6400 */
extern int rt_comm_platform_get_broadcast_ip(float);

int rt_comm_get_broadcast_ip(float f12) {
    return rt_comm_platform_get_broadcast_ip(f12);
}
/* merge_units: end func_002F6400 */

/* merge_units: begin func_002F6418 */
extern int rt_comm_platform_get_host_by_name(float);

int rt_comm_get_host_by_name(float f12) {
    return rt_comm_platform_get_host_by_name(f12);
}
/* merge_units: end func_002F6418 */
