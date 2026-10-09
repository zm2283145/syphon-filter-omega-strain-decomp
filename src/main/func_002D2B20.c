/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

int func_002D2B20(void) {
    return 1;
}

int func_002D2B30(void) {
    return 1;
}

void func_002D2B40(void) {
}

int func_002D2B50(void) {
    return 0;
}

/* Builds the target position as a homogeneous vector (w = 1). The original
 * returns the address of this stack buffer. */
float* func_002D2B60(Controller2D* self) {
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

int func_002D2BA0(void) {
    return 0;
}

void func_002D2BB0(void) {
}

void func_002D2BC0(void) {
}
