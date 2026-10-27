#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* cShadowMan_ProcessShadows: resets the projector list, finds whether any receiver takes light (0x20) or
 * ground (0x40) shadows, collects the lights near each caster and adds its ground-plane entry, then
 * builds every caster's projections. */
/* Quadword copies (lq/sq) and the VU0 dot product have no C spelling, so they are GCC-style asm.
 * The dead `xx`/`p` copies are deliberate: retail keeps those extra address computations. */
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V(const V& o) { const V* s = &o; void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct Mdl { int x0; char* x4; char pad8[0x1C]; unsigned int flags; };
class XV {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
};
struct Xf { void* vt; char pad4[0xC]; M world; unsigned char dirty; };
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
    virtual bool GetGroundNormal(V* n);
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
void cLightMan_AquireShadowSources(void* mgr, V* pos);
void cShadowMan_AddReflectionSource(Shadow* s, V* pos, V* v, float dist);
void cShadowMan_ProcessCaster(Shadow* sh, int idx);
void cShadowMan_ProcessShadows(Shadow* sh);
}
static inline void PosOf(M* m, V* out) { V* s = &m->r[3]; V* p = out; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(out) : "memory"); }
static inline int HasModel(Mdl* m) { return m->x0 ? 1 : 0; }
static inline float Dot4m(void* a, void* b) { float ret = 0.0f; int rv0; __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah $0, 0x6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddaz.w ACC, vf0, vf3z; vmaddw.w vf4, vf0, vf3w; qmfc2.ni %1, vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "=f"(ret), "=&r"(rv0) : "r"(a), "r"(b) : "memory"); return ret; }
/* empty else: `asm { .set reorder }` keeps retail's branch to the join (as in cPlayerCamera_UpdateCameraTrackingPoint.c) */
static inline float PlaneZ(V* n, float y, const V& p) { float d = 0.0f; if (d != n->z) { float nz = n->z; V pt(p.x, y, 0.0f, 1.0f); float t = Dot4m(n, &pt); d = -t / nz; } else asm { .set reorder } return d; }

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
                V cpos;
                sh->cur = c;
                x = gobj->x50;
                if (x->dirty) ((XV*)x)->Refresh();
                { M* m = &x->world; PosOf(m, &cpos); }
                cLightMan_AquireShadowSources(g_LightMgr, &cpos);
            }
            if (reflectionsExist && (g_DrawMode & 0x40)) {
                V refPlane;
                if (gobj->GetGroundNormal(&refPlane)) {
                    Xf* x;
                    x = gobj->x50;
                    if (x->dirty) ((XV*)x)->Refresh();
                    M* m = &x->world;
                    V gobjPos(m->r[3]);
                    float y = gobjPos.y;
                    V refPos(gobjPos.x, y, PlaneZ(&refPlane, y, gobjPos), 1.0f);
                    cShadowMan_AddReflectionSource(sh, &refPos, &V(0.0f, 0.0f, 1.0f, 0.0f), sh->groundDist);
                }
            }
        }
        { int s; for (s = 0; s < 5; s++) sh->x11748[s] = -1; }
        { int c; for (c = 0; c < sh->nCasters; c++) cShadowMan_ProcessCaster(sh, c); }
    }
}
