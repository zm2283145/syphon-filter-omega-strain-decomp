/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* False for 0, -80 and -104; true otherwise. */
int func_002FE8B0(int code) {
    int result = 0;

    if (code != 0 && code != -80) {
        result = code != -104;
    }
    return result;
}
