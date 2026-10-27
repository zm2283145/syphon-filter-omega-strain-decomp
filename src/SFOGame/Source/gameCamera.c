/*
 * SFOGame/Source/gameCamera: 9 files, 00179F30-0017A610
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00179F30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004EE938;

/* Returns the value of global D_004EE938. */
int cHumanSeenMsg_GetMsgId(void) {
    return D_004EE938;
}
static inline void merge_flush_func_00179F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179F30 */

/* merge_units: begin func_00179F40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_0049CEC8[] = "gameCamera.hh"; }
DEFINE_NET_MSG_CLONE(cHumanSeenMsg_Clone, 0x28, D_0049CEC8, 0x214, D_004DA310, NMC_W(0x24))
static inline void merge_flush_func_00179F40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179F40 */

/* merge_units: begin func_0017A050 */
#pragma push /* merge_units */
extern int D_004EE948;
extern int cGOBJ_SOBJ_toInt(int);

/* Script binding: args[0] is the message; returns its "who" field (+0x24). */
int Script_cHumanSeenMsg_Who(char** args) {
    return cGOBJ_SOBJ_toInt(*(int*)(args[0] + 0x24));
}

void cHumanSeenMsg_SOBJ_init(void) {
}

/* Returns the value of global D_004EE948. */
int cHumanSeenMsg_getSOBJClassId(void) {
    return D_004EE948;
}
static inline void merge_flush_func_0017A050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017A050 */

/* merge_units: begin func_0017A080 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x1C]; unsigned char flag; char pad21[3]; char m24[0xC]; } Ev_A080;
extern char D_004EE930[];
extern char D_004DA310[];
extern char D_004DCF10[];
void cMessage_ctor_cMessageNameR(Ev_A080* e, void* type);
void cNetMsg_GetGOBJ(void* p);
void QueueMessage_cMessageR_cSystemP_int(Ev_A080* e, void* target, int a);
void cMessage_dtor(Ev_A080* e, int f);
void cHumanSeenMsg_NetReceive(void* target)
{
    Ev_A080 e;
    cMessage_ctor_cMessageNameR(&e, D_004EE930);
    e.vt = D_004DA310;
    cNetMsg_GetGOBJ(e.m24);
    e.flag = 1;
    if (target)
        QueueMessage_cMessageR_cSystemP_int(&e, target, 0);
    e.vt = D_004DCF10;
    cMessage_dtor(&e, 0);
}
static inline void merge_flush_func_0017A080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017A080 */

/* merge_units: begin func_0017A100 */
#pragma push /* merge_units */
extern int cGameSystem_PopCamera(char* world);
extern int cGameSystem_RemoveCamera(char* world, int camera);
extern int D_004EE908;
extern char g_Game[]; /* world object */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(char*, int, int);
extern int cGameSystem_PushCamera(char* world, int camera); /* push camera */
extern void cNetMsg_PutGOBJ(int);

/* Script binding: removes camera args[0] from the world camera stack. */
int Script_cGameCamera_RemoveCamera(int* args) {
    cGameSystem_RemoveCamera(g_Game, args[0]);
    return 0;
}

/* Script binding: pops the current camera. */
int Script_cGameCamera_PopCurrent(void) {
    cGameSystem_PopCamera(g_Game);
    return 0;
}

/* Script binding: pushes camera args[0] as current. */
int Script_cGameCamera_PushCurrent(int* args) {
    cGameSystem_PushCamera(g_Game, args[0]);
    return 0;
}

void cGameCamera_SOBJ_init(void) {
}

/* Returns the value of global D_004EE908. */
int cGameCamera_getSOBJClassId(void) {
    return D_004EE908;
}

int cGameCamera_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

void cHumanSeenMsg_Pack(char* msg) {
    cNetMsg_PutGOBJ(*(int*)(msg + 0x24));
}
static inline void merge_flush_func_0017A100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017A100 */

