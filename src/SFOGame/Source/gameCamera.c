/*
 * SFOGame/Source/gameCamera: 10 files, 00179F30-0017A640
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
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(Ev_A080* e, void* type);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

void cNetMsg_GetGOBJ(void* p);
void QueueMessage_cMessageR_cSystemP_int(Ev_A080* e, void* target, int a);
#if 0 /* merge_units */
void cMessage_dtor(Ev_A080* e, int f);
#endif /* merge_units */
void cMessage_dtor(void*, int); /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

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
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
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
void cMessage_ctor_cMessageNameR(void*, void*);

void cMessage_dtor(void*, int);

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

/* merge_units: begin func_0017A640 */
#pragma push /* merge_units */
/* 0017A640 cGameCamera::UpdateMotion(float) (gameCamera.cc).
 * k8's gc1.c (prototype DWARF rebuild) finished by re-nesting inline helpers: MW creates virtual registers
 * breadth-first by inline depth and colours them in reverse creation order, so several helpers below exist
 * only to put an address computation one inline level deeper or shallower (XformPtQ, Sub2B/SubQ, DotW1,
 * SP1, ST1/ST2, Neg3's explicit tail copy). VU0 / quadword operations are inline asm (no C equivalent). */
#pragma cplusplus on
typedef unsigned char u8;
#pragma always_inline on
#pragma inline_depth(8)

