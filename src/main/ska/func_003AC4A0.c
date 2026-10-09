/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern char** func_003AC4F0(void* blocks, unsigned int block);
extern void* func_003AC520(void* self);

/* Address of entry (first + index) in a block array of 248-byte entries, eight per block. */
char* func_003AC4A0(SkaBlockArray* self, int index) {
    int i = index + self->first;
    return *func_003AC4F0(func_003AC520(self), (unsigned int)i >> 3) + (i & 7) * 248;
}
