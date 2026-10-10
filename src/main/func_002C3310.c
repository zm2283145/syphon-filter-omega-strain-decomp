#include "types.h"
typedef struct { char pad[0x10]; float f10; } T2C3310;
typedef struct { T2C3310* t; float v; } O2C3310;
void func_002C3310(O2C3310* o, T2C3310* t, float x) {
    o->t = t;
    if (x < 0.0f) {
        x = t->f10;
    }
    o->v = x;
}