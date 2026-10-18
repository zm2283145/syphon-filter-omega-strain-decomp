#pragma cplusplus on
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_AE3B0;
struct S_AE3B0 { char pad0[0xC]; bool bC; char padD[0x187 - 0xD]; bool f187; char pad188[8]; V4_AE3B0 v190; float f1A0; float f1A4; };
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline void V4Copy(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void func_001AE3B0(S_AE3B0* s, V4_AE3B0* v, float a, float b)
{
    V4Copy(&s->v190, v);
    s->f1A0 = a;
    s->f1A4 = b;
    s->f187 = s->bC && a == 0.0f && Abs(b) > 0.0001f;
}
