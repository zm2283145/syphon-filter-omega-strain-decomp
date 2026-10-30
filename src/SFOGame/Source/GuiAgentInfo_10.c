/*
 * SFOGame/Source/GuiAgentInfo: 19 files, 003643A0-003647B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003643A0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "vc_copy.h"

/* library prototypes shared by the blocks below (C linkage) */
void *memset(void *, int, int);

#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
char * cMemMan_Allocate(...);                      
int cGOBJ_CreateXform(...);           
int cGOBJ_ctor(...);              
char * cSKM_GOBJ_ctor_cObjectIdR(...);                 
int GuiWidget_onAdd(...);                                  
extern char D_004BBA20;
extern char D_004DA470;
extern unsigned char g_ProfileLockEnabled;
extern char g_IdentityMatrix;
}
#pragma push
#pragma opt_common_subs off
extern "C" void GuiAgentDisplay_onAdd(char * arg0) {
        int x4C[1];
    char * temp_s1;
    char * var_s1;

    GuiWidget_onAdd();
    {
        AllocGuard g;
    temp_s1 = (char *)(cMemMan_Allocate(0, 0x68, &D_004BBA20, 0x49));
    }
    if (temp_s1 != NULL) {
        int x44[1]; int x40[1]; x40[0] = 0;
        x44[0] = 0;
        cGOBJ_ctor(temp_s1, x44, 9, x40);
        F_(temp_s1, 0x0, int) = (int)(&D_004DA470);
        F_(temp_s1, 0x60, int) = 0;
        F_(temp_s1, 0x64, int) = 0;
        cGOBJ_CreateXform(temp_s1, &g_IdentityMatrix, 0);
        F_(temp_s1, 0x30, int) = 0;
    }
    F_(arg0, 0x90, int) = (int)(temp_s1);
    {
        AllocGuard g;
    var_s1 = (char *)(cMemMan_Allocate(0, 0x3030, &D_004BBA20, 0x4C));
    }
    if (var_s1 != NULL) {
        x4C[0] = 0;
        var_s1 = (char *)(cSKM_GOBJ_ctor_cObjectIdR(var_s1, x4C));
    }
    F_(arg0, 0x48, int) = (int)(var_s1);
    memset(arg0 + 0xA0, 0, 0x440);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003643A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003643A0 */

/* merge_units: begin func_00364540 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00364540)
static inline void merge_flush_func_00364540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364540 */

/* merge_units: begin func_00364590 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V3 { float x, y, z; V3() {} V3(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
struct S364590 { void* vtable; char pad4[0x44]; int unk48; char pad4C[0x34]; V3 v80; char pad90[0x4E0 - 0x90]; float f4E0; };
extern "C" char GuiAgentDisplay_vtable[];
extern "C" void GuiWidget_ctor(S364590* self);
extern "C" S364590* GuiAgentDisplay_ctor(S364590* self) {
    V3 t;
    float z;
    GuiWidget_ctor(self);
    self->vtable = GuiAgentDisplay_vtable;
    t.x = 0.0f; t.y = 0.0f; t.z = 3.1415927f;
    VCopyF(&self->v80, &t);
    z = 0.0f;
    self->unk48 = 0;
    self->f4E0 = z;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364590 */

/* merge_units: begin func_00364600 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


void func_00364600(void) {
}

void func_00364610(void) {
}
static inline void merge_flush_func_00364600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364600 */

/* merge_units: begin func_00364620 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "v4_asm_copy.h"
struct V364620 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q364620 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub364620 { char pad[0x10]; Q364620 pos; };
struct T364620 { V364620 v; char pad4[0xC]; Sub364620 sub; char pad40[0x20]; unsigned char b50; };
struct A364620 { char pad[0x50]; T364620* t; char pad54[0x10]; float heading; };
extern "C" {
float Libc_Atan2f(float y, float x);
void cGOBJ_NextFrame(A364620* a, float dt);
}
extern "C" void func_00364620(A364620* a, float dt)
{
    T364620* t = a->t;
    Q364620 p;
    if (t->b50)
        t->v.v20();
    Sub364620* s = (Sub364620*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Libc_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    cGOBJ_NextFrame(a, dt);
}
static inline void merge_flush_func_00364620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364620 */

/* merge_units: begin func_003646A0 */
#pragma push /* merge_units */
void func_003646A0(char* self) {
    self[80] = 0;
}

void func_003646B0(void) {
}

void func_003646C0(char* self) {
    self[44] = 1;
}

void func_003646D0(char* self) {
    self[44] = 0;
}

unsigned char func_003646E0(unsigned char* self) {
    return self[44];
}

int func_003646F0(void) {
    return 0;
}

void func_00364700(void) {
}

int func_00364710(void) {
    return 0;
}

int func_00364720(void) {
    return 0;
}

int func_00364730(void) {
    return 0;
}

int func_00364740(void) {
    return 0;
}

int func_00364750(void) {
    return 0;
}

void func_00364760(void) {
}

int func_00364770(void) {
    return 0;
}
static inline void merge_flush_func_003646A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003646A0 */

/* merge_units: begin func_00364780 */
#pragma push /* merge_units */
/* Three independent compiler-emitted virtual/zero-return wrappers.
 * No prototype .cc ownership is confirmed for this range. */
#pragma cplusplus on
#pragma exceptions off
struct R364 { int a, b, c, d; };
struct VO364 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D(); virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual R364 GetE4(); /* +0xE4 */
};
struct A364 { VO364* o; };
extern "C" R364 func_00364780(VO364* o);
extern "C" R364 func_00364790(VO364* o);
extern "C" int func_003647A0(void);
R364 func_00364780(VO364* o) { return o->GetE4(); }
R364 func_00364790(VO364* o) { return o->GetE4(); }
int func_003647A0(void) { return 0; }
static inline void merge_flush_func_00364780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364780 */

