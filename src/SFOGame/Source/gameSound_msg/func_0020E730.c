#pragma cplusplus on
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%1)" : "=r"(q) : "r"(s)); *(__int128*)d = q; }
struct V4 { int x, y, z, w; } __attribute__((aligned(16)));
struct V4b {
    __int128 q;
    V4b& operator=(const V4b& o) { V4b* t = this; GQ(t, &o); return *this; }
};
struct I32 { int v; I32& operator=(const I32& o) { v = o.v; return *this; } };
/* Head's implicit op= is non-trivial (I32), so MW copies name[] with its own 2x-unrolled byte loop. */
struct Head { I32 m0; signed char name[0x80]; };
struct Sub : Head {
    short m84;
    int m88;
    int m8C;
    int m90;
    unsigned char m94;
    int m98;
    Sub& operator=(const Sub& o) {
        Sub* t = this;
        t->Head::operator=(o);
        t->m84 = o.m84;
        t->m88 = o.m88;
        t->m8C = o.m8C;
        t->m90 = o.m90;
        t->m94 = o.m94;
        t->m98 = o.m98;
        return *this;
    }
};
struct Outer {
    int m0;
    V4 m10;
    int m20;
    int m24;
    V4b m30;
    int m40;
    signed char m44;
    Sub s48;
    Sub sE4;
    int m180;
    short m184;
    unsigned char m186;
};
#pragma inline_depth(8)
extern "C" Outer* cSndFx_ctor_cSndFxR(Outer* d, const Outer* s)
{
    *d = *s;
    return d;
}
