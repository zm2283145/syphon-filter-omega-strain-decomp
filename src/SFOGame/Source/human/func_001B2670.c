/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void cStatesWithHistory_1_ClearAllStates(char* self) {
    *(int*)(self + 8) = 0;
}

/* Shift the three-entry history down by one. */
void cStatesWithHistory_1_NextFrame(int* history) {
    history[0] = history[1];
    history[1] = history[2];
}
