#pragma cplusplus on
#include "types.h"
struct V4c { float x, y, z, w; };
static inline float LenSqP(V4c* p) {
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(p)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
struct DirLight {
    unsigned char f0;
    unsigned char f1;
    char pad2[2];
    void* vt;
    char pad8[4];
    int fC;
    char pad10[8];
    float f18;
    unsigned char f1C;
    unsigned char f1D;
    unsigned char f1E;
    char pad1F;
    V4c color;
    V4c dir;
};
extern "C" {
extern char D_004D9240[];
extern char D_004D9280[];
extern signed char D_0048A148;
extern unsigned char g_LevelLightsDirty;
}
extern "C" DirLight* LevelLight_CreateDirectional(DirLight* l, unsigned char a, V4c* c)
{
    V4c v;
    float y, z, w, x;
    float one;
    l->vt = D_004D9280;
    l->f0 = D_0048A148;
    l->f1 = 0;
    l->vt = D_004D9240;
    l->fC = 0;
    l->f1C = 0;
    l->f1D = 0;
    l->f1E = a;
    l->color = *c;
    one = 1.0f;
    l->dir.x = 0.0f;
    l->dir.y = 0.0f;
    l->dir.z = 0.0f;
    l->dir.w = one;
    g_LevelLightsDirty = 1;
    w = c->w; z = c->z; y = c->y; x = c->x;
    v.x = x; v.y = y; v.z = z; v.w = w;
    l->f18 = one / LenSqP(&v);
    return l;
}
