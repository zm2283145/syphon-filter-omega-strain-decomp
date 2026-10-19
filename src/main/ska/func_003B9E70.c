#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct DqBuf { unsigned int cap; unsigned int size; unsigned int start; int* data; };
extern "C" {
extern char D_0049AF00[];
extern char D_0049AE50[];
extern unsigned int D_004BCEE8[2];
extern signed char D_00542C90;
}
static inline unsigned int MaxSize(void) {
    int size[1];
    int ref;
    if (D_00542C90 == 0) {
        ref = (int)size;
        size[0] = 0x1800000;
        ref = *(int*)ref;
        D_00542C90 = 1;
        (*(int*)D_004BCEE8) = ref - 1;
    }
    return (*(int*)D_004BCEE8);
}
static inline void Dealloc(int* p)
{
    if (p) {
        AllocGuard g;
        Mem_Free(0, p, D_0049AF00, 0x64);
    }
}
static inline void CopyQ(DqBuf* q, int* d)
{
    int* end = q->data + (q->cap ? (q->start + q->size) % q->cap : 0);
    int* data = q->data;
    int* p = q->data + q->start;
    int* lim = q->data + q->cap;
    while (p != end) {
        *d = *p;
        if (++p == lim)
            p = data;
        d++;
    }
}
extern "C" void func_003B9E70(DqBuf* self, unsigned int n)
{
    if ((self->cap == 0 ? 0 : self->cap - 1) < n) {
        int* nd;
        if (MaxSize() < n) {
            Libc_Fprintf(D_00489738->stream, "cdeque::reserve length error");
            Libc_Abort();
        }
        nd = (int*)TStr_Alloc((n + 1) * 4, D_0049AE50, 0x5C);
        if (self->data) {
            CopyQ(self, nd);
            Dealloc(self->data);
        }
        self->data = nd;
        self->cap = n + 1;
        self->start = 0;
    }
}