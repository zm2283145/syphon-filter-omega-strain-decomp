/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

Word* cString4_opAssign(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
