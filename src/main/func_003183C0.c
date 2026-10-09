/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

int func_003183C0(ParamOwner* self) {
    return self->params->unk2A = 1;
}

ParamBlock* func_003183D0(ParamOwner* self) {
    ParamBlock* params = self->params;

    params->unk2A = 0;
    return params;
}

int func_003183E0(ParamOwner* self) {
    return self->params->unk2C = 1;
}

ParamBlock* func_003183F0(ParamOwner* self) {
    ParamBlock* params = self->params;

    params->unk2C = 0;
    return params;
}
