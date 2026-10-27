/*
 * Libs/SFOLib/Source/bone: 2 files, 003B9C20-003B9E70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B9C20 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003B9C20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B9C20 */

/* merge_units: begin func_003B9E70 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
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
static inline void CopyQ_003B9E70(DqBuf* q, int* d)
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
extern "C" void _cdeque_deleter_int_1_reserve(DqBuf* self, unsigned int n)
{
    if ((self->cap == 0 ? 0 : self->cap - 1) < n) {
        int* nd;
        if (MaxSize() < n) {
            Libc_Fprintf(D_00489738->stream, "cdeque::reserve length error");
            Libc_Abort();
        }
        nd = (int*)TStr_Alloc((n + 1) * 4, D_0049AE50, 0x5C);
        if (self->data) {
            CopyQ_003B9E70(self, nd);
            Dealloc(self->data);
        }
        self->data = nd;
        self->cap = n + 1;
        self->start = 0;
    }
}
static inline void merge_flush_func_003B9E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B9E70 */
