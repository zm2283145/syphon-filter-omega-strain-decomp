/*
 * main/ska: range (2 files, 003BA0C0-003BA1B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BA0C0 */
#pragma push /* merge_units */
typedef struct Deq { unsigned int cap; unsigned int size; unsigned int start; int* data; } Deq;

extern void Libc_Fprintf(int, const char*);
extern void Libc_Abort(void);
extern char* D_00489738;
extern unsigned int D_004BCEE8[2];
extern signed char D_00542C90;

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

unsigned int func_003BA0C0(Deq* self, unsigned int n)
{
    unsigned int m = MaxSize();
    unsigned int c;
    if (m < n) {
        Libc_Fprintf(*(int*)(D_00489738 + 0xC), "cdeque max_size error");
        Libc_Abort();
    }
    c = self->cap ? self->cap - 1 : 1;
    while (n > c) {
        if (c < m / 2) c *= 2; else c = m;
    }
    return c;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA0C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA0C0 */

/* merge_units: begin func_003BA1B0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* 4x4 matrix constructor filling every row with one vector: the explicit do/while walk is the empty V ctor loop over the rows,
   the goto loop reproduces retail's jump-to-test copy loop; lq/sq quad copy as asm. */
struct V {
    float x, y, z, w;
    V() {}
} __attribute__((aligned(16)));
static inline void QCopy(V* pd, const V* ps) { __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
struct M {
    V r[4];
};
#pragma push
#pragma opt_unroll_loops off
extern "C" M* func_003BA1B0(M* d, const V* s)
{
    V* p = d->r;
    V* e = d->r + 4;
    do { p++; } while (p != e);
    {
        int i = 0;
        goto test;
    loop:
        QCopy(&d->r[(unsigned)i], s);
        i++;
    test:
        if (i <= 3) goto loop;
    }
    return d;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA1B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA1B0 */
