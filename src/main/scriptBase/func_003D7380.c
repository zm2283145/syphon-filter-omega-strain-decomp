#pragma cplusplus on
#include "types.h"
#pragma inline_depth(10)
extern "C" {
void PtrVector_Resize(void* v, int n, int* val);
}
typedef struct { int pad0; int count; int* data; unsigned char owns; } V7380;
typedef struct { int x0; int x4; V7380 vec; int x18; } O7380;
extern "C" {
void func_003D6010(V7380* v);
}
static inline int* At(V7380* v, unsigned int i) { return &v->data[i]; }
extern "C" O7380* func_003D7380(O7380* o, int x0, int x4, int x18, int n, int* src)
{
    V7380* v; int i; int zero;
    v = &o->vec;
    func_003D6010(v);
    v->owns = 1;
    o->x0 = x0;
    o->x4 = x4;
    o->x18 = x18;
    zero = 0;
    PtrVector_Resize(v, n, &zero);
    for (i = 0; i < n; i++) *At(&o->vec, i) = src[i];
    return o;
}
