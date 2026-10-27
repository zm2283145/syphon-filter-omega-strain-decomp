/*
 * Libs/SFOLib/Source/gameobj: 9 files, 00393F60-00394520
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
void cGOBJ_Activate(Self394270* self, int arg);
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
