#pragma cplusplus on
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));
struct Iter {
    int *p;
    bool operator==(const Iter &o) const { int *q = o.p; return p == q; }
    Iter() {}
    Iter(const Iter &o) : p(o.p) {}
    Iter &operator=(const Iter &o) { p = o.p; return *this; }
    bool operator!=(const Iter &o) const { return !(*this == o); }
    Iter &operator++() { ++p; return *this; }
};
struct SmokeDef { char pad0[0xBC]; unsigned char bBC; char padBD[0xC8 - 0xBD]; float fC8; };
struct Smoke {
    char pad0[0x60];
    float f60;
    char pad64[0xC];
    V4 pos;
    SmokeDef *def;
    char pad84[0xD5 - 0x84];
    unsigned char bD5;
    unsigned char bD6;
};
extern "C" {
extern char D_004F8040[];
extern float D_0048AFE8;
extern float D_0048AFE0;
int *func_002596D0(void *);
int *func_002596A0(void *);
Iter func_002596C0(void *, int *const &);
int func_0025A880(V4 *, V4 *, float, float);
int func_0025AA20(V4 *, V4 *, V4 *, float);
}
static inline Iter Begin() { return func_002596C0(D_004F8040, func_002596D0(D_004F8040)); }
static inline Iter End() { return func_002596C0(D_004F8040, func_002596A0(D_004F8040)); }
#pragma opt_rotateloops off
extern "C" Smoke *SmokeVolumes_BlockSight(V4 *a, V4 *b)
{
    Iter it, end;
    it = Begin();
    end = End();
    for (; it != end; ++it) {
        Smoke *s = (Smoke *)*it.p;
        if (s->bD6) {
            V4 p0 = *a;
            V4 q0 = *b;
            float ratio = 1.0f;
            unsigned char hit = 0;
            float k;
            if (!s->bD5 && s->f60 < D_0048AFE8 && s->def->bBC != 4)
                ratio = s->f60 / D_0048AFE8;
            k = s->def->fC8 * ratio;
            float h = D_0048AFE0 * (1.0f + ratio) / 2.0f;
            if (func_0025A880(&p0, &q0, s->pos.z, s->pos.z + h)) {
                V4 c = s->pos;
                c.z += D_0048AFE0 / 2.0f;
                hit = func_0025AA20(&p0, &q0, &c, k);
            }
            if (hit) return (Smoke *)*it.p;
        }
    }
    return 0;
}