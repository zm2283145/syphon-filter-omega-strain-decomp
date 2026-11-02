/*
 * Libs/SFOLib/Source/ska: 3 files, 003B0730-003B0A50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B0730 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Table entry i (8-byte entries at +0x90). */
SkaPair* cSkaParams_GetSwitchValue(SkaPairTableOwner* owner, int i) {
    return &owner->table[i];
}

/* Address of element i in an array of 36-byte elements at +0x0C. */
char* cSkaSwitchItem_GetTrans(SkaTable0C* t, int i) {
    char* data = t->data;
    return data + i * 36;
}
static inline void merge_flush_func_003B0730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B0730 */

/* merge_units: begin func_003B0760 */
#pragma push /* merge_units */
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
float cSkaParams_GetSliderValue(Ctx* c, int i);
Elem** std_vector_deleter_cSkaBlendSequenceItem_data_void_2(void* v);
void cSkaSlider_UpdateNodes(Sel* self, float t, const V* q, Ctx* ctx);
}

void cSkaSlider_UpdateNodes(Sel* self, float t, const V* q, Ctx* ctx)
{
    if (t < D_004BCD68) return;
    const V* r = Pick(self, q);
    float pos = cSkaParams_GetSliderValue(ctx, self->idx);
    unsigned int n = self->n;
    It cur = Begin2(std_vector_deleter_cSkaBlendSequenceItem_data_void_2(&self->vec));
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
static inline void merge_flush_func_003B0760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B0760 */

/* merge_units: begin func_003B0A50 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V_003B0A50 {
    float x, y, z, w;
    V_003B0A50() {}
    V_003B0A50(const V_003B0A50& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V_003B0A50& operator=(const V_003B0A50& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    V_003B0A50 MulX(const V_003B0A50& b) const { V_003B0A50 c; const V_003B0A50* r = &b; V_003B0A50* d = &c; const V_003B0A50* l = this;  __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory"); return c; }
    bool IsIdent() const { bool b = w == 1.0f; return b; }
    bool NotIdentR() const { return !IsIdent(); }
    V_003B0A50 operator*(const V_003B0A50& b) const {
        V_003B0A50 c; const V_003B0A50* l = this; V_003B0A50* d = &c; const V_003B0A50* r = &b;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
} __attribute__((aligned(16)));

static inline V_003B0A50 W(const V_003B0A50& a, const V_003B0A50& b) { return a.MulX(b); }
struct Sel_003B0A50 { char pad0[0x10]; V_003B0A50 rot; char pad20[0x1C]; float wgt; int id; char pad44[0xC]; int ch; float lo; float hi; char pad5C[4]; float ax, ay, az; };
struct AnimContribution { char pad[0x20]; };
extern "C" {
float Libc_Cosf(float);
float Libc_Sinf(float);
char* cArray_cSkaSliderValue_opIndex(void* v, int i);
float cSkaSliderValue_opCast_float(char* c);
int AnimContext_GetCount(void* s);
void** PtrStack_Top(void* s);
void* AnimBlend_GetGroupCollection(void* b);
void cSkaPlaybackItem_ctor(AnimContribution* c, Sel_003B0A50* clip, const V_003B0A50* q, float w);
void cSkaPlaybackList_Add(void* g, AnimContribution* c, int id, float w);
void cSkaPlaybackItem_dtor(AnimContribution* c, int f);
}
static inline void Submit(Sel_003B0A50* self, const V_003B0A50* r, char* ctx, float w)
{
    int id = self->id;
    float wt = self->wgt;
    if (AnimContext_GetCount(ctx + 0x14)) {
        void* blend = *PtrStack_Top(ctx + 0x14);
        if (blend) {
            AnimContribution c;
            cSkaPlaybackItem_ctor(&c, self, r, w);
            cSkaPlaybackList_Add(AnimBlend_GetGroupCollection(blend), &c, id, wt);
            cSkaPlaybackItem_dtor(&c, -1);
        }
    }
}
static inline void Submit2(Sel_003B0A50* self, const V_003B0A50* r, char* ctx, float w) { Submit(self, r, ctx, w); }
extern "C" void cSkaRotatableAnim_UpdateNodes(Sel_003B0A50* self, const V_003B0A50* q, char* ctx, float t)
{
    if (t < D_004BCD68) return;
    float k = cSkaSliderValue_opCast_float(cArray_cSkaSliderValue_opIndex(ctx + 0x78, self->ch));
    V_003B0A50 quat;
    V_003B0A50 aa;
    float ang = self->lo + k * (self->hi - self->lo);
    aa.x = self->ax;
    aa.y = self->ay;
    aa.z = self->az;
    aa.w = ang;
    float h = 0.5f * aa.w;
    float c = Libc_Cosf(h);
    float s = Libc_Sinf(h);
    quat.x = s * aa.x;
    quat.y = s * aa.y;
    quat.z = s * aa.z;
    quat.w = c;
    if (q->w != 1.0f) quat = *q * quat;
    if (self->rot.NotIdentR()) { V_003B0A50 t2 = W(quat, self->rot); quat = t2; }
    Submit2(self, &quat, ctx, t);
}
static inline void merge_flush_func_003B0A50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B0A50 */
