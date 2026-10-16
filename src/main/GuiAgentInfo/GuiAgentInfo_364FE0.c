/*
 * main/GuiAgentInfo: range (6 files, 00364FE0-00365260)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00364FE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a[13]; float f; } S364;
int func_00364FE0(S364* s) { return !(s->f == 0.0f); }
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
extern "C" void func_00365010(Crv_5010b* c, float* v0, float* s0, float* v1, float* s1)
{
    if (c) Init_5010b(c, v0, s0, v1, s1, c->dur);
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00365010 */

/* merge_units: begin func_003650B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float f10; } A5_003650B0_B;
typedef struct { char pad[0x28]; float f28; char pad2[4]; A5_003650B0_B* b; float f34; } A5_003650B0;
int func_003650B0(A5_003650B0* p) {
    return p->f34 == p->b->f10 && p->f28 > 0.0f;
}
#pragma pop /* merge_units */
/* merge_units: end func_003650B0 */

/* merge_units: begin func_00365100 */
#pragma push /* merge_units */
typedef struct { char pad0[8]; float t; char pad1[0x38 - 0xC]; unsigned char wrap; } B4Obj3;
extern float Math_FMod(float, float);
static inline float b4clamp(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
void func_00365100(B4Obj3* p) {
    float t = p->t;
    float r;
    if (!p->wrap) {
        r = b4clamp(t, 0.0f, 1.0f);
    } else {
        r = Math_FMod(t, 1.0f);
        if (r < 0.0f) r += 1.0f;
    }
    p->t = r;
}
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
    r = Math_FMod(d, 1.0f);
    if (r < 0.5f) {
        r += 1.0f;
    } else if (r > 0.5f) {
        r -= 1.0f;
    }
    return r;
}
void func_00365180(B7_AnimCh* p, float dt, float speed)
{
    float d = B7_Wrap(p, p->f8 - p->f4);
    p->fC = speed * d;
    p->fC *= fmax_(0.0f, 1.0f - p->f14 * dt);
}
#pragma pop /* merge_units */
/* merge_units: end func_00365180 */

/* merge_units: begin func_00365260 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(func_00365260, D_004DF530, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_00365260 */
