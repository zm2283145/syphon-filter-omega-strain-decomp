/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern Unk004E2D58 D_004E2D58;

/* Install a handler (+0x0C) and its argument (+0x10); returns the previous handler. */
int func_0010F730(int handler, int arg) {
    Unk004E2D58* state;
    int old;

    state = (Unk004E2D58*)(int)&D_004E2D58; /* cast keeps the base in a register */
    old = state->handler;
    state->arg = arg;
    state->handler = handler;
    return old;
}
