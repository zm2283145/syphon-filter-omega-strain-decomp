#pragma cplusplus on
#include "types.h"
struct E1EEEC0 { int w[4]; };
struct V1EEEC0 { int capacity; int count; E1EEEC0* data; };
extern "C" void func_001E0FE0(E1EEEC0* e, int flags);
extern "C" void func_001EEEC0(V1EEEC0* v)
{
    E1EEEC0* first = v->data;
    E1EEEC0* last = first + v->count;
    while (first < last) {
        --last;
        func_001E0FE0(last, -1);
    }
    v->count = 0;
}