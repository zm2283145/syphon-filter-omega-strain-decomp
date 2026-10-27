/*
 * Libs/SFOLib/Source/gameobj: 7 files, 003926D0-00392B40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003926D0 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 * cVUM_GOBJ script type registration and model-context setup.
 */

#include "gobj_types.h"

extern int D_0053B4F0;   /* cVUM_GOBJ script-type value */
extern int D_0053B4F8;   /* cVUM_GOBJ script-type key */
extern char D_0053BB70[];
extern char D_00555070[];
extern int cSkeleton_Reset(int* ctx, ModelCtxParams* params);
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int cSkeletonDataBank_GetSkeletonData(void* table, int a1);
extern int* cGOBJ_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int base);

/* Registers the cVUM_GOBJ script type under cGOBJ. */
void cVUM_GOBJ_SOBJ_init(void) {
    int* base;

    base = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_0053B4F8, *base);
}

int cVUM_GOBJ_getSOBJClassId(void) {
    return D_0053B4F0;
}

int cVUM_GOBJ_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

/*
 * Looks up the skeleton and initializes the embedded model context.
 * a1 is passed through to cSkeletonDataBank_GetSkeletonData unchanged.
 */
void cSKM_GOBJ_ResetSkeleton(cVUM_GOBJ* self, int a1) {
    ModelCtxParams params;
    int skel;

    skel = cSkeletonDataBank_GetSkeletonData(D_0053BB70, a1);
    params.unk04 = self->base.unk50;
    params.unk10 = 1.0f;
    params.unk14 = 0.5f;
    params.skel = skel;
    params.unk18 = 0.2f;
    params.unk1C = 0.2f;
    params.unk20 = 0.2f;
    cSkeleton_Reset(&self->modelCtx, &params);
}
static inline void merge_flush_func_003926D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003926D0 */

/* merge_units: begin func_003927A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef __int128 Q3927A0;
struct Def3927A0 { char pad0[0x70]; Q3927A0 key; char pad80[0x2C04 - 0x80]; void* ctx; char pad2C08[8]; signed char preset; char pad2C11[0x2DF0 - 0x2C11]; };
struct Skel3927A0 { char pad0[0x50]; int x50; char pad54[0xC]; Def3927A0 def; char ctx[0x10]; };
struct Sc3927A0 { float a, b, c, d, e; };
struct Prm3927A0 { void* model; int x; int pad[2]; Sc3927A0 sc; };
extern "C" {
#if 0 /* merge_units */
void* cSkeletonDataBank_GetSkeletonData(void* tab, Q3927A0* key);
#endif /* merge_units */
#define cSkeletonDataBank_GetSkeletonData(a0, a1) ((void *)cSkeletonDataBank_GetSkeletonData((a0), (int)(a1))) /* merge_units */

#if 0 /* merge_units */
void cSkeleton_Reset(void* ctx, Prm3927A0* p);
#endif /* merge_units */
#define cSkeleton_Reset(a0, a1) ((void)cSkeleton_Reset((int *)(a0), (ModelCtxParams *)(a1))) /* merge_units */