/* merge_units: begin func_003647B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


int func_003647B0(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003647B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003647B0 */

/* merge_units: begin func_003647C0 */
#pragma push /* merge_units */
/* Returns 1.0f. */
float func_003647C0(void)
{
    return 1.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003647C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003647C0 */

/* merge_units: begin func_003647D0 */
#pragma push /* merge_units */
int func_003647D0(void) {
    return 0;
}

int func_003647E0(void) {
    return 1;
}

int func_003647F0(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003647D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003647D0 */

/* merge_units: begin func_00364800 */
#pragma push /* merge_units */
typedef struct { char pad[0x58]; void* other; } Obj58;
/* Returns the linked object at +0x58, or the object itself. */
void* func_00364800(Obj58* p) { if (p->other) return p->other; return p; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364800 */

/* merge_units: begin func_00364820 */
#pragma push /* merge_units */
void func_00364820(void) {
}

int func_00364830(void) {
    return 1;
}

int func_00364840(void) {
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364820 */

/* merge_units: begin func_00364850 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; float f40; } FObj;

/* Returns 3 if the float at +0x40 truncates to 0, else 0. */
int func_00364850(FObj* self)
{
    return (int)self->f40 ? 0 : 3;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364850 */

/* merge_units: begin func_00364870 */
#pragma push /* merge_units */
void* func_00364870(char* self) {
    return self + 12;
}

int func_00364880(void) {
    return 1;
}

void func_00364890(void) {
}

void func_003648A0(void) {
}

int func_003648B0(void) {
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364870 */

/* merge_units: begin func_003648C0 */
#pragma push /* merge_units */
typedef struct { char pad[4]; float f4; float f8; float vel; float f10; float f14; } D2_Curve;
static inline float d2_max(float a, float b) { float r; asm { max.s r, a, b } return r; }
void Curve_SetVelocity_3648C0(D2_Curve* c, float dt, float scale) {
    c->vel = scale * (c->f8 - c->f4);
    c->vel *= d2_max(0.0f, 1.0f - c->f14 * dt);
}
static inline void merge_flush_func_003648C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003648C0 */

/* merge_units: begin func_00364910 */
#pragma push /* merge_units */
void func_00364910(void) {
}
static inline void merge_flush_func_00364910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364910 */

/* merge_units: begin func_00364920 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
struct B5kRef { char pad[0x10]; float end; };
class B5kObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetRate();
    int a;
    int b8;
    int bc;
    float b10;
    int b14;
    int b18;
    char pad[0x20 - 0x1C];
    float out0;
    float out1;
    float scale;
    char pad2[0x30 - 0x2C];
    B5kRef* ref;
    float cur;
};
extern "C" void func_0017CA90(void* p, int n);
extern "C" void* opNew_uint_voidP(int kind, void* p);
extern "C" void cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(void* p, float s, void* a, void* b, void* c, float* r);
static inline int B5kIsZero(float f) { return 0.0f == f; }
extern "C" void Curve_Retarget_364920(B5kObj* o) {
    unsigned char flag = 0;
    if (o->cur == o->ref->end && !(o->scale <= 0.0f)) {
        flag = 1;
    }
    if (flag) {
        float r = o->GetRate();
        void* p;
        func_0017CA90(&o->b18, -1);
        p = opNew_uint_voidP(0x18, &o->b18);
        if (p) {
            cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(p, o->scale, &o->b8, &o->bc, &o->b10, &r);
        }
    } else if ((B5kIsZero(o->cur) ^ 1)) {
        float r = o->GetRate();
        float s = o->scale;
        o->out0 = o->b10;
        o->out1 = r * s;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364920(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364920 */

/* merge_units: begin func_00364A20 */
#pragma push /* merge_units */
#pragma cplusplus on
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_4A20b { float v; float s; Key_4A20b() {} };
struct Crv_4A20b { Key_4A20b k[2]; float dur; float inv; };
/* two-key curve: keys (*v0, *s0 * dur) and (*v1, *s1 * dur), duration and inverse */
#pragma push
#pragma opt_unroll_loops off
extern "C" Crv_4A20b* func_00364A20(Crv_4A20b* c, float* v0, float* s0, float* v1, float* s1, float dur)
{
    float vs0; float vs1;
    vs1 = *s1 * dur; vs0 = *s0 * dur;
    { Key_4A20b* e = c->k; do { new (e) Key_4A20b; } while (++e != c->k + 2); }
    c->k[0].v = *v0;
    c->k[0].s = vs0;
    c->k[1].v = *v1;
    c->k[1].s = vs1;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364A20 */

/* merge_units: begin func_00364AB0 */
#pragma push /* merge_units */
#include "GuiAgentInfo_types.h"

/* Adds *delta to each float field of the range. */
void func_00364AB0(ShiftRange* self, float* delta) {
    self->unk04 = self->unk04 + *delta;
    self->unk08 = self->unk08 + *delta;
    self->unk10 = self->unk10 + *delta;
    self->unk18 = self->unk18 + *delta;
    self->unk20 = self->unk20 + *delta;
}
static inline void merge_flush_func_00364AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364AB0 */
