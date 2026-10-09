/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int ColQuery_Execute(int);

int ColQuery_ExecuteThunk(int a0) {
    return ColQuery_Execute(a0);
}
