#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; V* d = this; const V* s = &o; __int128 q;  __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
    float& operator[](int i) { return (&x)[i]; }
} __attribute__((aligned(16)));
extern "C" V* cMatrix_GetAxis(void* m, int i);
struct R4 {
    float x, y, z, w;
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
struct M4 {
    R4 r[4];
    V* Row(int k) { return cMatrix_GetAxis(this, k); }
    void SetRow(int k, const V& v) { r[k].Set(v.x, v.y, v.z, v.w); }
};
template <class T> struct Vec { T* data; T& At(int i) { Vec* p = this; return p->data[i]; } T& At2(int i) { return At(i); } T& operator[](int i) { return At(i); } };
struct V3 { float x, y, z; float& operator[](int i) { return (&x)[i]; } };
struct SNode {
    char pad[0x110];
    M4 m;
    char pad2[0x1D0 - 0x150];
};
struct VT : V { VT(const V& o) { void* xx = this; const V* s = &o; __int128 q; V* d = this;  __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); } };
static inline V WithComp(VT t, int k, float f) { V* p = &t; (&p->x)[k] = f; return *p; }
static inline void CPa(V* d0, const V* s0) { const V* s = s0;__int128 q;V* d = d0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct VT3 : V { VT3(const V& o) { void* xx = this; CPa(this, &o); } };
static inline V W3(VT3 t, int k, float f) { V* p = &t; (&p->x)[k] = f; return *p; }
struct S { char pad[0xC]; Vec<V3> scales; char pad10[4]; unsigned char x14; char pad15[7]; int count; Vec<SNode> nodes; };
#define BLK3(K, C) { float f = s->scales[i].C;SNode* nd = &s->nodes[i]; V r = W3(*nd->m.Row(K), K, f); nd->m.SetRow(K, r); }
#define BLK(K, C) { float f = s->scales[i].C;SNode* nd = &s->nodes[i]; V r = WithComp(*nd->m.Row(K), K, f); nd->m.SetRow(K, r); }
extern "C" void cSkeleton_SetupBoneScaleMatrices(S* s);
void cSkeleton_SetupBoneScaleMatrices(S* s)
{
    if (s->x14) {
        int n = s->count;
        for (int i = 0; i < n; i++) {
            BLK(0, x)
            BLK(1, y)
            BLK3(2, z)
        }
    }
}





