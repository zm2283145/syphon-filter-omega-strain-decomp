/*
 * main/particle: range (4 files, 003A39B0-003A3F80)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003A39B0 */
#pragma push /* merge_units */
/* func_003A39B0 (particle, mw38): copy two V4s and a {xyz,(float)count} V4 into a particle emitter.
   GCC-style volatile lq/sq copy + dead address locals give retail's duplicate addius (LESSONS c57da). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { float x, y, z; } V3;
typedef struct P39 { char pad0[0x900]; V4 m900; char pad910[0x40]; V4 m950; V4 m960; char pad970[0xCC]; unsigned int nA3C; } P39;
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline V4* VA(V4* d, const V4* s) { GQ(d, s); return d; }
static inline void MK(V4* t, float x, float y, float z, float w) { t->x = x; t->y = y; t->z = z; t->w = w; }
#pragma peephole off
void func_003A39B0(P39* p, const V4* a, const V4* b, const V3* c)
{
    V4 t;
    void* xx;
    void* yy;
    VA(&p->m900, a);
    xx = &p->m950; /* dead on purpose */
    VA(&p->m950, b);
    MK(&t, c->x, c->y, c->z, (float)p->nA3C);
    yy = &p->m960; /* dead on purpose */
    VA(&p->m960, &t);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A39B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A39B0 */

/* merge_units: begin func_003A3A40 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off

extern "C" {
int strtod(char*, char**);
float SoftFloat_DoubleToFloat(int);
char* strchr(const char*, int);
long strtoul(char*, char**, int);
}

struct V4_3A3A40 {
    float x, y, z, w;
    V4_3A3A40& operator=(const V4_3A3A40& o)
    {
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct Obj3A3A40 {
    char pad0[0x18];
    float f18, f1C, f20, f24, f28, f2C, f30, f34;
    char pad38[0x4C - 0x38];
    float f4C;
    char pad50[0x64 - 0x50];
    unsigned char b64;
    char pad65[0x15C - 0x65];
    float f15C;
    char pad160[0x16C - 0x160];
    float f16C;
    char pad170[0x8F4 - 0x170];
    int i8F4;
    char pad8F8[0x910 - 0x8F8];
    V4_3A3A40 v910, v920, v930, v940;
    char pad950[0x974 - 0x950];
    float f974, f978;
    char pad97C[0x980 - 0x97C];
    float f980, f984, f988, f98C;
    V4_3A3A40 v990;
    float f9A0, f9A4, f9A8, f9AC;
    char pad9B0[0xA20 - 0x9B0];
    float fA20, fA24, fA28, fA2C, fA30, fA34, fA38;
    int iA3C;
    float fA40, fA44, fA48, fA4C, fA50, fA54, fA58, fA5C, fA60, fA64, fA68, fA6C;
};

struct Mk3A3A40 : V4_3A3A40 {
    Mk3A3A40(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

#define RD() SoftFloat_DoubleToFloat(strtod(s, &s))
#define NL() s = strchr(s, '\n') + 1

extern "C" void func_003A3A40(Obj3A3A40* self, char* str)
{
    char* s = str;
    self->fA20 = RD();
    self->fA24 = RD();
    self->fA28 = RD();
    NL();
    self->fA2C = RD();
    self->fA30 = RD();
    NL();
    self->fA34 = RD();
    self->fA38 = RD();
    self->iA3C = strtoul(s, &s, 10);
    NL();
    self->fA40 = RD();
    self->fA44 = RD();
    self->fA48 = RD();
    self->fA4C = 1.0f;
    NL();
    self->fA50 = RD();
    self->fA54 = RD();
    self->fA58 = RD();
    self->fA5C = 1.0f;
    NL();
    self->fA60 = RD();
    self->fA64 = RD();
    self->fA68 = RD();
    self->fA6C = 1.0f;
    NL();
    self->f980 = RD();
    self->f988 = RD();
    self->f9A0 = RD();
    self->f9A8 = RD();
    NL();
    self->f984 = RD();
    self->f98C = RD();
    self->f9A4 = RD();
    self->f9AC = RD();
    NL();
    self->v990 = Mk3A3A40(self->f988, self->f98C, self->f9A0, self->f9A4);
    self->i8F4 = strtoul(s, &s, 10);
    if (self->i8F4 != 0) self->iA3C = -1;
    self->f974 = self->f4C;
    self->f978 = (unsigned int)self->b64;
    {
    void* d0 = &self->v910; /* dead on purpose */
    void* d1 = &self->v920; /* dead on purpose */
    void* d2 = &self->v930; /* dead on purpose */
    void* d3 = &self->v940; /* dead on purpose */
    self->v910 = Mk3A3A40(self->fA34, self->fA38, self->f2C, self->f18);
    self->v920 = Mk3A3A40(self->f30, self->f34, self->f1C, self->f24);
    self->v930 = Mk3A3A40(self->f15C, self->f16C, self->f20, self->f28);
    self->v940 = Mk3A3A40(self->fA30, self->fA28, self->fA2C, 0.0f);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3A40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3A40 */

