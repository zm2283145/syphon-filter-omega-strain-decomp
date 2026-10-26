#pragma cplusplus on
/* 4x4 matrix copy constructor: the explicit do/while walk is the empty V ctor loop over the rows,
   the goto loop reproduces retail's jump-to-test copy loop; lq/sq quad copy as asm. */
struct V {
    float x, y, z, w;
    V() {}
} __attribute__((aligned(16)));
static inline void QCopy(V* pd, const V* ps) { __int128 q; asm { lq q, 0(ps); sq q, 0(pd) } }
struct M {
    V r[4];
};
#pragma push
#pragma opt_unroll_loops off
extern "C" M* cArray_FixedSize_cVector_4_ctor_cArrayFixedSizeR(M* d, const M* s)
{
    V* p = d->r;
    V* e = d->r + 4;
    do { p++; } while (p != e);
    {
        int i = 0;
        goto test;
    loop:
        QCopy(&d->r[(unsigned)i], &s->r[(unsigned)i]);
        i++;
    test:
        if (i <= 3) goto loop;
    }
    return d;
}
#pragma pop
