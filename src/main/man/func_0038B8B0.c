/*
 * Matched functions (byte-identical with the retail executable).
 * Stores a value in a 256-entry table indexed by a byte.
 */

#include "types.h"
#include "man_types.h"

extern int WoundEffectTable[256];

void WoundEffectIds_Set(int index, int value) {
    WoundEffectTable[index & 0xFF] = value;
}
