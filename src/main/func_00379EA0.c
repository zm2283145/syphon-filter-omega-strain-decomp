#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

/* Returns true if point p, transformed by the renderer's camera matrix
 * (0xF00), lies inside the clip volume (|x|,|y|,|z| <= |w|). */

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    V() {}
    /* The unused xx keeps retail's dead address addiu. */
    V(const V& o) { void* xx = this; Q16(this, &o); }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct R { char pad[0xF00]; M m; };

extern "C" {
void Renderer_UpdateCameraMatrices(R*);
bool func_00379EA0(R* r, V* p);
}

static inline V Xform(M* m, const V& v)
{
    V t = v;
    V* pp = &t;
    asm {
        lqc2 vf8, 0x0(pp)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(pp)
    }
    return *pp;
}

bool func_00379EA0(R* r, V* p)
{
    Renderer_UpdateCameraMatrices(r);
    V c = Xform(&r->m, *p);
    float aw = 0.0f;
    float cw = c.w;
    asm { abs.s aw, cw } /* fabs: same asm idiom as src/main/Ladder_ChannelArrived.c */
    return c.x <= aw && c.x >= -aw && c.y <= aw && c.y >= -aw && c.z <= aw && c.z >= -aw;
}
