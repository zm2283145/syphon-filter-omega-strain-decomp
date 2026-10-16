#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct S {
    signed char a;
    V v10;
    V v20;
    V v30;
    V v40;
};
extern "C" { extern signed char D_004E1D88; extern V D_004E1D90; }
static inline const V& Zero() { if (!D_004E1D88) { D_004E1D90.x = 0.0f; D_004E1D88 = 1; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f; } return D_004E1D90; }
static inline V Unit() { V l0; V* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
extern "C" S* func_00190A00(S* p)
{
    p->a = 0;
    p->v10 = Zero();
    p->v20 = Zero();
    { V u = Unit(); p->v30 = u; }
    p->v40 = Unit();
    return p;
}

