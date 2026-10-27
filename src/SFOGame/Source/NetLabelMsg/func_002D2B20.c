/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

int cNetNPC_IsNetNPC(void) {
    return 1;
}

int cNetNPC_DetermineDeathType(void) {
    return 1;
}

void cNetNPC_SelectTravelMode(void) {
}

int cNetNPC_UseCurrentLookAt(void) {
    return 0;
}

/* Builds the target position as a homogeneous vector (w = 1). The original
 * returns the address of this stack buffer. */
float* cNetNPC_TargetPositionLastSeen(Controller2D* self) {
    float pos[4];
    ControllerTarget* target;
    float x, z, y;  /* declaration order fixes register choice */

    target = self->target;
    z = target->z;
    y = target->y;
    x = target->x;
    pos[0] = x;
    pos[3] = 1.0f;
    pos[1] = y;
    pos[2] = z;
    return pos;
}

int cNetNPC_TargetDirectionValid(void) {
    return 0;
}

void cNetNPC_RequestLookAt_cVector_float_int(void) {
}

void cNetNPC_ResumeAITravelSpeed(void) {
}
