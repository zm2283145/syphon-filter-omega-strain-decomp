#pragma cplusplus on
#include "types.h"
#pragma opt_propagation off

struct V {
    float x, y, z, w;
    V& operator+=(const V& o) { V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(tp), "r"(op) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct Seg { char pad[0x10]; V pos; char pad20[0x20]; };
struct Rope { char pad[0x14]; int n; Seg* segs; char pad1C[0xC4 - 0x1C]; float len; float ampX; float ampZ; Seg& At(int i) { Seg** pp = &segs; return (*pp)[i]; } };

extern "C" {
extern int D_0048B170[];
extern float D_0048B160[];
float Libc_Sinf(float);
}

extern "C" void cAirTaser_AddWhipAction(Rope* r, float dt)
{
    float step = 3.14f / r->len;
    int n = r->n;
    float ang;
    float ax = r->ampX * dt;
    float az = r->ampZ * dt;
    ang = step;
    float cnt = (float)(D_0048B170[0] < n ? n : D_0048B170[0]);
    int i;
    for (i = 1; i < n; i++) {
        V v;
        v.x = ax * ((float)i / cnt) * Libc_Sinf(ang);
        v.y = 0.0f;
        v.z = az * ((float)i / cnt) * Libc_Sinf(ang);
        r->segs[i].pos += v;
        ang += step;
        r->At(i).pos.y *= D_0048B160[0];
    }
}



