/* func_001EC1C0: ctor; function-local static identity placement D_00497F00 (guard D_004E1D80) copied via VecPair_Copy then lq/sq into place. */
#pragma cplusplus on
#pragma exceptions off
struct V4c {
    float x, y, z, w;
    V4c& operator=(const V4c& o) { const V4c* s = &o; V4c* d = this; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Pair { V4c a; V4c b; Pair() {} Pair(const Pair& o); };
struct T {
    unsigned char b0, b1, b2;
    char p3[0x3D];
    unsigned char b40;
    char p41[0x1F];
    int i60;
    int i64;
    int i68;
    char p6C[4];
    int a70[1];
    int i74;
    char p78[8];
    Pair place;
};
extern "C" {
extern signed char D_004E1D80;
extern Pair D_00497F00;
Pair* Placement_GetIdentity(Pair* p, const V4c* a, const V4c* b);
Pair* VecPair_Copy(Pair* d, const Pair* s);
V4c Vec4_SetOrigin(void);
V4c Quat_SetIdentity(void);
}
static inline const Pair& IdentPl(void)
{
    if (!D_004E1D80) {
        Placement_GetIdentity(&D_00497F00, &Quat_SetIdentity(), &Vec4_SetOrigin());
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
extern "C" T* func_001EC1C0(T* p)
{
    int i;
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 0;
    p->b40 = 0;
    p->i60 = -1;
    p->i64 = -1;
    p->i68 = 0;
    for (i = 0; i < 1; i++) p->a70[i] = 0;
    p->i74 = 0;
    {
        Pair pl;
        IdentPl();
        VecPair_Copy(&pl, &D_00497F00);
        p->place.a = pl.a;
        p->place.b = pl.b;
    }
    return p;
}