struct V_0017A640;
extern "C" {
void cGOBJ_UpdateMotion(void*, float);
V_0017A640* CameraCol_Sweep(void*, V_0017A640*);
void Camera_UpdateZoom(void*, void*, float);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_NextFrame(void*, float);
int cSplinedMotion_float_IsTransitionInProgress(void*);
float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Evaluate(void*);
void cSplinedMotion_cQuaternion_RestartTransition(void*, float);
void std_vector_deleter_cVector_clear(void*);
float Libc_Atanf(float);
float Libc_Tanf(float);
V_0017A640* cVector_Rotate_cMatrixR(void*, void*);
void cCollisionSystem_cBox_NextFrame(void*, void*, float);
void* cQuatVec_Invert(void*);
void cSplinedMotion_float_NextFrame(void*, float, float);
V_0017A640* cVector_ctor_cVectorR(V_0017A640*, const V_0017A640*);
void cVector_opAssign(void*, const void*);
void cVector_Copy_WSet1(V_0017A640*, const V_0017A640*);
void cSplinedMotion_cVector_RestartTransition(void*, float);
void cSplinedMotion_cVector_SetTargetVal(void*, V_0017A640*);
void* cQuatVec_ctor_cQuatVecR(void*, const void*);
void cSplinedMotion_cVector_NextFrame(void*, float, float);
void* cVector_ctor_float_float_float_float(void*, float, float, float, float);
void cQuaternion_opAssign(void*, const void*);
void cSplinedMotion_cVector_ResetCurrValAndResetCurrVelocity(void*, V_0017A640*, V_0017A640*);
void cArray_cVector_PushBackActual(void*, V_0017A640*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_Evaluate(V_0017A640*, void*);
int cSplinedMotion_cVector_IsTransitionInProgress(void*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_NextFrame(void*, float);
char* cHermiteSpline_cVector_ControlPoint(void*, int);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(V_0017A640*, void*);
int func_0017D510(void*);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(void*, float);
float nGameUnits_Sec(float);
void* cMatrix_ctor_cEulerAngleTR(void*, void*);
void* cEulerAngle_T_1_2_ctor_float_float_float(void*, float, float, float);
int RAND(void);
float cCameraShake_cPulsedShakeMagnitude_GetCurrVal(void*);
float* cSplinedMotion_float_GetCurrVal(void*);
void cCameraShake_cPulsedShakeMagnitude_NextFrame(void*, float, float);
extern float D_0048A170;
extern float D_0048A178;
}


struct V_0017A640 {
    float x, y, z, w;
    V_0017A640() {}
    V_0017A640(const V_0017A640& o) { const V_0017A640* s = &o; V_0017A640* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    void CopyFrom(const V_0017A640& source) { V_0017A640* refThis = this; __int128 reg; const V_0017A640* s = &source; asm volatile { lq reg, 0(s); sq reg, 0(refThis) } }
    V_0017A640(const V_0017A640& source, int) { CopyFrom(source); }
    V_0017A640& operator=(const V_0017A640& o) { const V_0017A640* s = &o; V_0017A640* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M_0017A640 { float m[4][4]; } __attribute__((aligned(16)));
struct M4 { float m[4][4]; } __attribute__((aligned(16)));
struct Plc { V_0017A640 rot; V_0017A640 pos; } __attribute__((aligned(16)));

static inline void ScaleEq(V_0017A640* v, float k) { int t; asm { .set noreorder
    lqc2 vf1, 0x0(v)
    mfc1 t, k
    qmtc2.ni t, vf2
    vmulx.xyzw vf1, vf1, vf2x
    sqc2 vf1, 0x0(v)
    .set reorder } }
static inline void Add3(V_0017A640* d, const V_0017A640* s) { asm {
    lqc2 vf1, 0x0(d)
    lqc2 vf2, 0x0(s)
    vadd.xyz vf1, vf1, vf2
    sqc2 vf1, 0x0(d) } }
static inline void SubP(V_0017A640* rp, const V_0017A640* a, const V_0017A640* b) { __asm__ volatile ("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" :  : "r"(a), "r"(b), "r"(rp) : "memory"); }
static inline V_0017A640 Sub2(const V_0017A640& a, const V_0017A640& b) { V_0017A640 r; const V_0017A640* ap; const V_0017A640* bp; V_0017A640* rp; ap = &a; bp = &b; rp = &r; SubP(rp, ap, bp); return r; }
static inline void QMulP(V_0017A640* rp, const V_0017A640* q, const V_0017A640* p) { __asm__ volatile ("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%2)" :  : "r"(q), "r"(p), "r"(rp) : "memory"); }
static inline V_0017A640 QMul2(const V_0017A640& q, const V_0017A640& p) { V_0017A640 r; const V_0017A640* pp; const V_0017A640* qp; V_0017A640* rp; qp = &q; pp = &p; rp = &r; QMulP(rp, qp, pp); return r; }
static inline float Dot3(const V_0017A640& a, const V_0017A640& b) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&a), "r"(&b) : "memory"); return r; }
static inline void QRot(V_0017A640* v, const V_0017A640* q) { asm {
    lqc2 vf1, 0x0(v)
    vmove.w vf6, vf1
    vmr32.w vf1, vf0
    lqc2 vf2, 0x0(q)
    vmove.w vf3, vf2
    vsub.xyz vf3, vf0, vf2
    vmul.xyzw vf4, vf2, vf1
    vopmula.xyz ACC, vf2, vf1
    vmaddaw.xyz ACC, vf1, vf2w
    vopmsub.xyz vf5, vf1, vf2
    vsubaz.w ACC, vf4, vf4z
    vmsubay.w ACC, vf0, vf4y
    vmsubx.w vf5, vf0, vf4x
    vopmula.xyz ACC, vf5, vf3
    vmaddaw.xyz ACC, vf5, vf3w
    vmaddaw.xyz ACC, vf3, vf5w
    vopmsub.xyz vf6, vf3, vf5
    sqc2 vf6, 0x0(v) } }
static inline void QToMp(M_0017A640* mp, const V_0017A640* q) { asm {
    lqc2 vf1, 0x0(q)
    vadd.xyzw vf2, vf1, vf1
    vaddw.xyz vf3, vf0, vf0w
    vmulx.w vf8, vf0, vf0x
    vmulx.w vf9, vf0, vf0x
    vmuly.xyzw vf5, vf1, vf2y
    vmulz.xyzw vf6, vf1, vf2z
    vmulx.xyzw vf4, vf1, vf2x
    vmulx.w vf10, vf0, vf0x
    vsubay.x ACC, vf3, vf5y
    vmsubz.x vf8, vf3, vf6z
    vsubw.x vf9, vf5, vf6w
    vaddw.x vf10, vf6, vf5w
    vaddw.y vf8, vf4, vf6w
    vsubax.y ACC, vf3, vf4x
    vmsubz.y vf9, vf3, vf6z
    vsubw.y vf10, vf6, vf4w
    vsubw.z vf8, vf4, vf5w
    vaddw.z vf9, vf5, vf4w
    vsubax.z ACC, vf3, vf4x
    vmsuby.z vf10, vf3, vf5y
    sqc2 vf0, 0x30(mp)
    sqc2 vf8, 0x0(mp)
    sqc2 vf9, 0x10(mp)
    sqc2 vf10, 0x20(mp) } }
static inline void MulRot(V_0017A640* v, const M4* m) { asm {
    lqc2 vf8, 0x0(v)
    lqc2 vf4, 0x0(m)
    lqc2 vf5, 0x10(m)
    lqc2 vf6, 0x20(m)
    vmulax.xyz ACC, vf4, vf8x
    vmadday.xyz ACC, vf5, vf8y
    vmaddz.xyz vf8, vf6, vf8z
    sqc2 vf8, 0x0(v) } }
static inline float ClampC(float lo, float hi, float x) { float r = 0.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float ClampM(float x, float lo, float hi) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2; min.s %0, %0, %3" : "+f"(r) : "f"(x), "f"(lo), "f"(hi)); return r; }

static inline V_0017A640 Pt(const V_0017A640& v_) { const V_0017A640* v; v = &v_; V_0017A640 r(*v, 0); V_0017A640* p = &r; p->w = 1.0f; return *p; }
static inline V_0017A640 MulV(const V_0017A640* a_, float k) { V_0017A640 r; int tt; V_0017A640* d = &r; const V_0017A640* a = a_; asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 tt, k
        qmtc2.ni tt, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    } return r; }
static inline void XformPtQ(V_0017A640* v_, Plc* p)
{
    V_0017A640* v; v = v_;
    QRot(v, &p->rot);
    float* pw = &v->w;
    float w = *pw;
    if (1.0f == w) {
        Add3(v, &p->pos);
    } else {
        V_0017A640 tq = MulV(&p->pos, w);
        Add3(v, &tq);
        float* pw2 = &v->w; *pw2 = tq.w;
    }
}
static inline V_0017A640 PtW(const V_0017A640& v) { return Pt(v); }
static inline void XW(V_0017A640* v, Plc* p) { XformPtQ(v, p); }
static inline void Neg3(V_0017A640* out, const V_0017A640& a_) { V_0017A640 r; const V_0017A640* a; V_0017A640* rp; a = &a_; rp = &r; asm {
    lqc2 vf1, 0x0(a)
    vmulax.xyzw ACC, vf0, vf0x
    vmsubw.xyzw vf1, vf1, vf0w
    sqc2 vf1, 0x0(rp) } { const V_0017A640* s = &r; V_0017A640* d = out; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); } }
static inline void NegP2(V_0017A640* out, const V_0017A640& a) { Neg3(out, a); }
static inline void AddV3(V_0017A640* out, const V_0017A640& a, const V_0017A640& b) { V_0017A640 w(a); V_0017A640* wp = &w; Add3(wp, &b); *out = *wp; }
static inline void AddP2(V_0017A640* out, const V_0017A640& a, const V_0017A640& b) { AddV3(out, a, b); }
static inline void ToWorld(V_0017A640* out, char* t, Plc* p, const V_0017A640& in)
{
    V_0017A640 r(PtW(in));
    V_0017A640* rp = &r;
    XW(rp, p);
    {
        V_0017A640 o(*(V_0017A640*)(t + 0xBC0));
        Add3(rp, &o);
    }
    *out = *rp;
}
static inline void Inv4(Plc* inv, Plc* p) { Plc a; cQuatVec_ctor_cQuatVecR(inv, cQuatVec_Invert(cQuatVec_ctor_cQuatVecR(&a, p))); }
static inline void Inv5(Plc* inv, Plc* p) { Inv4(inv, p); }
static inline void Inv3(Plc* inv, Plc* p) { Inv5(inv, p); }
static inline void Inv2(Plc* inv, Plc* p) { Inv3(inv, p); }
static inline void Inv1(Plc* inv, Plc* p) { Inv2(inv, p); }
static inline void MulVTo(V_0017A640* out, const V_0017A640* a_, float k_) { V_0017A640 r; int tt; V_0017A640* d = &r; const V_0017A640* a = a_; float k = k_; asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 tt, k
        qmtc2.ni tt, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    } *out = *d; }
