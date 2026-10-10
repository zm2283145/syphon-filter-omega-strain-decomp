#include "types.h"
typedef struct {
    int f0;
    float slopeA;
    int f8;
    float slopeB;
    float scale;
    float invScale;
} AnimScalar_1E5280;
void AnimScalar_RescaleSlopes(AnimScalar_1E5280* p, float s) {
    float r = s * p->invScale;
    float inv;
    p->slopeA *= r;
    p->slopeB *= r;
    p->scale = s;
    inv = (s != 0.0f) ? 1.0f / s : 0.0f;
    p->invScale = inv;
}