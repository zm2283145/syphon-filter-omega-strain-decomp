/*
 * Matched functions (byte-identical with the retail executable).
 * Record copy.
 */

#include "types.h"
#include "AgentData_types.h"

extern void* std_vector_pod_eRequirementState_ctor(void* dst, void* src);

/* Copy-assigns a 20-byte record. */
AgentRec14* cAgentData_tAchievement_ctor(AgentRec14* dst, AgentRec14* src) {
    AgentRecSub* sub = &dst->sub;
    dst->unk00 = src->unk00;
    std_vector_pod_eRequirementState_ctor(sub, &src->sub);
    sub->unk0C = src->sub.unk0C;
    return dst;
}
