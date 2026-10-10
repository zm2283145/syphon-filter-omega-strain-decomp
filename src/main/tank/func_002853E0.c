#include "types.h"

typedef struct Target20 {
    char pad[0x20];
    float x;
    float y;
} Target20;

typedef struct Obj6C {
    char pad[0x6C];
    Target20* target;
} Obj6C;

/* Stores (x, y) scaled by 0.0174533 (degrees to radians) into the target. */
void func_002853E0(Obj6C* o, float x, float y) {
    Target20* t = o->target;
    if (t != 0) {
        float k = 0.017453292f;
        t->x = k * x;
        t->y = k * y;
    }
}
