/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern SkaFlaggedVec* func_003B4EB0(SkaFlaggedVec* dst, SkaFlaggedVec* src);

/* Copy-construct: copy the array part, then the flag byte. */
SkaFlaggedVec* func_003B4E70(SkaFlaggedVec* dst, SkaFlaggedVec* src) {
    func_003B4EB0(dst, src);
    dst->flag = src->flag;
    return dst;
}
