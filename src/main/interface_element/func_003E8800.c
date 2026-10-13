#pragma cplusplus on
#include "types.h"
typedef struct { __int128 q[4]; } M4_E88;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_E88;
typedef struct { char pad[0xA80]; M4_E88 m[1]; } MStack_E88;
typedef struct { char pad[0x62]; unsigned char b62; } Info_E88;
typedef struct { char pad[0x20]; V4_E88 v20; float m30[16]; Info_E88* p70; } Elem_E88;
extern "C" {
extern MStack_E88 D_005381F0;
extern int D_00538C64;
extern char D_00538C68;
}
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void GV(void* d, void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void M4Mul(void* o, void* a, void* b) {
    asm {
        lqc2 vf4, 0x0(a)
        lqc2 vf5, 0x10(a)
        lqc2 vf6, 0x20(a)
        lqc2 vf7, 0x30(a)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(o)
        sqc2 vf13, 0x10(o)
        sqc2 vf14, 0x20(o)
        sqc2 vf15, 0x30(o)
    }
}
static inline bool IsIdent(float* m) {
    return m[0] == 1.0f && m[1] == 0.0f && m[2] == 0.0f && m[3] == 0.0f &&
           m[4] == 0.0f && m[5] == 1.0f && m[6] == 0.0f && m[7] == 0.0f &&
           m[8] == 0.0f && m[9] == 0.0f && m[10] == 1.0f && m[11] == 0.0f &&
           m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f && m[15] == 1.0f;
}

extern "C" void func_003E8800(Elem_E88* e)
{
    M4_E88 a;
    M4_E88 r;
    M4_E88 t;
    {
        GQR(&D_005381F0.m[D_00538C64 + 1], &D_005381F0.m[D_00538C64]);
        void* x0 = &a; /* dead on purpose */
        D_00538C64++;
    }
    UM(&a);
    {
        void* x1 = &a.q[3]; /* dead on purpose */
        GV(&a.q[3], &e->v20);
    }
    if (e->p70->b62) {
        M4Mul(&t, &a, &D_005381F0.m[D_00538C64]);
        {
            M4_E88* pr = &r;
            void* x2 = &r; /* dead on purpose */
            GQR(&r, &t);
            GQR(&D_005381F0.m[D_00538C64], pr);
        }
        D_00538C68 = 1;
    } else {
        M4_E88* c = &D_005381F0.m[D_00538C64];
        M4Mul(c, c, &a);
        D_00538C68 = 1;
    }
    if (!IsIdent(e->m30)) {
        M4_E88* c = &D_005381F0.m[D_00538C64];
        M4Mul(c, c, e->m30);
        D_00538C68 = 1;
    }
}