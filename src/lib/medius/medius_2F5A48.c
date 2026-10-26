/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004AF148[];
static void * const dat_00490898[1] = { (void*)D_004AF148 };

int rt_comm_get_version_string_ptr(void) {
    int tmp0;

    tmp0 = *(int*)((char*)dat_00490898);
    return tmp0;
}
