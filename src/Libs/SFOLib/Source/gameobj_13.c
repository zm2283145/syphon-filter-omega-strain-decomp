/*
 * Libs/SFOLib/Source/gameobj: 19 files, 00393F60-00394EE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00393F60 */
#pragma push /* merge_units */
#include "gobj_types.h"

/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */


extern Rel* std_vector_imp_cBoneScale_ctor(Rel* r);
extern int std_vector_imp_cBone_init(Rel* r, int a1, int a2);

/* Clears the record, then calls std_vector_imp_cBone_init with the incoming a1/a2 unchanged. */
Rel* std_vector_imp_cBone_ctor(Rel* r, int a1, int a2) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    std_vector_imp_cBone_init(r, a1, a2);
    return r;
}

RelFlag* cArray_cBoneScale_ctor(RelFlag* r) {
    std_vector_imp_cBoneScale_ctor(&r->rel);
    r->flag = 1;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393F60 */

/* merge_units: begin func_00393FD0 */
#pragma push /* merge_units */
Rel* std_vector_imp_cBoneScale_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393FD0 */

/* merge_units: begin func_00393FF0 */
#pragma push /* merge_units */
#include "types.h"

#pragma opt_propagation off

typedef struct { float v[4]; } V4;
typedef struct { char p[0x1D8]; } SkelNode;

typedef struct Anim {
    int x0;
    char p4[0xC];
    char x10[0xF0];
    char x100[0x10];
} Anim;

typedef struct Sub2E50 {
    int x0;
    char x4[0x10];
    unsigned char x14;
    char p15[3];
    char x18[0x10];
    int x28;
    char p2c[4];
    char x30[0x20];
    V4 x50;
} Sub2E50;

typedef struct Tail {
    int x0;
    char p4[0xC];
    float mn[4];
    float mx[4];
    int x30;
    int x34;
    char p38[8];
    Sub2E50* x40;
    int x44;
} Tail;

static inline void Tail_ctor(Tail* t, Sub2E50* s)
{
    t->x0 = 0;
    t->mn[0] = 3.4028235e38f;
    t->mn[1] = 3.4028235e38f;
    t->mn[2] = 3.4028235e38f;
    t->mn[3] = 1.0f;
    t->mx[0] = -3.4028235e38f;
    t->mx[1] = -3.4028235e38f;
    t->mx[2] = -3.4028235e38f;
    t->mx[3] = 1.0f;
    t->x30 = 0;
    t->x34 = 0;
    t->x40 = s;
    t->x44 = 0;
}

typedef struct Actor {
    void* vt;
    char p4[0x2B];
    unsigned char x2F;
    int x30;
    char p34[0x2C];
    char x60[0x2E50 - 0x60];
    Sub2E50 x2E50;
    int x2EB0;
    char p2EB4[0xC];
    Anim x2EC0;
    char p2FD0[0x2FE0 - 0x2EC0 - sizeof(Anim)];
    Tail x2FE0;
} Actor;

extern char D_004DF740[];
extern void cGOBJ_ctor(Actor* self, int* name, int type, int* extra);
extern void cMan_ctor(void*);
#if 0 /* merge_units */
extern void cArray_cBoneScale_ctor(void*);
#endif /* merge_units */
#define cArray_cBoneScale_ctor(a0) ((void)cArray_cBoneScale_ctor((RelFlag *)(a0))) /* merge_units */


extern void cBone_ctor_void(SkelNode*);
extern void cArray_cBone_ctor(void*, int, SkelNode*);
extern void cBone_dtor(SkelNode*, int);
extern void cBox_ctor_void(void*);
extern void cVector_Get0001(V4*);
extern void cVector_ctor_cVectorR(V4*, V4*);
extern void cSkaParams_ctor(void*, void*, void*);
extern void cTreeNode_cSkaSystemPtr_ctor(void*, Anim**);
extern void cSkaSystem_SetInitialAnimation(Anim*);

static inline void Anim_ctor(Anim* a, void* owner)
{
    a->x0 = 0;
    cSkaParams_ctor(a->x10, owner, 0);
    cTreeNode_cSkaSystemPtr_ctor(a->x100, &a);
    cSkaSystem_SetInitialAnimation(a);
}

Actor* cSKM_GOBJ_ctor_cObjectIdR(Actor* me, int* name)
{
    int z = 0;
    Sub2E50* s;
    Actor* self = me;
    cGOBJ_ctor(me, name, 2, &z);
    self->vt = D_004DF740;
    cMan_ctor(self->x60);
    s = &self->x2E50;
    s->x0 = 0;
    cArray_cBoneScale_ctor(s->x4);
    s->x14 = 0;
    {
        SkelNode n;
        cBone_ctor_void(&n);
        cArray_cBone_ctor(s->x18, 0, &n);
        cBone_dtor(&n, -1);
    }
    s->x28 = 0;
    cBox_ctor_void(s->x30);
    {
        V4 v;
        cVector_Get0001(&v);
        cVector_ctor_cVectorR(&s->x50, &v);
    }
    self->x2EB0 = 0xDEADBEEF;
    Anim_ctor(&self->x2EC0, &self->x2E50);
    Tail_ctor(&self->x2FE0, &self->x2E50);
    self->x2F = 1;
    self->x30 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393FF0(void) {}
#undef cArray_cBoneScale_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00393FF0 */

/* merge_units: begin func_00394140 */
#pragma push /* merge_units */
extern int cParticle_GetEvent(int, int);

int cPARTICLE_GOBJ_GetEvent(int a0) {
    int a1, v0;
    int cond;

    a0 = *(int*)((char*)a0 + 100);
    cond = a0 == 0;
    v0 = 0;
    if (cond) goto L00394160;
    v0 = cParticle_GetEvent(a0, a1);
L00394160:;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00394140 */

/* merge_units: begin func_00394170 */
#pragma push /* merge_units */
extern unsigned char cParticle_EventHappened(void* p);

/* Returns cParticle_EventHappened(self->unk64), or 0 when unk64 is null. */
int cPARTICLE_GOBJ_EventHappened(cVUM_GOBJ* self) {
    void* p = self->unk64;
    int result = 0;

    if (p != 0) {
        result = cParticle_EventHappened(p);
    }
    return result;
}
static inline void merge_flush_func_00394170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00394170 */

/* merge_units: begin func_003941A0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cParticle_dtor(...);                            
int cGOBJ_Deactivate(...);                         
extern unsigned char g_ProfileLockEnabled;
}
#pragma opt_common_subs off
extern "C" void cPARTICLE_GOBJ_Deactivate(char * arg0, int arg1) {
    int temp_s2;

    temp_s2 = F_(arg0, 0x64, int);
    if (temp_s2 != 0) {
        {
            AllocGuard g;
        cParticle_dtor(temp_s2, -1);
        cMemMan_Deallocate(0, temp_s2, "gameobj.cc", 0x286);
        }
        F_(arg0, 0x64, int) = 0;
    }
    cGOBJ_Deactivate(arg0, arg1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003941A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003941A0 */

/* merge_units: begin func_00394270 */
#pragma push /* merge_units */
#pragma cplusplus on

class Owner394270 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
};

struct OwnerData394270 {
    void* vt;
    char p4[0xC];
    char pos[0x40];
    unsigned char dirty;
};

struct Tracer394270 {
    char p[0x50];
    float width;
};

struct Self394270 {
    char p0[0x50];
    OwnerData394270* owner;
    char p54[0xC];
    int id;
    Tracer394270* tracer;
    char p68[4];
    float width;
};

extern "C" {
extern char D_004BC430[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
Tracer394270* cParticle_ctor(void* p, int id, void* pos, float scale);
#if 0 /* merge_units */
void cGOBJ_Activate(Self394270* self, int arg);
#endif /* merge_units */
void cGOBJ_Activate(void*, int); /* merge_units */
#define cGOBJ_Activate(a0, a1) (cGOBJ_Activate((void *)(a0), (a1))) /* merge_units */

}

extern "C" void cPARTICLE_GOBJ_Activate(Self394270* self, int arg)
{
    if (self->id != -1 && self->tracer == 0) {
        void* p;
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, 0x70, D_004BC430, 0x273);
        }
        if (p) {
            OwnerData394270* o = self->owner;
            if (o->dirty) ((Owner394270*)o)->Update();
            p = cParticle_ctor(p, self->id, o->pos, 1.0f);
        }
        self->tracer = (Tracer394270*)p;
        if (self->tracer) self->tracer->width = self->width;
    }
    cGOBJ_Activate(self, arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394270(void) {}
#undef cGOBJ_Activate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00394270 */

/* merge_units: begin func_003943A0 */
#pragma push /* merge_units */
static inline void Q43(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4_003943A0;
typedef struct {
    Vec4_003943A0 min;
    Vec4_003943A0 max;
} Box;
typedef struct {
    char pad[0x64];
    void *mdl;
    char pad68[8];
    float scale;
} Obj;
extern Box *cParticle_GetBBox(void *);
extern signed char D_0053B4C0;
extern Box D_0053B4D0;
Box *cPARTICLE_GOBJ_GetBBox(Obj *o)
{
    if (o->mdl != 0) {
    if (o->scale == 1.0f) return cParticle_GetBBox(o->mdl);
    if (!D_0053B4C0) {
        D_0053B4D0.min.x = 3.4028235e38f;
        D_0053B4D0.min.y = 3.4028235e38f;
        D_0053B4D0.min.z = 3.4028235e38f;
        D_0053B4D0.min.w = 1.0f;
        D_0053B4D0.max.x = -3.4028235e38f;
        D_0053B4D0.max.y = -3.4028235e38f;
        D_0053B4D0.max.z = -3.4028235e38f;
        D_0053B4D0.max.w = 1.0f;
        D_0053B4C0 = 1;
    }
    Q43(&D_0053B4D0.min, &cParticle_GetBBox(o->mdl)->min);
    D_0053B4D0.min.x = o->scale * cParticle_GetBBox(o->mdl)->min.x;
    D_0053B4D0.min.y = o->scale * cParticle_GetBBox(o->mdl)->min.y;
    Q43(&D_0053B4D0.max, &cParticle_GetBBox(o->mdl)->max); { void* xx = &D_0053B4D0.max; /* dead on purpose: retail keeps this addiu */ }
    D_0053B4D0.max.x = o->scale * cParticle_GetBBox(o->mdl)->max.x;
    D_0053B4D0.max.y = o->scale * cParticle_GetBBox(o->mdl)->max.y;
    return &D_0053B4D0;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003943A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003943A0 */

/* merge_units: begin func_00394520 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_classes.h"

/* Refresh the attached node (virtual update if flagged) and hand it on. */
typedef struct Node_394520 { void* vt; unsigned char pad[0xC]; unsigned char data[0x40]; unsigned char dirty; } Node_394520;
typedef struct {
    unsigned char pad0[0x38]; int arg;
    unsigned char pad1[0x14]; Node_394520* node;
    unsigned char pad2[0x10]; int target;
} Obj_394520;
extern "C" void cParticle_Render(int target, int arg, void* data);

extern "C" void cPARTICLE_GOBJ_Render(Obj_394520* o)
{
    if (o->target != 0) {
        Node_394520* n = o->node;
        if (n->dirty)
            ((VSlots67*)n)->slot20();
        cParticle_Render(o->target, o->arg, n->data);
    }
}
static inline void merge_flush_func_00394520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00394520 */

/* merge_units: begin func_00394590 */
#pragma push /* merge_units */
#pragma cplusplus on

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
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#endif /* merge_units */

#if 0 /* merge_units */
void cParticle_dtor(Tracer394590* t, int flag);
#endif /* merge_units */

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

struct cVUM_GOBJ_00394AD0 {
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
void cShadowMan_PreRenderReceiver(void* r, cVUM_GOBJ_00394AD0* o);
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

extern "C" void cVUM_GOBJ_Render(cVUM_GOBJ_00394AD0* self)
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

/* merge_units: begin func_00394EE0 */
#pragma push /* merge_units */
typedef struct Res394EE0 { unsigned int flags; char data[0x90]; unsigned char b94; } Res394EE0;
typedef struct Hog394EE0 { int x0; char data[0x94]; char* name; } Hog394EE0;
typedef struct ModelInfo394EE0 { int x0; unsigned int flags; } ModelInfo394EE0;
typedef struct Model394EE0 { int loaded; ModelInfo394EE0* info; char p8[0x20]; int x28; } Model394EE0;

typedef struct Obj394EE0 {
    char p0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char p2F[0x31];
    int x60;
    int x64;
    Model394EE0* model;
    int p6C;
    void* col;
    char x74[0x16C];
    Res394EE0* res;
    Hog394EE0* h1E4;
    Hog394EE0* h1E8;
    Hog394EE0* h1EC;
    unsigned char b1F0;
    unsigned char b1F1;
    unsigned char b1F2;
} Obj394EE0;

extern void* GetFileStreamMan(void);
#if 0 /* merge_units */
extern void cFileStreamMan_IsStreamRequestDone(void* mgr, Res394EE0* r);
#endif /* merge_units */
void cFileStreamMan_IsStreamRequestDone(void*, void*); /* merge_units */
#define cFileStreamMan_IsStreamRequestDone(a0, a1) (cFileStreamMan_IsStreamRequestDone((a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int cFileMan_Read_void(Res394EE0* r);
#endif /* merge_units */
int cFileMan_Read_void(void*); /* merge_units */
#define cFileMan_Read_void(a0) (cFileMan_Read_void((void *)(a0))) /* merge_units */

extern void cHogFile_Open(void* ctx, void* data, int size, int z);
extern int String_CompareNoCase(char* a, char* b);
#if 0 /* merge_units */
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(Hog394EE0* h, void* data, void* ctx, int z);
#endif /* merge_units */
void cFileMan_EncodeFilename_charP_cHogFileR_bool(void*, void*, void*, int); /* merge_units */
#define cFileMan_EncodeFilename_charP_cHogFileR_bool(a0, a1, a2, a3) (cFileMan_EncodeFilename_charP_cHogFileR_bool((void *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cVU1Model_Load(Model394EE0* m, Hog394EE0* a, Hog394EE0* b);
#endif /* merge_units */
void cVU1Model_Load(void*, void*, void*); /* merge_units */
#define cVU1Model_Load(a0, a1, a2) (cVU1Model_Load((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void cCollisionModelMaster_Load(void* c, Hog394EE0* h);
#endif /* merge_units */
void cCollisionModelMaster_Load(void*, void*); /* merge_units */
#define cCollisionModelMaster_Load(a0, a1) (cCollisionModelMaster_Load((a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cGOBJ_Deactivate(Obj394EE0* o, int arg);
#endif /* merge_units */

extern void cVU1Model_Unload(Model394EE0* m);
extern void* g_TextureMgr;
extern void cTexMan_RemoveTextureHOG(void* mgr, Hog394EE0* h);
extern void cCollisionModelMaster_UnLoad(void* c);

static inline void LoadCol(void* c, Hog394EE0* h) { if (c) cCollisionModelMaster_Load(c, h); }
static inline unsigned char Model_IsLoaded(Model394EE0* m) { return m->loaded != 0; }

void cVUM_GOBJ_Deactivate(Obj394EE0* o, int arg)
{
    Res394EE0* r = o->res;
    if (r->flags & 4) {
        if (r->b94 && Model_IsLoaded(o->model) && o->model->x28 == 0) {
            cVU1Model_Unload(o->model);
            if (!o->b1F2 && String_CompareNoCase(o->h1E4->name, o->h1E8->name) == 0)
                cTexMan_RemoveTextureHOG(g_TextureMgr, o->h1E4);
            if (o->col) cCollisionModelMaster_UnLoad(o->col);
            o->b2E = 1;
            if (o->b1F2 && o->x64 == 0) {
                Res394EE0* r2 = o->res;
                cHogFile_Open(o->x74, r2->data, cFileMan_Read_void(r2), 0);
                cFileMan_EncodeFilename_charP_cHogFileR_bool(o->h1E4, o->h1E4->data, o->x74, 0);
                cTexMan_RemoveTextureHOG(g_TextureMgr, o->h1E4);
            }
        }
        if (o->x60 && !Model_IsLoaded(o->model)) o->b2E = 1;
    } else {
        o->b2E = 0;
    }
    o->b2C = 0;
    cGOBJ_Deactivate(o, arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394EE0(void) {}
#undef cFileStreamMan_IsStreamRequestDone /* merge_units */
#undef cFileMan_Read_void /* merge_units */
#undef cFileMan_EncodeFilename_charP_cHogFileR_bool /* merge_units */
#undef cVU1Model_Load /* merge_units */
#undef cCollisionModelMaster_Load /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00394EE0 */

/* merge_units: begin func_00395050 */
#pragma push /* merge_units */
typedef struct Res395050 { unsigned int flags; char data[0x90]; unsigned char b94; } Res395050;
typedef struct Hog395050 { int x0; char data[0x94]; char* name; } Hog395050;
typedef struct ModelInfo395050 { int x0; unsigned int flags; } ModelInfo395050;
typedef struct Model395050 { int loaded; ModelInfo395050* info; char p8[0x20]; int x28; } Model395050;

typedef struct Obj395050 {
    char p0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char p2F[0x31];
    int x60;
    int x64;
    Model395050* model;
    int p6C;
    void* col;
    char x74[0x16C];
    Res395050* res;
    Hog395050* h1E4;
    Hog395050* h1E8;
    Hog395050* h1EC;
    unsigned char b1F0;
    unsigned char b1F1;
    unsigned char b1F2;
} Obj395050;
#if 0 /* merge_units */
extern void cFileStreamMan_IsStreamRequestDone(void* mgr, Res395050* r);
#endif /* merge_units */
#define cFileStreamMan_IsStreamRequestDone(a0, a1) (cFileStreamMan_IsStreamRequestDone((a0), (void *)(a1))) /* merge_units */



#if 0 /* merge_units */
extern int cFileMan_Read_void(Res395050* r);
#endif /* merge_units */
#define cFileMan_Read_void(a0) (cFileMan_Read_void((void *)(a0))) /* merge_units */



#if 0 /* merge_units */
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(Hog395050* h, void* data, void* ctx, int z);
#endif /* merge_units */
#define cFileMan_EncodeFilename_charP_cHogFileR_bool(a0, a1, a2, a3) (cFileMan_EncodeFilename_charP_cHogFileR_bool((void *)(a0), (a1), (a2), (a3))) /* merge_units */



#if 0 /* merge_units */
extern void cVU1Model_Load(Model395050* m, Hog395050* a, Hog395050* b);
#endif /* merge_units */
#define cVU1Model_Load(a0, a1, a2) (cVU1Model_Load((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */



#if 0 /* merge_units */
extern void cCollisionModelMaster_Load(void* c, Hog395050* h);
#endif /* merge_units */
#define cCollisionModelMaster_Load(a0, a1) (cCollisionModelMaster_Load((a0), (void *)(a1))) /* merge_units */



#if 0 /* merge_units */
extern void cGOBJ_Activate(Obj395050* o, int arg);
#endif /* merge_units */
#define cGOBJ_Activate(a0, a1) (cGOBJ_Activate((void *)(a0), (a1))) /* merge_units */


static inline void LoadCol_00395050(void* c, Hog395050* h) { if (c) cCollisionModelMaster_Load(c, h); }
static inline unsigned char Model_IsLoaded_00395050(Model395050* m) { return m->loaded != 0; }

void cVUM_GOBJ_Activate(Obj395050* o, int arg)
{
    Res395050* r = o->res;
    if (r->flags & 4) {
        if (!Model_IsLoaded_00395050(o->model)) {
            cFileStreamMan_IsStreamRequestDone(GetFileStreamMan(), r);
            r = o->res;
            cHogFile_Open(o->x74, r->data, cFileMan_Read_void(r), 0);
            if (String_CompareNoCase(o->h1E4->name, o->h1E8->name) == 0)
                cFileMan_EncodeFilename_charP_cHogFileR_bool(o->h1E4, o->h1E4->data, o->x74, 0);
            cFileMan_EncodeFilename_charP_cHogFileR_bool(o->h1E8, o->h1E8->data, o->x74, 0);
            cFileMan_EncodeFilename_charP_cHogFileR_bool(o->h1EC, o->h1EC->data, o->x74, 0);
            cVU1Model_Load(o->model, o->h1E8, o->h1E4);
            LoadCol_00395050(o->col, o->h1EC);
            if (o->model->info->flags & 0x10) {
                o->b1F0 = 0;
                o->b1F1 = 0;
            }
        }
    }
    o->b2E = 0;
    o->b2C = 1;
    cGOBJ_Activate(o, arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00395050(void) {}
#undef cFileStreamMan_IsStreamRequestDone /* merge_units */
#undef cFileMan_Read_void /* merge_units */
#undef cFileMan_EncodeFilename_charP_cHogFileR_bool /* merge_units */
#undef cVU1Model_Load /* merge_units */
#undef cCollisionModelMaster_Load /* merge_units */
#undef cGOBJ_Activate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00395050 */

/* merge_units: begin func_003951A0 */
#pragma push /* merge_units */
void cVUM_GOBJ_NextFrame(void) {
}
static inline void merge_flush_func_003951A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003951A0 */

/* merge_units: begin func_003951B0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Res3951B0 {
    unsigned int flags;
    char path[0x80];
    short x84;
    int x88;
    int x8C;
    int x90;
    unsigned char b94;
    char* name;
};
struct ModelInfo3951B0 { int x0; unsigned int flags; };
struct Model3951B0 { int loaded; ModelInfo3951B0* info; };

struct Obj3951B0 {
    char p0[0x60];
    struct Obj3951B0* x60;
    int x64;
    Model3951B0* model;
    int p6C;
    void* col;
    char x74[0x16C];
    Res3951B0* res;
    Res3951B0* h1E4;
    Res3951B0* h1E8;
    Res3951B0* h1EC;
    unsigned char b1F0;
    unsigned char b1F1;
    unsigned char b1F2;
};

struct Desc3951B0 {
    Res3951B0* res;
    Res3951B0* res2;
    Obj3951B0* tmpl;
    int xC;
    char* name;
};

extern "C" {
extern char D_004BC440[];
extern char D_004BC448[];
extern char D_004BC450[];
void cVUM_GOBJ_CreateModelData(Obj3951B0* self, int x);
void Libc_Strcpy(char* d, const char* s);
char* strchr(const char* s, int c);
void cFileMan_EncodeFilename_charP_cFileManR(Res3951B0* h, char* path, Res3951B0* r);
int String_CompareNoCase(char* a, char* b);
#if 0 /* merge_units */
int cFileMan_Read_void(Res3951B0* r);
#endif /* merge_units */
#define cFileMan_Read_void(a0) (cFileMan_Read_void((void *)(a0))) /* merge_units */


void cHogFile_Open(void* ctx, void* data, int size, int z);
#if 0 /* merge_units */
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Res3951B0* h, void* data, void* ctx, int z);
#endif /* merge_units */
#define cFileMan_EncodeFilename_charP_cHogFileR_bool(a0, a1, a2, a3) (cFileMan_EncodeFilename_charP_cHogFileR_bool((void *)(a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
void cVU1Model_Load(Model3951B0* m, Res3951B0* a, Res3951B0* b);
#endif /* merge_units */
#define cVU1Model_Load(a0, a1, a2) (cVU1Model_Load((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */


#if 0 /* merge_units */
void cCollisionModelMaster_Load(void* c, Res3951B0* h);
#endif /* merge_units */
#define cCollisionModelMaster_Load(a0, a1) (cCollisionModelMaster_Load((a0), (void *)(a1))) /* merge_units */


}

static inline void LoadCol_003951B0(void* c, Res3951B0* h) { if (c) cCollisionModelMaster_Load(c, h); }

extern "C" void cVUM_GOBJ_Load(Obj3951B0* self, Desc3951B0* d)
{
    char buf[0x70];
    if (d->name) self->b1F2 = 1; else self->b1F2 = 0;
    Obj3951B0* t = d->tmpl;
    if (t) {
        self->x60 = t;
        self->x64 = t->x64;
        self->model = t->model;
        self->col = t->col;
        self->res = t->res;
        self->h1E4 = t->h1E4;
        self->h1E8 = t->h1E8;
        self->h1EC = t->h1EC;
        self->x64 = d->xC;
        return;
    }
    cVUM_GOBJ_CreateModelData(self, d->xC);
    if (!d->xC) *self->res = *d->res;
    char* base = d->res->path;
    if (d->name) Libc_Strcpy(buf, d->name); else Libc_Strcpy(buf, base);
    Libc_Strcpy(strchr(buf, '.'), D_004BC440);
    cFileMan_EncodeFilename_charP_cFileManR(self->h1E8, buf, self->res);
    if (d->name) Libc_Strcpy(buf, d->name); else Libc_Strcpy(buf, base);
    Libc_Strcpy(strchr(buf, '.'), D_004BC448);
    cFileMan_EncodeFilename_charP_cFileManR(self->h1EC, buf, self->res);
    if (String_CompareNoCase(d->res2->name, d->res->name) == 0) {
        Libc_Strcpy(buf, base);
        Libc_Strcpy(strchr(buf, '.'), D_004BC450);
        cFileMan_EncodeFilename_charP_cFileManR(self->h1E4, buf, self->res);
    } else {
        *self->h1E4 = *d->res2;
    }
    Res3951B0* r = self->res;
    if (!(r->flags & 4)) {
        cHogFile_Open(self->x74, r->path, cFileMan_Read_void(r), 0);
        if (String_CompareNoCase(self->h1E4->name, self->h1E8->name) == 0)
            cFileMan_EncodeFilename_charP_cHogFileR_bool(self->h1E4, self->h1E4->path, self->x74, 0);
        cFileMan_EncodeFilename_charP_cHogFileR_bool(self->h1E8, self->h1E8->path, self->x74, 0);
        cFileMan_EncodeFilename_charP_cHogFileR_bool(self->h1EC, self->h1EC->path, self->x74, 0);
        cVU1Model_Load(self->model, self->h1E8, self->h1E4);
        LoadCol_003951B0(self->col, self->h1EC);
        if (self->model->info->flags & 0x10) {
            self->b1F0 = 0;
            self->b1F1 = 0;
        }
    }
}
#undef cFileMan_Read_void /* merge_units */
#undef cFileMan_EncodeFilename_charP_cHogFileR_bool /* merge_units */
#undef cVU1Model_Load /* merge_units */
#undef cCollisionModelMaster_Load /* merge_units */
static inline void merge_flush_func_003951B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003951B0 */
