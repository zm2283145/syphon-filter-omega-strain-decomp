#include "types.h"
#pragma cplusplus on

struct DqBuf { unsigned int cap; unsigned int size; unsigned int start; int* data; };
struct DqIt {
    int* cur; int* data; int* beg; int* lim;
    int* D() const { return data; }
    DqIt(const DqBuf* x, unsigned int i) { cur = x->data + i; data = x->data; beg = D() + x->start; lim = D() + x->cap; }
};
struct DqTag { char c; };
extern "C" {
void _cdeque_deleter_int_1_do_assign(DqBuf* self, DqIt first, DqIt last, DqTag t);
}
static inline DqIt DqBegin(const DqBuf* x) { return DqIt(x, x->start); }
static inline DqIt DqEnd(const DqBuf* x)
{
    unsigned int i = x->cap ? (x->start + x->size) % x->cap : 0;
    return DqIt(x, i);
}
extern "C" DqBuf* _cdeque_imp_cSkaSystem_RequestPtr_1_opAssign(DqBuf* self, const DqBuf* x)
{
    if (self != x) {
        DqTag t;
        _cdeque_deleter_int_1_do_assign(self, DqBegin(x), DqEnd(x), t);
    }
    return self;
}


