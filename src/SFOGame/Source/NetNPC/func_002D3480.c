/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

float cNetNPC_GetRawTravelSpeed(Controller2D* self) {
    return self->unk200;
}

int cNetNPC_GetTravelSpeed_void(void) {
    return 2;
}
