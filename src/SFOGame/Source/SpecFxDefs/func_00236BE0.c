#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
static inline void Q16b(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V4b {
    float x, y, z, w;
    V4b() {}
    V4b(const V4b& o) { const V4b* ss = &o; V4b* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(ss) : "memory"); }
    V4b& operator=(const V4b& o) { V4b* d = this; const V4b* ss = &o; Q16b(d, ss); return *this; }
} __attribute__((aligned(16)));
struct V4p : V4b {
    V4p(const V4b& o) { V4b* d = this; Q16b(d, &o); }
};
struct M4b { V4b r[4]; };
struct Obj_236BE0 {
    char pad[0xC];
    void* node;
    M4b m;
};
extern "C" V4b* cParticle_GetBBox(void* node);
extern "C" int XLib_TestBBox_cVectorR_cVectorR(void* obj, V4b* a, V4b* b);
extern "C" void cParticle_Render(void* node, int arg, M4b* m);
extern "C" char g_Video[];
static inline void My_236BE0(V4b* a, M4b* b) {
    asm {
        lqc2 vf8, 0x0(a)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(a)
    }
}
static inline void Mx_236BE0(V4b* a, Obj_236BE0* s) { My_236BE0(a, &s->m); }
static inline V4b Xf_236BE0(Obj_236BE0* s, V4p v) {
    V4b* a = &v;
    Mx_236BE0(a, s);
    return *a;
}

extern "C" void cParticleFx_SfxRender(Obj_236BE0* self);
void cParticleFx_SfxRender(Obj_236BE0* self) {
    void* n = self->node;
    if (n) {
        V4b* v = cParticle_GetBBox(n);
        V4b p0 = Xf_236BE0(self, v[0]);
        V4b p1 = Xf_236BE0(self, v[1]);
        cParticle_Render(self->node, XLib_TestBBox_cVectorR_cVectorR(g_Video, &p0, &p1), &self->m);
    }
}









