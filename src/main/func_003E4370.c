#pragma cplusplus on
#include "types.h"
struct V { float x, y, z, w; V& operator=(const V& o) { __int128 t; const V* s = &o; asm volatile { lq t, 0(s)
 sq t, 0(this) } return *this; } } __attribute__((aligned(16)));
struct T70 { int a; int b; char pad[8]; V c; V d; };
extern "C" T70* func_003E4370(T70* t, int a, const V* q, const int* p);
T70* func_003E4370(T70* t, int a, const V* q, const int* p) {
    t->a = a;
    t->b = *p;
    t->c = q[0];
    t->d = q[1];
    void* xx = &t->d; /* dead on purpose: retail keeps this addiu */
    return t;
}

