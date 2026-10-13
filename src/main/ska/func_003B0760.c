#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies and VU0 ops as GCC-style volatile asm; unused xx locals reproduce retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    bool IsIdent() const { bool b = w == 1.0f; return b; }
    bool NotIdentR() const { return !IsIdent(); }
    bool NotIdent() const { bool b = !IsIdent(); return b; }
    V operator*(const V& b) const {
        V c; const V* r = &b; const V* l = this; V* d = &c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
} __attribute__((aligned(16)));

struct Ctx;
struct EvNode {
    virtual void v0();
    virtual void Eval(float t, const V* q, Ctx* c);
};
struct Elem { EvNode* node; float start; float fade; };
struct Sel { char pad0[0x10]; V rot; int idx; char vec[4]; unsigned int n; char pad2C[8]; unsigned char smooth; };
/* child-array iterator: Begin2 returns a named copy (temp slot 0xA4); operator= copies the 4-byte object through an FPR as retail does */
struct It { Elem* p; It(Elem* e) : p(e) {} It(const It& o) : p(o.p) {} void Inc() { p++; } Elem* operator->() const { return p; } It& operator=(const It& o) { const It* s = &o; It* d = this; *(float*)d = *(const float*)s; return *this; } };
static inline It Begin2(Elem** d) { It r(*d); return r; }

static inline float MinF(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline const V* Pick(Sel* self, const V* q) {
    const V* r;
    if (self->rot.NotIdent()) {
        if (q->NotIdentR()) {
            V a = *q * self->rot;
            V b = a;
            r = &b;
        } else {
            r = &self->rot;
        }
        return r;
    }
    return q;
}

extern "C" {
extern float D_004BCD68;
float AnimChannel_GetCurrent(Ctx* c, int i);
Elem** MotionChildArr_GetData(void* v);
void MotionSlider_Evaluate(Sel* self, float t, const V* q, Ctx* ctx);
}

void MotionSlider_Evaluate(Sel* self, float t, const V* q, Ctx* ctx)
{
    if (t < D_004BCD68) return;
    const V* r = Pick(self, q);
    float pos = AnimChannel_GetCurrent(ctx, self->idx);
    unsigned int n = self->n;
    It cur = Begin2(MotionChildArr_GetData(&self->vec));
    It next = cur;
    next.Inc();
    float start = cur->start;
    float w = 0.0f;
    for (unsigned int i = 1; i < n + 1; i++) {
        int last = i >= n;
        float fade = cur.p->fade;
        float end = !last ? next.p->start : 1.0f;
        float rem = 0.0f;
        if (!(pos < start) && (pos < end || last)) {
            if (pos > fade && !last) {
                float x = (end - pos) / (end - fade);
                if (self->smooth) { float x2 = x * x; x = 3.0f * x2 - 2.0f * (x * x2); }
                w = t * x;
                w = MinF(t, w);
                rem = t - w;
            } else {
                w = t;
            }
        }
        if (w != 0.0f) cur.p->node->Eval(w, r, ctx);
        cur = next;
        start = end;
        w = rem;
        next.Inc();
    }
}
