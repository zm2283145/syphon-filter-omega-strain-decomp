/*
 * SFOGame/Source/playerControls: 11 files, 00249460-002497C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00249460 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { unsigned char b0; char pad[3]; int f4; int f8; char fC; } Slot49;
typedef struct { char pad[0x13C]; void* p13C; Slot49* p140; } Owner49;
typedef struct { char pad[0x3584]; Slot49* p3584; } Ctx49;
void cPlayerControls_NetDisableManualAim(Owner49* self, Ctx49* ctx) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) self->p140->b0 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249460 */

/* merge_units: begin func_00249490 */
#pragma push /* merge_units */
typedef struct { float x, y, z; } Vec49;
typedef struct { unsigned char b0; char pad[15]; Vec49 v; } Slot49c;
typedef struct { char pad[0x140]; Slot49c* p140; } Owner49c;
typedef struct { char pad[0x3584]; Slot49c* p3584; } Ctx49c;
void cPlayerControls_NetSetManualTarget(Owner49c* self, Ctx49c* ctx, Vec49* v) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) {
        Slot49c* s = self->p140;
        s->b0 = 1;
        s->v.x = v->x;
        s->v.y = v->y;
        s->v.z = v->z;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249490(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249490 */

/* merge_units: begin func_002494E0 */
#pragma push /* merge_units */
void cPlayerControls_NetSetTarget(Owner49* self, Ctx49* ctx, int a2, int* a3, char t0) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) {
        self->p140->f4 = a2;
        self->p140->f8 = *a3;
        self->p140->fC = t0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002494E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002494E0 */

/* merge_units: begin func_00249530 */
#pragma push /* merge_units */
typedef struct { unsigned short count; } Sub49b;
typedef struct { char pad[0x13C]; Sub49b* p13C; void* p140; } Owner49b;
typedef struct { char pad[0x3584]; char* p3584; } Ctx49b;
void cPlayerControls_NetShootWeapon(Owner49b* self, Ctx49b* ctx) {
    if (!self->p13C) {
        char* q = ctx->p3584;
        if (q) q += 0x1C;
        self->p13C = (Sub49b*)q;
    }
    if (self->p13C) self->p13C->count++;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249530 */

/* merge_units: begin func_00249580 */
#pragma push /* merge_units */
typedef struct { char p[0xC]; int id; } Obj249580;
typedef struct { void* vtable; char base[0x1C]; unsigned char b20; char p21[3]; int f24; unsigned char b28; char p29[3]; int f2C; } Msg249580;
extern char g_ActorActionMsgClass[];
extern char D_004E01A0[];
extern char D_004E0840[];
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void cPlayerControls_SetManualAimEyesTargetInHuman(void* self, Obj249580* o, void* target) {
    if (o) {
        Msg249580 m;
        int id = o->id;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.f24 = 0x3E;
m.b28 = 5;
m.vtable = D_004E01A0;
m.b20 = 1;
m.f2C = id;
        QueueMessage_cMessageR_cSystemP_int(&m, target, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    } else {
        Msg249580 m;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.vtable = D_004E0840;
        m.f24 = 0x3F;
        m.b20 = 1;
        m.b28 = 0;
        QueueMessage_cMessageR_cSystemP_int(&m, target, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249580 */

/* merge_units: begin func_00249670 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator*(float k) const { V r; V* rp = &r; const V* tp = this; __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(tp), "r"(rp), "f"(k) : "memory"); return r; }
    V operator+(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
} __attribute__((aligned(16)));

struct CamView { char pad[0x10]; V dir; char pad20[0x10]; V pos; };
struct Cam { char pad[0xDA0]; CamView view; };

extern "C" {
extern unsigned char g_IsMultiplayer;
extern char D_004E0140[];
#if 0 /* merge_units */
void cPlayerControls_NetSetManualTarget(void* s, void* actor, V* v);
#endif /* merge_units */
#define cPlayerControls_NetSetManualTarget(a0, a1, a2) (cPlayerControls_NetSetManualTarget((Owner49c *)(a0), (Ctx49c *)(a1), (Vec49 *)(a2))) /* merge_units */


}

struct MsgB {
    void* vt; char base[0x1C]; unsigned char b20; char p21[3]; int type; unsigned char kind; char p29[3];
    MsgB() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgB() { vt = D_004E0840; cMessage_dtor(this, 0); }
    void Send(void* to) { b20 = 1; QueueMessage_cMessageR_cSystemP_int(this, to, 1); }
    void Init(int t, unsigned char k) { cMessage_ctor_cMessageNameR(this, g_ActorActionMsgClass); vt = D_004E0840; type = t; kind = k; }
};
struct MsgPt : MsgB { char p2C[4]; V pt; MsgPt(const V& v) { MsgPt* p = this; p->Init(0x39, 4); p->vt = D_004E0140; p->pt = v; } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgPt() {} };

extern "C" void cPlayerControls_SetManualAimWeaponTargetInHuman(void* s, Cam* cam, void* actor)
{
    CamView* cv = &cam->view;
    V pos = cv->pos;
    V dir = cv->dir;
    float k = 100.0f;
    V pt = pos + dir * k;
    MsgPt(pt).Send(actor);
    if (g_IsMultiplayer) cPlayerControls_NetSetManualTarget(s, actor, &pt);
}
#undef cPlayerControls_NetSetManualTarget /* merge_units */
static inline void merge_flush_func_00249670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00249670 */

/* merge_units: begin func_002497C0 */
#pragma push /* merge_units */
#include "vslot_pad.h"
#include "vu0_ops.h"

#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V_002497C0 {
    float x, y, z, w;
    V_002497C0() {}
    V_002497C0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_002497C0(const V_002497C0& o) { V_002497C0* d = this; const V_002497C0* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V_002497C0& operator=(const V_002497C0& o) { V_002497C0* d = this; const V_002497C0* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V_002497C0 operator-() const { V_002497C0 t; const V_002497C0* sp = this; V_002497C0* tp = &t; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(tp), "r"(sp) : "memory"); return t; }
    V_002497C0 operator*(float s) const { V_002497C0 r; int t; const V_002497C0* tp = this; V_002497C0* rp = &r; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(rp), "r"(tp), "f"(s) : "memory"); return r; }
} __attribute__((aligned(16)));
struct M {
    V_002497C0 r0, r1, r2, t;
    M() {}
    M(const M& o) { const M* s = &o; M* d = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MulV(V_002497C0* v, M* m) { V_002497C0* o = v; __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
struct Sub {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0xC];
    M m;
    unsigned char f50;
};
static inline const M& SubMtx(Sub* o) { if (o->f50) o->Sync(); return o->m; }
struct Obj { char pad[0x50]; Sub* sub; };
struct Svc { virtual void v0(); virtual void Send(void* m); };
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct HitSub { VP v[3]; V_002497C0 n; unsigned char b40; char b41; unsigned char b42; char pad43[0x1D]; int f60; int f64; void Init() { HitSub* q = this; VP* i = q->v; VP* e = q->v + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->f60 = 0; q->f64 = 0; } };
struct HitRes { unsigned char hit; char pad1[0xF]; V_002497C0 pos; HitSub s; char pad88[0x10]; HitRes() { HitRes* p = this; p->s.Init(); } V_002497C0 Normal() const { const V_002497C0* q = &s.n; return *q; } };
struct Item { char pad[0x3C]; int range; };
struct Plr { char pad[0x3524]; int inv; };
struct RayMsg { void* vt; char base[0x20]; int f24; int f28; HitRes* res; V_002497C0 start; V_002497C0 end; Plr* pl; void* cl; int f58; unsigned char b5C; };
extern "C" {
extern char* g_Hud;
extern char g_Game[];
extern char g_LosCheckService[];
extern char g_LosRequestMsgClass[];
extern char D_004D9180[];
Svc* cSystemContainer_GetSystem(void* a, void* b);
void cHud_SetAimCursorColor(char* h, float f);
void cHud_SetAimCursorPosition(char* h, V_002497C0* a, V_002497C0* b);
Item* cWeapon_GetWeaponEntry(int inv);
}
extern "C" unsigned char GetGrenadeManualAimTarget(V_002497C0* out, Obj* obj, Plr* p)
{
    M m = SubMtx(obj->sub);
    char* hud = g_Hud;
    cHud_SetAimCursorColor(hud, 0.0f);
    V_002497C0 a;
    unsigned char r = 0;
    a.y = 1.5f; a.w = 1.0f; a.x = 0.0f; a.z = 0.0f;
    MulV(&a, &m);
    m.t = a;
    float range = (float)cWeapon_GetWeaponEntry(p->inv)->range;
    HitRes res;
    RayMsg msg;
    V_002497C0 b;
    V_002497C0 d;
    V_002497C0 dir = m.r1 * range;
    RayMsg* mp = &msg;
    V_002497C0* st = &m.t;
    cMessage_ctor_cMessageNameR(mp, g_LosRequestMsgClass);
    mp->vt = D_004D9180;
    mp->f24 = 0;
    mp->f28 = 0;
    mp->res = &res;
    mp->start = *st;
    mp->end = dir;
    mp->pl = p;
    mp->cl = 0;
    mp->f58 = 0x10;
    mp->b5C = 0;
    mp->start.w = 1.0f;
    mp->end.w = 0.0f;
    cSystemContainer_GetSystem(g_Game, g_LosCheckService)->Send(&msg);
    b.x = 0.0f; b.y = range; b.z = 0.0f; b.w = 1.0f;
    MulV(&b, &m);
    if (res.hit) {
        *out = res.pos;
        d = res.Normal();
        r = 1;
    } else {
        *out = b;
        d = -m.r1;
    }
    cHud_SetAimCursorPosition(hud, out, &d);
    msg.vt = D_004D9180;
    cMessage_dtor(&msg, 0);
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002497C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002497C0 */

/* merge_units: begin func_00249B10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Cam_249B10 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void GetMatrix(void* m, int a, int b); };
struct Hit_249B10 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual unsigned char Kind(); };
typedef struct {
    int a0; void* mat; int a8; unsigned char ac; int b0; float range; int b8; int bc; unsigned char c0;
    int c4; float c8; unsigned char cc; unsigned char cd; int kind; int d4; Hit_249B10* hit; char padDC[0x14];
} Probe_249B10;
typedef struct { float m[16]; } Mat_249B10;
typedef struct { char pad[0xF4]; float beam; } Wpn_249B10;
typedef struct { char pad[0x58]; Cam_249B10* cam; char pad5C[0x3524 - 0x5C]; Wpn_249B10* wpn; } Pl_249B10;
typedef struct { char pad[0xC]; int id; } HitData_249B10;
extern "C" {
extern char D_004A75B8[];
float cWeapon_GetMaxRange(Wpn_249B10* w);
float GetCollisionDist(Pl_249B10* p, Probe_249B10* pr, int n);
int cGOBJ_Enemy(Pl_249B10* p, Hit_249B10* h);
void cHud_ActivateNoFireIcon(char* h);
void cHud_DeactivateNoFireIcon(char* h);
int nGlobalization_GetString_charP(char* key);
void cHud_SetCallout(char* a0, int* a1, float f0, float f1, int text, int a3, signed char c0, signed char c1);
}
static inline bool IsKind23(Hit_249B10* h) { unsigned char k = h->Kind(); return k == 2 || k == 3; }
extern "C" Hit_249B10* cPlayerControls_GetManualAimTarget(int a0, int a1, Pl_249B10* p)
{
    Probe_249B10 pr;
    Mat_249B10 m;
    float r;
    bool show;
    char* h;
    pr.c0 = 0;
    pr.bc = 0;
    pr.ac = 0;
    pr.b0 = -1;
    pr.cc = 1;
    pr.a8 = 0;
    pr.c4 = 0;
    pr.cd = 1;
    p->cam->GetMatrix(&m, 0, 1);
    pr.mat = &m;
    pr.c8 = 0.2f;
    pr.range = cWeapon_GetMaxRange(p->wpn);
    r = GetCollisionDist(p, &pr, 0x10);
    if (pr.hit && !cGOBJ_Enemy(p, pr.hit)) {
        pr.kind = 0;
        cHud_ActivateNoFireIcon(g_Hud);
    } else {
        cHud_DeactivateNoFireIcon(g_Hud);
    }
    show = pr.kind == 2 && !IsKind23(pr.hit);
    h = g_Hud;
    if (pr.kind == 0)
        cHud_SetAimCursorColor(h, 1.0f);
    else
        cHud_SetAimCursorColor(h, 0.0f);
    if (show) {
        int* idp = &((HitData_249B10*)pr.hit)->id;
        cHud_SetCallout(h, idp, 0.1f, 1.0f, nGlobalization_GetString_charP(D_004A75B8), 0, 0, 0);
    }
    p->wpn->beam = r;
    return pr.hit;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249B10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249B10 */

/* merge_units: begin func_00249D00 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* vtable; char pad[0x20]; int kind; unsigned char b; char pad2[3]; } QtMsg;
typedef struct { char pad[0x38]; int state; char pad3C[0x24]; float v60[4]; char pad70[0xA4]; float t; unsigned char flag; } QtState;
typedef struct { float x; float y; } QtIn;
typedef struct { char pad[0xDC]; unsigned char busy; } QtSub;
typedef struct { char pad[0x320C]; int mode; char pad3210[0x100]; QtSub* sub; } QtPl;
extern float D_004A7580;
#if 0 /* merge_units */
extern "C" void cMessage_ctor_cMessageNameR(QtMsg* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern "C" void QueueMessage_cMessageR_cSystemP_int(QtMsg* m, void* target, int immediate);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern "C" void cMessage_dtor(QtMsg* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


extern "C" void cSplinedMotion_cQuaternion_RestartTransition(void* c, float f);
extern "C" void cSplinedMotion_cVector_RestartTransition(void* c, float f);
static inline bool QtBusy(QtPl* pl) {
    bool b = 0;
    if (pl->sub && pl->sub->busy) b = 1;
    return b;
}
extern "C" void cPlayerControls_DetectForAndHandle180Turn(QtState* q, QtIn* in, float dt, QtPl* pl, char* c)
{
    if ((q->state == 0 || q->state == 4) && !QtBusy(pl)) {
        if (in->y < 0.0f) {
            if (!(q->t <= 0.0f) || VU0_IsZero4(q->v60)) {
                q->t += dt;
                if (in->y < -0.75f)
                    q->flag = 1;
            } else {
                q->t = 0.0f;
                q->flag = 0;
            }
        } else if (!(in->y < 0.0f) && in->y < 0.5f) {
            if (!(q->t <= 0.0f) && q->t <= D_004A7580 && q->flag && pl->mode != 3) {
                QtMsg msg;
                cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
                msg.vtable = D_004E0840;
                msg.kind = 0xE;
                msg.b = 0;
                QueueMessage_cMessageR_cSystemP_int(&msg, pl, 0);
                msg.vtable = D_004E0840;
                cMessage_dtor(&msg, 0);
                cSplinedMotion_cQuaternion_RestartTransition(c + 0x210, 1.0f);
                cSplinedMotion_cVector_RestartTransition(c + 0x2E0, -1.0f);
                cSplinedMotion_cVector_RestartTransition(c + 0x3A0, -1.0f);
                cSplinedMotion_cQuaternion_RestartTransition(c + 0x780, -1.0f);
                cSplinedMotion_cVector_RestartTransition(c + 0x910, -1.0f);
            }
            q->t = 0.0f;
            q->flag = 0;
        } else {
            q->t = 0.0f;
            q->flag = 0;
        }
    } else {
        q->t = 0.0f;
        q->flag = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249D00(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00249D00 */

/* merge_units: begin func_00249F40 */
#pragma push /* merge_units */
typedef struct Msg_00249F40 {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
    char pad29[7];
} Msg_00249F40;
typedef struct Pl_00249F40 { char pad[0x320C]; int state; } Pl_00249F40;
typedef struct In_00249F40 { char pad[0x24]; unsigned char b24; char pad25[0xAC - 0x25]; unsigned char held; } In_00249F40;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_00249F40* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(Msg_00249F40* msg, void* target, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Msg_00249F40* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern int cPlayerControls_HasEnteredCrawlHotbox(In_00249F40* in);
#endif /* merge_units */
int cPlayerControls_HasEnteredCrawlHotbox(void*); /* merge_units */
#define cPlayerControls_HasEnteredCrawlHotbox(a0) (cPlayerControls_HasEnteredCrawlHotbox((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cPlayerControls_ToggleCrawl(In_00249F40* in, Pl_00249F40* p);
#endif /* merge_units */
int cPlayerControls_ToggleCrawl(void*, void*); /* merge_units */
#define cPlayerControls_ToggleCrawl(a0, a1) (cPlayerControls_ToggleCrawl((void *)(a0), (void *)(a1))) /* merge_units */

#define SENDB(V) { Msg_00249F40 msg; cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass); msg.vtable = D_004E0840; msg.value = V; msg.b20 = 1; msg.b28 = 0; QueueMessage_cMessageR_cSystemP_int(&msg, p, 1); msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
#define SEND(V) { Msg_00249F40 msg; cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass); msg.vtable = D_004E0840; msg.b20 = 1; msg.value = V; msg.b28 = 0; QueueMessage_cMessageR_cSystemP_int(&msg, p, 1); msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
void cPlayerControls_HandleCrouchButtonPress(In_00249F40* in, Pl_00249F40* p, float v)
{
    int t = 1;
    unsigned char pressed;
    unsigned char edge;
    if (v <= 0.0f)
        t = 0;
    pressed = t;
    edge = !in->held && pressed;
    in->held = pressed;
    if (edge || (cPlayerControls_HasEnteredCrawlHotbox(in) && pressed)) {
        if (cPlayerControls_ToggleCrawl(in, p))
            pressed = 0;
    }
    if (p->state == 0x10) {
        if (pressed)
            SEND(0x1C)
        else
            SEND(0x1D)
    }
    if (pressed)
        SEND(0x10)
    if (pressed && !in->b24)
        SENDB(1)
    else
        SENDB(2)
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249F40(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cPlayerControls_HasEnteredCrawlHotbox /* merge_units */
#undef cPlayerControls_ToggleCrawl /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00249F40 */

/* merge_units: begin func_0024A1C0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* vtable; char pad4[0x1C]; unsigned char x20; char pad21[3]; int kind; unsigned char b; char pad29[3]; } Msg_24A1C0;
typedef struct { Msg_24A1C0 base; unsigned char x2C; char pad2D[3]; } Msg2_24A1C0;
struct Sub_24A1C0 { char pad[0xDC]; unsigned char busy; };
class Pl_24A1C0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual unsigned char Kind();
    char pad4[0x3208];
    int mode;
    char pad3210[0x100];
    Sub_24A1C0* sub;
};
struct H_24A1C0 { int v; H_24A1C0() : v(-1) {} };
struct St_24A1C0 {
    char pad0[0x40];
    int x40;
    int bits[1];
    char pad48[0x65];
    unsigned char xAD; char padAE[0xE]; unsigned char xBC; unsigned char xBD; char padBE[0xA];
    int xC8; H_24A1C0 xCC; char padD0[0x5C]; unsigned char x12C; char pad12D[0xB]; unsigned char x138;
    bool Test(int i) { return (bits[i / 32] >> (i & 31)) & 1 ? true : false; }
};
extern "C" {
extern char D_004D9320[];
extern unsigned char D_0048AEC8;
extern int g_HotboxTracker;
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(Msg_24A1C0* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(Msg_24A1C0* m, void* target, int immediate);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
void cMessage_dtor(Msg_24A1C0* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


int cHotboxMan_Interact(int a, Pl_24A1C0* p, int b, int c);
#if 0 /* merge_units */
int cPlayerControls_HasEnteredCrawlHotbox(St_24A1C0* s);
#endif /* merge_units */
#define cPlayerControls_HasEnteredCrawlHotbox(a0) (cPlayerControls_HasEnteredCrawlHotbox((void *)(a0))) /* merge_units */


#if 0 /* merge_units */
int cPlayerControls_ToggleCrawl(St_24A1C0* s, Pl_24A1C0* p);
#endif /* merge_units */
#define cPlayerControls_ToggleCrawl(a0, a1) (cPlayerControls_ToggleCrawl((void *)(a0), (void *)(a1))) /* merge_units */


}
static inline bool Busy_(Pl_24A1C0* pl) {
    bool b = 0;
    if (pl->sub && pl->sub->busy) b = 1;
    return b;
}
static inline bool IsKind23_0024A1C0(Pl_24A1C0* h) { unsigned char k = h->Kind(); return k == 2 || k == 3; }
#pragma push
#pragma opt_propagation off
extern "C" void cPlayerControls_HandleInteractButtonPress(St_24A1C0* s, Pl_24A1C0* p, float v)
{
    bool pressed = v > 0.0f;
    bool edge = !s->xAD && pressed;
    s->xAD = pressed;
    if (!pressed) {
        s->xBD = 0;
    } else if (s->xBD) {
        pressed = 0;
        edge = 0;
    }
    if (edge) {
        int k = s->x138 ? 0x2D : 0x2C;
        Msg_24A1C0 m;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.x20 = 1;
        m.kind = (signed char)k;
        m.b = 0;
        m.vtable = D_004E0840;
        QueueMessage_cMessageR_cSystemP_int(&m, p, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
        if (p->mode == 0x14) {
            Msg2_24A1C0 m2x;
            cMessage_ctor_cMessageNameR(&m2x.base, g_ActorActionMsgClass);
            m2x.base.kind = 0x28;
            m2x.base.b = 1;
            m2x.base.vtable = D_004D9320;
            m2x.base.x20 = 1;
            m2x.x2C = D_0048AEC8;
            QueueMessage_cMessageR_cSystemP_int(&m2x.base, p, 1);
            m2x.base.vtable = D_004E0840;
            pressed = 0;
            edge = 0;
            cMessage_dtor(&m2x.base, 0);
        }
    }
    if (edge && !Busy_(p) && !IsKind23_0024A1C0(p)) {
        int mode = p->mode;
        if ((mode == 0 || mode == 0x11 || mode == 0x12) && cHotboxMan_Interact(g_HotboxTracker, p, 1, 0)) {
            int i;
            s->x12C = 1;
            s->xC8 = 0;
            pressed = 0;
            edge = 0;
            { H_24A1C0 t; H_24A1C0* hp = &t; s->xCC = *hp; }
            s->xBC = 1;
            s->bits[0] &= ~0x20;
            for (i = 0xB; i >= 0 && !s->Test(i); i--) {}
            if (!s->Test(i))
                s->x40 = -1;
            else
                s->x40 = i;
        }
    }
    if ((edge || (cPlayerControls_HasEnteredCrawlHotbox(s) && pressed)) && cPlayerControls_ToggleCrawl(s, p))
        pressed = 0;
    if (pressed) {
        {
            Msg_24A1C0 m3;
            cMessage_ctor_cMessageNameR(&m3, g_ActorActionMsgClass);
            m3.x20 = 1;
            m3.vtable = D_004E0840;
            m3.kind = 0xF;
            m3.b = 0;
            QueueMessage_cMessageR_cSystemP_int(&m3, p, 1);
            m3.vtable = D_004E0840;
            cMessage_dtor(&m3, 0);
        }
        {
            Msg_24A1C0 m4;
            cMessage_ctor_cMessageNameR(&m4, g_ActorActionMsgClass);
            m4.vtable = D_004E0840;
            m4.kind = 0x1B;
            m4.x20 = 1;
            m4.b = 0;
            QueueMessage_cMessageR_cSystemP_int(&m4, p, 1);
            m4.vtable = D_004E0840;
            cMessage_dtor(&m4, 0);
        }
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024A1C0(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cPlayerControls_HasEnteredCrawlHotbox /* merge_units */
#undef cPlayerControls_ToggleCrawl /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024A1C0 */
