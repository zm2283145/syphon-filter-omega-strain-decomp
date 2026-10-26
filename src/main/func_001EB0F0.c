#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_opAssign: HumanColPreset entry assignment (implicit member-wise operator=: bitset masks, float groups, flags, quad vectors) */
struct Bits {
    int w[1];
    Bits() {}
    Bits& operator=(const Bits& o) { for (int i = 0; i < 1; i++) w[i] = o.w[i]; return *this; }
};
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct F4 { float a, b, c, d; };
struct F3 { float a, b, c; };
/* one-byte struct member: MW copies it through address registers like retail */
struct B1 { unsigned char v; };
struct Shape { V a; V b; V c; B1 flag; float r; V d; V e; };
struct Col {
    signed char b0;
    Bits m4, m8, mC, m10;
    F4 f14;
    F3 f24;
    unsigned char x30, x31, x32;
    Shape shape;
    Bits mA0;
    V qB0, qC0, qD0;
    float xE0, xE4;
};
extern "C" Col* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_opAssign(Col* d, const Col* s)
{
    *d = *s;
    return d;
}
