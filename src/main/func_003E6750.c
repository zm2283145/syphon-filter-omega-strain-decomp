/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int ObjectAction_SendKind7(int obj, int action, int target, int arg, float time);

/* PerformAction without a target object. */
int Global_PerformAction(int obj, int action) {
    return ObjectAction_SendKind7(obj, action, 0, 0, -1.0f);
}