/* merge_units: begin func_0017A1E0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cGameCamera_CanSee: set the fog slot, push the camera inverse matrix, and LOS-test from the camera eye to the target position */
#include "vslot_pad.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
static inline void AddV2(V* d, V* a, V* b);
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator-(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    V operator*(float k) const { V r; ScaleV(&r, this, k); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V& operator+=(V o) { AddV2(this, this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void AddV(V* d, V* a, V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void AddV2(V* d, V* a, V* b) { AddV(d, a, b); }
static inline V operator/(V v, float s) { V* pv = &v; return *pv * (1.0f / s); }

// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len0(V* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }

static inline float Len(V* a) { return Len0(a); }
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct LosHit {
    VP arr[3];
    V normal;
    unsigned char b40; char p41; unsigned char b42; char p43[0x1D];
    int x60;
    void* x64;
    char pad68[0x18];
    void Init() { LosHit* q = this; VP* i = q->arr; do { i++; } while (i != q->arr + 3); q->b40 = 0; q->b42 = 0; q->x60 = 0; q->x64 = 0; }
};
struct LosRes {
    bool hit;
    char pad1[0xF];
    V pt;
    LosHit h;
    LosRes() { LosRes* p = this; p->h.Init(); }
};
struct Svc { VPAD1(a) virtual void Post(void* m); };
struct Mq { __int128 q[4]; Mq() {} };
struct M {
    V r0, r1, r2, r3;
    M() {}
    // 128-bit lq/sq quadword copy idiom
    M(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
struct XNode {
    VPAD1(a)
    virtual void SetMatrix(M m);
    VPAD16(b) VPAD2(c)
    virtual void Update();
    char pad4[0xC];
    M m;
    unsigned char b50;
    const M& Mtx() { if (b50) Update(); return m; }
};
struct Cam { char pad0[0x50]; XNode* node; char pad54[0xC]; float x60; };
struct Tgt { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual V GetPos(); };
struct Fog { char pad0[0x64]; float x64; };
struct Holder { char pad0[0xC]; Fog* fog; };
struct Slot { char pad[0x2E4]; float f2E4; int pad2E8; float f2EC; float f2F0; char f2F4; char f2F5; char f2F6; };
struct Rs { char pad[0xA80]; Mq mtx[1]; };
extern "C" {
extern Holder* D_004FFBD4;
extern char g_LosRequestMsgClass[];
extern char D_004D9180[];
extern char g_LosCheckService[];
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((Ev_A080 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Ev_A080 *)(a0), (a1))) /* merge_units */

Svc* cSystemContainer_GetSystem(void* a, void* b);
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
void* cGOBJ_GetXform_void(void* o);
Mq cXform_GetInverseMatrix(void* xf);
int XLib_Inside(void* r, V* p);
bool cGameCamera_CanSee(Cam* c, Tgt* t);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct LosMsg : MsgB {
    int x24;
    int x28;
    LosRes* res;
    V from;
    V dir;
    void* self;
    int x54;
    int mask;
    unsigned char b5C;
    LosMsg(LosRes* r, const V& f, const V& d, void* o, int mask)
    {
        LosMsg* m = this;
        cMessage_ctor_cMessageNameR(m, g_LosRequestMsgClass);
        m->vtable = D_004D9180;
        m->x24 = 0;
        m->x28 = 0;
        m->res = r;
        m->from = f;
        m->dir = d;
        m->self = o;
        m->x54 = 0;
        m->mask = mask;
        m->b5C = 0;
        m->from.w = 1.0f;
        m->dir.w = 0.0f;
    }
    __declspec(weak) __declspec(MSG_DTOR) ~LosMsg() { vtable = D_004D9180; }
};

#define RS ((Rs*)g_Video)
#define SLOT(i) ((Slot*)(g_Video + (i) * 0x110))

static inline void SetFog(Cam* c, float b) { Fog* fg = D_004FFBD4->fog; float fx = fg->x64; float fa = c->x60; int i = D_00538C60; char* base = g_Video; Slot* s = (Slot*)(base + i * 0x110); s->f2F0 = fa; s->f2E4 = b; s->f2EC = 12.0f + fx; s->f2F6 = 1; s->f2F4 = 0; }
// 64-byte quadword copy (lq/sq pairs)
static inline void QR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

/* the unused xx reproduces retail's dead addiu of the matrix temporary's address */
static inline void SetTop(const Mq& m) { const Mq* xx = &m; QR(&RS->mtx[D_00538C64], (void*)&m); }

bool cGameCamera_CanSee(Cam* c, Tgt* t)
{
    bool vis = 0;
    SetFog(c, 2.0f);
    QR(&RS->mtx[D_00538C64 + 1], &RS->mtx[D_00538C64]);
    D_00538C64++;
    SetTop(cXform_GetInverseMatrix(cGOBJ_GetXform_void(c)));
    D_00538C68 = 1;
    V p = t->GetPos();
    if ((unsigned char)XLib_Inside(g_Video, &p)) {
        LosRes res;
        M m = c->node->Mtx();
        V eye = m.r3;
        V dir = p - eye;
        float len = Len(&dir);
        eye += dir * 2.0f / len;
        {
            LosMsg msg(&res, eye, dir, t, 4);
            cSystemContainer_GetSystem(g_Game, g_LosCheckService)->Post(&msg);
            if (!res.hit) vis = 1;
        }
    }
    D_00538C64--;
    D_00538C68 = 1;
    return vis;
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0017A1E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017A1E0 */

/* merge_units: begin func_0017A5D0 */
#pragma push /* merge_units */
int cGameCamera_RemoveCamera(int camera) {
    return cGameSystem_RemoveCamera(g_Game, camera);
}

int cGameCamera_PushCurrent(int camera) {
    return cGameSystem_PushCamera(g_Game, camera);
}

void* cGameCamera_GetGlobalOffset(char* self) {
    return self + 0xB10;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017A5D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017A5D0 */

/* merge_units: begin func_0017A600 */
#pragma push /* merge_units */
typedef struct { char pad[0xB10]; Vec4 v; } ObjB10;
/* Copies a vector into the object's field at +0xB10. */
#pragma peephole off
void cGameCamera_SetGlobalOffset(ObjB10* obj, Vec4* v) { obj->v = *v; }
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017A600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017A600 */

/* merge_units: begin func_0017A610 */
#pragma push /* merge_units */
typedef struct { char pad[0x9C4]; float v; } F17A610_t;
int cSplinedMotion_cQuaternion_IsTransitionInProgress(F17A610_t* p) {
    return !(0.0f == p->v);
}
static inline void merge_flush_func_0017A610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017A610 */