void cMan_SetBoneSet(Def3927A0* d, int preset);
}
/* 16-byte block copy loop (lq/sq), as in cMan_dtor. */
static inline void QMove_3927A0(void* d0, void* s, int n0) {
    int n = n0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline long QCmp_3927A0(Q3927A0 a, Q3927A0 b) { register Q3927A0 r; asm { pceqw r, a, b
 ppach r, r, r } return (long)r; }
extern "C" void cSKM_GOBJ_CloneMan(Skel3927A0* s, Def3927A0* def)
{
    Q3927A0 oldKey = s->def.key;
    int oldPreset = s->def.preset;
    QMove_3927A0(&s->def, def, 0x2DF);
    s->def.ctx = s->ctx;
    if (QCmp_3927A0(oldKey, s->def.key) != -1) {
        Sc3927A0 sc;
        Prm3927A0 p;
        void* m = cSkeletonDataBank_GetSkeletonData(D_0053BB70, &s->def.key);
        sc.a = 1.0f; sc.b = 0.5f; sc.c = 0.2f; sc.d = 0.2f; sc.e = 0.2f;
        p.x = s->x50;
        p.sc = sc;
        p.model = m;
        cSkeleton_Reset(s->ctx, &p);
    }
    if (oldPreset != s->def.preset) cMan_SetBoneSet(&s->def, s->def.preset);
}
#undef cSkeletonDataBank_GetSkeletonData /* merge_units */
#undef cSkeleton_Reset /* merge_units */
static inline void merge_flush_func_003927A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003927A0 */

/* merge_units: begin func_003928A0 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 * cVUM_GOBJ overrides that forward to cGOBJ and then to the model context.
 */


extern int cMan_SetGunOffsets(int* p);
extern void cSkeleton_Deactivate(int* ctx);
extern int cSkeleton_Activate(int* ctx);
extern void cGOBJ_Deactivate(cVUM_GOBJ* self);
extern void cGOBJ_NetDeactivate(cVUM_GOBJ* self);
extern void cGOBJ_NetActivate(cVUM_GOBJ* self);

void cSKM_GOBJ_NetDeactivate(cVUM_GOBJ* self) {
    cGOBJ_NetDeactivate(self);
    cSkeleton_Deactivate(&self->modelCtx);
}

void cSKM_GOBJ_Deactivate(cVUM_GOBJ* self) {
    cGOBJ_Deactivate(self);
    cSkeleton_Deactivate(&self->modelCtx);
}

void cSKM_GOBJ_NetActivate(cVUM_GOBJ* self) {
    cSkeleton_Activate(&self->modelCtx);
    self->model = &self->modelCtx;
    cMan_SetGunOffsets(&self->unk60);
    cGOBJ_NetActivate(self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003928A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003928A0 */

/* merge_units: begin func_00392940 */
#pragma push /* merge_units */
/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma opt_common_subs off

typedef struct Obj3929 {
    char pad0000[0x60];
    char part60[0x2C04];    /* 0x0060 */
    void* current;          /* 0x2C64 */
    char pad2C68[0x1E8];
    char part2E50[4];       /* 0x2E50 */
} Obj3929;

#if 0 /* merge_units */
extern int cSkeleton_Activate(void* part);
#endif /* merge_units */
#define cSkeleton_Activate(a0) (cSkeleton_Activate((int *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern int cMan_SetGunOffsets(void* part);
#endif /* merge_units */
#define cMan_SetGunOffsets(a0) (cMan_SetGunOffsets((int *)(a0))) /* merge_units */


extern void cGOBJ_Activate(Obj3929* self, int arg);

/* Initializes the sub-parts and activates the object. */
void cSKM_GOBJ_Activate(Obj3929* self, int arg) {
    cSkeleton_Activate(self->part2E50);
    self->current = self->part2E50;
    cMan_SetGunOffsets(self->part60);
    cGOBJ_Activate(self, arg);
}

#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00392940(void) {}
#undef cSkeleton_Activate /* merge_units */
#undef cMan_SetGunOffsets /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00392940 */

/* merge_units: begin func_00392990 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma opt_propagation off
#pragma opt_common_subs off

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { *(__int128*)this = *(const __int128*)&o; }
    V4& operator=(const V4& o) { *(__int128*)this = *(const __int128*)&o; return *this; }
} __attribute__((aligned(16)));

struct ActorModel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual V4 GetPos();
};
struct ActorModelData {
    void* vt;
    char pad04[0x34];
    int lod;              /* 0x38 */
    char pad3C[0x24];
    char part60[0x2DF0];  /* 0x60 */
    char part2E50[4];     /* 0x2E50 */
};

extern "C" V4 D_00535D40;
extern "C" unsigned char D_00535D60;
extern "C" unsigned char D_00535D61;
extern "C" int g_VisionNight;
extern "C" void cMan_ManRender(void* a, void* b, int c, int d, int e, int f);

static inline int Vec4_Equal_(V4* a, V4* b) {
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

static inline bool Neq(V4* a, V4* b) { return !Vec4_Equal_(a, b); }
extern "C" void cSKM_GOBJ_Render(ActorModel* self) {
    ActorModelData* d = (ActorModelData*)self;
    V4 pos = self->GetPos();
    if (Neq(&D_00535D40, &pos)) {
        V4* dst = &D_00535D40;
        V4* s = &pos;
        asm { .set reorder }  /* scheduling barrier: lets the lui fill the branch delay slot */
        *(__int128*)dst = *(__int128*)s;
        D_00535D60 = 1;
        D_00535D61 = 1;
    }
    if (g_VisionNight != 0) {
        cMan_ManRender(d->part60, d->part2E50, d->lod, 0, 0, 1);
    } else {
        cMan_ManRender(d->part60, d->part2E50, d->lod, 0, 0, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00392990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00392990 */

/* merge_units: begin func_00392AA0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct UpdAW { virtual void v00(); virtual void Update(float dt); };
extern "C" void cSkaSystem_NextFrame(void* m, float dt);
extern "C" void cCollisionSystem_cBox_NextFrame(void* p, void* a, float dt);
extern "C" void cSkeleton_UpdateBBox(void* m);
extern "C" void cSkeleton_UpdateCenterOfMass(void* m);
extern "C" void cMan_ManNextFrame(void* r, float dt);
extern "C" void cGOBJ_UpdateMotion(void* a, float dt);
extern "C" void cSKM_GOBJ_UpdateMotion(char* a, float dt)
{
    UpdAW* o;
    cSkaSystem_NextFrame(a + 0x2EC0, dt);
    cCollisionSystem_cBox_NextFrame(a + 0x2FE0, a, dt);
    o = *(UpdAW**)(a + 0x3024);
    if (o) {
        o->Update(dt);
    }
    if (*(unsigned char*)(a + 0x2E64)) {
        cSkeleton_UpdateBBox(a + 0x2E50);
        cSkeleton_UpdateCenterOfMass(a + 0x2E50);
    }
    cMan_ManNextFrame(a + 0x60, dt);
    cGOBJ_UpdateMotion(a, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00392AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00392AA0 */

/* merge_units: begin func_00392B40 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */


extern void cGOBJ_NextFrame(cVUM_GOBJ* self);

void cSKM_GOBJ_NextFrame(cVUM_GOBJ* self) {
    cGOBJ_NextFrame(self);
}
static inline void merge_flush_func_00392B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00392B40 */
