/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004AF8B0[];
static void * const dat_00491348[1] = { (void*)D_004AF8B0 };

int rt_upnp_get_version_string(void) {
    int tmp0;

    tmp0 = *(int*)((char*)dat_00491348);
    return tmp0;
}
