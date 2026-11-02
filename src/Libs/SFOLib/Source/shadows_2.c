/*
 * Libs/SFOLib/Source/shadows: 10 files, 003D35D0-003D40D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D35D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc;
typedef struct { Alloc alloc; int value; } TaggedInt;
extern void std_list_imp_int_remove_if(void* self, TaggedInt arg);
/* Forwards value, paired with an empty allocator tag, to std_list_imp_int_remove_if. */
void cLList_int_Remove(void* self, int value)
{
    Alloc alloc;
    TaggedInt arg;
    arg.alloc = alloc;
    arg.value = value;
    std_list_imp_int_remove_if(self, arg);
}
static inline void merge_flush_func_003D35D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D35D0 */

/* merge_units: begin func_003D3600 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

/* Returns the address 8 bytes into the object pointed to by the second word. */
char* cLList_int_Back(char** self) {
    return self[1] + 8;
}

void XLib_SetAspectRatio(Unk3D3670* self, float value) {
    self->unkF94 = value;
}

/* Fills an entry: position, a tag byte, and marks it in use. */
void cXViewport_SetWindow(L4Entry110* entry, Vec4* pos, int tag) {
    entry->unk00.x = pos->x;
    entry->unk00.y = pos->y;
    entry->unk00.z = pos->z;
    entry->unk00.w = pos->w;
    entry->unk105 = tag;
    entry->unk106 = 1;
}

