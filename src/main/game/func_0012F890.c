/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

extern GameTimerService* D_004FFC2C; /* world +0xDC service */
extern int func_00245560(GameTimerService*, int, float);

/* Starts the global timer: forwards to the timer service. */
int Global_StartGlobalTimer(int id, float value) {
    return func_00245560(D_004FFC2C, id, value);
}
