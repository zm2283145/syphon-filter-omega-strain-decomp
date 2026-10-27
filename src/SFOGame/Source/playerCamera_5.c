/*
 * SFOGame/Source/playerCamera: 2 files, 00280390-00280470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00280390 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x320C];
    int x320C;
    char pad3210[0x3248 - 0x3210];
    int x3248;
} O_280390;
void ModifyCameraTrackingPoint_ForHuman(float* out, O_280390* o, signed char mode, int flag)
{
    switch (mode) {
    case 0:
        break;
    case 1:
        if (o->x320C == 16) {
            if ((o->x3248 >> 29) & 1)
                *out = -3.0f;
            else
                *out = -6.3f;
        } else if (flag) {
            *out = -0.5f;
        } else if (o->x320C == 1) {
            *out = -3.0f;
        } else if (o->x320C == 8 || o->x320C == 7) {
            *out = -7.0f;
        } else {
            return;
        }
        break;
    case 2:
        *out = -6.3f;
        break;
    case 3:
        break;
    }
}
static inline void merge_flush_func_00280390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00280390 */

/* merge_units: begin func_00280470 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void Q16s(const void* s, void* d) { Q16(d, s); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o;V* d = this;__int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { Q16s(&o, this); return *this; }
    V operator-() const { V t; __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
} __attribute__((aligned(16)));
static inline void CPa(V* d0, const V* s0) { const V* s = s0;__int128 q;V* d = d0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
struct VR : V { VR() {} VR(const VR& o) { void* xx = this; CPa(this, &o); } };
static inline void ScaleI(V* pr, V* pa, float k)
{
    int t;__int128 tt = 0;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(pa), "r"(pr), "f"(k) : "memory");
}
static inline void ScaleJ(V* pr, V* pa, float k) { V* p2 = pa; ScaleI(pr, p2, k); }
static inline VR operator*(V a, float k)
{
    VR r;
    ScaleJ(&r, &a, k);
    return r;
}
struct M { float f[4][4]; V& R(int i) { return *(V*)f[i]; } } __attribute__((aligned(16)));
static inline M* QuatToMtx(M* a, V* b)
{
    __asm__ volatile("lqc2 vf1, 0x0(%1); vadd.xyzw vf2, vf1, vf1; vaddw.xyz vf3, vf0, vf0w; vmulx.w vf8, vf0, vf0x; vmulx.w vf9, vf0, vf0x; vmuly.xyzw vf5, vf1, vf2y; vmulz.xyzw vf6, vf1, vf2z; vmulx.xyzw vf4, vf1, vf2x; vmulx.w vf10, vf0, vf0x; vsubay.x ACC, vf3, vf5y; vmsubz.x vf8, vf3, vf6z; vsubw.x vf9, vf5, vf6w; vaddw.x vf10, vf6, vf5w; vaddw.y vf8, vf4, vf6w; vsubax.y ACC, vf3, vf4x; vmsubz.y vf9, vf3, vf6z; vsubw.y vf10, vf6, vf4w; vsubw.z vf8, vf4, vf5w; vaddw.z vf9, vf5, vf4w; vsubax.z ACC, vf3, vf4x; vmsuby.z vf10, vf3, vf5y; sqc2 vf0, 0x30(%0); sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0)" : : "r"(a), "r"(b) : "memory");
    return a;
}
struct QM : M { QM(V* q) { QuatToMtx(this, q); } };
extern "C" {
extern signed char D_004E1D88;
extern V D_004E1D90;
extern const char D_004A9338[];
void* cSkaAnimAnchorList_Find(void* self, void* key);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
V* cQuatVec_Rotation(void* p);
}
struct Key {
    char c[4];
    Key(const char* s)
    {
        bool end = false;
        for (unsigned int i = 0; i < 4; i++) {
            if (!s[i]) end = true;
            c[i] = end ? 0 : s[i];
        }
    }
};
struct Sub { char pad[0xB0]; char coll[1]; void* Coll() { return coll; } };
struct Ctx { char pad[0x2EC0]; Sub sub; Sub* S() { return &sub; } };
struct Obj { char pad[0x100]; unsigned char b100; char pad101[0xF]; V v110; char pad120[0xBD4]; int flags; };
static inline V& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f;
        D_004E1D88 = 1;
    }
    return D_004E1D90;
}
static inline void* RWr(void* c, const Key& k) { return cSkaAnimAnchorList_Find(c, (void*)&k); }
extern "C" void func_00280470(Obj* self, Ctx* ctx)
{
    int f = self->flags;
    if (((f >> 9) & 1) || ((f >> 6) & 1) || ((f >> 4) & 1)) {
        VR d = -QM(cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RWr(ctx->S()->Coll(), Key(D_004A9338))))).R(1) * 1.25f;
        self->b100 = 1;
        self->v110 = d;
    } else {
        V* z = &Zero();
        self->b100 = 0;
        __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(&self->v110), "r"(z) : "memory");
    }
}
static inline void merge_flush_func_00280470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00280470 */