static inline void XformPtL(V_0017A640* v_, Plc* p)
{
    V_0017A640* v = v_;
    QRot(v, &p->rot);
    float* pw = &v->w;
    float w = *pw;
    if (1.0f == w) {
        Add3(v, &p->pos);
    } else {
        V_0017A640 tq;
        MulVTo(&tq, &p->pos, w);
        Add3(v, &tq);
        float* pw2 = &v->w; *pw2 = tq.w;
    }
}
static inline void XL3(V_0017A640* v, Plc* p) { XformPtL(v, p); }
static inline void XL2(V_0017A640* v, Plc* p) { XL3(v, p); }
static inline void ToLocal(V_0017A640* out, char* t, Plc* p, const V_0017A640& in)
{
    V_0017A640 r;
    V_0017A640 n;
    V_0017A640 o;
    Plc inv;
    Plc* ip;
    Inv1(&inv, p);
    ip = &inv;
    o = *(V_0017A640*)(t + 0xBC0);
    V_0017A640* op = &o;
    NegP2(&n, *op);
    AddP2(&r, in, n);
    V_0017A640* rp = &r;
    XL2(rp, &inv);
    *out = *rp;
}
typedef void (*VF1)(void*);
typedef void (*VF2)(void*, float, float);
typedef V_0017A640 (*VF3)(void*);
struct Obj {
    virtual void s08();
    virtual void s0C(void*);
    virtual void s10(void*);
    virtual V_0017A640 s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20(float, float);
    virtual void s24(); virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void s3C(); virtual void s40(); virtual void s44(); virtual void s48();
    virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58();
};
#define O(c) ((Obj*)(c))


