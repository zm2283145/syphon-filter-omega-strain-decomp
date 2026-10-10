#include "types.h"

typedef struct Vec2f {
    float x, y;
} Vec2f;

/* Initializes a float pair from two ints. */
Vec2f* func_002503B0(Vec2f* v, int x, int y) {
    v->x = (float)x;
    v->y = (float)y;
    return v;
}
