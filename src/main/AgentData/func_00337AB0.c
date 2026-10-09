/*
 * Matched functions (byte-identical with the retail executable).
 * Record copy.
 */

#include "types.h"
#include "AgentData_types.h"

extern void* func_0033AA30(void* dst, void* src);

/* Copy-assigns a 20-byte record. */
AgentRec14* func_00337AB0(AgentRec14* dst, AgentRec14* src) {
    AgentRecSub* sub = &dst->sub;
    dst->unk00 = src->unk00;
    func_0033AA30(sub, &src->sub);
    sub->unk0C = src->sub.unk0C;
    return dst;
}
