/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Table entry i (8-byte entries at +0x90). */
SkaPair* cSkaParams_GetSwitchValue(SkaPairTableOwner* owner, int i) {
    return &owner->table[i];
}

/* Address of element i in an array of 36-byte elements at +0x0C. */
char* cSkaSwitchItem_GetTrans(SkaTable0C* t, int i) {
    char* data = t->data;
    return data + i * 36;
}
