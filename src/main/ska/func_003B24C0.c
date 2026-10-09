/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

void* func_003B24C0(void* self) {
    return self;
}

int func_003B24D0(char* self) {
    return *(int*)(self + 0);
}

/* angular += rate * dt */
void AnimRoot_AccumAngular(SkaAnimRoot* root, float rate, float dt) {
    root->angular = root->angular + rate * dt;
}

int func_003B2500(char* self) {
    return *(int*)(self + 0);
}

/* Build an XYZ vector with W = 0 from the source's +8/+0xC/+0x10 floats. */
void func_003B2510(SkaVec4* out, SkaPoseSrc* src) {
    float z = src->z;
    float y = src->y;
    float x = src->x;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 0;
}

int func_003B2530(SkaAnimRoot* root) {
    return root->unkC0;
}
