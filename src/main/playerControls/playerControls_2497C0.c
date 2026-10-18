/*
 * main/playerControls: range (5 files, 002497C0-0024A1C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#include "vu0_ops.h"

/* merge_units: begin func_002497C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator-() const { V t; const V* sp = this; V* tp = &t; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(tp), "r"(sp) : "memory"); return t; }
    V operator*(float s) const { V r; int t; const V* tp = this; V* rp = &r; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(rp), "r"(tp), "f"(s) : "memory"); return r; }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
    M(const M& o) { const M* s = &o; M* d = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MulV(V* v, M* m) { V* o = v; __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
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
struct HitSub { VP v[3]; V n; unsigned char b40; char b41; unsigned char b42; char pad43[0x1D]; int f60; int f64; void Init() { HitSub* q = this; VP* i = q->v; VP* e = q->v + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->f60 = 0; q->f64 = 0; } };
struct HitRes { unsigned char hit; char pad1[0xF]; V pos; HitSub s; char pad88[0x10]; HitRes() { HitRes* p = this; p->s.Init(); } V Normal() const { const V* q = &s.n; return *q; } };
struct Item { char pad[0x3C]; int range; };
struct Plr { char pad[0x3524]; int inv; };
struct RayMsg { void* vt; char base[0x20]; int f24; int f28; HitRes* res; V start; V end; Plr* pl; void* cl; int f58; unsigned char b5C; };
extern "C" {
extern char* D_004FFC2C;
extern char D_004FFB50[];
extern char D_004EA0B0[];
extern char D_005435A0[];
extern char D_004D9180[];
Svc* Service_Lookup(void* a, void* b);
void Event_Construct(void* m, void* type);
void cMessage_dtor(void* m, int flags);
void Hud_SetLockMeter(char* h, float f);
void Hud_ShowThrowMarker(char* h, V* a, V* b);
Item* WeaponInv_GetHeldItem(int inv);
}
extern "C" unsigned char Player_AimViewThrownPoint(V* out, Obj* obj, Plr* p)
{
    M m = SubMtx(obj->sub);
    char* hud = D_004FFC2C;
    Hud_SetLockMeter(hud, 0.0f);
    V a;
    unsigned char r = 0;
    a.y = 1.5f; a.w = 1.0f; a.x = 0.0f; a.z = 0.0f;
    MulV(&a, &m);
    m.t = a;
    float range = (float)WeaponInv_GetHeldItem(p->inv)->range;
    HitRes res;
    RayMsg msg;
    V b;
    V d;
    V dir = m.r1 * range;
    RayMsg* mp = &msg;
    V* st = &m.t;
    Event_Construct(mp, D_005435A0);
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
    Service_Lookup(D_004FFB50, D_004EA0B0)->Send(&msg);
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
    Hud_ShowThrowMarker(hud, out, &d);
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
float Weapon_GetHeldRange(Wpn_249B10* w);
float Flashlight_BeamProbe(Pl_249B10* p, Probe_249B10* pr, int n);
int TeamTable_AreEnemies(Pl_249B10* p, Hit_249B10* h);
void Hud_ShowNoFire(char* h);
void Hud_HideNoFire(char* h);
int Loc_LookupText(char* key);
void Hud_ShowCallout(char* a0, int* a1, float f0, float f1, int text, int a3, signed char c0, signed char c1);
}
static inline bool IsKind23(Hit_249B10* h) { unsigned char k = h->Kind(); return k == 2 || k == 3; }
extern "C" Hit_249B10* PlayerInput_AimViewLock(int a0, int a1, Pl_249B10* p)
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
    pr.range = Weapon_GetHeldRange(p->wpn);
    r = Flashlight_BeamProbe(p, &pr, 0x10);
    if (pr.hit && !TeamTable_AreEnemies(p, pr.hit)) {
        pr.kind = 0;
        Hud_ShowNoFire(D_004FFC2C);
    } else {
        Hud_HideNoFire(D_004FFC2C);
    }
    show = pr.kind == 2 && !IsKind23(pr.hit);
    h = D_004FFC2C;
    if (pr.kind == 0)
        Hud_SetLockMeter(h, 1.0f);
    else
        Hud_SetLockMeter(h, 0.0f);
    if (show) {
        int* idp = &((HitData_249B10*)pr.hit)->id;
        Hud_ShowCallout(h, idp, 0.1f, 1.0f, Loc_LookupText(D_004A75B8), 0, 0, 0);
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
extern char D_0055D480[];
extern char D_004E0840[];
extern float D_004A7580;
#if 0 /* merge_units */
extern "C" void Event_Construct(QtMsg* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

extern "C" void Event_Send(QtMsg* m, void* target, int immediate);
#if 0 /* merge_units */
extern "C" void cMessage_dtor(QtMsg* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

extern "C" void Curve_Retime1s(void* c, float f);
extern "C" void VecCurve_SetDuration(void* c, float f);
static inline bool QtBusy(QtPl* pl) {
    bool b = 0;
    if (pl->sub && pl->sub->busy) b = 1;
    return b;
}
extern "C" void Player_UpdateQuickTurn(QtState* q, QtIn* in, float dt, QtPl* pl, char* c)
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
                Event_Construct(&msg, D_0055D480);
                msg.vtable = D_004E0840;
                msg.kind = 0xE;
                msg.b = 0;
                Event_Send(&msg, pl, 0);
                msg.vtable = D_004E0840;
                cMessage_dtor(&msg, 0);
                Curve_Retime1s(c + 0x210, 1.0f);
                VecCurve_SetDuration(c + 0x2E0, -1.0f);
                VecCurve_SetDuration(c + 0x3A0, -1.0f);
                Curve_Retime1s(c + 0x780, -1.0f);
                VecCurve_SetDuration(c + 0x910, -1.0f);
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
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249D00(void) {}
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
extern void Event_Construct(Msg_00249F40* msg, void* name);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(Msg_00249F40* msg, void* target, int flags);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_00249F40* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

extern int PlayerInput_ZoneEnteredThisFrame(In_00249F40* in);
extern int PlayerInput_CrouchToggle(In_00249F40* in, Pl_00249F40* p);
#define SENDB(V) { Msg_00249F40 msg; Event_Construct(&msg, D_0055D480); msg.vtable = D_004E0840; msg.value = V; msg.b20 = 1; msg.b28 = 0; Event_Send(&msg, p, 1); msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
#define SEND(V) { Msg_00249F40 msg; Event_Construct(&msg, D_0055D480); msg.vtable = D_004E0840; msg.b20 = 1; msg.value = V; msg.b28 = 0; Event_Send(&msg, p, 1); msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
void PlayerInput_HandleCross(In_00249F40* in, Pl_00249F40* p, float v)
{
    int t = 1;
    unsigned char pressed;
    unsigned char edge;
    if (v <= 0.0f)
        t = 0;
    pressed = t;
    edge = !in->held && pressed;
    in->held = pressed;
    if (edge || (PlayerInput_ZoneEnteredThisFrame(in) && pressed)) {
        if (PlayerInput_CrouchToggle(in, p))
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
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249F40(void) {}
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
extern int D_004FFBD0;
#if 0 /* merge_units */
void Event_Construct(Msg_24A1C0* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void Event_Send(Msg_24A1C0* m, void* target, int immediate);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((QtMsg *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(Msg_24A1C0* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

int Actor_TryObjectInteraction(int a, Pl_24A1C0* p, int b, int c);
#if 0 /* merge_units */
int PlayerInput_ZoneEnteredThisFrame(St_24A1C0* s);
#endif /* merge_units */
#define PlayerInput_ZoneEnteredThisFrame(a0) (PlayerInput_ZoneEnteredThisFrame((In_00249F40 *)(a0))) /* merge_units */

#if 0 /* merge_units */
int PlayerInput_CrouchToggle(St_24A1C0* s, Pl_24A1C0* p);
#endif /* merge_units */
#define PlayerInput_CrouchToggle(a0, a1) (PlayerInput_CrouchToggle((In_00249F40 *)(a0), (Pl_00249F40 *)(a1))) /* merge_units */

}
static inline bool Busy_(Pl_24A1C0* pl) {
    bool b = 0;
    if (pl->sub && pl->sub->busy) b = 1;
    return b;
}
static inline bool IsKind23_0024A1C0(Pl_24A1C0* h) { unsigned char k = h->Kind(); return k == 2 || k == 3; }
#pragma push
#pragma opt_propagation off
extern "C" void PlayerInput_HandleTriangle(St_24A1C0* s, Pl_24A1C0* p, float v)
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
        Event_Construct(&m, D_0055D480);
        m.x20 = 1;
        m.kind = (signed char)k;
        m.b = 0;
        m.vtable = D_004E0840;
        Event_Send(&m, p, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
        if (p->mode == 0x14) {
            Msg2_24A1C0 m2x;
            Event_Construct(&m2x.base, D_0055D480);
            m2x.base.kind = 0x28;
            m2x.base.b = 1;
            m2x.base.vtable = D_004D9320;
            m2x.base.x20 = 1;
            m2x.x2C = D_0048AEC8;
            Event_Send(&m2x.base, p, 1);
            m2x.base.vtable = D_004E0840;
            pressed = 0;
            edge = 0;
            cMessage_dtor(&m2x.base, 0);
        }
    }
    if (edge && !Busy_(p) && !IsKind23_0024A1C0(p)) {
        int mode = p->mode;
        if ((mode == 0 || mode == 0x11 || mode == 0x12) && Actor_TryObjectInteraction(D_004FFBD0, p, 1, 0)) {
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
    if ((edge || (PlayerInput_ZoneEnteredThisFrame(s) && pressed)) && PlayerInput_CrouchToggle(s, p))
        pressed = 0;
    if (pressed) {
        {
            Msg_24A1C0 m3;
            Event_Construct(&m3, D_0055D480);
            m3.x20 = 1;
            m3.vtable = D_004E0840;
            m3.kind = 0xF;
            m3.b = 0;
            Event_Send(&m3, p, 1);
            m3.vtable = D_004E0840;
            cMessage_dtor(&m3, 0);
        }
        {
            Msg_24A1C0 m4;
            Event_Construct(&m4, D_0055D480);
            m4.vtable = D_004E0840;
            m4.kind = 0x1B;
            m4.x20 = 1;
            m4.b = 0;
            Event_Send(&m4, p, 1);
            m4.vtable = D_004E0840;
            cMessage_dtor(&m4, 0);
        }
    }
}
#pragma pop
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef PlayerInput_ZoneEnteredThisFrame /* merge_units */
#undef PlayerInput_CrouchToggle /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024A1C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024A1C0 */
