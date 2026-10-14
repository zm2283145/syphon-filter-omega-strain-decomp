/* RayProbe ctor: function-local static zero V (guard D_004E1D88) written out by hand with externs. */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct P { int a, b; } __attribute__((aligned(16)));
struct S {
    signed char a;
    V v10;
    V v20;
    P v30;
    V v40;
    V v50;
    unsigned char c60;
    unsigned char c61;
    unsigned char c62;
    int i64;
};
extern signed char D_004E1D88; extern V D_004E1D90;
static inline const V& Zero() { if (!D_004E1D88) { D_004E1D90.x = 0.0f; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f; D_004E1D88 = 1; } return D_004E1D90; }
static inline V Unit() { V l0; V* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
extern "C" S* RayProbe_Ctor(S* p, const V& e, const V& s)
{
    p->a = 0;
    p->v10 = Zero();
    p->v20 = Unit();
    p->v30.a = 0;
    p->v30.b = 0;
    p->v40 = s;
    p->v50 = e;
    p->c60 = 0;
    p->c61 = 0;
    p->c62 = 0;
    p->i64 = 0;
    return p;
}

