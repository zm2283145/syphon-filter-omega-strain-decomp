#include "types.h"
static inline void UnitMtx_55C0(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
typedef struct { __int128 r[4]; } M44;
typedef struct {
    char pad0[0x10];
    M44 m10;
    M44 m50;
    char pad90[0x105 - 0x90];
    unsigned char b105;
    unsigned char b106;
    char pad107[0x110 - 0x107];
} CameraRecord;
extern void* memset(void*, int, unsigned int);
CameraRecord* CameraRecord_Construct(CameraRecord* r)
{
    memset(r, 0, sizeof(CameraRecord));
    { void* p = &r->m10; UnitMtx_55C0(p); }
    { void* xx = &r->m50; /* dead on purpose: retail keeps this addiu */ }
    UnitMtx_55C0(&r->m50);
    r->b105 = 1;
    r->b106 = 1;
    return r;
}

