/*
 * SFOGame/Source/gamelight: 17 files, 00178FA0-00179620
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00178FA0 */
#pragma push /* merge_units */
#include "types.h"

/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cGameDirectionalLight {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42();
    virtual void TurnOff(); /* +0x114 */
};

/* Script native: cGameDirectionalLight::TurnOff() on args[0]; returns 0. */
extern "C" int Script_cGameDirectionalLight_TurnOff(ScriptArg* args)
{
    cGameDirectionalLight* obj = (cGameDirectionalLight*)args[0].p;
    obj->TurnOff();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00178FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00178FA0 */

/* merge_units: begin func_00178FD0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00178FD0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00178FD0;

/* Virtual-call view of cGameDirectionalLight: only the slots used here are named (vtable offset in comments). */
struct cGameDirectionalLight_00178FD0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void TurnOn(); /* +0x110 */
};

/* Script native: cGameDirectionalLight::TurnOn() on args[0]; returns 0. */
extern "C" int Script_cGameDirectionalLight_TurnOn(ScriptArg_00178FD0* args)
{
    cGameDirectionalLight_00178FD0* obj = (cGameDirectionalLight_00178FD0*)args[0].p;
    obj->TurnOn();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00178FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00178FD0 */

/* merge_units: begin func_00179000 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cGameDirectionalLight script type registration and class helpers.
 */


extern int D_004EE8D8;   /* cGameDirectionalLight class type id */
extern int D_004EE8E0;   /* cGameDirectionalLight script type */
extern int D_004EE898;   /* cGameLight class type id (parent) */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern void cScriptBase_declareParent(int type, int parentType);

/* Registers the cGameDirectionalLight script type under its parent type. */
void cGameDirectionalLight_SOBJ_init(void) {
    cScriptBase_declareParent(D_004EE8E0, D_004EE898);
}

int cGameDirectionalLight_getSOBJClassId(void) {
    return D_004EE8D8;
}

int cGameDirectionalLight_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179000 */

/* merge_units: begin func_00179050 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cGameSceneLight {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42();
    virtual void TurnOff(); /* +0x114 */
};

/* Script native: cGameSceneLight::TurnOff() on args[0]; returns 0. */
extern "C" int Script_cGameSceneLight_TurnOff(ScriptArg* args)
{
    cGameSceneLight* obj = (cGameSceneLight*)args[0].p;
    obj->TurnOff();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179050 */

/* merge_units: begin func_00179080 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00179080 { int i; float f; void* p; } ScriptArg_00179080;

/* Virtual-call view of cGameSceneLight: only the slots used here are named (vtable offset in comments). */
struct cGameSceneLight_00179080 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void TurnOn(); /* +0x110 */
};

