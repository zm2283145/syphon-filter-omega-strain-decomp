/*
 * Libs/SFOLib/Source/gameobj: 6 files, 00394590-00394AD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00394590 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

class OwnerV394590 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
};

class SelfV394590 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void Kill(int arg);
    virtual int IsDone();
};

struct Owner394590 {
    void* vt;
    char p4[0xC];
    char pos[0x40];
    unsigned char dirty;
};

struct Tracer394590 {
    char p0[0x1C];
    int active;
};

struct Self394590 {
    void* vt;
    char p4[8];
    unsigned int type;
    char p10[0x40];
    Owner394590* owner;
    char p54[0x10];
    Tracer394590* tracer;
    char p68[4];
    float age;
};

extern "C" {
extern char D_004BC430[];
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cParticle_dtor(Tracer394590* t, int flag);
void cParticle_NextFrame(Tracer394590* t, void* pos, int z, float dt);
void nGobjManager_RemoveGOBJ(Self394590* self);
void cSystem_ActualScheduleDelete(Self394590* self, float t);
}

extern "C" void cPARTICLE_GOBJ_NextFrame(Self394590* self, float dt)
{
    if (self->tracer) {
        if (self->tracer->active) {
            Owner394590* o = self->owner;
            if (o->dirty) ((OwnerV394590*)o)->Update();
            cParticle_NextFrame(self->tracer, o->pos, 0, dt);
        } else if (((SelfV394590*)self)->IsDone()) {
            ((SelfV394590*)self)->Kill(-1);
            if (((self->type & 0xFF0000) >> 16) == 0xE7) {
                nGobjManager_RemoveGOBJ(self);
                cSystem_ActualScheduleDelete(self, 0.1f);
                Tracer394590* t = self->tracer;
                if (t) {
                    {
                        AllocGuard g;
                        cParticle_dtor(t, -1);
                        cMemMan_Deallocate(0, t, D_004BC430, 0x23A);
                    }
                    self->tracer = 0;
                }
            }
        }
        self->age += dt;
    }
}
static inline void merge_flush_func_00394590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00394590 */

/* merge_units: begin func_00394720 */
#pragma push /* merge_units */
extern char D_0053B540[];
extern void cParticleSystem_RequestEffectLoad(void* list, int value, void* item);

