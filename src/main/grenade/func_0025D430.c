#include "types.h"
extern float D_0048AF70;
extern float D_0048AF78;
float func_0025D430(float t) {
    if (t > 1.0f) t = 1.0f;
    return D_0048AF70 + t * (D_0048AF78 - D_0048AF70);
}