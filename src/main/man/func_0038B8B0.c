/*
 * Matched functions (byte-identical with the retail executable).
 * Stores a value in a 256-entry table indexed by a byte.
 */

#include "types.h"
#include "man_types.h"

extern int D_004933D0[256];

void func_0038B8B0(int index, int value) {
    D_004933D0[index & 0xFF] = value;
}
