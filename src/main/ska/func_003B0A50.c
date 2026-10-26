#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    V MulX(const V& b) const { V c; const V* r = &b; V* d = &c; const V* l = this;  __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory"); return c; }
    bool IsIdent() const { bool b = w == 1.0f; return b; }
    bool NotIdentR() const { return !IsIdent(); }
    V operator*(const V& b) const {
        V c; const V* l = this; V* d = &c; const V* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
} __attribute__((aligned(16)));

static inline V W(const V& a, const V& b) { return a.MulX(b); }
struct Sel { char pad0[0x10]; V rot; char pad20[0x1C]; float wgt; int id; char pad44[0xC]; int ch; float lo; float hi; char pad5C[4]; float ax, ay, az; };
struct AnimContribution { char pad[0x20]; };
extern "C" {
extern float D_004BCD68;
float Math_Cos(float);
float Math_Sin(float);
char* cArray_cSkaSliderValue_opIndex(void* v, int i);
float cSkaSliderValue_opCast_float(char* c);
int AnimContext_GetCount(void* s);
void** PtrStack_Top(void* s);
void* AnimBlend_GetGroupCollection(void* b);
void AnimContribution_Init(AnimContribution* c, Sel* clip, const V* q, float w);
void AnimGroup_AddContribution(void* g, AnimContribution* c, int id, float w);
void cSkaPlaybackItem_dtor(AnimContribution* c, int f);
}
static inline void Submit(Sel* self, const V* r, char* ctx, float w)
{
    int id = self->id;
    float wt = self->wgt;
    if (AnimContext_GetCount(ctx + 0x14)) {
        void* blend = *PtrStack_Top(ctx + 0x14);
        if (blend) {
            AnimContribution c;
            AnimContribution_Init(&c, self, r, w);
            AnimGroup_AddContribution(AnimBlend_GetGroupCollection(blend), &c, id, wt);
            cSkaPlaybackItem_dtor(&c, -1);
        }
    }
}
static inline void Submit2(Sel* self, const V* r, char* ctx, float w) { Submit(self, r, ctx, w); }
extern "C" void cSkaRotatableAnim_UpdateNodes(Sel* self, const V* q, char* ctx, float t)
{
    if (t < D_004BCD68) return;
    float k = cSkaSliderValue_opCast_float(cArray_cSkaSliderValue_opIndex(ctx + 0x78, self->ch));
    V quat;
    V aa;
    float ang = self->lo + k * (self->hi - self->lo);
    aa.x = self->ax;
    aa.y = self->ay;
    aa.z = self->az;
    aa.w = ang;
    float h = 0.5f * aa.w;
    float c = Math_Cos(h);
    float s = Math_Sin(h);
    quat.x = s * aa.x;
    quat.y = s * aa.y;
    quat.z = s * aa.z;
    quat.w = c;
    if (q->w != 1.0f) quat = *q * quat;
    if (self->rot.NotIdentR()) { V t2 = W(quat, self->rot); quat = t2; }
    Submit2(self, &quat, ctx, t);
}



