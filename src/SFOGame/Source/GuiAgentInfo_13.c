/*
 * SFOGame/Source/GuiAgentInfo: 9 files, 00364D20-003652C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00364D20 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#pragma bool off
struct Seg364D20 { char pad[0x10]; float end; };
struct Pair364D20 { float a; float b; };
class Ch364D20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetRate();
    int a;
    float b8;
    float bc;
    float b10;
    int b14;
    int b18;
    int b1C;
    Pair364D20 out;
    float scale;
    char pad2[0x30 - 0x2C];
    Seg364D20* ref;
    float cur;
    unsigned char wrap;
};
extern "C" float Libc_Fmodf(float, float);
extern "C" int cSplinedMotion_float_HasTransitionJustBeenStarted(Ch364D20*);
extern "C" int cSplinedMotion_float_IsTransitionInProgress(Ch364D20*);
extern "C" void cHermiteSplineWithScaledDuration_float_Reset(void*, float*, float*, float*, float*);
extern "C" void cHermiteSplineWithScaledDuration_float_ResetPoint(void*, int, float*, float*);
extern "C" void func_0017CA90(void* p, float d, int n);
extern "C" void* opNew_uint_voidP(int kind, void* p);
extern "C" void cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(void* p, float s, void* a, void* b, void* c, float* r);
extern float D_00492ED0;
extern float D_00492ED8;
static inline int IsZero_364D20(float f) { return 0.0f == f; }
static inline float Wrap_364D20(Ch364D20* p, float d)
{
    float r;
    if (!p->wrap) {
        return d;
    }
    r = Libc_Fmodf(d, 1.0f);
    if (r < 0.5f) {
        r += 1.0f;
    } else if (r > 0.5f) {
        r -= 1.0f;
    }
    return r;
}
static inline void Set_364D20(Pair364D20* q, float a, float b) { q->a = a; q->b = b; }
extern "C" void func_00364D20(Ch364D20* o)
{
    if (!o->wrap) {
        if (cSplinedMotion_float_HasTransitionJustBeenStarted(o)) {
            float r = o->GetRate();
            cHermiteSplineWithScaledDuration_float_Reset(&o->b18, &o->b8, &o->bc, &o->b10, &r);
        } else if (cSplinedMotion_float_IsTransitionInProgress(o)) {
            float r = o->GetRate();
            cHermiteSplineWithScaledDuration_float_ResetPoint(&o->b18, 1, &o->b10, &r);
        }
    } else {
        unsigned char flag = 0;
        if (o->cur == o->ref->end && !(o->scale <= 0.0f)) {
            flag = 1;
        }
        if (flag) {
            void* p;
            float d = Wrap_364D20(o, o->b10 - o->b8);
            o->b10 = o->b8 + d;
            func_0017CA90(&o->b18, d, -1);
            p = opNew_uint_voidP(0x18, &o->b18);
            if (p) {
                cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(p, o->scale, &o->b8, &o->bc, &o->b10, &D_00492ED0);
            }
        } else if ((IsZero_364D20(o->cur) ^ 1)) {
            Pair364D20* q = &o->out;
            float base = q->a;
            float d = Wrap_364D20(o, o->b10 - base);
            o->b10 = base + d;
            Set_364D20(q, o->b10, D_00492ED8 * o->scale);
        }
    }
}
static inline void merge_flush_func_00364D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364D20 */

/* merge_units: begin func_00364FB0 */
#pragma push /* merge_units */
typedef struct { float a; float b; } FPair;
typedef struct { FPair items[2]; float scale; } FPairTable;

/* Sets entry idx to (*a, *b * scale). */
void func_00364FB0(FPairTable* self, int idx, float* a, float* b)
{
    float scaled = *b * self->scale;
    self->items[idx].a = *a;
    self->items[idx].b = scaled;
}
static inline void merge_flush_func_00364FB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364FB0 */

