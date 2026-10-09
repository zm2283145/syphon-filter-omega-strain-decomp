/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

float FloatStack_Top(FStack* s) {
    float* p = &s->vals[s->count - 1];
    return *p;
}
