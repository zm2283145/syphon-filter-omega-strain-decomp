/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

typedef struct Float3 {
    float x, y, z;
} Float3;

extern int Random_Next(void);

Float3* Camera_ShakeMatrix(Float3* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

int Random_Next_Thunk(void) {
    return Random_Next();
}

float cCameraShake_cPulsedShakeMagnitude_GetCurrVal(char* self) {
    return *(float*)(self + 8);
}

void* cSplinedMotion_float_GetCurrVal(char* self) {
    return self + 8;
}
