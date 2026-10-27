#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Box { V mn; V mx; };
extern "C" void cBox_Empty(Box* b);
void cBox_Empty(Box* b)
{
    V lo(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
    b->mn = lo;
    V hi(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    b->mx = hi;
}
