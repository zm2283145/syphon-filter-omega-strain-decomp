#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void Q0220(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
typedef struct {
    char pad0[0x80];
    V4 v80;
    char pad90[0xF0 - 0x90];
    V4 vF0;
    char pad100[0x11A - 0x100];
    unsigned char b11A;
} ColQuery;
extern void cCollisionProbe_SphereSweptRay_Reset_CommonCode(ColQuery* q, int kind);
void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(ColQuery* q, int kind, V4* a, V4* b)
{
    cCollisionProbe_SphereSweptRay_Reset_CommonCode(q, kind);
    { V4* d = &q->vF0; __int128 t; /* 16-byte copy; temp passed as input after dest for retail colouring */ __asm__ volatile("lq %1, 0x0(%2); sq %1, 0x0(%0)" : : "r"(d), "r"(t), "r"(a) : "memory"); }
    Q0220(&q->v80, b);
    { void* xx = &q->v80; /* dead on purpose: retail keeps this addiu */ }
    q->b11A = 0;
}



