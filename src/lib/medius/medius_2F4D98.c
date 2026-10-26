/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004AF128[];
static void * const dat_00490888[2] = { (void*)D_004AF128, (void*)0x0 };

int rt_audio_get_version_string_ptr(void) {
    int tmp0;

    tmp0 = *(int*)((char*)dat_00490888);
    return tmp0;
}