/* merge_units: begin func_00364FE0 */
#pragma push /* merge_units */
typedef struct { int a[13]; float f; } S364;
int func_00364FE0(S364* s) { return !(s->f == 0.0f); }
static inline void merge_flush_func_00364FE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364FE0 */

/* merge_units: begin func_00365010 */
#pragma push /* merge_units */
#pragma cplusplus on
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_5010b { float v; float s; Key_5010b() {} };
struct Crv_5010b { Key_5010b k[2]; float dur; float inv; };
/* rebuild a two-key segment in place, keeping its duration */
#pragma push
#pragma opt_unroll_loops off
static inline Crv_5010b* Init_5010b(Crv_5010b* c, float* v0, float* s0, float* v1, float* s1, float dur)
{
    float vs0; float vs1;
    vs1 = *s1 * dur; vs0 = *s0 * dur;
    { Key_5010b* e = c->k; do { new (e) Key_5010b; } while (++e != c->k + 2); }
    c->k[0].v = *v0;
    c->k[0].s = vs0;
    c->k[1].v = *v1;
    c->k[1].s = vs1;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
extern "C" void AnimChannel_RebuildSegment_365010(Crv_5010b* c, float* v0, float* s0, float* v1, float* s1)
{
    if (c) Init_5010b(c, v0, s0, v1, s1, c->dur);
}
#pragma pop
static inline void merge_flush_func_00365010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00365010 */

/* merge_units: begin func_003650B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float f10; } A5_003650B0_B;
typedef struct { char pad[0x28]; float f28; char pad2[4]; A5_003650B0_B* b; float f34; } A5_003650B0;
int AnimChannel_IsFreshSegment_3650B0(A5_003650B0* p) {
    return p->f34 == p->b->f10 && p->f28 > 0.0f;
}
static inline void merge_flush_func_003650B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003650B0 */

/* merge_units: begin func_00365100 */
#pragma push /* merge_units */
typedef struct { char pad0[8]; float t; char pad1[0x38 - 0xC]; unsigned char wrap; } B4Obj3;
extern float Libc_Fmodf(float, float);
static inline float b4clamp(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
void AnimChannel_ClampValue_365100(B4Obj3* p) {
    float t = p->t;
    float r;
    if (!p->wrap) {
        r = b4clamp(t, 0.0f, 1.0f);
    } else {
        r = Libc_Fmodf(t, 1.0f);
        if (r < 0.0f) r += 1.0f;
    }
    p->t = r;
}
static inline void merge_flush_func_00365100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00365100 */

/* merge_units: begin func_00365180 */
#pragma push /* merge_units */
static inline float fmax_(float a, float b) { float r; asm { max.s r, a, b } return r; }
typedef struct {
    char pad0[4];
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    char pad18[0x20];
    unsigned char b38;
} B7_AnimCh;
static inline float B7_Wrap(B7_AnimCh* p, float d)
{
    float r;
    if (!p->b38) {
        return d;
    }
    r = Libc_Fmodf(d, 1.0f);
    if (r < 0.5f) {
        r += 1.0f;
    } else if (r > 0.5f) {
        r -= 1.0f;
    }
    return r;
}
void AnimChannel_UpdateRate_365180(B7_AnimCh* p, float dt, float speed)
{
    float d = B7_Wrap(p, p->f8 - p->f4);
    p->fC = speed * d;
    p->fC *= fmax_(0.0f, 1.0f - p->f14 * dt);
}
static inline void merge_flush_func_00365180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00365180 */

/* merge_units: begin func_00365260 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(GuiAgentDisplay_dtor, GuiAgentDisplay_vtable, GuiWidget_dtor)
static inline void merge_flush_func_00365260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00365260 */

/* merge_units: begin func_003652C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */



int GuiAgentDisplay_GetClassName(void) {
    return (int)"GuiAgentDisplay";
}
static inline void merge_flush_func_003652C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003652C0 */
