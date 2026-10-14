/* Implicit member-wise operator= (bytes + lq/sq quad copies). */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct S {
    signed char a;
    signed char b;
    V v10;
    V v20;
    signed char c30;
    V v40;
    V v50;
    signed char c60;
};
extern "C" S* func_001DBA60(S* d, const S* s)
{
    *d = *s; return d;
}

