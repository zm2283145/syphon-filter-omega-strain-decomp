/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sets parameters unk30/unk34 and raises flag unk2A. */
ParamBlock* func_00318390(ParamOwner* self, float a, float b) {
    ParamBlock* params = self->params;

    params->unk34 = b;
    params->unk2A = 1;
    params->unk30 = a;
    return params;
}
