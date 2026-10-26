#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    ~V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct W {
    float x, y, z, w;
    W() {}
    W& operator=(const W& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct B { unsigned char d; };
struct E {
    V a, b, c;
    B d;
    float e;
    V f;
    W g;
};
/* vector<E>::erase(first, last): 96-byte element, tail copied down, empty dtors. */
struct EVec { int cap; int count; E* data; };
static inline E* Copy(E* first, E* last, E* dest) {
    while (first < last) { *dest = *first; ++first; ++dest; }
    return dest;
}
extern "C" E* std_vector_imp_cCollisionEdge_erase(EVec* self, E* first, E* last)
{
    if (first == last)
        return first;
    E* end = self->data + self->count;
    int tailCount = end - last;
    if (tailCount)
        Copy(last, end, first);
    E* tail = first + tailCount;
    while (tail < end) {
        tail->~E();
        ++tail;
    }
    self->count -= last - first;
    return first;
}
