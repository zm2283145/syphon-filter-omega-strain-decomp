/*
 * Matched functions (byte-identical with the retail executable).
 * MemCard.cc
 */

#include "types.h"
#include "MemCard_types.h"

extern int MemCard_MemCardMain(int a0);

/* Refresh the "present" flag from MemCard_MemCardMain; clear unk0C when absent. */
void cMemCard_NextFrame(MemCardState* state) {
    state->present = MemCard_MemCardMain(state->unk00) != 0;
    if ((state->present != 0) ^ 1) { /* C++ "!bool" codegen */
        state->unk0C = 0;
    }
}
