/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Iterator equality. */
int func_003B1710(Iter* a, Iter* b) {
    return a->p == b->p;
}

void* AnimBlend_GetGroupCollection(char* self) {
    return self + 232;
}
