/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

int NellyRobotOnSase3200(ParamOwner* self) {
    return self->params->unk2A = 1;
}

ParamBlock* NellyRobotOffSase3200(ParamOwner* self) {
    ParamBlock* params = self->params;

    params->unk2A = 0;
    return params;
}

int NellyWhisperOnSase3200(ParamOwner* self) {
    return self->params->unk2C = 1;
}

ParamBlock* NellyWhisperOffSase3200(ParamOwner* self) {
    ParamBlock* params = self->params;

    params->unk2C = 0;
    return params;
}