static inline void QStep(char* c, float dt, float inv)
{
    cQuaternion_opAssign(c + 0x10, c + 0x20);
    O(c)->s18();
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(c + 0xB0, dt);
    if (func_0017D510(c)) {
        V_0017A640 q;
        cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(&q, c + 0xB0);
        cQuaternion_opAssign(c + 0x20, &q);
        O(c)->s1C();
    } else {
        cQuaternion_opAssign(c + 0x20, c + 0x40);
    }
    O(c)->s20(dt, inv);
}
static inline void VStep(char* c, float dt, float inv)
{
    cVector_opAssign(c + 0x10, c + 0x20);
    O(c)->s18();
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_NextFrame(c + 0xB0, dt);
    if (cSplinedMotion_cVector_IsTransitionInProgress(c)) {
        V_0017A640 q;
        cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_Evaluate(&q, c + 0xB0);
        cVector_opAssign(c + 0x20, &q);
        O(c)->s1C();
    } else {
        cVector_opAssign(c + 0x20, c + 0x40);
    }
    O(c)->s20(dt, inv);
}
static inline void Reset(char* c)
{
    *(V_0017A640*)(c + 0x10) = *(V_0017A640*)(c + 0x20) = *(V_0017A640*)(c + 0x40);
    *(V_0017A640*)(c + 0x30) = O(c)->s14();
}
static inline void Retime(char* c, float d_)
{
    float d = d_;
    float k;
    float r;
    if (d < 0.0f) return;
    k = d * *(float*)(c + 0x44);
    ScaleEq((V_0017A640*)(cHermiteSpline_cVector_ControlPoint(c, 0) + 0x10), k);
    ScaleEq((V_0017A640*)(cHermiteSpline_cVector_ControlPoint(c, 1) + 0x10), k);
    *(float*)(c + 0x40) = d;
    r = 0.0f; if (r != d) r = 1.0f / d; else asm { .set reorder } *(float*)(c + 0x44) = r;
    *(float*)(c + 0x54) = *(float*)(*(char**)(c + 0x50) + 0x40);
}
static inline void RetimeS(char* c, float d_)
{
    float d = d_;
    float k;
    float r;
    if (d < 0.0f) return;
    k = d * *(float*)(c + 0x2C);
    *(float*)(c + 0x1C) *= k;
    *(float*)(c + 0x24) *= k;
    *(float*)(c + 0x28) = d;
    r = 0.0f; if (r != d) r = 1.0f / d; else asm { .set reorder } *(float*)(c + 0x2C) = r;
    *(float*)(c + 0x34) = *(float*)(*(char**)(c + 0x30) + 0x10);
}
static inline void Reset1(char* c) { Reset(c); }
static inline u8 HitU(char* s) { return *(u8*)(s + 0x60); }
static inline void RetimeMax(char* c, float d_) { float d = d_; if (*(float*)(c + 0x54) <= d) Retime(c, d); }
static inline u8 IsZ(float f) { return f == 0.0f; }
static inline bool NBS(u8 b) { return !(b != 0); }