/* Script native: cGameSceneLight::TurnOn() on args[0]; returns 0. */
extern "C" int Script_cGameSceneLight_TurnOn(ScriptArg_00179080* args)
{
    cGameSceneLight_00179080* obj = (cGameSceneLight_00179080*)args[0].p;
    obj->TurnOn();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179080 */

/* merge_units: begin func_001790B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cGameSceneLight script type registration and class helpers.
 */


extern int D_004EE8B8;   /* cGameSceneLight class type id */
extern int D_004EE8C0;   /* cGameSceneLight script type */

/* Registers the cGameSceneLight script type under its parent type. */
void cGameSceneLight_SOBJ_init(void) {
    cScriptBase_declareParent(D_004EE8C0, D_004EE898);
}

int cGameSceneLight_getSOBJClassId(void) {
    return D_004EE8B8;
}

int cGameSceneLight_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001790B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001790B0 */

/* merge_units: begin func_00179100 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00179100 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00179100;

/* Virtual-call view of cGameLight: only the slots used here are named (vtable offset in comments). */
struct cGameLight {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42();
    virtual void TurnOff(); /* +0x114 */
};

/* Script native: cGameLight::TurnOff() on args[0]; returns 0. */
extern "C" int Script_cGameLight_TurnOff(ScriptArg_00179100* args)
{
    cGameLight* obj = (cGameLight*)args[0].p;
    obj->TurnOff();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179100 */

/* merge_units: begin func_00179130 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cGameLight_00179130 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void TurnOn(); /* +0x110 */
};

/* Script native: cGameLight::TurnOn() on args[0]; returns 0. */
extern "C" int Script_cGameLight_TurnOn(ScriptArg* args)
{
    cGameLight_00179130* obj = (cGameLight_00179130*)args[0].p;
    obj->TurnOn();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179130 */

/* merge_units: begin func_00179160 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cGameLight script type registration and class helpers.
 */


extern int D_004EE8A0;   /* cGameLight script type */
extern int* cGOBJ_SOBJ_getClassId(void);

/* Registers the cGameLight script type under its parent type. */
void cGameLight_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();

    cScriptBase_declareParent(D_004EE8A0, *parent);
}

int cGameLight_getSOBJClassId(void) {
    return D_004EE898;
}

int cGameLight_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179160 */

/* merge_units: begin func_001791C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C5Sub {
    int a;
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void Method30(); /* +0x30 */
};
struct C5Light { char pad[0x60]; C5Sub* sub; };
extern "C" void cGOBJ_Deactivate(C5Light* p);
extern "C" void cGameDirectionalLight_Deactivate(C5Light* p) {
    cGOBJ_Deactivate(p);
    p->sub->Method30();
}
static inline void merge_flush_func_001791C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001791C0 */

/* merge_units: begin func_00179200 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct LightBase { int unk0; }; /* data before the vtable pointer (vptr at +4) */

/* Virtual-call view of Light: only the slots used here are named (vtable offset in comments). */
struct Light : LightBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08();
    virtual void Method2C(); /* +0x2C */
};

typedef struct SceneLight {
    char pad[0x60];
    Light* light; /* +0x60 */
} SceneLight;

extern "C" void cGOBJ_Activate(SceneLight* self, void* arg);

/* Virtual 0x15: runs the base handler, then the light's virtual +0x2C. */
extern "C" void cGameDirectionalLight_Activate(SceneLight* self, void* arg)
{
    cGOBJ_Activate(self, arg);
    self->light->Method2C();
}
static inline void merge_flush_func_00179200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179200 */

