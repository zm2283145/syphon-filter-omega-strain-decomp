#include "types.h"
static const float dat_0048AF60[2] = { 5.0f, 0.0f };
static const float dat_0048AF68[2] = { 100.0f, 0.0f };
float cGrenade_FigureThrowDist(float t) {
    if (t > 1.0f) t = 1.0f;
    return (*(float*)dat_0048AF60) + t * ((*(float*)dat_0048AF68) - (*(float*)dat_0048AF60));
}