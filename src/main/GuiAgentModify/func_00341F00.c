#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"

struct M;
extern "C" void Mtx44_SetRotation(M* m, float, float, float, float, float, float, float, float, float);
extern "C" M* Mtx_Copy(M* d, const M* s);
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M* p) { Mtx_Copy(this, p); void* xx = this; }
    M(float a, float b, float c, float d, float e, float f, float g, float h, float i) { Mtx44_SetRotation(this, a, b, c, d, e, f, g, h, i); }
    V& r(int i) { return *(V*)m[i]; }
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& operator=(const M& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct TM { M m; };
struct VA : V { VA(float ax, float ay, float az, float aw) { void* xx = this; x = ax; y = ay; z = az; w = aw; } };
struct Place { V q; V p; Place(M& m); };

struct Cam {
    float col[4]; char pad10[0xF0 - 0x10];
    float f2E0, f2E4, f2E8, f2EC, fov;
    unsigned char b2F4, b2F5, b2F6;
};
struct Slot { char pad[0x1F0]; Cam cam; };

class Xf {
public:
    VPAD2(a) virtual void v2(); virtual void SetPos(V* p);
};
struct Obj { char pad[0x50]; Xf* xf; };
struct Coll { char pad[1]; };
struct Root { char pad[0x160]; int x160; };
struct Root2 { char pad[0xB0]; char coll[4]; };
class Mdl {
public:
    VPAD16(a) virtual void Tick(float t); VPAD2(b) virtual void v19(); virtual void Draw();
    char pad4[0x34]; float x38; char pad3c[0x2EC0-0x3C]; Root2 r2EC0;
};
struct Scr { char pad[0x64]; float t; };

struct Self {
    char pad0[0x8C];
    Mdl* mdl;
    Obj* obj;
    char pad94[0xB4 - 0x94];
    float fov;
    float ex, ey, ez;
    float rx, ry, rz;
    float f70, f74, f78;
};
struct Fog { char pad[0x150]; float fogNear, fogFar, zNear, zFar; int ci[4]; float cf[4]; };

extern "C" {
extern char D_005381F0[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int D_005392D0;
extern long long D_005392D8;
extern long long D_004BC1B0;
extern float D_00539170[4];
extern char D_004B9F20[];
void func_0037A1E0(char* p);
void func_0037E310(char* p);
float Math_CosThunk(float);
float Math_SinThunk(float);
void Mtx44_SetRotation(M* m, float, float, float, float, float, float, float, float, float);
M* Mtx_Copy(M* d, const M* s);
M* Mtx_InvertRigid(M* m);
void func_001D3E20(TM* m);
void Mtx_MakeAxisRotation(TM* m, float x, float y, float z, float a);
void Mtx_Multiply(M* a, TM* b);
Root* RootCollection_FindByKey(void* c, char* key);
void Root_SetWorldPlacement(Root* r, Place* p);
Scr* Gui_GetScreenStack(void);
void ActorRender_Update(void* p, float t);
void World_PhysicsTraversal(float t);
void GuiAgentModify_DrawModelCallback(Self* self); void GuiAgentModify_CameraApproach(Self* self); void Fog_ComputeTerms(char* r);
}

#define SLOT(i) ((Slot*)(D_005381F0 + (i) * 0x110))
#define STK(i) ((M*)(D_005381F0 + 0xA80 + (i) * 0x40))

static inline void UnitM(M* m) { M* p = m; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void Apply33(V* out, const V* v, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(out), "r"(m), "r"(v) : "memory"); }
static inline void Mul33(M* out, const M* a, const M* b) { __asm__ volatile("lqc2 vf4, 0x0(%2); lqc2 vf5, 0x10(%2); lqc2 vf6, 0x20(%2); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; vmulax.xyz ACC, vf4, vf9x; vmadday.xyz ACC, vf5, vf9y; vmaddz.xyz vf9, vf6, vf9z; vmulax.xyz ACC, vf4, vf10x; vmadday.xyz ACC, vf5, vf10y; vmaddz.xyz vf10, vf6, vf10z; vmulax.xyz ACC, vf4, vf11x; vmadday.xyz ACC, vf5, vf11y; vmaddz.xyz vf11, vf6, vf11z; sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0); sqc2 vf11, 0x30(%0)" : : "r"(out), "r"(b), "r"(a) : "memory"); }

static inline void MtxToQuat(void* m, void* out) {
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(out)
        .set reorder
    }
}

static inline M Euler(float ey, float ex, float ez)
{
    float cy = Math_CosThunk(ey);
    float sy = Math_SinThunk(ey);
    float cx = Math_CosThunk(ex);
    float sx = Math_SinThunk(ex);
    float cz = Math_CosThunk(ez);
    float sz = Math_SinThunk(ez);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    float a1 = czcy - szsy * sx;
    float a2 = -sz * cx;
    float a3 = czsy + szcy * sx;
    float a4 = szcy + czsy * sx;
    float a5 = cz * cx;
    float a6 = szsy - czcy * sx;
    float a7 = -cx * sy;
    float a8 = sx;
    float a9 = cx * cy;
    return M(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

static inline M Inverse(const M& m) { M t; return M(Mtx_InvertRigid(Mtx_Copy(&t, &m))); }

static inline void Rot2(M* m, const V& ax, float a)
{
    TM t;
    func_001D3E20(&t);
    Mtx_MakeAxisRotation(&t, ax.x, ax.y, ax.z, a);
    Mtx_Multiply(m, &t);
}

inline Place::Place(M& m) { MtxToQuat(&m, &q); p = m.r(3); }
static inline void Rot(M* m, const V& ax, float a) { Rot2(m, ax, a); }
static inline void SetPl(Root* r, const Place& pl) { Root_SetWorldPlacement(r, (Place*)&pl); }


/* cvt.w.s+mfc1 asm: a C (int) cast compiles to a different sequence; the dead r=0 matches retail's daddu */
static inline int F2I(float f) { int r = 0; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }
static inline float FMul(float a, float b) { return a * b; }
static inline void SetCol(Fog* g, float r, float gg, float b)
{
    r = FMul(r, 256.0f); gg = FMul(gg, 256.0f); b = FMul(b, 256.0f); float a = r, c = gg, d = b;
    g->cf[0] = a;
    g->cf[1] = c;
    g->cf[2] = d;
    g->cf[3] = 256.0f;
    g->ci[0] = F2I(a);
    g->ci[1] = F2I(c);
    g->ci[2] = F2I(d);
    g->ci[3] = 0x80;
}

extern "C" void GuiAgentModify_DrawModelCallback(Self* self)
{
    M view;
    M r2;
    V p;
    M cm;
    M mm;
    int saved;
    func_0037A1E0(D_005381F0);
    GuiAgentModify_CameraApproach(self);
    saved = D_005392D0;
    D_005392D0 = 0x95;
    { long long t = D_004BC1B0;
    D_005392D8 = t; }
    *STK(D_00538C64 + 1) = *STK(D_00538C64);
    ((Fog*)D_005381F0)->fogNear = 0.0f;
    ((Fog*)D_005381F0)->fogFar = 1.0f;
    D_00538C64++;
    Fog_ComputeTerms(D_005381F0);
    ((Fog*)D_005381F0)->zNear = 50.0f;
    ((Fog*)D_005381F0)->zFar = 80.0f;
    Fog_ComputeTerms(D_005381F0);
    SetCol((Fog*)D_005381F0, 0.25f, 0.25f, 0.25f);
    {
        Cam* c = &SLOT(D_00538C60)->cam;
        c->fov = self->fov;
        c->f2E4 = 2.0f;
        c->f2EC = 15000.0f;
        c->b2F6 = 1;
        c->b2F4 = 0;
    }
    { float ey = self->f74; float ex = self->f70; float ez = self->f78; r2 = Euler(ey, ex, ez); }
    p = V(self->ex, -self->ey, self->ez, 1.0f);
    Apply33(&p, &p, &r2);
    cm.m[0][0] = r2.m[0][0]; cm.m[0][1] = r2.m[0][1]; cm.m[0][2] = r2.m[0][2];
    cm.m[1][0] = r2.m[1][0]; cm.m[1][1] = r2.m[1][1]; cm.m[1][2] = r2.m[1][2];
    cm.m[2][0] = r2.m[2][0]; cm.m[2][1] = r2.m[2][1]; cm.m[2][2] = r2.m[2][2];
    cm.m[0][3] = r2.m[0][3]; cm.m[1][3] = r2.m[1][3]; cm.m[2][3] = r2.m[2][3];
    cm.r(3) = p;
    view = Inverse(cm);
    *STK(D_00538C64) = view;
    D_00538C68 = 1;
    self->obj->xf->SetPos(&cm.r(3));
    V pp(0.0f, 0.0f, -3.0f, 1.0f);
    UnitM(&mm);
    Rot(&mm, VA(1.0f, 0.0f, 0.0f, 0.0f), self->rx);
    Rot(&mm, V(0.0f, 1.0f, 0.0f, 0.0f), self->ry);
    Rot(&mm, V(0.0f, 0.0f, 1.0f, 0.0f), self->rz);
    mm.r(3) = pp;
    Mul33(&mm, &cm, &mm);
    {
        char key[4];
        bool done = false;
        unsigned int k;
        for (k = 0; k < 4u; k++) {
            char c;
            if (!D_004B9F20[k]) done = true;
            if (done) c = 0; else c = D_004B9F20[k];
            key[k] = c;
        }
        Root2* rr = &self->mdl->r2EC0; Root* r = RootCollection_FindByKey(rr->coll, key);
        SetPl(r, Place(mm));
        r->x160 = 0;
    }    {
        float t = Gui_GetScreenStack()->t;
        self->mdl->Tick(t);
        ActorRender_Update((char*)self->mdl + 0x60, t);
        World_PhysicsTraversal(t);
        { Mdl* m = self->mdl; m->x38 = 2.0f; }
        self->mdl->Draw();
    }
    func_0037E310(D_005381F0);
    {
        Slot* s = SLOT(D_00538C60);
        s->cam.f2E0 = 0;
        s->cam.f2E8 = 1000.0f;
        s->cam.b2F6 = 1;
        s->cam.b2F4 = 1;
        {
            float* v = D_00539170;
            s->cam.col[0] = v[0];
            s->cam.col[1] = v[1];
            s->cam.col[2] = v[2];
            s->cam.col[3] = v[3];
        }
        s->cam.b2F5 = 1;
        s->cam.b2F6 = 1;
    }
    D_00538C68 = 1;
    D_005392D0 = saved;
    D_00538C64--;
}