#pragma cplusplus on
#pragma peephole off
/* func_001DFAD0: matched by c80nm. The copy address registers follow the order the
   pointer locals are declared in (src, then the second dst, then the copy-src/dst). */
typedef struct { int x, y, z, w; } __attribute__((aligned(16))) V4;
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct T { V m0; V m10; V4 m20; };
extern "C" signed char D_004E1D88;
extern "C" V4 D_004E1D90;
static inline V4* Vec4_Zero(void) {
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return &D_004E1D90;
}
static inline void VF0(void* d) { __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(d) : "memory"); }
static inline void Cp0(void* d, const void* s) { __int128 t; asm { lq t, 0(s)
 sq t, 0(d) } }
static inline void Cp1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
extern "C" T* func_001DFAD0(T* d)
{
    V tC; V tD; V tA; V tB;
    VF0(&tA);
    {
        void* s = &tA; void* u = &tC; void* t = &tC;
        Cp1(t, s);
        Cp0(&d->m0, u);
    }
    VF0(&tB);
    {
        void* s = &tB; void* m = &d->m10; void* u = &tD; void* t = &tD;
        Cp1(t, s);
        Cp0(m, u);
    }
    Cp0(&d->m20, Vec4_Zero());
    return d;
}
