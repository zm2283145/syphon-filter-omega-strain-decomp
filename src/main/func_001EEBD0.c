#pragma cplusplus on
#include "types.h"
struct V { float x, y, z, w; } __attribute__((aligned(16)));
typedef struct { int x, y, z, w; } __attribute__((aligned(16))) V4;
struct T {
    unsigned char b0;
    char pad1[0xF];
    V v10;
    V v20;
    V v30;
    V v40;
    V v50;
    unsigned char b60;
    unsigned char b61;
    unsigned char b62;
    char pad63;
    int i64;
};
extern "C" {
extern signed char D_004E1D88;
extern V4 D_004E1D90;
V* Vec4_GetZero(void);
void Vec4_Assign(V* d, const void* s);
void Vec4_SetOrigin(V* v);
void func_0013B0C0(V* v);
T* func_001EEBD0(T* o);
}
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
static inline void VF0(void* d) { asm volatile { .set noreorder
 sqc2 vf0, 0x0(d)
 .set reorder } }
static inline void Cp1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
T* func_001EEBD0(T* o_)
{
    V4* z;
    T* o;
    const V* rr;
    V t;
    V a;
    V p;
    {
        void* s = &a;
        VF0(s);
        void* d = &t;
        Cp1(d, s);
    }
    rr = &t; /* dead: retail keeps this addiu (in the guard bnez delay slot) */
    z = Vec4_Zero();
    o_->b0 = 0;
    o = o_;
    Vec4_Assign(&o->v10, Vec4_GetZero());
    Vec4_SetOrigin(&p);
    Vec4_Assign(&o->v20, &p);
    func_0013B0C0(&o->v30);
    Vec4_Assign(&o->v40, z);
    Vec4_Assign(&o->v50, &t);
    o->b60 = 0;
    o->b61 = 0;
    o->b62 = 0;
    o->i64 = 0;
    return o;
}
