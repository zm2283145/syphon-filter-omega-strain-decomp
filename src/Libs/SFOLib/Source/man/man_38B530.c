/*
 * main/man: range (2 files, 0038B530-0038B800)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0038B530 */
#pragma push /* merge_units */
typedef struct { int t; float v; } KtKey;
float AnimMix(int t, KtKey* keys); /* gsynth: defined below */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;

typedef struct { u8 pad[0x40D]; u8 n; } Grip_38B530;
typedef struct { s8 a[0x18]; s8 b[0x18]; } GripTab_38B530;

typedef struct {
    u8 pad0[0x23D0];
    float w0;
    float w0b;
    int pad23D8;
    int k0;
    float w1;
    float w1b;
    int pad23E8;
    int k1;
    float vals[8];
    Grip_38B530* g0;
    Grip_38B530* g1;
    u8 pad2418[0x2BC1 - 0x2418];
    u8 count;
    u8 ids[8];
    u8 pad2BCA[0x2C0C - 0x2BCA];
    u8 type;
    u8 pad2C0D[0x2D90 - 0x2C0D];
    u8 s0;
    u8 s1;
    u8 s2;
    u8 pad2D93;
    s16 timer;
    s16 pad2D96;
    u16 limit;
} Equip_38B530;

extern GripTab_38B530 D_00571510[];
extern u8 D_0053B340[];
extern u8 D_0053B348[];
extern char g_MorphCurveGrip[], g_MorphCurveActive[], g_MorphCurvePeriodic[];
#if 0 /* merge_units */
extern float AnimMix(int frame, char* track);
#endif /* merge_units */
#define AnimMix(a0, a1) (AnimMix((a0), (void *)(a1))) /* merge_units */

extern int Libc_Rand(void);

void cMan_UpdateMorphs(Equip_38B530* e)
{
    u8 s;
    int i;
    float f;
    s = e->s0;
    if (s && e->g0) {
        if (s == 1) {
            i = e->g0->n + 1;
            e->w0b = 0.0f;
            if (i >= 0) {
                e->k0 = D_00571510[e->type].a[i];
                e->w0 = 1.0f;
            } else {
                e->w0 = 0.0f;
            }
        }
        f = AnimMix(e->s0, g_MorphCurveGrip);
        e->w0 = f;
        e->w0b = 1.0f - f;
    }
    s = e->s1;
    if (s && e->g1) {
        if (s == 1) {
            i = e->g1->n + 1;
            e->w1b = 0.0f;
            if (i >= 0) {
                e->k1 = D_00571510[e->type].b[i];
                e->w1 = 1.0f;
            } else {
                e->w1 = 0.0f;
            }
        }
        f = AnimMix(e->s1, g_MorphCurveGrip);
        e->w1 = f;
        e->w1b = 1.0f - f;
    }
    s = e->s2;
    if (s) {
        if (s == 1) {
            e->timer = 300;
            e->limit = 3000;
        }
        if (e->count < 8) {
            e->ids[e->count] = D_0053B340[e->type];
            e->vals[e->count] = AnimMix(e->s2, g_MorphCurveActive);
            if (!e->vals[e->count]) {
            } else {
                e->count++;
            }
        }
        e->s2++;
        if (e->s2 > 72) {
            e->s2 = 0;
        }
    } else if (e->timer >= 0) {
        if (e->timer >= e->limit) {
            e->timer = 0;
            e->limit = (Libc_Rand() & 0x3FF) + 300;
        }
        if (e->count < 8) {
            e->ids[e->count] = D_0053B348[e->type];
            e->vals[e->count] = AnimMix(e->timer, g_MorphCurvePeriodic);
            if (!e->vals[e->count]) {
            } else {
                e->count++;
            }
        }
        e->timer++;
    }
}
#undef AnimMix /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B530 */

/* merge_units: begin func_0038B800 */
#pragma push /* merge_units */
float AnimMix(int t, KtKey* keys)
{
    int i = 0;
    int kt;
    float a, b;
    while (t > (kt = keys[i].t)) i++;
    if (t == kt) return keys[i].v;
    b = keys[i].v;
    a = keys[i - 1].v;
    if (a == b) return b;
    {
        int pt = keys[i - 1].t;
        int span = kt - pt;
        float r;
        t -= pt;
        r = (float)t / (float)span;
        return a - r * (a - b);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B800 */
