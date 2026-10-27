/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

void cSkaParams_SetSwitchNextGoalState(char* self, int i, int value) {
    *(int*)(*(char**)(self + 144) + (i << 3)) = value;
}
