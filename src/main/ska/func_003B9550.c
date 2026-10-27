#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct DqBuf { unsigned int cap; unsigned int size; unsigned int start; int* data; };
struct DqIt { int* cur; int* data; int* beg; int* lim; };
struct DqTag { char c; };
extern "C" {
extern char D_0049AF00[];
extern char D_0049AE50[];
unsigned int _cdeque_deleter_common_int_suggest_new_cap(DqBuf* self, unsigned int n);
}
static inline int Distance(DqIt first, DqIt last)
{
    int* beg = last.beg;
    int n = last.cur - first.cur;
    if (last.cur >= beg) {
        if (first.cur < beg)
            n -= last.lim - last.data;
    } else {
        if (first.cur >= beg)
            n += last.lim - last.data;
    }
    return n;
}
static inline void Dealloc(int* p)
{
    if (p) {
        AllocGuard g;
        cMemMan_Deallocate(0, p, D_0049AF00, 0x64);
    }
}
extern "C" void _cdeque_deleter_int_1_do_assign(DqBuf* self, DqIt first, DqIt last, DqTag t)
{
    unsigned int n = Distance(first, last);
    self->size = 0;
    self->start = 0;
    if ((self->cap == 0 ? 0 : self->cap - 1) < n) {
        unsigned int c = _cdeque_deleter_common_int_suggest_new_cap(self, n);
        if (self->data) {
            Dealloc(self->data);
            self->data = 0;
            self->cap = 0;
        }
        self->data = (int*)TStr_Alloc((c + 1) * 4, D_0049AE50, 0x5C);
        self->cap = c + 1;
    }
    {
        int* d = self->data;
        DqIt f = first;
        DqIt l = last;
        while (f.cur != l.cur) {
            *d = *f.cur;
            if (++f.cur == f.lim)
                f.cur = f.data;
            d++;
        }
    }
    self->size = n;
}