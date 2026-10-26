/* NpcRoute_BuildRegionBoxes: once per level, build the axis-aligned bounding
 * box of every route region's nodes (grown by 2 units on each side). */
#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
#include "alloc_guard.h"
/* lq/sq and VU0 ops: no C equivalent (asm). */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V4& operator=(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void AddXYZ(V4* a, const V4* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(a), "r"(b) : "memory");
}
static inline V4 operator-(const V4& a) { V4 r; V4* pr = &r; const V4* pa = &a; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa) : "memory"); return r; }
struct Box0 { V4 lo, hi;
    Box0& operator=(const Box0& o) { __int128 t0; __int128 t1; Box0* d = this; const Box0* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); sq %1, 0x10(%2)" : "=&r"(t0), "=&r"(t1) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct Box : Box0 {
    Box() {
        lo.x = 3.4028235e38f; lo.y = 3.4028235e38f; lo.z = 3.4028235e38f; lo.w = 1.0f;
        hi.x = -3.4028235e38f; hi.y = -3.4028235e38f; hi.z = -3.4028235e38f; hi.w = 1.0f;
    }
    void Extend(V4* p) { V4* l = &lo; V4* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(p) : "memory"); }
    void Reset() {
        lo = V4(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
        hi = V4(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    }
};
struct BoxVec { int p0; int n; Box* data; unsigned char owned; void Resize(int n, Box* f); Box& At(int i) { Box** pd = &data; return (*pd)[i]; } };
struct Region { int p0; int n; int p8[2]; };
struct RegionVec { int p0; int n; Region* data; };
extern "C" {
extern BoxVec* D_004EE118;
extern int D_004FFBE4;
extern RegionVec* D_004FFBE8;
extern char D_0049C1B8[];
void* Mem_Alloc(int, int, char*, int);
void std_vector_cBox_ctor(BoxVec* v);
void std_vector_imp_cBox_resize(BoxVec* v, int n, Box* fill);
int* std_vector_int_opIndex_uint(Region* r, int i);
void* NpcPath_GetNode(int id);
void Node_GetTranslation(V4* out, void* node);
void NpcRoute_BuildRegionBoxes(void);
}

inline void BoxVec::Resize(int n, Box* f) { std_vector_imp_cBox_resize(this, n, f); }
static inline void Grow(Box* b, float d)
{
    V4 v(d, d, d, 0.0f);
    V4 n = -v;
    AddXYZ(&b->lo, &n);
    { const V4* pv = &v; AddXYZ(&b->hi, pv); }
}
void NpcRoute_BuildRegionBoxes(void)
{
    if (!D_004EE118 && D_004FFBE4 > 0) {
        BoxVec* v;
        { AllocGuard g; v = (BoxVec*)Mem_Alloc(0, 0x10, D_0049C1B8, 0xB1A); }
        if (v) {
            std_vector_cBox_ctor(v);
            v->owned = 1;
        }
        D_004EE118 = v;
        {
            Box init;
            D_004EE118->Resize(D_004FFBE4, &init);
        }
        for (int i = 0; i < D_004FFBE4; i++) {
            Region* r = &D_004FFBE8->data[i];
            D_004EE118->data[i].Reset();
            for (int j = 0; j < r->n; j++) {
                V4 p;
                Node_GetTranslation(&p, NpcPath_GetNode(*std_vector_int_opIndex_uint(r, j)));
                D_004EE118->At(i).Extend(&p);
            }
            Grow(&D_004EE118->At(i), 2.0f);
        }
    }
}
