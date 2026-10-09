/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern SkaFlaggedVec* func_001C5370(SkaFlaggedVec* dst, SkaFlaggedVec* src);
extern SkaFlaggedVec* func_003B6C70(SkaFlaggedVec* dst, SkaFlaggedVec* src);
extern SkaRecordB0* func_003B6CB0(SkaRecordB0* dst, SkaRecordB0* src);

/* Copy-construct: base part, word +0xB0, flagged array +0xB4. */
SkaRecordB0* func_003B6C20(SkaRecordB0* dst, SkaRecordB0* src) {
    func_003B6CB0(dst, src);
    dst->unkB0 = src->unkB0;
    func_003B6C70(&dst->unkB4, &src->unkB4);
    return dst;
}

/* Copy-construct: copy the array part, then the flag byte. */
SkaFlaggedVec* func_003B6C70(SkaFlaggedVec* dst, SkaFlaggedVec* src) {
    func_001C5370(dst, src);
    dst->flag = src->flag;
    return dst;
}
