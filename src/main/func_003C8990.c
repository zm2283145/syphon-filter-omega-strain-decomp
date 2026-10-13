#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;

static inline void Q8990(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
#pragma peephole off
#pragma opt_propagation off
void Culler_TestObject(void* self, V4* box, V4* m, int* outi, float* outf)
{
    V4* d = (V4*)0x11004050;
    V4 v;
    int one;
    int r;
    V4* q;
    float w;
    __int128 t0;
    /* v = box[0]; dest/temp listed as inputs in this order to get retail colouring (&v=s2, temp=s1) */
    __asm__ volatile("lq %1, 0x0(%2); sq %1, 0x0(%0)" : : "r"(&v), "r"(t0), "r"(box) : "memory");
    if (m) {
        one = 1;
        w = *(float*)&one;
    } else {
        w = 0.0f;
    }
    q = &d[1]; /* dead on purpose: retail keeps this addiu */ v.w = w;
    Q8990(d, &v); Q8990(&d[1], &box[1]);
    if (m) {
        Q8990(&d[2], &m[0]); q = &d[2]; Q8990(&d[3], &m[1]); q = &d[3]; Q8990(&d[4], &m[2]); q = &d[4]; Q8990(&d[5], &m[3]); q = &d[5];
    }
    asm {
        .set noreorder
        sync
        vnop
        vcallmsr vi27
        cfc2.i r, vi0
        .set reorder
    }
    d = (V4*)0x11004050;
    *outi = *(int*)&d->x;
    *outf = d->z;
}

