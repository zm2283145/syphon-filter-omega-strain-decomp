#pragma cplusplus on
#include "types.h"
#pragma always_inline on
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V& operator=(const V& o) { void* xx = this; __int128 t; V* d = this; const V* s = &o; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
};
struct M;
struct Obj;
extern "C" int XLib_GetOutCode(Obj*, M*, V*);
/* Writes the 8 corners of an AABB to the scratchpad and classifies them against the view clip
   planes: 0x80 all outside one plane, 4 any behind (0x20), 1 fully inside, 2 straddling; |0x10 if any 0x40. */
extern "C" int XLib_TestBBox_cMatrixR_cVectorR_cVectorR(Obj* o, M* m, const V* mn, const V* mx)
{
    V* sp = (V*)0x70000000;
    int orAll = 0;
    int andAll = 0x3F;
    int cnt = 0;
    int i;
    int r;
    sp[0] = V(mn->x, mn->y, mn->z, 1.0f);
    sp[1] = V(mn->x, mx->y, mn->z, 1.0f);
    sp[2] = V(mx->x, mn->y, mn->z, 1.0f);
    sp[3] = V(mx->x, mx->y, mn->z, 1.0f);
    sp[4] = V(mn->x, mx->y, mx->z, 1.0f);
    sp[5] = V(mx->x, mn->y, mx->z, 1.0f);
    sp[6] = V(mn->x, mn->y, mx->z, 1.0f);
    sp[7] = V(mx->x, mx->y, mx->z, 1.0f);
    for (i = 0; i < 8; i++) {
        int c = XLib_GetOutCode(o, m, &sp[i]);
        orAll |= c;
        andAll &= c;
        cnt += c & 0x20;
    }
    if (andAll) return 0x80;
    if (cnt) {
        r = 4;
    } else if (orAll == 0 || orAll == 0x40) {
        r = 1;
    } else {
        r = 2;
    }
    if (orAll & 0x40) r |= 0x10;
    return r;
}