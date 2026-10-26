#include "types.h"
#pragma cplusplus on
struct Q_240CE0 {
    int a[4];
    Q_240CE0& operator=(const Q_240CE0& o)
    {
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct E_00240CE0 {
    float f;
    Q_240CE0 a, b, c;
    E_00240CE0& operator=(const E_00240CE0& o)
    {
        E_00240CE0* t = this;
        t->f = o.f; t->a = o.a; t->b = o.b; t->c = o.c;
        return *this;
    }
};
struct V_00240CE0 { unsigned int cap; unsigned int count; E_00240CE0* data; };
extern "C" E_00240CE0* std_vector_imp_VectorKey_erase(V_00240CE0* self, E_00240CE0* first, E_00240CE0* last)
{
    if (first == last)
        return first;
    E_00240CE0* end = self->data + self->count;
    int tailCount = end - last;
    if (tailCount) {
        E_00240CE0* s;
        E_00240CE0* d;
        d = first;
        s = last;
        while (s < end) {
            *d = *s;
            ++d;
            ++s;
        }
    }
    E_00240CE0* tail = first + tailCount;
    while (tail < end) {
        ++tail;
    }
    self->count -= last - first;
    return first;
}

