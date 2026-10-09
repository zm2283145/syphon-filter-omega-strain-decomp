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

Float3* func_0017DE50(Float3* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

int func_0017DE70(void) {
    return Random_Next();
}

float func_0017DE80(char* self) {
    return *(float*)(self + 8);
}

void* func_0017DE90(char* self) {
    return self + 8;
}
