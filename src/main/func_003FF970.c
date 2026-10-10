#include "types.h"
float func_003FF970(float target, float cur, float* maxStep) {
    float d = target - cur;
    float step;
    if (d > 3.1415927f) cur += 6.2831855f;
    if (d < -3.1415927f) cur -= 6.2831855f;
    step = (target - cur) / 8.0f;
    d = cur + step;
    if (step < 0.0f) step = -step;
    if (step > *maxStep) *maxStep = step;
    return d;
}