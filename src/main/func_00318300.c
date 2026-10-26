/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sets parameter unk1C and marks it dirty. */
ParamBlock* NellySetPitchOffsetSase3200(ParamOwner* self, float value) {
    ParamBlock* params = self->params;

    params->unk1C = value;
    params->unk28 = 1;
    return params;
}
