/*
 * Libs/SFOLib/Source/man: 5 files, 0038B530-0038B8D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0038B530 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int t; float v; } KtKey;
#if 0 /* merge_units */
float AnimMix(int t, KtKey* keys); /* gsynth: defined below */
#endif /* merge_units */
float AnimMix(); /* merge_units */

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
float AnimMix(); /* merge_units */


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

/* merge_units: begin func_0038B8B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Stores a value in a 256-entry table indexed by a byte.
 */

#include "man_types.h"

extern int WoundEffectTable[256];

void cMan_SetBloodEffect(int index, int value) {
    WoundEffectTable[index & 0xFF] = value;
}
static inline void merge_flush_func_0038B8B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038B8B0 */

/* merge_units: begin func_0038B8D0 */
#pragma push /* merge_units */
typedef struct { unsigned char pad[7]; unsigned char count; unsigned char* data; unsigned char pad2[4]; } Grp_B8D0;
typedef struct {
    unsigned char pad0[0x1EC0];
    Grp_B8D0 groups[0x48];
    unsigned char* bufs[0x20];
    unsigned short numGroups;
} Model_B8D0;
void cMan_Bloodlost(Model_B8D0* m)
{
    unsigned int i;
    unsigned int n;
    unsigned char* d;
    unsigned char* buf;
    unsigned int j;
    unsigned char* p;
    unsigned int c;
    unsigned int k;
    for (i = 0; i < m->numGroups; i++) {
        buf = m->bufs[i];
        if (buf != 0) {
            n = m->groups[i].count;
            d = m->groups[i].data; d += 2;
            for (j = 0; j < n; j++) {
                c = d[1];
                d += 2;
                p = buf;
                buf += 0x20;
                for (k = 0; k < c; k++) {
                    if (*p != 0) *p = 0x5A;
                    p++;
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B8D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B8D0 */

/* merge_units: begin func_0038B990 */
#pragma push /* merge_units */
typedef struct { unsigned char a; unsigned char n; } HgPair;
typedef struct { char pad0[2]; HgPair p[1]; } HgDef;
typedef struct {
    char pad0[7];
    unsigned char count;
    HgDef* def;
    char padC[4];
} HgEnt;
typedef struct {
    char pad0[0x1EC0];
    HgEnt ents[32];
    char pad20C0[0x2340 - 0x20C0];
    unsigned char* items[32];
    unsigned short count;
    char pad23c2[0x2C08 - 0x23C2];
    unsigned int age;
} HitGore;

void cMan_BloodUpdate(HitGore* self)
{
    unsigned int i;
    unsigned int cnt;
    HgPair* pr;
    unsigned char* p;
    unsigned int k;
    unsigned char* q;
    unsigned int n;
    unsigned int b;
    unsigned char* buf;
    if (self->age) {
        for (i = 0; i < self->count; i++) {
            p = self->items[i];
            buf = p;
            if (buf) {
                cnt = self->ents[i].count;
                pr = (HgPair*)self->ents[i].def; pr++;
                for (k = 0; k < cnt; k++) {
                    n = pr->n;
                    q = buf;
                    buf += 0x20;
                    pr++;
                    for (b = 0; b < n; b++, q++) {
                        unsigned int v = *q;
                        if (v) {
                            v += self->age;
                            if (v > 0x5A) v = 0x5A;
                            *q = v;
                        }
                    }
                }
            }
        }
        self->age = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B990 */
