#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct DqBuf { unsigned int cap; unsigned int size; unsigned int start; int* data; };
extern "C" {
extern char D_0049AF00[];
extern char D_0049AE50[];
unsigned int _cdeque_deleter_common_int_suggest_new_cap(DqBuf* self, unsigned int n);
}
static inline void Dealloc(int* p)
{
    if (p) {
        AllocGuard g;
        cMemMan_Deallocate(0, p, D_0049AF00, 0x64);
    }
}
static inline int* CopyQ(DqBuf* q, int* o)
{
    int* d;
    int* p = q->data + q->start;
    int* data = q->data;
    int* lim = q->data + q->cap;
    int* end = q->data + (q->cap ? (q->start + q->size) % q->cap : 0);
    d = o;
    while (p != end) {
        *d = *p;
        if (++p == lim)
            p = data;
        d++;
    }
    return d;
}
extern "C" void _cdeque_deleter_int_1_push_back(DqBuf* self, const int* v)
{
    unsigned int c0 = self->cap == 0 ? 0 : self->cap - 1;
    unsigned int size = self->size;
    if (size < c0) {
        self->size = size + 1;
        self->data[(self->start + size) % self->cap] = *v;
    } else {
        unsigned int c = _cdeque_deleter_common_int_suggest_new_cap(self, size + 1);
        int* nd = (int*)TStr_Alloc((c + 1) * 4, D_0049AE50, 0x5C);
        int* d = CopyQ(self, nd);
        *d = *v;
        if (self->data)
            Dealloc(self->data);
        self->data = nd;
        self->cap = c + 1;
        self->start = 0;
        self->size++;
    }
}