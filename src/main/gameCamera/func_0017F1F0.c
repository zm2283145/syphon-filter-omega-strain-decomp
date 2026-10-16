/* func_0017F1F0: Pair[2] init from (a, b*f) + f40=f, f44=1/f. Empty do/while stands in for the Pair array ctor loop; named scale temp V s fixes stack order; 'i <= 1' gives slti $at. */
#pragma cplusplus on
#pragma exceptions off
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V operator*(float k) const;
} __attribute__((aligned(16)));
static inline void ScaleTo(V* d, const V* s, float k) { int r; V* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }
struct Pair {
    V a; V b;
    Pair() {}
    Pair(const V& x, const V& y) : a(x), b(y) {}
    Pair& operator=(const Pair& o) { Pair* t = this; t->a = o.a; t->b = o.b; return *this; }
};
struct T {
    Pair arr[2];
    float f40;
    float f44;
};
extern "C" T* func_0017F1F0(T* p, const V* a, const V* b, float f)
{
    int i;
    V s = *b * f; Pair pl(*a, s);
    {
        Pair* q = p->arr;
        do { q++; } while (q != p->arr + 2);
    }
    for (i = 0; i <= 1; i++) p->arr[i] = pl;
    p->f40 = f;
    p->f44 = (f != 0.0f) ? 1.0f / f : 0.0f;
    return p;
}





