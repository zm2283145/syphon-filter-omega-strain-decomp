/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00211190(Args* a) {
    union { int i; float f; } u;
    u.i = a->arg1;
    a->obj->speed = u.f;
    return 0;
}
