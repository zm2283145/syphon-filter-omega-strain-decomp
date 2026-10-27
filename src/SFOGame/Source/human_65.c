/*
 * SFOGame/Source/human: 9 files, 0019D580-0019D7D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0019D580 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

AnimChannel* std_vector_cSkaSliderValue_opIndex(ChannelVec* v, int i) {
    return &v->data[i];
}
static inline void merge_flush_func_0019D580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D580 */

/* merge_units: begin func_0019D5A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float f10; } Src_D640;
typedef struct {
    char pad[0x1C]; float f1C; float f20; float f24; float f28; float f2C; Src_D640* p30; float f34;
} Ch_D640;
void cSplinedMotion_float_RestartTransition(Ch_D640* c, float d); /* gsynth: defined below */typedef struct {
    char pad0[0x10];
    float target;
    float damping;
    char pad18[0x20];
    unsigned char active;
    char pad39[3];
} B7_Chan;
typedef struct { char pad[0x80]; B7_Chan* chans; } B7_Anim;
#if 0 /* merge_units */
extern void cSplinedMotion_float_RestartTransition(B7_Chan* ch, float d);
#endif /* merge_units */
#define cSplinedMotion_float_RestartTransition(a0, a1) (cSplinedMotion_float_RestartTransition((Ch_D640 *)(a0), (a1))) /* merge_units */


void cSkaParams_SetSliderValue_UsingSplineForInterpolation(B7_Anim* a, int idx, unsigned int n, float target, float dur, float damping)
{
    B7_Chan* ch = &a->chans[idx];
    ch->target = target;
    ch->damping = damping;
    cSplinedMotion_float_RestartTransition(ch, dur);
    { float fn = n; float z = 0.0f; ch->active = fn != z; }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D5A0(void) {}
#undef cSplinedMotion_float_RestartTransition /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D5A0 */

/* merge_units: begin func_0019D640 */
#pragma push /* merge_units */
void cSplinedMotion_float_RestartTransition(Ch_D640* c, float d) {
    float s;
    if (d >= 0.0f) {
        s = d * c->f2C;
        c->f1C = c->f1C * s;
        c->f24 = c->f24 * s;
        c->f28 = d;
        c->f2C = d != 0.0f ? 1.0f / d : 0.0f;
        c->f34 = c->p30->f10;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D640(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D640 */

/* merge_units: begin func_0019D6C0 */
#pragma push /* merge_units */
void cSkaParams_SetSwitchNextGoalState(char* self, int i, int value) {
    *(int*)(*(char**)(self + 144) + (i << 3)) = value;
}
static inline void merge_flush_func_0019D6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D6C0 */

/* merge_units: begin func_0019D6E0 */
#pragma push /* merge_units */
typedef struct { int pad0; int pad4; int bits[1]; } Bits_19D6E0;
static inline void Set_19D6E0(int* a, int bit) { a[bit/32] |= 1 << (bit&31); }
static inline void Clr_19D6E0(int* a, int bit) { a[bit/32] &= ~(1 << (bit&31)); }
void func_0019D6E0(Bits_19D6E0* b, int bit, int on)
{
    if (on) Set_19D6E0(b->bits, bit);
    else Clr_19D6E0(b->bits, bit);
}
static inline void merge_flush_func_0019D6E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D6E0 */

/* merge_units: begin func_0019D760 */
#pragma push /* merge_units */
/* Returns 1 if bit n is set in the bit array. */
int BitArray_Test(int* bits, int n)
{
    return ((bits[n / 32] >> (n & 31)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D760 */

/* merge_units: begin func_0019D790 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern AnimChannel* std_vector_cSkaSliderValue_opIndex(ChannelVec*, int);
#endif /* merge_units */
#define std_vector_cSkaSliderValue_opIndex(a0, a1) (std_vector_cSkaSliderValue_opIndex((a0), (a1))) /* merge_units */


/* Current value of a channel in the collection at +0x88 (index is not set by the caller-side code). */
float AnimChannel_GetCurrentValue(char* owner) {
    int index;

    return std_vector_cSkaSliderValue_opIndex((ChannelVec*)(owner + 136), index)->base.current;
}

/* Current value of channel i in the collection at +0x78. */
float cSkaParams_GetSliderValue(char* owner, int i) {
    ChannelVec* v = (ChannelVec*)(owner + 120);

    return ((AnimChannel*)((char*)v->data + (((i << 4) - i) << 2)))->base.current;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D790(void) {}
#undef std_vector_cSkaSliderValue_opIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D790 */

/* merge_units: begin func_0019D7D0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Chan_b6 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual float Eval();
    float a4; float cur; float cC; float c10; unsigned char pad[0x3C - 0x14];
};
typedef struct { unsigned char pad[0x80]; Chan_b6* ch; } Anim_b6;
static inline float fmax_b6(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline float fmin_b6(float a, float b) { float r; asm { min.s r, a, b } return r; }
extern "C" void cSkaParams_SetSliderValue_int_float_float_bool(Anim_b6* a, int idx, int wrap, float target, float step)
{
    Chan_b6* c = &a->ch[idx];
    float v = c->cur;
    float d = target - v;
    if (wrap) {
        if (d < -0.5f) {
            d += 1.0f;
        } else if (!(d <= 0.5f)) {
            d += -1.0f;
        }
    }
    v += fmin_b6(fmax_b6(d, -step), step);
    if (wrap) {
        if (v < 0.0f) {
            v += 1.0f;
        } else if (!(v <= 1.0f)) {
            v += -1.0f;
        }
    }
    c->c10 = v;
    c->cur = v;
    c->a4 = v;
    c->cC = c->Eval();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D7D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D7D0 */

/* merge_units: begin func_0019D8E0 */
#pragma push /* merge_units */
typedef struct { int unk0; int unk4; unsigned int pending[1]; } D6ActorFlags;
void Actor_SetPendingFlag(D6ActorFlags* a, unsigned char bit, int on)
{
    if (on) {
        a->pending[(unsigned int)bit >> 5] |= 1 << (bit & 0x1F);
    } else {
        a->pending[(unsigned int)bit >> 5] &= ~(1 << (bit & 0x1F));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D8E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D8E0 */