/* merge_units: begin func_00179240 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cGameDirectionalLight_ctor: read a directional light record (id, 28-byte direction/colour block, enable flag, intensity) and create its LevelLight */
// quadword/byte block copy (retail's memcpy idiom; lq/sq loop, not expressible in C)
static inline void QCopy(void* dst0, void* src0, int n0)
{
    int n; int t; int m; char* dst; char* src;
    n = n0; dst = (char*)dst0; src = (char*)src0;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
struct V4 { float x, y, z, w; };
struct V3 { float x, y, z; };
struct GLt {
    int f0;
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5();
    virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void Update();
    int f8;
    float fC;
};
struct LReader { int version; int a, b; char* cur; };
struct LRec { int kind; V3 dir; V3 col; };
struct Id { int v; };
struct GLight { void* vt; char pad4[8]; Id id; char pad10[0x60 - 0x10]; GLt* light; unsigned char on; };
extern "C" {
extern char D_004DA1D0[];
extern char D_004DA0B0[];
extern char D_004DA070[];
extern char g_LightMgr[];
extern void* D_004EE890;
void cGOBJ_ctor(GLight* obj, int* id, int kind, void* type);
GLt* cLightMan_AddLight(void* pool, int n);
V4* tRGBA_ctor_tRGBR_float(V4* out, V3* in, float w);
void cLightSrc_ctor_eLightSrcTypes_tRGBAR(GLt* l, int a, V4* c);
void cVector_ctor_cVectorR(void* d, V4* s);
GLight* cGameDirectionalLight_ctor(GLight* obj, LReader* r);
}
static inline int Read(LReader* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadFloat(LReader* r, float* out) { *out = *(float*)r->cur; r->cur += 4; }
static inline void Align(LReader* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline GLt* MakeDir(GLt* p0, LRec& rec, V3& col, V4& dir, V4& tmp)
{
    GLt* p = p0; /* separate copy (propagation off): retail moves the light into s3 inside the arm and back to v0 at the join */
    float x, y, z, a, b, c;
    z = rec.col.z; y = rec.col.y; x = rec.col.x;
    c = rec.dir.z; b = rec.dir.y; a = rec.dir.x;
    col.z = z; col.y = y; col.x = x; dir.z = c; dir.y = b; dir.x = a; dir.w = 0.0f;
    cLightSrc_ctor_eLightSrcTypes_tRGBAR(p, 2, tRGBA_ctor_tRGBR_float(&tmp, &col, 0.0f));
    *(void**)((char*)p + 4) = D_004DA070;
    cVector_ctor_cVectorR((char*)p + 0x40, &dir);
    return p;
}
#pragma push
#pragma opt_propagation off
GLight* cGameDirectionalLight_ctor(GLight* obj, LReader* r)
{
    volatile int id; /* volatile: retail stores the packed id to its stack slot and reloads it */
    int gid;
    float k;
    V3 col;
    LRec rec;
    V4 dir;
    V4 tmp;
    int hi, lo;
    unsigned char en;
    gid = -1;
    cGOBJ_ctor(obj, &gid, 6, &D_004EE890);
    obj->vt = D_004DA1D0;
    obj->light = 0;
    obj->on = 1;
    obj->vt = D_004DA0B0;
    hi = Read(r);
    lo = Read(r);
    QCopy(&rec, r->cur, 28);
    r->cur += 28;
    en = *(unsigned char*)r->cur;
    r->cur++;
    Align(r);
    ReadFloat(r, &k);
    {
        GLt* l = cLightMan_AddLight(g_LightMgr, 2);
        if (l) l = MakeDir(l, rec, col, dir, tmp);
        obj->light = l;
    }
    if (en) obj->light->fC = k;
    else obj->light->fC = 0.0f;
    obj->light->Update();
    id = lo | (hi << 16);
    obj->id.v = id;
    return obj;
}
#pragma pop
static inline void merge_flush_func_00179240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179240 */

/* merge_units: begin func_00179490 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Light parameter setter.
 */

#include "gameLight_types.h"

void cLightSrc_SetId(GameLightParams* self, int value) {
    self->unk08 = value;
}
static inline void merge_flush_func_00179490(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179490 */

/* merge_units: begin func_001794A0 */
#pragma push /* merge_units */
typedef struct { int a; int b; } E794;
typedef struct { char pad0[0x1C]; unsigned char flag; char pad1[0x60-0x1D]; E794 e[16]; } S794;
extern unsigned char g_LevelLightsDirty;
void cSceneLight_Init(S794* p) {
    unsigned int i;
    for (i = 0; i < 16; i++) {
        p->e[i].a = 0;
        p->e[i].b = -1;
    }
    if (p->flag == 0) {
        p->flag = 1;
        g_LevelLightsDirty = 1;
    }
}
static inline void merge_flush_func_001794A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001794A0 */

/* merge_units: begin func_00179520 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Light parameter setters.
 */


void LightEffect_SetOuter(GameLightParams* self, float value) {
    self->unk14 = value;
}

void LightEffect_SetInner(GameLightParams* self, float value) {
    self->unk10 = value;
}
static inline void merge_flush_func_00179520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179520 */

/* merge_units: begin func_00179540 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint: point-light variant of cLightSrc_ctor_eLightSrcTypes_tRGBAR (cLightSrc_ctor_eLightSrcTypes_tRGBAR.c) */
struct V4c { float x, y, z, w; };
// VU0 macro-mode squared length (COP2), not expressible in C
static inline float LenSqP(const V4c* a) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
// 128-bit lq/sq quadword copy
static inline void Q16(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
struct DirLight {
    unsigned char f0;
    unsigned char f1;
    char pad2[2];
    void* vt;
    char pad8[4];
    int fC;
    char pad10[8];
    float f18;
    unsigned char f1C;
    unsigned char f1D;
    unsigned char f1E;
    char pad1F;
    V4c color;
    V4c dir;
};
extern "C" {
extern char D_004D9240[];
extern char D_004D9280[];
extern signed char D_0048A150;
}
extern "C" DirLight* cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(DirLight* l, unsigned char a, V4c* c, V4c* pos, unsigned char b)
{
    V4c v;
    float x, y, z, w;
    l->vt = D_004D9280;
    l->f0 = D_0048A150;
    l->f1 = 0;
    l->vt = D_004D9240;
    l->fC = 0;
    l->f1C = 0;
    l->f1D = b;
    l->f1E = a;
    l->color = *c;
    Q16(&l->dir, pos);
    g_LevelLightsDirty = 1;
    w = c->w; z = c->z; y = c->y; x = c->x;
    v.x = x; v.y = y; v.z = z; v.w = w;
    l->f18 = 1.0f / LenSqP(&v);
    return l;
}
static inline void merge_flush_func_00179540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179540 */

/* merge_units: begin func_00179620 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cGameSceneLight_ctor: read a point/spot light record and create its LevelLight */
static inline void QCopy_00179620(void* dst0, void* src0, int n0)
{
    int n; int t; int m; char* dst; char* src;
    n = n0; dst = (char*)dst0; src = (char*)src0;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
struct PLt {
    int f0;
    void* vt;
    int f8;
    float fC;
    float f10;
    float f14;
    char pad18[5];
    unsigned char f1D;
    char pad1E[0x40 - 0x1E];
    V4 v40;
    float f50;
    float f54;
    unsigned char f58;
    int f5C;
};
struct LRec_00179620 { int kind; V3 pos; V3 col; float inner; float outer; };
struct GLight_00179620 { void* vt; char pad4[8]; Id id; char pad10[0x60 - 0x10]; PLt* light; unsigned char on; };
extern "C" {
extern char D_004D9F50[];
extern char D_004DF700[];
#if 0 /* merge_units */
void cGOBJ_ctor(GLight_00179620* obj, int* id, int kind, void* type);
#endif /* merge_units */
#define cGOBJ_ctor(a0, a1, a2, a3) (cGOBJ_ctor((GLight *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
PLt* cLightMan_AddLight(void* pool, int n);
#endif /* merge_units */
#define cLightMan_AddLight(a0, a1) ((PLt *)cLightMan_AddLight((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(PLt* l, int a, V4* c, V4* pos, int b);
#endif /* merge_units */
#define cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(a0, a1, a2, a3, a4) ((void)cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint((DirLight *)(a0), (unsigned char)(a1), (V4c *)(a2), (V4c *)(a3), (unsigned char)(a4))) /* merge_units */

void cVector_ctor_float_float_float_float(V4* v, float x, float y, float z, float w);
#if 0 /* merge_units */
void LightEffect_SetInner(PLt* l, float v);
#endif /* merge_units */
#define LightEffect_SetInner(a0, a1) (LightEffect_SetInner((GameLightParams *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void LightEffect_SetOuter(PLt* l, float v);
#endif /* merge_units */
#define LightEffect_SetOuter(a0, a1) (LightEffect_SetOuter((GameLightParams *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cSceneLight_Init(PLt* l);
#endif /* merge_units */
#define cSceneLight_Init(a0) (cSceneLight_Init((S794 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cLightSrc_SetId(PLt* l, int id);
#endif /* merge_units */
#define cLightSrc_SetId(a0, a1) (cLightSrc_SetId((GameLightParams *)(a0), (a1))) /* merge_units */

float Libc_Cosf(float a);
GLight_00179620* cGameSceneLight_ctor(GLight_00179620* obj, LReader* r);
}
static inline void Q16_00179620(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline float Deg2Rad(float d) { return 0.017453292f * d; }
static inline void SetA(PLt* l, float v) { l->f10 = v; }
static inline void SetB(PLt* l, float v) { l->f14 = v; }
static inline unsigned char ReadByte(LReader* r) { unsigned char v = *(unsigned char*)r->cur; r->cur++; return v; }
static inline PLt* MakePoint(PLt* p0, LRec_00179620& rec, V3& col, V4& pos, V4& tmp, volatile int& id)
{
    int i = id;
    float x, y, z, a, b, c;
    z = rec.col.z; y = rec.col.y; x = rec.col.x;
    c = rec.pos.z; b = rec.pos.y; a = rec.pos.x;
    col.z = z; col.y = y; col.x = x; pos.z = c; pos.y = b; pos.x = a; pos.w = 1.0f;
    PLt* p = p0;
    cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(p, 0x10, tRGBA_ctor_tRGBR_float(&tmp, &col, 0.0f), &pos, 0);
    p->vt = D_004DF700;
    cVector_ctor_float_float_float_float(&p->v40, 0.0f, 0.0f, 0.0f, 0.0f);
    p->f50 = 0.0f;
    p->f54 = 0.0f;
    p->f58 = 1;
    p->f5C = 0;
    LightEffect_SetInner(p, 0.0f);
    LightEffect_SetOuter(p, 0.0f);
    cSceneLight_Init(p);
    cLightSrc_SetId(p, i);
    return p;
}
#pragma push
#pragma opt_propagation off
GLight_00179620* cGameSceneLight_ctor(GLight_00179620* obj, LReader* r)
{
    volatile int id;
    int gid;
    V3 col;
    LRec_00179620 rec;
    V4 v;
    V4 pos;
    V4 tmp;
    int hi, lo;
    float outer, inner, k;
    unsigned char en, f8, f10;
    gid = -1;
    cGOBJ_ctor(obj, &gid, 6, &D_004EE890);
    obj->vt = D_004DA1D0;
    obj->light = 0;
    obj->on = 1;
    obj->vt = D_004D9F50;
    f8 = 0;
    f10 = 0;
    v.x = 0.0f; v.y = 0.0f; v.z = 0.0f; v.w = 0.0f;
    hi = Read(r);
    lo = Read(r);
    r->cur += 4;
    r->cur += 4;
    QCopy_00179620(&rec, r->cur, 0x24);
    r->cur += 0x24;
    ReadFloat(r, &v.x);
    ReadFloat(r, &v.y);
    ReadFloat(r, &v.z);
    ReadFloat(r, &outer);
    ReadFloat(r, &inner);
    en = ReadByte(r);
    Align(r);
    if (r->version >= 0x3B) {
        f8 = ReadByte(r);
        Align(r);
        f10 = ReadByte(r);
        Align(r);
    }
    ReadFloat(r, &k);
    id = lo | (hi << 16);
    obj->id.v = id;
    {
        PLt* l;
        PLt* a = cLightMan_AddLight(g_LightMgr, 0x10);
        if (a) a = MakePoint(a, rec, col, pos, tmp, id);
        l = a;
        if (l) {
            SetA(l, rec.inner);
            SetB(l, rec.outer);
            l->f50 = Libc_Cosf(Deg2Rad(0.5f * outer));
            l->f54 = Libc_Cosf(Deg2Rad(0.5f * inner));
            Q16_00179620(&l->v40, &v);
            if (en) l->fC = k;
            else l->fC = 0.0f;
            if (f8) l->f1D |= 8;
            if (f10) l->f1D |= 0x10;
        }
        obj->light = l;
    }
    return obj;
}
#pragma pop
#undef cGOBJ_ctor /* merge_units */
#undef cLightMan_AddLight /* merge_units */
#undef cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint /* merge_units */
#undef LightEffect_SetInner /* merge_units */
#undef LightEffect_SetOuter /* merge_units */
#undef cSceneLight_Init /* merge_units */
#undef cLightSrc_SetId /* merge_units */
static inline void merge_flush_func_00179620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179620 */
