#pragma cplusplus on
#include "types.h"
static inline float fmin_(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
struct V { float x, y, z, w; V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; /* dead on purpose: retail keeps this addiu */ return *this; } } __attribute__((aligned(16)));
struct T80 { V a; V b; float c; float d; int e; };
extern "C" T80* func_003E4880(T80* t, const V* a, const V* b, float c, float d, int e);
T80* func_003E4880(T80* t, const V* a, const V* b, float c, float d, int e) {
    t->a = *a;
    t->b = *b;
    t->c = c;
    t->d = fmin_(1.0f, d);
    t->e = e;
    return t;
}

