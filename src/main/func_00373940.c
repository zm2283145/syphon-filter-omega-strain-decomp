#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o, int) { __int128 t; V* d = this; const V* s = &o; d = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V(const V& o) { const V* s = &o; void* xx = this; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { void* xx = this; const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
};
struct M { float m[4][4]; } __attribute__((aligned(16)));
static inline V& XformInPlace(V* v, const M* m)
{
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2 $vf12, 0x0(%0)" : "+r"(v) : "r"(m) : "memory");
    return *v;
}
static inline V Xform3(V v, const M* m) { V& r = XformInPlace(&v, m); return V(r, 0); }
static inline void Sub(V* c, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(c), "r"(a), "r"(b) : "memory"); }
struct LV { char vpad[4]; virtual float v0(); virtual float v1(); virtual float v2(); virtual float v3(); virtual float v4(); virtual float v5(); virtual float v6(); virtual float v7(); virtual float v8(); virtual float v9(); virtual float v10(); virtual float v11(); };
struct Light {
    char pad0[4];
    void* vt;
    char pad8[0x14 - 0x8];
    float x14;
    float x18;
    unsigned char x1C;
    unsigned char x1D;
    signed char type;
    char pad1F[0x30 - 0x1F];
    V pos;
};
struct LEnt { signed char type; unsigned char x61; unsigned char code; char pad; Light* light; float x68; float x6C; V pos; };
struct LMgr { char pad0[0x4C]; int count; char pad50[0x10]; LEnt ents[1]; };
extern "C" {
void Renderer_UpdateCameraMatrices(void*);
unsigned int Shadow_ClipCode(void*, M*, V*);
extern char D_005381F0[];
extern M D_005390F0;
}
/* Adds a light to the manager's per-frame table if it is directional (type 2), its transformed
   position passes the camera clip test, or it lies within its radius (+f) of the camera. */
extern "C" void LightMgr_BuildTable(LMgr* self, Light* l, M* m, V* cam, float f)
{
    int code;
    bool ok;
    if (!l->x1C) return;
    if ((unsigned char)l->type == 2) {
        code = 1;
        ok = true;
    } else {
        V q = Xform3(l->pos, m); V e; V d;
        Renderer_UpdateCameraMatrices(D_005381F0);
        M* view = &D_005390F0;
        ok = (Shadow_ClipCode(D_005381F0, view, &q) & ~0x40) == 0;
        if (ok) {
            code = 3;
        } else {
            float lim = f + 0.5f * ((LV*)l)->v11();
            Sub(&d, cam, &q);
            e = d;
            ok = e.Length() < lim;
            if (ok) {
                code = 2;
            }
        }
    }
    if (ok) {
        self->ents[self->count].type = l->type;
        self->ents[self->count].x61 = (unsigned char)(int)l->x1D;
        self->ents[self->count].code = (unsigned char)code;
        self->ents[self->count].light = l;
        self->ents[self->count].x68 = l->x14;
        self->ents[self->count].x6C = l->x18;
        self->ents[self->count].pos = l->pos;
        self->count++;
    }
}