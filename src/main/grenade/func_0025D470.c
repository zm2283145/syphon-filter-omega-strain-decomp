#include "types.h"
extern float D_0048AF60;
extern float D_0048AF68;
float func_0025D470(float t) {
    if (t > 1.0f) t = 1.0f;
    return D_0048AF60 + t * (D_0048AF68 - D_0048AF60);
}