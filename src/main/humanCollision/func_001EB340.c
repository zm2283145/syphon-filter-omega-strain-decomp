/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "humanCollision_types.h"

/* Copy-assign of a preset configuration. */
HumanColPresetCfg* HumanColPreset_Copy(HumanColPresetCfg* dst, HumanColPresetCfg* src) {
    dst->range0Min = src->range0Min;
    dst->range0Max = src->range0Max;
    dst->range1Min = src->range1Min;
    dst->range1Max = src->range1Max;
    dst->range2Min = src->range2Min;
    dst->range2Max = src->range2Max;
    dst->enabled = src->enabled;
    return dst;
}

Word* func_001EB380(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* func_001EB390(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
