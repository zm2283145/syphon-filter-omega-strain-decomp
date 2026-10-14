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


