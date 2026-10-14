/*
 * main/gameCamera: range (4 files, 0017D7F0-0017DA60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017D7F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_0017D7F0)
#pragma pop /* merge_units */
/* merge_units: end func_0017D7F0 */

/* merge_units: begin func_0017D840 */
#pragma push /* merge_units */
#include "types.h"
#include "vu0_scale_eq.h"
#pragma push
#pragma peephole off
#pragma opt_propagation off
CURVE_RETIME_FUNC(Curve_Retime1s)
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0017D840 */

/* merge_units: begin func_0017D8E0 */
#pragma push /* merge_units */
void Curve_Sample(char* arg0, char* arg1, float farg0); /* gsynth: defined below */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct W {
    float x, y, z, w;
    W() {}
    W& operator=(const W& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
extern "C" float func_0017DC50(void* c);
#if 0 /* merge_units */
extern "C" void Curve_Sample(V* out, void* c, float t);
#endif /* merge_units */
#define Curve_Sample(a0, a1, a2) (Curve_Sample((char *)(a0), (char *)(a1), (a2))) /* merge_units */

static inline float CR_Max(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline bool Pos(float f) { return f > 0.0f; }
struct VC {
    /* vptr at 0; slots 0x18/0x1C/0x20 */
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Begin();
    virtual void Changed();
    virtual void Update(float dt, float x);
    char pad4[0xC];
    W v10;
    W v20;
    char pad30[0x10];
    W v40;
    char pad50[0x60];
    void* curve;
    float t;
    bool Zero() const { return t == 0.0f; }
    bool NotZero() const { return !Zero(); }
};
extern "C" bool VectorCurve_Advance(VC* self, float dt, float x)
{
    bool done;
    self->v10 = self->v20;
    self->Begin();
    float z = 0.0f; /* dead on purpose: retail keeps this mtc1 */
    float old = self->t;
    self->t -= dt;
    self->t = CR_Max(0.0f, self->t);
    {
        bool r = Pos(old);
        if (r) r = self->Zero();
        done = r;
    }
    if (self->NotZero()) {
        V tmp;
        Curve_Sample(&tmp, self->curve, func_0017DC50(self->curve) - self->t);
        { void* xx = &tmp; /* dead on purpose: retail keeps this addiu */ }
        self->v20 = (W&)tmp;
        self->Changed();
    } else {
        self->v20 = self->v40;
    }
    self->Update(dt, x);
    return done;
}
#undef Curve_Sample /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017D8E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017D8E0 */

/* merge_units: begin func_0017DA60 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Vec4_Add(char *, char *, char *);                          
int func_0017DBF0(int);                             
int func_0017DC00(float, char *, int);                     
int func_0017DC30(int);                             
int func_0017DC40(char * , int);                       

void Curve_Sample(char *arg0, char * arg1, float farg0) {
    int sp90[4];
    int sp80[4];
    int sp70[4];
    float temp_f22;
    float temp_f21;
    int sp60[4];
    int sp50[4];
    float var_f20;
    float temp_f23;
    int sp40[4];

    if (F_(arg1, 0x40, float) != 0.0f) {
        var_f20 = farg0 * F_(arg1, 0x44, float);
    } else {
        var_f20 = 1.0f;
    }
    temp_f22 = var_f20 * var_f20;
    temp_f21 = temp_f22 * var_f20;
    temp_f23 = 3.0f * temp_f22;
    func_0017DC00(1.0f + ((2.0f * temp_f21) - temp_f23), sp70, func_0017DC30(func_0017DC40(arg1, 0)));
    func_0017DC00((-2.0f * temp_f21) + temp_f23, sp60, func_0017DC30(func_0017DC40(arg1, 1)));
    Vec4_Add(sp80, sp70, sp60);
    func_0017DC00(var_f20 + (temp_f21 - (2.0f * temp_f22)), sp50, func_0017DBF0(func_0017DC40(arg1, 0)));
    Vec4_Add(sp90, sp80, sp50);
    func_0017DC00(temp_f21 - temp_f22, sp40, func_0017DBF0(func_0017DC40(arg1, 1)));
    Vec4_Add(arg0, sp90, sp40);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017DA60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017DA60 */
