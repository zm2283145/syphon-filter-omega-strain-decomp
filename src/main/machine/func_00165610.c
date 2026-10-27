/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int g_FrameCounter;  /* counter */

void cMachine_CalcFrameTime(void) {
    g_FrameCounter = g_FrameCounter + 1;
}
