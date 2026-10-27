/*
 * SFOGame/Source/SpecFxDefs: 7 files, 00236BE0-00236D20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00236BE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
static inline void Q16b(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V4b {
    float x, y, z, w;
    V4b() {}
    V4b(const V4b& o) { const V4b* ss = &o; V4b* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(ss) : "memory"); }
    V4b& operator=(const V4b& o) { V4b* d = this; const V4b* ss = &o; Q16b(d, ss); return *this; }
} __attribute__((aligned(16)));
struct V4p : V4b {
    V4p(const V4b& o) { V4b* d = this; Q16b(d, &o); }
};
struct M4b { V4b r[4]; };
struct Obj_236BE0 {
    char pad[0xC];
    void* node;
    M4b m;
};
extern "C" V4b* cParticle_GetBBox(void* node);
extern "C" int XLib_TestBBox_cVectorR_cVectorR(void* obj, V4b* a, V4b* b);
extern "C" void cParticle_Render(void* node, int arg, M4b* m);
extern "C" char g_Video[];
static inline void My_236BE0(V4b* a, M4b* b) {
    asm {
        lqc2 vf8, 0x0(a)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(a)
    }
}
static inline void Mx_236BE0(V4b* a, Obj_236BE0* s) { My_236BE0(a, &s->m); }
static inline V4b Xf_236BE0(Obj_236BE0* s, V4p v) {
    V4b* a = &v;
    Mx_236BE0(a, s);
    return *a;
}

extern "C" void cParticleFx_SfxRender(Obj_236BE0* self);
void cParticleFx_SfxRender(Obj_236BE0* self) {
    void* n = self->node;
    if (n) {
        V4b* v = cParticle_GetBBox(n);
        V4b p0 = Xf_236BE0(self, v[0]);
        V4b p1 = Xf_236BE0(self, v[1]);
        cParticle_Render(self->node, XLib_TestBBox_cVectorR_cVectorR(g_Video, &p0, &p1), &self->m);
    }
}
static inline void merge_flush_func_00236BE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00236BE0 */

/* merge_units: begin func_00236CD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Per-frame update of an emitter-driven effect.
 */

#include "SpecFxDefs_types.h"

extern int cParticle_NextFrame(SpecEmitter* emitter, float* pos, int c, float dt);

/* Updates the emitter at the effect position; marks the effect done once the
 * emitter is no longer active. */
void cParticleFx_SfxUpdate(SpecEmitterFx* fx, float dt) {
    if (fx->emitter != 0) {
        cParticle_NextFrame(fx->emitter, fx->pos, 0, dt);
        if (fx->emitter->active == 0) {
            fx->done = 1;
        }
    }
}
static inline void merge_flush_func_00236CD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00236CD0 */

/* merge_units: begin func_00236D20 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { char pad[0xC]; void* buf; } E4Own;
extern "C" {
extern char D_004A6E38[];
void cParticle_dtor(void* p, int n);
}
extern "C" void cParticleFx_SfxStop(E4Own* o)
{
    void* p = o->buf;
    if (p) {
        {
            AllocGuard g;
            cParticle_dtor(p, -1);
            cMemMan_Deallocate(0, p, D_004A6E38, 0x12C);
        }
        o->buf = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236D20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236D20 */

/* merge_units: begin func_00236DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cMemMan_Allocate(...);                        
int cParticle_ctor(int, int, char*, float);             
#if 0 /* merge_units */
extern char D_004A6E38;
#endif /* merge_units */
#define D_004A6E38 (*(char*)&D_004A6E38) /* merge_units */


extern unsigned char g_ProfileLockEnabled;
}
extern "C" void cParticleFx_SfxStart(char * arg0) {
    int var_s1;

    {
        AllocGuard g;
    var_s1 = cMemMan_Allocate(0, 0x70, &D_004A6E38, 0x125);
    }
    if (var_s1 != 0) {
        var_s1 = cParticle_ctor(var_s1, F_(arg0, 0x8, int), arg0 + 0x10, 1.0f);
    }
    F_(arg0, 0xC, int) = var_s1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236DE0(void) {}
#undef D_004A6E38 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00236DE0 */

/* merge_units: begin func_00236EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Obj00236EA0 {
public:
    int id;
    virtual void s0();
    virtual void s1();
    virtual void release();
};
struct Raw00236EA0 { int id; void* vt; };
extern "C" char D_004DBE90[];
extern "C" char D_004D9280[];
extern "C" void cSpecFx_opDelete(void* p);
extern "C" Obj00236EA0* cParticleFx_dtor(Obj00236EA0* self, short deleteFlag)
{
    if (self) {
        Raw00236EA0* r = (Raw00236EA0*)self;
        r->vt = D_004DBE90;
        self->release();
        if (self)
            r->vt = D_004D9280;
        if (deleteFlag > 0)
            cSpecFx_opDelete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236EA0 */

/* merge_units: begin func_00236F20 */
#pragma push /* merge_units */
typedef struct { unsigned char flag; char pad[7]; } D2_FxFlag;
typedef struct { int a; int b; } D2_FxEntry;
extern D2_FxFlag D_004F7A54[];
extern D2_FxEntry SpecFxTable[];
static inline D2_FxEntry* d2_get(int id) {
    if ((unsigned int)id < 41) return &SpecFxTable[id];
    return 0;
}
D2_FxEntry* nSfxLoader_GetHandle(signed char id) {
    if (!D_004F7A54[id].flag) return 0;
    return d2_get(id);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236F20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236F20 */

/* merge_units: begin func_00236F80 */
#pragma push /* merge_units */
typedef struct { int obj; unsigned char flag; char pad[3]; } E236F;
typedef struct { char pad[0xD0]; E236F e[15]; } G236F;
#if 0 /* merge_units */
extern G236F SpecFxTable;
#endif /* merge_units */
#define SpecFxTable (*(G236F*)&SpecFxTable) /* merge_units */


extern int g_TextureMgr;
extern void cTexMan_RemoveTexture(int a, int b, int c);
void nSfxLoader_UnloadEffects(void)
{
    int i;
    for (i = 0; i < 15; i++) {
        if (SpecFxTable.e[i].flag) {
            cTexMan_RemoveTexture(g_TextureMgr, SpecFxTable.e[i].obj, 1);
            SpecFxTable.e[i].flag = 0;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236F80(void) {}
#undef SpecFxTable /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00236F80 */
