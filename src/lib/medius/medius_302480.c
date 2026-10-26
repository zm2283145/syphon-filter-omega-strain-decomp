/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int rt_mutex_platform_begin_critical_section(void);

int rt_mutex_begin_critical_section(void) {
    int tmp0;

    tmp0 = rt_mutex_platform_begin_critical_section();
    return tmp0;
}

int rt_mutex_end_critical_section(void) {
    int tmp0;

    tmp0 = rt_mutex_platform_begin_critical_section();
    return tmp0;
}
