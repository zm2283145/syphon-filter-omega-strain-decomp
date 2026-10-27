/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* "rt_udp version: 01.02.0052" */
char D_00491328[] __attribute__((aligned(8))) = "rt_udp version: 01.02.0052"; /* 8-aligned in the original data */

/* Library version string getter: "rt_udp version: 01.02.0052". */
char* rt_udp_get_version_string(void) {
    return D_00491328;
}
