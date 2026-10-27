/*
 * Libs/SFOLib/Source/animator: 8 files, 003F4190-003F4510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F4190 */
#pragma push /* merge_units */
#include "types.h"
#include "last_key_time.h"

/* Time of the last key. */
DEFINE_LAST_KEY_TIME(cKeyframeAnimation_cXyz_NumFrames)
static inline void merge_flush_func_003F4190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F4190 */

/* merge_units: begin func_003F41C0 */
#pragma push /* merge_units */
/* cKeyframeAnimation_tRGB_Update: piecewise-linear evaluation of a 3-component (colour) track;
 * the key search is cKeyframeAnimation_float_Update's (interface_model_3F3E70.c). */
typedef struct { float t; float v[3]; } Key;
typedef struct {
    char pad0[0x18];
    int cur;
    float* out;
    char pad20[4];
    int count;
    Key* keys;
} Curve;

static inline Key* KeyAt(Key* k, int i) { return &k[i]; }
static inline void Copy3(float* o, Key* k) { o[0] = k->v[0]; o[1] = k->v[1]; o[2] = k->v[2]; }
static inline Key* Last(Curve* c) { return c->keys + c->count - 1; }

#pragma opt_strength_reduction off
#pragma opt_propagation off
void cKeyframeAnimation_tRGB_Update(Curve* c, float t)
{
    /* Local declaration order matters for register allocation.
     * `cc` (an un-propagated alias of c) makes the second scan loop reload
     * keys from memory each iteration, as retail does. */
    Curve* cc = c;
    int i;
    Key* keys;
    Key** pk;
    float* o; /* declared last: keeps out in t0 (retail) */
    if (*(volatile int*)&c->count > 0) {
        pk = &c->keys;
        keys = c->keys;
        if (t <= KeyAt(keys, 0)->t) {
            Copy3(c->out, KeyAt(keys, 0));
            c->cur = 0;
        } else if (!(t < Last(c)->t)) {
            Copy3(c->out, Last(c));
            c->cur = c->count - 1;
        } else {
            i = c->cur;
            while (t < KeyAt(keys, i)->t)
                i--;
            if (t > KeyAt(keys, i + 1)->t) {
                do {
                    i++;
                } while (t > KeyAt(cc->keys, i + 1)->t);
            }
            c->cur = i;
            {
                Key* ks = *pk;
                Key* k0 = &ks[i];
                Key* k1 = &ks[i + 1];
                float t0;
                float r, g, b; float sb, sg, sr;
                t0 = k0->t;
                /* each sum is computed before its scale (retail's fused/unfused split) */
                sb = k1->v[2] * (t - t0) + k0->v[2] * (k1->t - t);
                b = sb * (1.0f / (k1->t - t0));
                sg = k1->v[1] * (t - t0) + k0->v[1] * (k1->t - t);
                g = sg * (1.0f / (k1->t - t0));
                sr = k1->v[0] * (t - t0) + k0->v[0] * (k1->t - t);
                r = sr * (1.0f / (k1->t - t0));
                o = c->out;
                o[0] = r;
                o[1] = g;
                o[2] = b;
            }
        }
    }
}
static inline void merge_flush_func_003F41C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F41C0 */

/* merge_units: begin func_003F4360 */
#pragma push /* merge_units */
/* Time of the last key. */
DEFINE_LAST_KEY_TIME(cKeyframeAnimation_tRGB_NumFrames)
static inline void merge_flush_func_003F4360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F4360 */

/* merge_units: begin func_003F4390 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_003F4390(char* self) {
    *(int*)(self + 4) = 0;
}

void func_003F43A0(char* self) {
    *(int*)(self + 4) = 0;
}

void func_003F43B0(char* self) {
    *(int*)(self + 4) = 0;
}
static inline void merge_flush_func_003F4390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F4390 */

/* merge_units: begin func_003F43C0 */
#pragma push /* merge_units */
void cAnimator_Update(void) {
}
static inline void merge_flush_func_003F43C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F43C0 */

/* merge_units: begin func_003F43D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct B7_Ramp {
    virtual void v0(); virtual void v1();
    virtual void SetValue(float v); /* +0x10 */
    float value;
    float min;
    float max;
    float vel;
    unsigned char pingpong;
};
extern "C" void cAnimator_NextFrame(B7_Ramp* r, float dt)
{
    if (r->vel != 0.0f) {
        r->value += r->vel * dt;
        if (r->vel > 0.0f) {
            if (r->value > r->max) {
                if (r->pingpong) {
                    r->vel = -r->vel;
                    r->value = r->max;
                } else if (r->min == r->max) {
                    r->vel = 0.0f;
                    r->value = r->max;
                } else {
                    r->value = r->min;
                }
            }
        } else {
            if (r->value < r->min) {
                if (r->pingpong) {
                    r->vel = -r->vel;
                    r->value = r->min;
                } else if (r->min == r->max) {
                    r->vel = 0.0f;
                    r->value = r->min;
                } else {
                    r->value = r->max;
                }
            }
        }
        r->SetValue(r->value);
    }
}
static inline void merge_flush_func_003F43D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F43D0 */

/* merge_units: begin func_003F44E0 */
#pragma push /* merge_units */
typedef struct { int f0; float f4; float f8; float fC; float f10; char b14; } S3F44E0;
void cAnimator_AnimateTo(S3F44E0* s, float x) {
    s->f8 = x;
    s->fC = x;
    if (s->f4 <= x) {
        s->f10 = 1.0f;
    } else {
        s->f10 = -1.0f;
    }
    s->b14 = 0;
}
static inline void merge_flush_func_003F44E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F44E0 */

/* merge_units: begin func_003F4510 */
#pragma push /* merge_units */
typedef struct { int pad0; float cur; float lo_; float hi_; float vdir; unsigned char fl; } S3F4510;
void cAnimator_StartAnimation(S3F4510* s, float lo_, float hi_, unsigned char fl)
{
    if (hi_ < lo_) {
        float t = lo_;
        lo_ = hi_;
        hi_ = t;
    }
    s->lo_ = lo_;
    s->hi_ = hi_;
    if (s->cur < lo_) {
        s->vdir = 1.0f;
    } else if (s->cur > hi_) {
        s->vdir = -1.0f;
    } else if (s->vdir != 1.0f && s->vdir != -1.0f) {
        s->vdir = 1.0f;
    }
    s->fl = fl;
}
static inline void merge_flush_func_003F4510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F4510 */
