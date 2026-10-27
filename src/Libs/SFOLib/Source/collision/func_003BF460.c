/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int cCollisionProbe_SphereSweptRay_DetectForCollision_uchar_uchar(int);

int ColQuery_ExecuteThunk(int a0) {
    return cCollisionProbe_SphereSweptRay_DetectForCollision_uchar_uchar(a0);
}
