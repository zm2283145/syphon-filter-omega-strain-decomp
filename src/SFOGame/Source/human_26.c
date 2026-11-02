/*
 * SFOGame/Source/human: 6 files, 001AE430-001AEF20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001AE430 */
#pragma push /* merge_units */
#include "types.h"
#include "v4_asm_copy.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

typedef struct { char pad[0x187]; char c; char pad2[8]; __int128 q; float x; float y; } XE430;
void cHumanMotionParams_RequestMotion_cVectorR_float_float_bool(XE430* t, __int128* q, char c, float x, float y) {
    __int128* d = &t->q; __int128 v;
    __asm__ volatile("lq %0,0(%1)" : "=r"(v) : "r"(q));
    asm { sq v, 0(d) }
    t->x = x;
    t->y = y;
    t->c = c;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE430(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE430 */

/* merge_units: begin func_001AE450 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Act {
    char pad0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x58 - 0x2F];
    void* p58;
    char pad5C[0x2C3D - 0x5C];
    unsigned char b2C3D;
    char pad2C3E[0x31FC - 0x2C3E];
    unsigned char b31FC;
    char pad31FD[0x339C - 0x31FD];
    int w339C;
    int w33A0;
};
extern "C" {

extern char D_0049D8D0[];
extern unsigned char g_IsMultiplayer;
extern int StartingArmor;

void* cMemMan_Allocate(int, int, char*, int);
void cGOBJ_DeleteController(Act*);
void cNetObj_AddPlayer(Act*);
void cGOBJ_AttachController(Act*, void*);
void* cPlayer_ctor(void*);
void* cNPC_ctor_cGOBJR_cObjectIdR_int(void*, Act*, int, int);
void* cNPC_ctor_cGOBJR(void*, Act*);
}
static inline bool Ready(Act* a)
{
    return a->b2D && a->b2C && !a->b2E;
}
static inline void Detach(Act* a)
{
    if (a->b31FC) {
        cGOBJ_DeleteController(a);
        a->b31FC = 0;
    }
}
static inline void* Alloc(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_0049D8D0, line);
}
extern "C" void cHuman_CreateGobjController(Act* a, unsigned char kind, int* ai, void* comp)
{
    if (g_IsMultiplayer && a->p58) {
        if (Ready(a)) {
            a->b2D = 0;
            Detach(a);
            a->b2D = 1;
        } else {
            Detach(a);
        }
    }
    switch (kind) {
    case 0:
    case 3:
        if (comp) {
            cGOBJ_AttachController(a, comp);
            a->b31FC = 1;
            cNetObj_AddPlayer(a);
        }
        {
            int v = StartingArmor;
            a->w339C = v;
            a->w33A0 = v;
        }
        break;
    case 1:
        {
            void* m = Alloc(0x1D0, 0xBCE);
            if (m) m = cPlayer_ctor(m);
            cGOBJ_AttachController(a, m);
            a->b31FC = 1;
            a->b2C3D = 1;
            {
                int v = StartingArmor;
                a->w339C = v;
                a->w33A0 = v;
            }
            cNetObj_AddPlayer(a);
        }
        break;
    case 2:
        if (ai) {
            void* m = Alloc(0x1E0, 0xBD8);
            if (m) m = cNPC_ctor_cGOBJR_cObjectIdR_int(m, a, ai[0], ai[1]);
            cGOBJ_AttachController(a, m);
        } else {
            void* m = Alloc(0x1E0, 0xBDE);
            if (m) m = cNPC_ctor_cGOBJR(m, a);
            cGOBJ_AttachController(a, m);
        }
        a->b31FC = 1;
        break;
    case 4:
        if (comp) {
            cGOBJ_AttachController(a, comp);
            a->b31FC = 1;
        }
        break;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AE450 */

/* merge_units: begin func_001AE7D0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Name32 { char s[32]; };
struct Key4 { char s[4]; };
struct NIt { char* volatile p; };
struct Model { char pad[0x44]; char tree[4]; };
struct Root { Model* model; char pad4[0xC]; char attach[0xA0]; char coll[4]; };
struct Act_001AE7D0 {
    char pad0[0x2EC0];
    Root root;
    char pad2F74[0x3260 - 0x2EC0 - sizeof(Root)];
    unsigned char b3260;
    char pad3261[0x326C - 0x3261];
    void* motion[8];
    char pad328C[0x3290 - 0x328C];
    void* parts[3];
};

extern "C" {
extern char D_004FFBC0[];
extern char D_0049D058[];
extern char D_0049D068[];
extern char D_0049E7A0[];
extern char D_0049E7B0[];
extern char D_0049E7C0[];
extern char D_0049E7D0[];
extern char D_0049E7E0[];
extern char D_0049E7F0[];
extern char D_0049E800[];
extern char D_0049E810[];
extern char D_0049E818[];
extern char D_0049E820[];
extern char D_0049E828[];
void cAssocArray_cString_cSkaAnimationSetPtr_Find(NIt*, char*, char*);
void cAssocArray_cString_cSkaAnimationSetPtr_End(NIt*, char*);
int cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(NIt*, NIt*);
Model** cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(NIt*);
#if 0 /* merge_units */
void cSkaParams_HandleNewAnimationSet(void*, Model*);
#endif /* merge_units */
struct ModelInst; /* merge_units */
struct ModelDef; /* merge_units */
void cSkaParams_HandleNewAnimationSet(ModelInst* inst, ModelDef* def); /* merge_units */
#define cSkaParams_HandleNewAnimationSet(a0, a1) (cSkaParams_HandleNewAnimationSet((ModelInst *)(a0), (ModelDef *)(a1))) /* merge_units */

void cSkaSystem_SetInitialAnimation(Root*);
void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(NIt*, void*, Name32*);
void* RootCollection_FindByKey(void*, Key4*);
}

#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma always_inline on
#pragma inline_depth(8)

static inline void N32(Name32* n, char* src)
{
    unsigned char end = 0;
    int i = 0;
    char c;
    char* s = src;
    for (; i < 0x1F; i++) {
        if (s[i] == 0) end = 1;
        c = 0;
        /* empty asm: scheduling barrier only, emits no instructions */
        if (end) asm { .set reorder } else c = s[i];
        n->s[i] = c;
    }
    n->s[i] = 0;
}

static inline void K4(Key4* k, char* src)
{
    unsigned char end = 0;
    unsigned int i = 0;
    char c;
    char* s = src;
    for (; i < 4; i++) {
        if (s[i] == 0) end = 1;
        c = 0;
        /* empty asm: scheduling barrier only, emits no instructions */
        if (end) asm { .set reorder } else c = s[i];
        k->s[i] = c;
    }
}


static inline void Find(NIt* out, Model* m, Name32* n)
{
    Name32* nn = n;
    NIt f;
    std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(&f, m->tree, nn);
    *out = f;
}

static inline void* Motion(Model* m, Name32* n)
{
    NIt c2;
    NIt c1;
    Find(&c1, m, n);
    c2 = c1;
    return *(void**)(c2.p + 0x30);
}

static inline Model* Lookup3(char* name)
{
    NIt it;
    NIt end;
    cAssocArray_cString_cSkaAnimationSetPtr_Find(&it, D_004FFBC0, name);
    cAssocArray_cString_cSkaAnimationSetPtr_End(&end, D_004FFBC0);
    Model* r;
    if (cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(&it, &end)) r = *cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(&it);
    /* empty asm: scheduling barrier only, emits no instructions */
    else { r = 0; asm { .set reorder } }
    return r;
}
static inline Model* Lookup2(char* name) { return Lookup3(name); }
static inline Model* Lookup(char* name) { return Lookup2(name); }

extern "C" Model* cHuman_InitAnimationSet(Act_001AE7D0* a)
{
    Key4 k1;
    Key4 k2;
    Key4 k3;
    Name32 n1;
    Name32 n2;
    Name32 n3;
    Name32 n4;
    Name32 n5;
    Name32 n6;
    Name32 n7;
    Name32 n8;
    char* name = 0;
    int t = a->b3260;
    Model* m;
    if (t == 1) name = D_0049D058;
    else if (t == 2) name = D_0049D068;
    if (name) {
    m = Lookup(name);
    if (m) {
    {
        Root* r = &a->root;
        cSkaParams_HandleNewAnimationSet(r->attach, m);
        r->model = m;
        cSkaSystem_SetInitialAnimation(r);
    }
    N32(&n1, D_0049E7A0); a->motion[0] = Motion(m, &n1);
    N32(&n2, D_0049E7B0); a->motion[1] = Motion(m, &n2);
    N32(&n3, D_0049E7C0); a->motion[2] = Motion(m, &n3);
    N32(&n4, D_0049E7D0); a->motion[3] = Motion(m, &n4);
    N32(&n5, D_0049E7E0); a->motion[4] = Motion(m, &n5);
    N32(&n6, D_0049E7F0); a->motion[5] = Motion(m, &n6);
    N32(&n7, D_0049E800); a->motion[6] = Motion(m, &n7);
    N32(&n8, D_0049E810); a->motion[7] = Motion(m, &n8);
    K4(&k1, D_0049E818); { Root* r = &a->root; a->parts[0] = RootCollection_FindByKey(r->coll, &k1); }
    K4(&k2, D_0049E820); { Root* r = &a->root; a->parts[1] = RootCollection_FindByKey(r->coll, &k2); }
    K4(&k3, D_0049E828); { Root* r = &a->root; a->parts[2] = RootCollection_FindByKey(r->coll, &k3); }
    return m;
    }}
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AE7D0(void) {}
#undef cSkaParams_HandleNewAnimationSet /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AE7D0 */

/* merge_units: begin func_001AEE90 */
#pragma push /* merge_units */
typedef struct ModelDef {
    int unk00;
    char roots[0x50];   /* 0x04 */
    int channelCount;   /* 0x54 */
    int pairCount;      /* 0x58 */
} ModelDef;

typedef struct ModelInst {
    char pad00[0x24];
    ModelDef* def;      /* 0x24 */
    char pad28[0x50];
    char channels[0x10];/* 0x78 */
    char pairs[0x18];   /* 0x88 */
    char roots[4];      /* 0xA0 */
} ModelInst;

typedef struct AnimChannel {
    char data[0x48];
} AnimChannel;

typedef struct IntPair2 {
    int a, b;
} IntPair2;

extern void cSkaAnimAnchorList_Reset(void* roots, void* src);
extern void cSplinedMotion_Scalar0To1_ctor(AnimChannel* ch);
extern void cSkaSliderValue_opAssign(AnimChannel* ch, float t);
extern void std_vector_imp_cSkaSliderValue_resize(void* vec, int count, AnimChannel* fill);
extern void cSplinedMotion_Scalar0To1_dtor(AnimChannel* ch, int flags);
extern void std_vector_imp_cSkaSwitchValue_resize(void* vec, int count, IntPair2* fill);

/* Attaches a model definition: roots, animation channels and pair table. */
void cSkaParams_HandleNewAnimationSet(ModelInst* inst, ModelDef* def) {
    AnimChannel ch;
    IntPair2 pair;
    inst->def = def;
    cSkaAnimAnchorList_Reset(inst->roots, def->roots);
    cSplinedMotion_Scalar0To1_ctor(&ch);
    cSkaSliderValue_opAssign(&ch, 0.0f);
    std_vector_imp_cSkaSliderValue_resize(inst->channels, def->channelCount, &ch);
    cSplinedMotion_Scalar0To1_dtor(&ch, -1);
    pair.a = 0;
    pair.b = 0;
    std_vector_imp_cSkaSwitchValue_resize(inst->pairs, def->pairCount, &pair);
}
static inline void merge_flush_func_001AEE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AEE90 */

/* merge_units: begin func_001AEF20 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSkaSwitchValue_dtor)
static inline void merge_flush_func_001AEF20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001AEF20 */

/* merge_units: begin func_001AEF70 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Anim channel destructor, optionally delete (DEFINE_ANIM_CHANNEL_DTOR_DEEP of
 * anim_channel_dtor.h written out, so the unit can define the class vtable). */
extern "C" {
#if 0 /* merge_units */
void cSplinedMotion_Scalar0To1_dtor();
#endif /* merge_units */

void cSplinedMotion_Scalar0To1_TeleportByDelta();
void cSplinedMotion_Scalar0To1_InitPos();
void cSplinedMotion_Scalar0To1_ZeroVel();
void cSplinedMotion_Scalar0To1_UpdateSplinePoints();
void cSplinedMotion_Scalar0To1_FixUpResultOfSplineEvaluation();
void cSplinedMotion_Scalar0To1_UpdateVelocity();
extern char D_004DA380[];
void operator_delete(void* allocation);

void* const D_004DA840[12] = { 0, 0, (void*)cSplinedMotion_Scalar0To1_dtor, (void*)cSplinedMotion_Scalar0To1_TeleportByDelta, (void*)cSplinedMotion_Scalar0To1_InitPos,
    (void*)cSplinedMotion_Scalar0To1_ZeroVel, (void*)cSplinedMotion_Scalar0To1_UpdateSplinePoints, (void*)cSplinedMotion_Scalar0To1_FixUpResultOfSplineEvaluation,
    (void*)cSplinedMotion_Scalar0To1_UpdateVelocity, 0, 0, 0 };
}

struct AnimChannelObj {
    void* vtable;
};

extern "C" AnimChannelObj* cSkaSliderValue_dtor(AnimChannelObj* self, short deleteFlag)
{
    if (self) {
        if (self) {
            self->vtable = (void*)D_004DA840;
            if (self)
                self->vtable = D_004DA380;
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AEF70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AEF70 */