/* merge_units: begin func_003A3EF0 */
#pragma push /* merge_units */
/* First quad copy uses a "+r" destination operand (G1) so the dest gets t0 and q gets v1 as in retail. */

typedef struct P3E { char pad0[0x60]; unsigned int n60; char pad64[0x8FC]; V4 m960; V4 m970; V4 m980; } P3E;
static inline void G1(void* d, const void* s) { __int128 q; __asm__ volatile("lq %1, 0(%2); sq %1, 0(%0)" : "+r"(d), "=&r"(q) : "r"(s) : "memory"); }
#pragma peephole off
void func_003A3EF0(P3E* p, const V4* a, const V4* b, const V3* c)
{
    V4 t;
    void* xx;
    void* yy;
    G1(&p->m960, b);
    MK(&t, c->x, c->y, c->z, (float)p->n60);
    xx = &p->m970; /* dead on purpose */
    yy = &p->m980; /* dead on purpose */
    VA(&p->m970, &t);
    VA(&p->m980, a);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3EF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3EF0 */

/* merge_units: begin func_003A3F80 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off

extern "C" {
}

struct V4_3A3F80 {
    float x, y, z, w;
    V4_3A3F80& operator=(const V4_3A3F80& o)
    {
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        { void* xx = this; } /* dead on purpose: retail recomputes &v[k] after each copy */
        return *this;
    }
} __attribute__((aligned(16)));

struct Obj3A3F80 {
    char pad0[0x18];
    float f18, f1C, f20, f24, f28, f2C, f30, f34;
    char pad38[0x15C - 0x38];
    float f15C;
    char pad160[0x16C - 0x160];
    float f16C;
    char pad170[0x8F4 - 0x170];
    int i8F4;
    char pad8F8[0x900 - 0x8F8];
    V4_3A3F80 v[9];
    float f990, f994, f998, f99C, f9A0, f9A4, f9A8, f9AC;
    float f9B0, f9B4, f9B8, f9BC, f9C0, f9C4;
    int i9C8;
    unsigned char b9CC;
};

struct Mk3A3F80 : V4_3A3F80 {
    Mk3A3F80(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

extern "C" void ParticleDef_ParseType0(Obj3A3F80* self, char* str, float ver)
{
    char* s = str;
    self->f990 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f994 = SoftFloat_DoubleToFloat(strtod(s, &s));
    s = strchr(s, '\n') + 1;
    self->f9A0 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9A4 = SoftFloat_DoubleToFloat(strtod(s, &s));
    s = strchr(s, '\n') + 1;
    self->f998 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f99C = SoftFloat_DoubleToFloat(strtod(s, &s));
    s = strchr(s, '\n') + 1;
    self->f9A8 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9AC = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9AC = self->f9AC / self->f9A8;
    s = strchr(s, '\n') + 1;
    self->f9B0 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9B4 = 0.0f;
    s = strchr(s, '\n') + 1;
    self->f9B8 = SoftFloat_DoubleToFloat(strtod(s, &s));
    self->f9BC = SoftFloat_DoubleToFloat(strtod(s, &s));
    s = strchr(s, '\n') + 1;
    if (ver >= 1.5f) {
        self->f9C0 = SoftFloat_DoubleToFloat(strtod(s, &s));
        self->f9C4 = SoftFloat_DoubleToFloat(strtod(s, &s));
        s = strchr(s, '\n') + 1;
        self->i8F4 = strtoul(s, &s, 10);
        s = strchr(s, '\n') + 1;
    } else {
        self->f9C0 = 0.0f;
        self->f9C4 = 0.0f;
        self->i8F4 = 0;
    }
    if (ver >= 2.0f) {
        self->i9C8 = strtoul(s, &s, 10);
        if (self->i9C8 == 0) self->i9C8 = 1;
        self->b9CC = strtoul(s, &s, 10) != 0;
        s = strchr(s, '\n') + 1;
    } else {
        self->i9C8 = 1;
        self->b9CC = 0;
    }
    {
    V4_3A3F80* d0 = &self->v[0];
    *d0 = Mk3A3F80(self->f990, self->f998, self->f9B8, self->f9B0);
    }
    {
    self->v[1] = Mk3A3F80(self->f994, self->f99C, self->f9BC, self->f9B4);
    self->v[2] = Mk3A3F80(0.0f, self->f9A0, self->f9C0, self->f9C4);
    self->v[3] = Mk3A3F80(0.0f, self->f9A4, self->f2C, self->f18);
    self->v[4] = Mk3A3F80(self->f30, self->f34, self->f1C, self->f24);
    self->v[5] = Mk3A3F80(self->f15C, self->f16C, self->f20, self->f28);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A3F80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A3F80 */