static inline void Shake5(char* t)
{
        float s = *cSplinedMotion_float_GetCurrVal(t + 0xB20) + cCameraShake_cPulsedShakeMagnitude_GetCurrVal(t + 0xB58);
        if (s > 0.0f) {
            V_0017A640 a;
            V_0017A640 q;
            M_0017A640 m;
            V_0017A640 e;
            V_0017A640 p;
            void* qp = cVector_ctor_float_float_float_float(&q, 0.0f, s, 0.0f, 0.0f);
            cVector_ctor_cVectorR(&a, cVector_Rotate_cMatrixR(qp, cMatrix_ctor_cEulerAngleTR(&m, cEulerAngle_T_1_2_ctor_float_float_float(&e, (float)RAND(), 0.0f, (float)RAND()))));
            cVector_Copy_WSet1(&p, &a);
            cSplinedMotion_cVector_SetTargetVal(t + 0xBA0, &p);
        }
}
static inline void Shake6(char* t) { Shake5(t); }
static inline void Shake4(char* t) { Shake6(t); }
static inline void Shake3(char* t) { Shake4(t); }
static inline void Shake2(char* t) { Shake3(t); }
static inline void Shake1(char* t) { Shake2(t); }
static inline void QS5(char* c, float dt, float inv) { QStep(c, dt, inv); }
static inline void QS4(char* c, float dt, float inv) { QS5(c, dt, inv); }
static inline void QS3(char* c, float dt, float inv) { QS4(c, dt, inv); }
static inline void QS2(char* c, float dt, float inv) { QS3(c, dt, inv); }
static inline void QS1(char* c, float dt, float inv) { QS2(c, dt, inv); }
static inline void VS5(char* c, float dt, float inv) { VStep(c, dt, inv); }
static inline void VS4(char* c, float dt, float inv) { VS5(c, dt, inv); }
static inline void VS3(char* c, float dt, float inv) { VS4(c, dt, inv); }
static inline void VS2(char* c, float dt, float inv) { VS3(c, dt, inv); }
static inline void VS1(char* c, float dt, float inv) { VS2(c, dt, inv); }
#define F(o) (*(float*)(t + (o)))
#define VV(o) (*(V_0017A640*)(t + (o)))
#define PP(o) (*(Plc*)(t + (o)))
#define B(o) (*(u8*)(t + (o)))

static inline V_0017A640 QMul4(const V_0017A640& q, const V_0017A640& p) { return QMul2(q, p); }
static inline V_0017A640 QMul3(const V_0017A640& q, const V_0017A640& p) { return QMul4(q, p); }
static inline void G1b(V_0017A640* g_, V_0017A640* d_, V_0017A640* s_, V_0017A640* e_) { V_0017A640* s; V_0017A640* d; V_0017A640* g; V_0017A640* e; g = g_; d = d_; s = s_; e = e_; *d = *g; *e = *s; }
static inline void G1(char* t)
{
    V_0017A640 g(QMul3(VV(0xAD0), VV(0x7A0)));
    G1b(&g, &VV(0x250), &VV(0xAE0), &VV(0x320));
}

