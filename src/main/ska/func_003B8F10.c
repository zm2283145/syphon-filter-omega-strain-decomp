/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern SkaFlaggedVec* func_003B8F50(SkaFlaggedVec* dst, SkaFlaggedVec* src);

/* Copy-construct: copy the array part, then the flag byte. */
SkaFlaggedVec* NotifyRange_CopyConstruct(SkaFlaggedVec* dst, SkaFlaggedVec* src) {
    func_003B8F50(dst, src);
    dst->flag = src->flag;
    return dst;
}