Vec4* tRECT_ctor(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

/* Returns the current entry. */
L4Entry110* XLib_EditViewport(Unk3D3670* self) {
    return &self->entries[self->cur];
}

/* Advances to the next entry and marks it in use. */
void XLib_PushViewport(int a0) {
    int tmp0;
    int tmp1;

    /* entries[++cur].unk106 = 1; the struct form swaps an addu operand order */
    tmp0 = *(int*)((char*)a0 + 2672);
    *(int*)((char*)a0 + 2672) = (tmp0 + 1);
    tmp1 = *(int*)((char*)a0 + 2672);
    *(char*)((char*)(a0 + (tmp1 * 272)) + 758) = 1;
}

/* Assumed to act on the same object as its neighbours. */
void XLib_SetDepthTest(Unk3D3670* self, int unused, int value) {
    self->unkF4 = value & 255;
}

unsigned char cUserFrameEnv_HasZBuffer(Unk3D36D0* self) {
    return self->unk10;
}

int cUserFrameEnv_GetZPSM(Unk3D36D0* self) {
    return self->unk0C;
}

int cUserFrameEnv_GetPSM(Unk3D36D0* self) {
    return self->unk08;
}
static inline void merge_flush_func_003D3600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D3600 */

/* merge_units: begin func_003D3700 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
static inline void Q3700(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ Q3700(this, &o); }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    void Apply(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
    V Applied(V v) const { V* p = &v; Apply(p); return *p; }
};
struct Renderer { char pad0[0x180]; float f180; char pad184[0xC]; float f190; char pad194[0xF00 - 0x194]; M view; };
extern "C" void XLib_UpdateCompMat(Renderer* r);
static inline float MaxF(float a, float b) { return a > b ? a : b; }
static inline float MinF(float a, float b) { return a < b ? a : b; }
extern "C" float XLib_GetFogVal(Renderer* r, const V* p)
{
    XLib_UpdateCompMat(r);
    const M* m = &r->view;
    V v = m->Applied(*p);
    float f = r->f180 + r->f190 / v.w;
    return MinF(MaxF(f, 0.0f), 255.0f);
}
static inline void merge_flush_func_003D3700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D3700 */

/* merge_units: begin func_003D37E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* cShadowMan_ProcessShadows: resets the projector list, finds whether any receiver takes light (0x20) or
 * ground (0x40) shadows, collects the lights near each caster and adds its ground-plane entry, then
 * builds every caster's projections. */
/* Quadword copies (lq/sq) and the VU0 dot product have no C spelling, so they are GCC-style asm.
 * The dead `xx`/`p` copies are deliberate: retail keeps those extra address computations. */
struct V_003D37E0 {
    float x, y, z, w;
    V_003D37E0() {}
    V_003D37E0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V_003D37E0(const V_003D37E0& o) { const V_003D37E0* s = &o; void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct M_003D37E0 { V_003D37E0 r[4]; };
struct Mdl { int x0; char* x4; char pad8[0x1C]; unsigned int flags; };
class XV {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
};
struct Xf { void* vt; char pad4[0xC]; M_003D37E0 world; unsigned char dirty; };
class Act {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual bool GetGroundNormal(V_003D37E0* n);
    char pad4[0x4C];
    Xf* x50;
    char pad54[0x14];
    Mdl* x68;
};
struct Obj { char pad0[0x68]; Mdl* x68; };
struct Recv { Obj* obj; char pad4[0x7C]; };
struct Caster { Act* actor; char pad4[0x12C]; };
struct CasterTab { char pad0[0x10]; Caster e[0xD9]; };
struct RecvTab { char pad0[0x4D0]; Recv e[0x200]; };
struct Shadow {
    union { CasterTab casters; RecvTab recv; };
    int nCasters;           /* 0x104D0 */
    char pad104D4[4];
    int nRecv;              /* 0x104D8 */
    char pad104DC[0x11740 - 0x104DC];
    int nProj;              /* 0x11740 */
    float groundDist;       /* 0x11744 */
    int x11748[5];          /* 0x11748 */
    char pad1175C[0x11768 - 0x1175C];
    int cur;                /* 0x11768 */
};
extern "C" {
extern int g_DrawMode;
extern char g_LightMgr[];
void cLightMan_AquireShadowSources(void* mgr, V_003D37E0* pos);
void cShadowMan_AddReflectionSource(Shadow* s, V_003D37E0* pos, V_003D37E0* v, float dist);
void cShadowMan_ProcessCaster(Shadow* sh, int idx);
void cShadowMan_ProcessShadows(Shadow* sh);
}
static inline void PosOf(M_003D37E0* m, V_003D37E0* out) { V_003D37E0* s = &m->r[3]; V_003D37E0* p = out; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(out) : "memory"); }
static inline int HasModel(Mdl* m) { return m->x0 ? 1 : 0; }
static inline float Dot4m(void* a, void* b) { float ret = 0.0f; int rv0; __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah $0, 0x6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddaz.w ACC, vf0, vf3z; vmaddw.w vf4, vf0, vf3w; qmfc2.ni %1, vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "=f"(ret), "=&r"(rv0) : "r"(a), "r"(b) : "memory"); return ret; }
/* empty else: `asm { .set reorder }` keeps retail's branch to the join (as in cPlayerCamera_UpdateCameraTrackingPoint.c) */
static inline float PlaneZ(V_003D37E0* n, float y, const V_003D37E0& p) { float d = 0.0f; if (d != n->z) { float nz = n->z; V_003D37E0 pt(p.x, y, 0.0f, 1.0f); float t = Dot4m(n, &pt); d = -t / nz; } else asm { .set reorder } return d; }

extern "C" void cShadowMan_ProcessShadows(Shadow* sh)
{
    sh->nProj = 0;
    if (g_DrawMode & 0x60) {
        bool shadowsExist = false;
        bool reflectionsExist = false;
        int r;
        int c;
        for (r = 0; r < sh->nRecv; r++) {
            Mdl* mdl = sh->recv.e[r].obj->x68;
            if (HasModel(mdl)) {
                if (mdl->flags & 0x20) shadowsExist = true;
                if (mdl->flags & 0x40) reflectionsExist = true;
            }
        }
        for (c = 0; c < sh->nCasters; c++) {
            Act* gobj = sh->casters.e[c].actor;
            if (shadowsExist && (g_DrawMode & 0x20)) {
                Xf* x;
                V_003D37E0 cpos;
                sh->cur = c;
                x = gobj->x50;
                if (x->dirty) ((XV*)x)->Refresh();
                { M_003D37E0* m = &x->world; PosOf(m, &cpos); }
                cLightMan_AquireShadowSources(g_LightMgr, &cpos);
            }
            if (reflectionsExist && (g_DrawMode & 0x40)) {
                V_003D37E0 refPlane;
                if (gobj->GetGroundNormal(&refPlane)) {
                    Xf* x;
                    x = gobj->x50;
                    if (x->dirty) ((XV*)x)->Refresh();
                    M_003D37E0* m = &x->world;
                    V_003D37E0 gobjPos(m->r[3]);
                    float y = gobjPos.y;
                    V_003D37E0 refPos(gobjPos.x, y, PlaneZ(&refPlane, y, gobjPos), 1.0f);
                    cShadowMan_AddReflectionSource(sh, &refPos, &V_003D37E0(0.0f, 0.0f, 1.0f, 0.0f), sh->groundDist);
                }
            }
        }
        { int s; for (s = 0; s < 5; s++) sh->x11748[s] = -1; }
        { int c; for (c = 0; c < sh->nCasters; c++) cShadowMan_ProcessCaster(sh, c); }
    }
}
static inline void merge_flush_func_003D37E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D37E0 */

/* merge_units: begin func_003D3B30 */
#pragma push /* merge_units */
typedef struct { char pad[0x64]; int count; } E2Target;
typedef struct { char pad[0x1176C]; E2Target* target; int pos; int step; } E2Anim;
void cShadowMan_NextShadowBatch(E2Anim* s) {
    if (s->target) {
        s->pos += s->step;
        if (s->pos == s->target->count) {
            s->target = 0;
            s->pos = 0;
            s->step = 0;
        }
    }
}
static inline void merge_flush_func_003D3B30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D3B30 */

/* merge_units: begin func_003D3BC0 */
#pragma push /* merge_units */
typedef struct { char pad[0x64]; int count; } C5Recv;
typedef struct {
    char pad[0x104E0]; int drawn;
    char pad2[0x1176C - 0x104E4]; C5Recv* recv; int first; int n;
} C5Shadow;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern void cShadowMan_BuildShadowMap(C5Shadow* s, int i);
void cShadowMan_BeginShadowBatch(C5Shadow* s) {
    if (s->recv) {
        int n = s->recv->count - s->first;
        int i;
        int save;
        s->n = n < 4 ? n : 4;
        s->drawn = s->n;
        save = g_DrawMode;
        g_DrawMode = 5;
        D_005392D8 = D_004BC1B0;
        for (i = 0; i < s->n; i++)
            cShadowMan_BuildShadowMap(s, i);
        g_DrawMode = save;
    }
}
static inline void merge_flush_func_003D3BC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D3BC0 */

/* merge_units: begin func_003D3CC0 */
#pragma push /* merge_units */
typedef struct E3ShRec {
    int key;            /* 0x00 */
    char pad04[0x64 - 0x04];
    int valid;          /* 0x64 */
    char pad68[0x80 - 0x68];
} E3ShRec;

typedef struct E3ShMgr {
    char pad0[0x4D0];
    E3ShRec recs[512];
    char pad104D0[8];
    int count;          /* 0x104D8 */
    char pad104DC[0x1176C - 0x104DC];
    E3ShRec* sel;       /* 0x1176C */
    int unk11770;
    int unk11774;
} E3ShMgr;

/* Selects the shadow receiver record whose key matches. */
void cShadowMan_PreRenderReceiver(E3ShMgr* m, int key)
{
    int i;
    m->sel = 0;
    m->unk11774 = 0;
    m->unk11770 = 0;
    for (i = 0; i < m->count; i++) {
        if (m->recs[i].key == key) {
            if (m->recs[i].valid) {
                m->sel = &m->recs[i];
            }
            break;
        }
    }
}
static inline void merge_flush_func_003D3CC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D3CC0 */

/* merge_units: begin func_003D3D50 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* cShadowMan_AssignShadow: adds projector idx to every receiver whose model takes this projector type,
 * lies within the shadow range of c and whose (world) bounds intersect the projector frustum.
 * VU0 math and quad copies are inline asm (as in cShadowMan_AddReceiver / cShadowMan_ProcessCaster). */
struct V_003D3D50 {
    float x, y, z, w;
    V_003D3D50() {}
    /* quad copy as lq/sq (C struct copies go through FPRs); the unused xx keeps retail's dead address set-up */
    V_003D3D50(const V_003D3D50& o) { __int128 q; V_003D3D50* d = this; void* xx = this; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(d) : "memory"); }
    V_003D3D50& operator=(const V_003D3D50& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M_003D3D50 { V_003D3D50 r[4]; };
struct Box { V_003D3D50 mn; V_003D3D50 mx; };
struct Xf_003D3D50 { void* vt; char pad4[0xC]; M_003D3D50 world; unsigned char dirty; };
struct Obj_003D3D50 { char pad0[0x50]; Xf_003D3D50* x50; char pad54[0x14]; Mdl* x68; };
struct Recv_003D3D50 { Obj_003D3D50* obj; int proj[24]; int nProj; char pad68[8]; V_003D3D50 c; };
struct Proj { Obj_003D3D50* actor; float x4; float fov; short x0C; unsigned char type; char padF; M_003D3D50 view; M_003D3D50 x50; char pad90[0x20]; V_003D3D50 dir; };
struct Shadow_003D3D50 {
    char pad0[0xC];
    int range;              /* 0xC */
    char pad10[0x4D0 - 0x10];
    Recv_003D3D50 recv[0x200];       /* 0x4D0 */
    char pad104D0[8];
    int count;              /* 0x104D8 */
    char pad104DC[0x10540 - 0x104DC];
    Proj proj[24];          /* 0x10540 */
};
extern "C" {
extern char g_Video[];
int XLib_TestBBox_cMatrixR_cVectorR_cVectorR(Obj_003D3D50* o, M_003D3D50* m, const V_003D3D50* mn, const V_003D3D50* mx);
void cShadowMan_AssignShadow(Shadow_003D3D50* sh, int idx, V_003D3D50* c);
}
static inline void Sub(V_003D3D50* r, const V_003D3D50* a, const V_003D3D50* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline V_003D3D50 operator-(const V_003D3D50& a, const V_003D3D50& b) { V_003D3D50 r; Sub(&r, &a, &b); return r; }
static inline void MulM(V_003D3D50* v, M_003D3D50* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
struct V2 : V_003D3D50 { V2(const V_003D3D50& o) { void* xx = this; V_003D3D50* d = this; const V_003D3D50* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); } } __attribute__((aligned(16)));
static inline V_003D3D50 XformPt2(const V_003D3D50& v, M_003D3D50* mm) { const V_003D3D50* sv = &v; V2 p(*sv); V_003D3D50* pp = &p; MulM(pp, mm); return *pp; }
static inline V_003D3D50 XformPt(const V_003D3D50& v, M_003D3D50* m) { M_003D3D50* mm = m; return XformPt2(v, mm); }
static inline int HasModel_003D3D50(Obj_003D3D50* o) { return o->x68->x0 ? 1 : 0; }
static inline Box* BoxOf(Obj_003D3D50* o) { return (Box*)(o->x68->x4 + 0x30); }

static inline bool HasFlag(Obj_003D3D50* o, unsigned int m) { return (o->x68->flags & m) != 0; }
static inline int TakesA(Proj* p, Recv_003D3D50* rc) { unsigned char r = 0; int one = 1; if (p->type == one) { bool f = HasFlag(rc->obj, 0x20); if (f) r = one; } return r; }
static inline bool TakesB(Proj* p, Recv_003D3D50* rc) { bool r = false; if (p->type == 2) { bool f = HasFlag(rc->obj, 0x40); if (f) r = true; } return r; }
/* World matrix of a transform, refreshed first when dirty (virtual slot 22). */
static inline M_003D3D50* WorldX(Xf_003D3D50* x) { if (x->dirty) ((XV*)x)->Refresh(); return &x->world; }
static inline M_003D3D50* World(Obj_003D3D50* o) { Xf_003D3D50* x = o->x50; if (x->dirty) ((XV*)x)->Refresh(); return &x->world; }
static inline float LenR(const V_003D3D50& v) { return v.Length(); }
#pragma opt_common_subs off
extern "C" void cShadowMan_AssignShadow(Shadow_003D3D50* sh, int idx, V_003D3D50* c)
{
    V_003D3D50 mn; Proj* p; int i; V_003D3D50 mx; Recv_003D3D50* rc;
    p = &sh->proj[idx];
    for (i = 0; i < sh->count; i++) {
        rc = &sh->recv[i];
        if (HasModel_003D3D50(rc->obj)) {
            unsigned char a = TakesA(p, rc);
            unsigned char b = TakesB(p, rc);
            if (a || b) {
                V_003D3D50 d = *c - rc->c;
                if (LenR(d) < (float)sh->range) {
                    mn = BoxOf(rc->obj)->mn;
                    mx = BoxOf(rc->obj)->mx;
                    /* bring the model-space bounds into world space; the second matrix fetch re-reads the transform */
                    Xf_003D3D50* x = rc->obj->x50;
                    if (x) {
                        mn = XformPt(mn, WorldX(x));
                        mx = XformPt(mx, World(rc->obj));
                    }
                    bool hit = XLib_TestBBox_cMatrixR_cVectorR_cVectorR((Obj_003D3D50*)g_Video, &p->x50, &mn, &mx) != 0x80;
                    if (hit) {
                        int n = rc->nProj;
                        if (n < 24) {
                            rc->proj[n] = idx;
                            rc->nProj++;
                        }
                    }
                }
            }
        }
    }
}
static inline void merge_flush_func_003D3D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D3D50 */

/* merge_units: begin func_003D40D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies and VU0 math as GCC-style volatile asm; the unused xx locals keep retail's dead addius.
   V2 gives the XformPt copy its own pointer-local order (dst before src) without disturbing the other V copies. */
struct V_003D40D0 {
    float x, y, z, w;
    V_003D40D0() {}
    V_003D40D0(const V_003D40D0& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V_003D40D0& operator=(const V_003D40D0& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M_003D40D0 { V_003D40D0 r[4]; };
struct Box_003D40D0 { V_003D40D0 mn; V_003D40D0 mx; V_003D40D0 Sum() const; };
struct Mdl_003D40D0 { int x0; char* x4; };
struct Xf_003D40D0 { void* vt; char pad4[0xC]; M_003D40D0 world; unsigned char dirty; };
struct Obj_003D40D0 { char pad0[0x38]; int x38; char pad3C[0x14]; Xf_003D40D0* x50; char pad54[0x14]; Mdl_003D40D0* x68; };
struct Ent { Obj_003D40D0* obj; char pad4[0x6C]; V_003D40D0 c; };
struct Shadow_003D40D0 { char pad0[0x4D0]; Ent ent[0x200]; char pad104D0[8]; int count; };
extern "C" int g_DrawMode;
static inline void Add(V_003D40D0* r, const V_003D40D0* a, const V_003D40D0* b);
static inline void Add(V_003D40D0* r, const V_003D40D0* a, const V_003D40D0* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
inline V_003D40D0 Box_003D40D0::Sum() const { V_003D40D0 c; Add(&c, &mn, &mx); return c; }
static inline V_003D40D0 Scale(V_003D40D0 v, float k) { __int128 z = 0; /* dead paddub */ V_003D40D0 r; int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(&v), "r"(&r), "f"(k) : "memory"); return r; }
static inline void MulM_003D40D0(V_003D40D0* v, M_003D40D0* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
struct V2_003D40D0 : V_003D40D0 { V2_003D40D0(const V_003D40D0& o) { void* xx = this; V_003D40D0* d = this; const V_003D40D0* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); } } __attribute__((aligned(16)));
static inline V_003D40D0 XformPt2_003D40D0(const V_003D40D0& v, M_003D40D0* mm) { const V_003D40D0* sv = &v; V2_003D40D0 p(*sv); V_003D40D0* pp = &p; MulM_003D40D0(pp, mm); return *pp; }
static inline V_003D40D0 XformPt_003D40D0(const V_003D40D0& v, M_003D40D0* m) { M_003D40D0* mm = m; return XformPt2_003D40D0(v, mm); }
static inline int HasModel_003D40D0(Obj_003D40D0* o) { return o->x68->x0 ? 1 : 0; }
extern "C" int cShadowMan_AddReceiver(Shadow_003D40D0* sh, Obj_003D40D0* o, int force)
{
    int idx = -1;
    if ((g_DrawMode & 0x60) || force) {
        if (sh->count < 0x200 && o->x38 != 0x80 && HasModel_003D40D0(o)) {
            if (force) {
                int i;
                for (i = 0; i < sh->count; i++) {
                    if (sh->ent[i].obj == o) return i;
                }
            }
            {
                Ent* e;
                Xf_003D40D0* x;
                idx = sh->count;
                sh->count = idx + 1;
                e = &sh->ent[idx];
                e->obj = o;
                Box_003D40D0* b = (Box_003D40D0*)(o->x68->x4 + 0x30);
                e->c = Scale(b->Sum(), 0.5f);
                x = o->x50;
                if (x) {
                    if (x->dirty) ((XV*)x)->Refresh();
                    e->c = XformPt_003D40D0(e->c, &x->world);
                }
            }
        }
    }
    return idx;
}
static inline void merge_flush_func_003D40D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D40D0 */

/* merge_units: begin func_003D4300 */
#pragma push /* merge_units */
typedef struct { int f; char p[0x7C]; } C1E_3D43;
typedef struct { char pad[0x534]; C1E_3D43 e[511]; char pad2[0x24]; int count; } C1S_3D43;
void cShadowMan_ClearReceivers(C1S_3D43* s)
{
    int i;
    for (i = 0; i < s->count; i++)
        s->e[i].f = 0;
    s->count = 0;
}
static inline void merge_flush_func_003D4300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D4300 */
