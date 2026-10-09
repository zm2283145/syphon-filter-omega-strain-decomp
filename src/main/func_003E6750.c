/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003E67C0(int obj, int action, int target, int arg, float time);

/* PerformAction without a target object. */
int Global_PerformAction(int obj, int action) {
    return func_003E67C0(obj, action, 0, 0, -1.0f);
}