static inline void UpOf2(V_0017A640* up, V_0017A640* q) { M_0017A640 m; QToMp(&m, q); V_0017A640* r = (V_0017A640*)&m; r++; *up = *r; }
static inline void UpOfS(char* s, V_0017A640* q) { M_0017A640 m; QToMp(&m, q); V_0017A640* r = (V_0017A640*)&m; r++; V_0017A640* up = (V_0017A640*)(s + 0x10); *up = *r; }
static inline void ColSet(char* s2_, V_0017A640* rot_, V_0017A640* pos_, V_0017A640* c_) { char* s2 = s2_; V_0017A640* rot; V_0017A640* c; V_0017A640* pos; rot = rot_; pos = pos_; c = c_; UpOfS(s2, rot); *(V_0017A640*)(s2 + 0x20) = *rot; *(V_0017A640*)(s2 + 0x40) = *c; *(V_0017A640*)(s2 + 0x50) = *pos; }
static inline void SubQ(V_0017A640* rp_, const V_0017A640& a, const V_0017A640& b) { V_0017A640* rp; const V_0017A640* ap; const V_0017A640* bp; rp = rp_; ap = &a; bp = &b; SubP(rp, ap, bp); }
static inline V_0017A640 Sub2B(const V_0017A640& a, const V_0017A640& b) { V_0017A640 r; SubQ(&r, a, b); return r; }
static inline float DotW1(const V_0017A640& a, const V_0017A640& b) { return Dot3(a, b); }
static inline void SP1(Plc& pl, char* t) { V_0017A640* pp = (V_0017A640*)(t + 0x300); pl.rot = VV(0x230); pl.pos = *pp; }
static inline void Toward(char* t, V_0017A640* lp, V_0017A640* a)
{
    V_0017A640 d0 = Sub2(*lp, *a);
    V_0017A640 d1 = Sub2B(*lp, VV(0xAF0));
    if (!(DotW1(d0, d1) <= 0.0f && F(0xAF4) != 0.0f)) Retime(t + 0x8B0, 0.067f);
    else Retime(t + 0x8B0, 0.5f);
}
static inline void Cur5(char* t, V_0017A640* lp) { V_0017A640 cur = O(t + 0x910)->s14(); cSplinedMotion_cVector_ResetCurrValAndResetCurrVelocity(t + 0x910, lp, &cur); }
static inline void Cur6(char* t, V_0017A640* lp) { Cur5(t, lp); }
static inline void Cur4(char* t, V_0017A640* lp) { Cur6(t, lp); }
static inline void Cur3(char* t, V_0017A640* lp) { Cur4(t, lp); }
static inline void Cur2(char* t, V_0017A640* lp) { Cur3(t, lp); }
static inline void Cur1(char* t, V_0017A640* lp) { Cur2(t, lp); }
static inline V_0017A640 RotBy(const V_0017A640& v, M4* w) { V_0017A640 o(v); V_0017A640* op = &o; MulRot(op, w); return *op; }
static inline void AddT(M4* d, const V_0017A640* s) { __asm__ volatile ("lqc2 $vf1, 0x30(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x30(%0)" :  : "r"(d), "r"(s) : "memory"); }
static inline void AddRot(M4* w, const V_0017A640& v) { const V_0017A640* vp = &v; V_0017A640 oo(RotBy(*vp, w)); AddT(w, &oo); }
static inline void ST1(M4* m, const V_0017A640& t) { V_0017A640* dp = (V_0017A640*)m->m[3]; *dp = t; }
static inline void ST2(M4* m, const V_0017A640& t) { ST1(m, t); }
static inline void Fill(M4* w, char* t)
{
    M_0017A640 m;
    V_0017A640* pp = (V_0017A640*)(t + 0x300);
    const V_0017A640* q = &VV(0x230);
    QToMp(&m, q);
    w->m[0][0] = ((M4*)&m)->m[0][0]; w->m[0][1] = ((M4*)&m)->m[0][1]; w->m[0][2] = ((M4*)&m)->m[0][2];
    w->m[1][0] = ((M4*)&m)->m[1][0]; w->m[1][1] = ((M4*)&m)->m[1][1]; w->m[1][2] = ((M4*)&m)->m[1][2];
    w->m[2][0] = ((M4*)&m)->m[2][0]; w->m[2][1] = ((M4*)&m)->m[2][1]; w->m[2][2] = ((M4*)&m)->m[2][2];
    w->m[0][3] = ((M4*)&m)->m[0][3]; w->m[1][3] = ((M4*)&m)->m[1][3]; w->m[2][3] = ((M4*)&m)->m[2][3];
    ST2(w, *pp);
    AddRot(w, VV(0x9F0));
    {
        V_0017A640 b(VV(0xBC0));
        M4* wp = w;
        V_0017A640* bp = &b;
        AddT(wp, bp);
    }
}
#define XX_UNUSED
extern "C" void cGameCamera_UpdateMotion(char* t_, float dt_)
{
    char* t = t_;
    char* x;
    char* s2;
    bool moving;
    float dt = dt_;
    float inv;
    V_0017A640 c1;
    V_0017A640 c0;

    if (dt == 0.0f || !B(0x200)) return;
    inv = 1.0f / dt;
    cSplinedMotion_float_NextFrame(t + 0xB20, dt, inv);
    cCameraShake_cPulsedShakeMagnitude_NextFrame(t + 0xB58, dt, inv);
    Shake1(t);

    cSplinedMotion_cVector_RestartTransition(t + 0xBA0, nGameUnits_Sec(0.01f));
    cSplinedMotion_cVector_NextFrame(t + 0xBA0, dt, inv);
    if (B(0x201)) {
        cSplinedMotion_cQuaternion_RestartTransition(t + 0x210, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x2E0, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x3A0, 0.0f);
        cSplinedMotion_cQuaternion_RestartTransition(t + 0x460, 0.0f);
        cSplinedMotion_cQuaternion_RestartTransition(t + 0x530, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x600, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x6C0, 0.0f);
        cSplinedMotion_cQuaternion_RestartTransition(t + 0x780, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x850, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x910, 0.0f);
        cSplinedMotion_cVector_RestartTransition(t + 0x9D0, 0.0f);
    }
    QS1(t + 0x460, dt, inv);
    VV(0x570) = VV(0x480);
    QS1(t + 0x530, dt, inv);
    Retime(t + 0x660, 0.15f);
    VS1(t + 0x600, dt, inv);
    VV(0x700) = VV(0x620);
    Retime(t + 0x720, 0.15f);
    VS1(t + 0x6C0, dt, inv);
    QS1(t + 0x780, dt, inv);
    G1(t);
    if (!B(0xC61)) VV(0x3E0) = VV(0x320);
    QS1(t + 0x210, dt, inv);
    VS1(t + 0x2E0, dt, inv);
    VS1(t + 0x3A0, dt, inv);

    s2 = *(char**)(t + 0x164);
    moving = NBS(IsZ(F(0x9C4)));
    if (B(0xC60)) {
        char* a0 = *(char**)(t + 0x130);
        Plc pl;
        O(a0)->s10(t + 0x3C0);
        V_0017A640* pp = (V_0017A640*)(t + 0x300);
        pl.rot = VV(0x230);
        pl.pos = *pp;
        ToWorld(&c0, t, &pl, VV(0xAF0));
        ToWorld(&c1, t, &pl, VV(0x930));
        ColSet(s2, &pl.rot, &pl.pos, &VV(0x3C0));
        std_vector_deleter_cVector_clear(s2 + 0x30);
        cArray_cVector_PushBackActual(s2 + 0x30, &c0);
        cArray_cVector_PushBackActual(s2 + 0x30, &c1);
        cCollisionSystem_cBox_NextFrame(t + 0x130, t, dt);
    }
    if (B(0xC60)) {
        V_0017A640 hit(*CameraCol_Sweep(s2, &c0));
        Plc pl;
        V_0017A640 lp;
        SP1(pl, t);
        ToLocal(&lp, t, &pl, hit);
        if (HitU(s2) == 0) {
            if (moving) RetimeMax(t + 0x8B0, 0.067f);
            else Retime(t + 0x8B0, 0.5f);
        } else if (moving) {
            Toward(t, &lp, &VV(0x890));
        } else {
            Toward(t, &lp, &VV(0x870));
        }
        VV(0x890) = lp;
    } else {
        VV(0x890) = VV(0xAF0);
    }
    VS1(t + 0x850, dt, inv);
    VV(0x950) = VV(0x870);
    VS1(t + 0x910, dt, inv);
    if (B(0xC60)) {
        Plc pl;
        V_0017A640 w;
        V_0017A640 up;
        V_0017A640 hit;
        V_0017A640 lp;
        u8 col;
        V_0017A640* pp = (V_0017A640*)(t + 0x300);
        pl.rot = VV(0x230);
        pl.pos = *pp;
        ToWorld(&w, t, &pl, VV(0x930));
        UpOf2(&up, &pl.rot);
        hit =  *CameraCol_Sweep(s2, &w);
        ToLocal(&lp, t, &pl, hit);
        col = HitU(s2);
        Retime(t + 0xA30, 0.067f);
        if (col) {
            Cur1(t, &lp);
        }
        V_0017A640* dst = &VV(0xA10);
        *dst = lp;
    } else {
        VV(0xA10) = VV(0x930);
    }
    VS1(t + 0x9D0, dt, inv);
    if (B(0x201)) {
        Reset1(t + 0x210);
        Reset1(t + 0x2E0);
        Reset1(t + 0x3A0);
        Reset1(t + 0x460);
        Reset1(t + 0x530);
        Reset1(t + 0x600);
        Reset1(t + 0x6C0);
        Reset1(t + 0x780);
        Reset1(t + 0x850);
        Reset1(t + 0x910);
        Reset1(t + 0x9D0);
        B(0x201) = 0;
    }
    {
        M4 w;
        Fill(&w, t);
        {
            char* x2 = *(char**)(t + 0x50);
            O(x2)->s0C(&w);
        }
        VV(0xB10) = *(V_0017A640*)w.m[3];
    }
    {
        float d = F(0xC68) - F(0xC64);
        d = ClampC(-D_0048A170, D_0048A170, d);
        float e = D_0048A178 * (d * dt);
        float a = F(0xC64) + e;
        F(0xC64) = ClampM(a, 0.00017453292f, 3.1414182f);
        F(0xC68) = F(0xC64);
    }
    {
        float lim = 1.1170107f;
        float fov = F(0xC64);
        float f;
        u8 z = HitU(t + 0x114);
        if (fov < lim) {
            x = *(char**)(t + 0x50);
            if (*(u8*)(x + 0x50)) O(x)->s58();
            Camera_UpdateZoom(t + 0x170, x + 0x10, F(0xC64));
            cCollisionSystem_cBox_NextFrame(t + 0x1C0, t, dt);
            f = F(0x178);
        } else {
            f = fov;
        }
        float k = 0.15f;
        F(0xAA0) = 1.0f / (1.0f / Libc_Tanf(0.5f * f));
        RetimeS(t + 0xA90, k);
    }
    F(0xA94) = F(0xA98);
    O(t + 0xA90)->s18();
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_NextFrame(t + 0xAC0, dt);
    if (cSplinedMotion_float_IsTransitionInProgress(t + 0xA90)) {
        F(0xA98) = cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Evaluate(t + 0xAC0);
        O(t + 0xA90)->s1C();
    } else {
        F(0xA98) = F(0xAA0);
    }
    O(t + 0xA90)->s20(dt, inv);
    F(0x60) = 0.5f * (2.0f * Libc_Atanf(1.0f / (1.0f / F(0xA98))));
    cGOBJ_UpdateMotion(t, dt);
}
static inline void merge_flush_func_0017A640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017A640 */
