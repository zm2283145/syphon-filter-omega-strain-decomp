#include "types.h"
typedef struct { char pad[0x10]; float def; } F291700_Src;
typedef struct { F291700_Src* src; float t; } F291700_t;
void func_00291700(F291700_t* o, F291700_Src* s, float t) {
    o->src = s;
    if (t < 0.0f) t = s->def;
    o->t = t;
}