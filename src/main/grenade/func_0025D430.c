#include "types.h"
float D_0048AF70 __attribute__((aligned(8))) = 0.100000002f;
float D_0048AF78 __attribute__((aligned(8))) = 0.7f;
float cGrenade_FigureThrowAngle(float t) {
    if (t > 1.0f) t = 1.0f;
    return D_0048AF70 + t * (D_0048AF78 - D_0048AF70);
}