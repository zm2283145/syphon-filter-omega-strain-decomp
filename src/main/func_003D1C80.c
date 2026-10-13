#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    /* The unused xx keeps retail's dead destination-address addiu. */
    V& operator=(const V& o) { void* xx = this; Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Mat { char pad[0x10]; V uv; };
struct Scroll { char pad[8]; Mat* a; Mat* b; char pad10[4]; float du; float dv; };

static inline void Wrap(V& v)
{
    if (v.x > 1.0f) v.x -= 1.0f;
    if (v.y > 1.0f) v.y -= 1.0f;
    if (v.x < -1.0f) v.x += 1.0f;
    if (v.y < -1.0f) v.y += 1.0f;
}

extern "C" void func_003D1C80(Scroll* s, float dt)
{
    float du = s->du * dt;
    float dv = s->dv * dt;
    Mat* a = s->a;
    Mat* b = s->b;
    a->uv = V(a->uv.x + du, a->uv.y + dv, 0.0f, 0.0f);
    b->uv = V(b->uv.x + du, b->uv.y + dv, 0.0f, 0.0f);
    Wrap(a->uv);
    Wrap(b->uv);
}
