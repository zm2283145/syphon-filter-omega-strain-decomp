/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Table entry i (8-byte entries at +0x90). */
SkaPair* func_003B0730(SkaPairTableOwner* owner, int i) {
    return &owner->table[i];
}

/* Address of element i in an array of 36-byte elements at +0x0C. */
char* func_003B0740(SkaTable0C* t, int i) {
    char* data = t->data;
    return data + i * 36;
}
