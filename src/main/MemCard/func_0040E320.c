/*
 * Matched functions (byte-identical with the retail executable).
 * MemCard.cc
 */

#include "types.h"
#include "MemCard_types.h"

extern int func_0040E5D0(int a0);

/* Refresh the "present" flag from func_0040E5D0; clear unk0C when absent. */
void func_0040E320(MemCardState* state) {
    state->present = func_0040E5D0(state->unk00) != 0;
    if ((state->present != 0) ^ 1) { /* C++ "!bool" codegen */
        state->unk0C = 0;
    }
}
