/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004AF450[];
static void * const dat_004908E8[1] = { (void*)D_004AF450 };

int func_002FB620(void) {
    int tmp0;

    tmp0 = *(int*)((char*)dat_004908E8);
    return tmp0;
}
