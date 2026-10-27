/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

typedef struct Float3 {
    float x, y, z;
} Float3;

extern int Libc_Rand(void);

Float3* cEulerAngle_T_1_2_ctor_float_float_float(Float3* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

int RAND(void) {
    return Libc_Rand();
}

float cCameraShake_cPulsedShakeMagnitude_GetCurrVal(char* self) {
    return *(float*)(self + 8);
}

void* cSplinedMotion_float_GetCurrVal(char* self) {
    return self + 8;
}