/* Registers the object's +0x60 sub-object in the global list D_0053B540. */
void cPARTICLE_GOBJ_Load(char* self, int* arg)
{
    cParticleSystem_RequestEffectLoad(D_0053B540, *arg, self + 0x60);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394720(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00394720 */

/* merge_units: begin func_00394740 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Sub {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void Method14(void* arg); /* +0x14 */
};

struct Object {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21();
    virtual void Method90(void* p, int n); /* +0x90 */
    char pad04[0x50 - 4];
    Sub* sub;   /* +0x50 */
    char pad54[0x64 - 0x54];
    int unk64;  /* +0x64 */
    int unk68;
    int unk6C;  /* +0x6C */
};

/* Calls virtual +0x90(arg+0x10, 0), passes arg to the +0x50 object (virtual +0x14) and clears +0x64/+0x6C. */
extern "C" void cPARTICLE_GOBJ_Init(Object* self, char* arg)
{
    self->Method90(arg + 0x10, 0);
    self->sub->Method14(arg);
    self->unk64 = 0;
    self->unk6C = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00394740 */

/* merge_units: begin func_003947A0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resolve the attached animation data pointer, directly or via lookup. */
typedef struct { int valid; unsigned char* data; } Ref_3947A0;
typedef struct { int pad0; int count; int key; int pad1; int key2; } Tab_3947A0;
typedef struct { Tab_3947A0* tab; } Inner_3947A0;
typedef struct { int pad0; Inner_3947A0* inner; } Res_3947A0;
class Obj_3947A0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual Res_3947A0* resolve();
    unsigned char pad[0x64];
    Ref_3947A0* ref;
};

extern "C" {
int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(Tab_3947A0* t, int* key);
int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(Tab_3947A0* t, int* key);
}

static inline unsigned char Valid_3947A0(Ref_3947A0* r) { return r->valid != 0; }

extern "C" int cVUM_GOBJ_GetBBox(Obj_3947A0* o)
{
    int r = 0;
    Ref_3947A0* ref = o->ref;
    if (ref != 0 && Valid_3947A0(ref)) {
        r = (int)(ref->data + 0x30);
    } else {
        Res_3947A0* res = o->resolve();
        if (res != 0) {
            Tab_3947A0* t = res->inner->tab;
            int v;
            if (t->count > 0) {
                int k = t->key;
                v = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(t, &k);
            } else {
                int k = t->key2;
                v = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(t, &k);
            }
            r = v;
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003947A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003947A0 */

/* merge_units: begin func_00394850 */
#pragma push /* merge_units */
extern void cGOBJ_CreateXform(void* self, float* m, int a, int b);
extern void cGOBJ_DestroyXform(void* self);

void cVUM_GOBJ_CreateXform(void* self, float* m, int a, int b)
{
    int r = m[0] == 1.0f && m[1] == 0.0f && m[2] == 0.0f && m[3] == 0.0f &&
            m[4] == 0.0f && m[5] == 1.0f && m[6] == 0.0f && m[7] == 0.0f &&
            m[8] == 0.0f && m[9] == 0.0f && m[10] == 1.0f && m[11] == 0.0f &&
            m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f && m[15] == 1.0f;
    if (!r) cGOBJ_CreateXform(self, m, a, b);
    else cGOBJ_DestroyXform(self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00394850 */

/* merge_units: begin func_00394AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vc_copy.h"
#pragma inline_depth(8)
#pragma opt_propagation off
#pragma opt_rebuildconditionals off

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { __int128 t; cVector* d = this; const cVector* s = &o; void* xx = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    cVector& Asg(const cVector& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
} __attribute__((aligned(16)));

class cMatrix { public: cVector m[4]; };
class cBox {
public:
    cVector min;
    cVector max;
    cBox(const cVector& a, const cVector& b) : min(a), max(b) {}
};

static inline int VEq(const cVector* a, const cVector* b) {
    int k, fl;
    unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline bool operator!=(const cVector& a, const cVector& b) { return !VEq(&a, &b); }

static inline cVector operator*(const cMatrix& m, const cVector& v) {
    cVector r = v;
    cVector* p = &r;
    const cMatrix* mm = &m;
    asm {
        lqc2 vf8, 0(p)
        lqc2 vf4, 0x0(mm)
        lqc2 vf5, 0x10(mm)
        lqc2 vf6, 0x20(mm)
        lqc2 vf7, 0x30(mm)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0(p)
    }
    return *p;
}

static inline cVector K0_0(const cMatrix& m, const cVector& v) { cVector r = v; cVector* p = &r; const cMatrix* mm = &m; asm { lqc2 vf8, 0(p); lqc2 vf4, 0x0(mm); lqc2 vf5, 0x10(mm); lqc2 vf6, 0x20(mm); lqc2 vf7, 0x30(mm); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0(p) } return *p; }
static inline cVector J0_0(const cMatrix& m, const cVector& v) { cVector r = v; cVector* p = &r; const cMatrix* mm = &m; asm { lqc2 vf8, 0(p); lqc2 vf4, 0x0(mm); lqc2 vf5, 0x10(mm); lqc2 vf6, 0x20(mm); lqc2 vf7, 0x30(mm); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0(p) } return *p; }
static inline cVector K0_1(const cMatrix& m, const cVector& v) { return K0_0(m, v); }
static inline cVector K0_2(const cMatrix& m, const cVector& v) { return K0_1(m, v); }
static inline cVector K0_3(const cMatrix& m, const cVector& v) { return K0_2(m, v); }
class cParent {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char p4[0xC];
    cMatrix mtx;
    unsigned char dirty;
    cMatrix* GetMatrix() { if (dirty) Update(); return &mtx; }
};

struct cModelInfo { char p0[0x30]; cVector bmin; cVector bmax; };
struct cVU1Model {
    void* data;
    cModelInfo* info;
    char p8[0x1C];
    unsigned int flags;
    int IsLoaded() { if (data) return 1; else return 0; }
};

struct cVUM_GOBJ {
    char p0[0x38];
    unsigned int x38;
    char p3C[0x14];
    cParent* parent;
    char p54[0x14];
    cVU1Model* mModel;
    char p6C[0x184];
    unsigned char isLit;
    unsigned char isShadowed;
};

extern "C" {
extern unsigned int g_DrawMode;
extern cVector D_00535D40;
extern cVector D_00535D50;
extern unsigned char D_00535D60;
extern unsigned char D_00535D61;
extern char D_00543790[];
void cShadowMan_PreRenderReceiver(void* r, cVUM_GOBJ* o);
void cVU1Model_Render(cVU1Model* m, unsigned int a, cMatrix* mtx);
}

static inline void SetLightBox(const cVector& bmin, const cVector& bmax) {
    if (D_00535D40 != bmin || D_00535D50 != bmax) {
        D_00535D40 = bmin;
        D_00535D50.Asg(bmax);
        D_00535D61 = 1;
        D_00535D60 = 0;
    }
}

extern "C" void cVUM_GOBJ_Render(cVUM_GOBJ* self)
{
    if (self->mModel->IsLoaded()) {
        unsigned int resCtxt = g_DrawMode;
        unsigned int setCtxt = resCtxt;
        cMatrix* pMat = 0;
        if (self->parent) {
            pMat = self->parent->GetMatrix();
            if (self->isLit) {
                cVector& bmin = self->mModel->info->bmin;
                cVector& bmax = (&bmin)[1];
                cBox wbox(K0_1(*pMat, bmin), J0_0(*pMat, bmax));
                SetLightBox(wbox.min, wbox.max);
            }
            if (self->isShadowed && (self->mModel->flags & 0x60))
                cShadowMan_PreRenderReceiver(D_00543790, self);
        } else {
            if (self->isLit) {
                cVector& bmin = self->mModel->info->bmin;
                SetLightBox(bmin, (&bmin)[1]);
            }
            if (self->isShadowed && (self->mModel->flags & 0x60))
                cShadowMan_PreRenderReceiver(D_00543790, self);
        }
        if (!self->isLit) setCtxt &= ~0x10;
        if (!self->isShadowed) setCtxt &= ~0x60;
        g_DrawMode = setCtxt;
        cVU1Model_Render(self->mModel, self->x38, pMat);
        g_DrawMode = resCtxt;
    }
}
static inline void merge_flush_func_00394AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00394AD0 */
