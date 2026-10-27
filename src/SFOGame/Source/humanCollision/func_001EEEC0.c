#pragma cplusplus on
#include "types.h"
struct E1EEEC0 { int w[4]; };
struct V1EEEC0 { int capacity; int count; E1EEEC0* data; };
extern "C" void cEdgeGroup_dtor(E1EEEC0* e, int flags);
extern "C" void std_vector_deleter_cEdgeGroup_clear(V1EEEC0* v)
{
    E1EEEC0* first = v->data;
    E1EEEC0* last = first + v->count;
    while (first < last) {
        --last;
        cEdgeGroup_dtor(last, -1);
    }
    v->count = 0;
}