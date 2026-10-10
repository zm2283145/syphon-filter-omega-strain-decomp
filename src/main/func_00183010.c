#include "types.h"

typedef struct Bounds {
    Vec4 min;
    Vec4 max;
} Bounds;

/* Resets a bounding box to empty (min = +FLT_MAX, max = -FLT_MAX, w = 1). */
Bounds* Bounds_SetEmpty(Bounds* b) {
    b->min.x = 3.4028235e38f;
    b->min.y = 3.4028235e38f;
    b->min.z = 3.4028235e38f;
    b->min.w = 1.0f;
    b->max.x = -3.4028235e38f;
    b->max.y = -3.4028235e38f;
    b->max.z = -3.4028235e38f;
    b->max.w = 1.0f;
    return b;
}
