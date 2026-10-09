/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between NPCInfoObject.cc (ends 0x00437490) and GenInfoObject.cc.
 */

#include "types.h"

/* Clears four bytes. */
char* func_004375B0(char* bytes) {
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    bytes[3] = 0;
    return bytes;
}
