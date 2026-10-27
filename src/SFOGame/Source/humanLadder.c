/*
 * SFOGame/Source/humanLadder: 6 files, 00472740-00474050
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00472740 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then cMemMan_Deallocate under the guard. */
extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void* std_pair_int_sMsgTypeInfo_dtor(void* self, short flags);
void opDelete_nodeP_int_bool_charP_etc_19(void* allocation, int pool, int destroy, char* file, int line);
}
void opDelete_nodeP_int_bool_charP_etc_19(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            std_pair_int_sMsgTypeInfo_dtor((char*)allocation + 12, -1);
    }
    cMemMan_Deallocate(pool, allocation, file, line);
}
static inline void merge_flush_func_00472740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00472740 */

/* merge_units: begin func_00472820 */
#pragma push /* merge_units */
extern char D_004C3460[];
extern void cTimerDisable_ctor(int* g);
extern void cTimerDisable_dtor(int* g, int del);
#if 0 /* merge_units */
extern void cMemMan_Deallocate(int heap, void* p, const char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (char *)(a2), (a3))) /* merge_units */


void cAllocator_node_deallocate_nodeP_uint_19(void* self, void* p)
{
    if (p) {
        int g[1];
        cTimerDisable_ctor(g);
        cMemMan_Deallocate(0, p, D_004C3460, 100);
        cTimerDisable_dtor(g, -1);
    }
}
#undef cMemMan_Deallocate /* merge_units */
static inline void merge_flush_func_00472820(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00472820 */

/* merge_units: begin func_00472880 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after NetMsgThrottle.cc (ends 0x00472370).
 */


extern int cNetMsgThrottle_sMsgTypeInfo_dtor(void* obj, int arg);

void* func_00472880(char* self) {
    return self + 4;
}

void cAllocator_pair_int_destroy_pairP_7(int unused, char* obj) {
    if (obj != 0) {
        cNetMsgThrottle_sMsgTypeInfo_dtor(obj + 4, -1);
    }
}

void* func_004728C0(void* self) {
    return self;
}
static inline void merge_flush_func_00472880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00472880 */

/* merge_units: begin func_004728D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void QP(void* d, const void* s) { __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(s) : "r"(d) : "memory"); }
static inline void QPW(void* d, const void* s) { QP(d, s); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(&o) : "memory"); return *this; }
    V& SetZ(float nz) { V* p = this; p->z = nz; return *p; }
} __attribute__((aligned(16)));
struct Pl { V q; V p; };
struct Rung { char pad[0x990]; float f990; float f994; float f998; unsigned char block[3]; unsigned char snapped; };
struct Ctrl {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual int v54();
};
struct Msg;
extern "C" {
extern char D_004E00E0[], D_004E0840[];
void cCharActionMsg_ctor_cCharActionMsgR(Msg* d, const Msg* s);
void cInteractParams_ctor_cInteractParamsR(void* d, const void* s);
void cMessage_dtor(void* msg, int flags);
void cCharActionMsg_ctor_int_eParamType(Msg* m, signed char action, int flag);
void cInteractParams_ctor_int_cQuatVecR_cGOBJP(void* d, int obj, Pl* pl, int z);
}
struct Msg {
    void* vt;
    char pad04[0x18];
    int flags;             /* 0x1C */
    unsigned char b20;     /* 0x20 */
    char pad21[0xF];
    char sub[0x30];        /* 0x30 */
    Msg(signed char action, int obj, Pl* pl);
    Msg(const Msg& o);
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Msg() { vt = D_004E0840; cMessage_dtor(this, 0); }
};
struct Lad {
    char pad0[0x14];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Ctrl* ctrl;            /* 0x58 */
    char pad5C[0x2EC0 - 0x5C];
    char anim[0x3248 - 0x2EC0];
    int flags;             /* 0x3248 */
    char pad324C[0x3298 - 0x324C];
    void* root;            /* 0x3298 */
    char pad329C[0x3310 - 0x329C];
    Rung* rung;            /* 0x3310 */
    char pad3314[0x3514 - 0x3314];
    int obj;               /* 0x3514 */
    signed char side;      /* 0x3518 */
};
extern float D_004A03C0, D_004A0410, D_004A0418;
extern "C" {
}
struct Msg;
extern "C" {
V cHuman_CalculateClosestLadderRungToStopAt(Lad* l, int i);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
V* cQuatVec_Translation(void*);
V* cQuatVec_Rotation(void*);
float cSkaParams_GetSliderValue(char* owner, int i);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
void cHuman_DismountFromLadder(Lad* a);
}
static inline float fab(float x) { float r; asm { abs.s r, x } return r; }
static inline bool Rung_Valid(Rung* r) { return r->f990 > -3.4028235e38f && r->f998 < 3.4028235e38f; }
static inline bool Ctrl_Test(Ctrl* c) { return c && c->v54(); }
static inline bool Flag25(Lad* a) { return (a->flags >> 25) & 1; }
static inline bool Flag26(Lad* a) { return (a->flags >> 26) & 1; }
static inline float AnimCur(Lad* a) { char* an = a->anim; return cSkaParams_GetSliderValue(an + 0x10, 0x15); }
inline Msg::Msg(signed char action, int obj, Pl* pl) { Msg* s = this; cCharActionMsg_ctor_int_eParamType(s, action, 0xE); cInteractParams_ctor_int_cQuatVecR_cGOBJP(s->sub, obj, pl, 0); s->vt = D_004E00E0; }
inline Msg::Msg(const Msg& o) { Msg* s = this; cCharActionMsg_ctor_cCharActionMsgR(s, &o); cInteractParams_ctor_cInteractParamsR(s->sub, o.sub); s->vt = D_004E00E0; }
static inline void Send(const Msg& m, Lad* t) { QueueMessage_cMessageR_cSystemP_int((void*)&m, t, 1); }
static inline unsigned char Open(Rung* r, int s) { return r->block[s]; }
static inline V WithZ(const V& p, float z) { V t; QPW(&t, &p); return t.SetZ(z); }

void cHuman_DismountFromLadder(Lad* a)
{
    if (a->rung) {
        if (Rung_Valid(a->rung) && Open(a->rung, a->side)) {
            unsigned char atTop = 0;
            unsigned char atBot = 0;
            V* pos = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(a->root));
            Rung* r = a->rung;
            float y = pos->z;
            float bot = r->f990;
            float top = r->f998 + D_004A0410;
            float k = D_004A0418;
            float tol = D_004A03C0 * k;
            if (fab(y - top) <= tol) atTop = 1;
            if (fab(y - bot) <= tol) atBot = 1;
            unsigned char exitTop = a->side == 2 && (atTop || (Flag25(a) && AnimCur(a) < 0.15f));
            unsigned char exitBot = a->side == 4 && (atBot || (Flag26(a) && AnimCur(a) < 0.15f));
            unsigned char go = (a->side != 2 && a->side != 4) || exitTop || exitBot;
            if (go) {
                if (Ctrl_Test(a->ctrl) && !a->b14)
                    return;
                int action = 0x1E;
                V target;
                if (exitTop) {
                    float z = a->rung->f998 + D_004A0410;
                    if ((a->flags >> 25) & 1)
                        z -= 1.0f;
                    target = WithZ(*cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(a->root)), z);
                    action = 0x1F;
                } else if (exitBot) {
                    float z = a->rung->f990;
                    target = WithZ(*cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(a->root)), z);
                    action = 0x20;
                } else if (a->rung->snapped) {
                    target = cHuman_CalculateClosestLadderRungToStopAt(a, 1);
                } else {
                    target = cHuman_CalculateClosestLadderRungToStopAt(a, 1);
                }
                Pl pl;
                pl.q = *cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(a->root));
                pl.p = target;
                Msg m(action, a->obj, &pl);
                if (!Ctrl_Test(a->ctrl))
                    m.b20 = 1;
                m.flags = 0x40;
                Send(Msg(m), a);
            }
        }
    }
}
static inline void merge_flush_func_004728D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004728D0 */

/* merge_units: begin func_00472E10 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off

typedef struct { float x, y, z, w; } V4_L;
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_L;
typedef struct { float q[4]; float p[4]; } __attribute__((aligned(16))) Plc_L;
typedef struct { int id; void* a; } Pair_L;
typedef struct { unsigned char kind; char pad[3]; Pair_L pairs[7]; char tail[0x10]; } X_L;
typedef struct { unsigned char mode; char pad1[0xF]; char sub[0x30]; int f40; int f44; unsigned char f48; char pad49[3]; X_L x; float f98; int f9C; } Sel_L;
typedef struct { float x, y, z, w; } Rate_L;
typedef struct { void* model; char pad4; unsigned char b5; char pad6[2]; V4_L v; } Anim_L;
typedef struct { void* lib; char pad4[0xC]; char f10[0x24]; Anim_L anim; } Sys_L;
typedef struct { int a, b; } Y_L;
typedef struct { char pad[0x40]; } Ev_L;
typedef struct { char pad[0x160]; int f160; } Root_L;
typedef struct { char pad[0x24]; int tree; } Lib_L;
typedef struct { int n; } It_L;
typedef struct { int top; int bits; } Pri_L;
typedef struct { char pad[0x99E]; unsigned char b99E; unsigned char b99F; unsigned char b9A0; unsigned char b9A1; unsigned char b9A2; char pad9A3; unsigned char b9A4; } Rung_L;

struct Act_L {
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
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual unsigned char GetState();
    char pad4[0x2EC0 - 4];
    Sys_L sys; char pad2EF4_[0x31B6 - 0x2EC0 - sizeof(Sys_L)];
    unsigned char b31B6; char pad31B7[0x320C - 0x31B7];
    Pri_L pri; char pad3214[0x3248 - 0x3214];
    int f3248; char pad324C[0x326C - 0x324C];
    int f326C; char pad3270[0x3294 - 0x3270];
    Root_L* r3294; char pad3298[0x3310 - 0x3298];
    Rung_L* s3310; char pad3314[0x3514 - 0x3314];
    int f3514;
    signed char b3518;
};

#define MSG_HDR \
    void* vtable; int f04; int f08; int f0C; int f10; int f14; int f18; int f1C; signed char f20; char pad21[3]
typedef struct { MSG_HDR; int act; unsigned char type; char pad29[7]; int flags; int id; char pad38[8]; Plc_L plc; } Msg_L;
typedef struct { MSG_HDR; int f24; unsigned char f28; char pad29[3]; } Ev2_L;

extern "C" {
extern char D_004E0840[]; extern char g_ActorActionMsgClass[];
extern char D_004C3470[]; extern char D_004C3490[]; extern char D_004C34B0[]; extern char D_004C34D0[];
extern char D_004C34F0[]; extern char D_004C3510[]; extern char D_004C3530[]; extern char D_004C3550[];
extern char D_004C3570[]; extern char D_004C3590[];
extern float g_DefaultMotionTransition;
void* cObjectId_ctor_uint(int* p, int v);
unsigned char opNe_cObjectIdR_cObjectIdR(int* a, int* b);
void* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void* cGOBJ_GetXform_void(void* o);
void* cXform_GetMatrix(void* p);
Plc_L* cQuatVec_ctor_cMatrixR(Plc_L* d, void* m);
void* cMatrix_GetUnit(void);
void cQuatVec_Copy_Transform(Plc_L* d, Plc_L* s, Plc_L* p);
void cQuatVec_ctor_cQuatVecR(Plc_L* d, Plc_L* s);
void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(Root_L* r, Plc_L* p);
void** cArray_FixedSize_cGOBJPtr_3_opIndex(void* p, int i);
void* cArray_FixedSize_cQuatVec_3_opIndex(void* p, int i);
unsigned char* func_00195DB0(void* p, int i);
void cQuatVec_opAssign(void* t, Plc_L* p);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
void cString16N_3_ctor_void(void* p);
void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(void* d, void* s);
void cSkaPlaybackGroupId_ctor_int(void* p, int v);
void cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(Sel_L* sel, int* out, Y_L* y, void* model);
float cSkaAnimationSet_DefaultCrossFadeDuration(void* m);
V4_L* cSkaCrossFadeDuration_ctor_float(V4_L* p, float f);
V4_L* cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(V4_L* d, V4_L* s);
void cSkaAnimEndedMessage_ctor_void(Ev_L* e);
signed char cSkaRequestStream_AnimationPacket_GetInstruction(Sel_L* s);
void* cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(Sel_L* s);
float cSkaRequestStream_AnimationPacket_GetDuration(Sel_L* s);
float func_0018A2C0(Sel_L* s);
void cSkaRequestStream_AddRequest(void* ctl, int id, signed char mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void cSkaAnimEndedMessage_dtor(void* p, int f);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
#if 0 /* merge_units */
float cSkaParams_GetSliderValue(void* p, int i);
#endif /* merge_units */
#define cSkaParams_GetSliderValue(a0, a1) (cSkaParams_GetSliderValue((char *)(a0), (a1))) /* merge_units */


int cHuman_ShouldLeftHandBeGraspingTheHigherRung(Act_L* a, int f);
void cMessage_ctor_cMessageNameR(void* m, void* t);
#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void* m, void* t, int f);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
void cMessage_dtor(void* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */


void cAssocArray_cString16N_3_int_Find(It_L* out, int* tree, Name_L* key);
void cAssocArray_cString16N_3_int_End(It_L* out, int* tree);
int cAssocArray_cString16N_3_int_ConstIterator_opNe(It_L* a, It_L* b);
int* cAssocArray_cString16N_3_int_ConstIterator_opMul(It_L* a);
}

static inline int IdNe_L(int* a, int* b) { return *a != *b; }
/* qword copy loop (lq/sq idiom); GCC-style operands also put mwcc in the no-propagation/aligned-label mode retail shows */
static inline void QCopyA_L(void* dd, void* ss) { int n = 3; __int128 q; void* s = ss; void* d = dd;
    __asm__ volatile(".set noreorder\n" "1:\n lq %0, 0(%2)\n addiu %1, %1, 0x10\n addi %3, %3, -1\n addiu %2, %2, 0x10\n bgtz %3, 1b\n sq %0, -0x10(%1)" "\n.set reorder" : "=&r"(q) : "r"(d), "r"(s), "r"(n) : "memory");
}
static inline void QZero_L(void* dd) { int n = 3; void* d = dd;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
#define NAME_COPY(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        char* ckc_s = (src); \
        for (; ckc_i < 0x2F; ckc_i++) { \
            if (ckc_s[ckc_i] == 0) ckc_end = 1; \
            if (ckc_end) ckc_c = 0; else ckc_c = ckc_s[ckc_i]; \
            (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }
static inline void NameAssign_L(Name_L* dst, char* src) { Name_L tmp; NAME_COPY(tmp.c, src) if (dst->c[0] || tmp.c[0]) QCopyA_L(dst, &tmp); }

static inline float Recip_L(float v) { return v != 0.0f ? 1.0f / v : 3.4028235e38f; }
static inline X_L* XInit_L(X_L* x) { X_L* px = x; px->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(px->pairs); cArray_cTimedEvent_ctor_void(px->tail); return px; }
static inline X_L* XSetR_L(X_L* x, int i, int id, void* a, unsigned char k) { Pair_L* p = &x->pairs[i]; p->id = id; p->a = a; x->kind = k; return x; }
static inline void XDtor_L(X_L* x) { func_001BE5A0(x->tail, 0); __destroy_array(x->pairs, (void*)func_0018A210, 8, 7); }
static inline void XDtorN_L(X_L* p) {
    void* t = p->tail;
    if (t) { if (t) { if (t) func_001BE5A0(t, 0); } }
    if (p->pairs) __destroy_array(p->pairs, (void*)func_0018A210, 8, 7);
}
static inline X_L* Set5_L(X_L* x, int a, int b, int c, int d, int e, void* act)
{
    return XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetR_L(x, 0, a, act, 1), 1, b, act, 1), 3, c, act, 1), 5, d, act, 1), 6, e, act, 1);
}
static inline void RateDef_L(Rate_L* r)
{
    float d = g_DefaultMotionTransition;
    r->x = d;
    r->y = d;
    r->z = Recip_L(d);
    r->w = Recip_L(g_DefaultMotionTransition);
}
static inline void Install_L(Act_L* a, Sel_L* sel, Rate_L* r)
{
    int out;
    Y_L y;
    V4_L vec;
    V4_L rate;
    Ev_L e1;
    Ev_L e2;
    Sys_L* sys = &a->sys;
    Anim_L* an = &sys->anim;
    a->sys.anim.v.x = r->x;
    a->sys.anim.v.y = r->y;
    a->sys.anim.v.z = r->z;
    a->sys.anim.v.w = r->w;
    a->sys.anim.b5 = 1;
    cSkaPlaybackGroupId_ctor_int(&y, -1);
    cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(sel, &out, &y, an->model);
    if (out) {
        V4_L* p;
        if (an->b5)
            p = &an->v;
        else
            p = cSkaCrossFadeDuration_ctor_float(&rate, cSkaAnimationSet_DefaultCrossFadeDuration(an->model));
        cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&vec, p);
        an->b5 = 0;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        cSkaRequestStream_AddRequest(an, out, cSkaRequestStream_AnimationPacket_GetInstruction(sel), &vec, &y, &e1, &e2, cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(sel), cSkaRequestStream_AnimationPacket_GetDuration(sel), func_0018A2C0(sel));
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void Inst2_L(Act_L* a, Sel_L* sel, Rate_L* r) { Install_L(a, sel, r); }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
static inline void Bind_L(Act_L* a, void* o, Msg_L* msg, int idx)
{
    char* s = (char*)a->s3310;
    if (s) {
        Plc_L t;
        void* p;
        void* m;
        Plc_L* pp = &msg->plc;
        *cArray_FixedSize_cGOBJPtr_3_opIndex(s + 0x1F0, idx) = o;
        cQuatVec_opAssign(cArray_FixedSize_cQuatVec_3_opIndex(s + 0x200, idx), pp);
        p = o ? cGOBJ_GetXform_void(o) : 0;
        if (p) m = cXform_GetMatrix(p); else m = cMatrix_GetUnit();
        cQuatVec_opAssign(cArray_FixedSize_cQuatVec_3_opIndex(s + 0x260, idx), cQuatVec_ctor_cMatrixR(&t, m));
        *func_00195DB0(s + 0x2C0, idx) = 1;
    }
}
static inline void BindW_L(Act_L* a, void* o, Msg_L* msg, int idx) { Bind_L(a, o, msg, idx); }
static inline void GetPlc_L(Plc_L* pplc, Msg_L* msg, int* pt)
{
        void* obj;
        void* parent;
        Plc_L* src;
        Plc_L t7B0;
        Plc_L t790;
        obj = opNe_cObjectIdR_cObjectIdR(&msg->id, (int*)cObjectId_ctor_uint(pt, -1)) != 0 ? nGobjManager_LookupGOBJ_cObjectIdR(&msg->id) : 0;
        parent = obj ? cGOBJ_GetXform_void(obj) : 0;
        if (parent) {
            cQuatVec_Copy_Transform(&t790, &msg->plc, cQuatVec_ctor_cMatrixR(&t7B0, cXform_GetMatrix(parent)));
            src = &t790;
        } else {
            src = &msg->plc;
        }
        cQuatVec_ctor_cQuatVecR(pplc, src);
}
static inline void GetPlcW_L(Plc_L* pplc, Msg_L* msg, int* pt) { GetPlc_L(pplc, msg, pt); }
static inline int FindAnchor_L(Act_L* actor, Name_L* key)
{
    It_L it;
    It_L end;
    Lib_L* lib = (Lib_L*)actor->sys.lib;
    cAssocArray_cString16N_3_int_Find(&it, &lib->tree, key);
    cAssocArray_cString16N_3_int_End(&end, &lib->tree);
    return cAssocArray_cString16N_3_int_ConstIterator_opNe(&it, &end) ? *cAssocArray_cString16N_3_int_ConstIterator_opMul(&it) : 0;
}
static inline int FindAnchorW_L(Act_L* actor, Name_L* key) { return FindAnchor_L(actor, key); }
static inline int FindAnchorW2_L(Act_L* actor, Name_L* key) { return FindAnchorW_L(actor, key); }
static inline int FindAnchorW3_L(Act_L* actor, Name_L* key) { return FindAnchorW2_L(actor, key); }
static inline void BlkB_L(Act_L* actor, int anchor, int tok)
{
    Rate_L r;
    X_L x;
    X_L* px;
    XInit_L(&x);
    px = Set5_L(&x, tok, 0x5E, 0x5F, 0x60, 0x61, actor);
    {
        Sel_L sel;
        Sel_L* ps = &sel;
        ps->mode = 1;
        cString16N_3_ctor_void(ps->sub);
        ps->f40 = anchor;
        ps->f48 = 1;
        cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&ps->x, px);
        ps->f98 = -1.0f;
        ps->f9C = 0;
        RateDef_L(&r);
        Inst2_L(actor, &sel, &r);
        XDtorN_L((X_L*)((char*)&sel + 0x4C));
    }
    XDtor_L(&x);
}
static inline void BlkC_L(Act_L* actor)
{
    Rate_L r;
    X_L x;
    XInit_L(&x);
    {
        Sel_L sel;
        Sel_L* ps = &sel;
        int id = actor->f326C;
        ps->mode = 2;
        cString16N_3_ctor_void(ps->sub);
        ps->f44 = id;
        ps->f48 = 0;
        cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&ps->x, &x);
        ps->f98 = -1.0f;
        ps->f9C = 0;
        RateDef_L(&r);
        Inst2_L(actor, &sel, &r);
        XDtorN_L((X_L*)((char*)&sel + 0x4C));
    }
    XDtor_L(&x);
}
static inline void Send24_L(Act_L* actor) {
    Ev2_L m;
    Ev2_L* p = &m;
    cMessage_ctor_cMessageNameR(p, g_ActorActionMsgClass);
    p->vtable = D_004E0840;
    p->f24 = 0x24;
    p->f28 = 0;
    QueueMessage_cMessageR_cSystemP_int(p, actor, 1);
    m.vtable = D_004E0840;
    cMessage_dtor(p, 0);
}
static inline bool Busy_L(Act_L* a) { bool b; unsigned char s = a->GetState(); b = true; if (s != 3 && s != 2) b = false; return b; }
static inline int PBit_L(Pri_L* p, int n) { return (p->bits >> n) & 1; }
static inline float Cur_L(Act_L* a) { char* an = (char*)&a->sys; return cSkaParams_GetSliderValue(an + 0x10, 0x15); }
#define Near_L(a, bit) ((((a)->f3248 >> (bit)) & 1) && Cur_L(a) < 0.15f)

extern "C" void cHuman_HandleGetOffLadderMessage(Act_L* actor0, Msg_L* msg)
{
    Act_L* actor = actor0;
    switch (msg->type) {
    case 14: {
        void* o2;
        Root_L* s1;
        int anchor;
        int tm1[1];
        int t;
        Plc_L plc;
        int tok;
        if (Busy_L(actor)) return;
        anchor = msg->flags;
        GetPlcW_L(&plc, msg, &t);
        tm1[0] = -1;
        o2 = IdNe_L(&msg->id, tm1) ? nGobjManager_LookupGOBJ_cObjectIdR(&msg->id) : 0;
        s1 = actor->r3294;
        cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(s1, &plc);
        s1->f160 = 0;
        BindW_L(actor, o2, msg, 1);
        switch (msg->act) { case 0x20: tok = 0x62; break; default: tok = 0x5D; break; }
        BlkB_L(actor, anchor, tok);
        BlkC_L(actor);
        break;
    }
    case 0: {
        int sel;
        Pri_L* pr;
        if (actor->b31B6) return;
        pr = &actor->pri;
        if (pr->top != 0x10) return;
        { int bits = pr->bits; if ((bits >> 12) & 1) return; if ((bits >> 15) & 1) return; }
        sel = -1;
        if (msg->act == 0x23) {
            sel = 0x23;
        } else if (((actor->s3310 && actor->s3310->b9A0) || Near_L(actor, 26)) && (msg->act == 0x20 || msg->act == 0x1E)) {
            sel = 0x20;
        } else if (((actor->s3310 && actor->s3310->b99E) || Near_L(actor, 25)) && (msg->act == 0x1F || msg->act == 0x1E)) {
            sel = 0x1F;
        } else if (actor->s3310 && actor->s3310->b99F) {
            if (actor->s3310->b9A1 && (msg->act == 0x21 || msg->act == 0x1E))
                sel = 0x21;
            else if (actor->s3310 && actor->s3310->b9A2 && (msg->act == 0x22 || msg->act == 0x1E))
                sel = 0x22;
        }
        if ((signed char)sel == 0x23) {
            if (actor->s3310 && actor->s3310->b9A4) Send24_L(actor);
        } else if ((signed char)sel != -1) {
            Name_L name;
            signed char kind;
            actor->b31B6 = 1;
            QZero_L(&name);
            kind = -1;
            switch ((signed char)sel) {
            case 0x23:
                if (cHuman_ShouldLeftHandBeGraspingTheHigherRung(actor, 1)) NameAssign_L(&name, D_004C3470); else NameAssign_L(&name, D_004C3490);
                kind = 8;
                break;
            case 0x20:
                if (cHuman_ShouldLeftHandBeGraspingTheHigherRung(actor, 1)) NameAssign_L(&name, D_004C34B0); else NameAssign_L(&name, D_004C34D0);
                kind = 4;
                break;
            case 0x1F:
                if (cHuman_ShouldLeftHandBeGraspingTheHigherRung(actor, 1)) NameAssign_L(&name, D_004C34F0); else NameAssign_L(&name, D_004C3510);
                kind = 2;
                break;
            case 0x21:
            case 0x22:
                if ((signed char)sel == 0x21) {
                    if (cHuman_ShouldLeftHandBeGraspingTheHigherRung(actor, 1)) NameAssign_L(&name, D_004C3530); else NameAssign_L(&name, D_004C3550);
                } else if ((signed char)sel == 0x22) {
                    if (cHuman_ShouldLeftHandBeGraspingTheHigherRung(actor, 1)) NameAssign_L(&name, D_004C3570); else NameAssign_L(&name, D_004C3590);
                }
                kind = 3;
                break;
            }
            actor->f3514 = FindAnchorW3_L(actor, &name);
            actor->b3518 = kind;
        }
        break;
    }
    }
}
#pragma pop
#undef cSkaParams_GetSliderValue /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00472E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00472E10 */

/* merge_units: begin NetMsgThrottle_474050 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off

typedef struct { char pad[0x28]; int f28; int bits[1]; char pad30[0x988 - 0x30]; float f988; float p98C; float f990; float p994; float f998; char pad99C[2]; unsigned char b99E; unsigned char b99F; unsigned char b9A0; unsigned char b9A1; unsigned char b9A2; char pad9A3; unsigned char b9A4; } Rung_L_gThrottle_474050;


struct Act_L_gThrottle_474050 {
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
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual unsigned char GetState();
    char pad4[0x2EC0 - 4];
    Sys_L sys; char pad2EF4_[0x31B5 - 0x2EC0 - sizeof(Sys_L)];
    unsigned char b31B5;
    unsigned char b31B6; char pad31B7[0x31D8 - 0x31B7];
    float f31D8; char pad31DC[0x3208 - 0x31DC];
    int f3208;
    Pri_L pri; char pad3214[0x3248 - 0x3214];
    int f3248; char pad324C[0x326C - 0x324C];
    int f326C; char pad3270[0x3294 - 0x3270];
    Root_L* r3294;
    void* r3298; char pad329C[0x3310 - 0x329C];
    Rung_L_gThrottle_474050* s3310; char pad3314[0x3514 - 0x3314];
    int f3514;
    signed char b3518;
};

extern "C" {
#if 0 /* merge_units */
float cSkaParams_GetSliderValue(void* p, int i);
#endif /* merge_units */
#define cSkaParams_GetSliderValue(a0, a1) (cSkaParams_GetSliderValue((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
int cHuman_ShouldLeftHandBeGraspingTheHigherRung(Act_L_gThrottle_474050* a, int f);
#endif /* merge_units */
#define cHuman_ShouldLeftHandBeGraspingTheHigherRung(a0, a1) (cHuman_ShouldLeftHandBeGraspingTheHigherRung((Act_L *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void* m, void* t, int f);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

}static inline void NameAssignT_L(Name_L* dst, Name_L* tmp, char* src) {
    unsigned char ckc_end = 0; int ckc_i = 0; char ckc_c;
    for (; ckc_i < 0x2F; ckc_i++) { if (src[ckc_i] == 0) ckc_end = 1; if (ckc_end) ckc_c = 0; else ckc_c = src[ckc_i]; tmp->c[ckc_i] = ckc_c; }
    tmp->c[ckc_i] = 0;
    if (dst->c[0] || tmp->c[0]) QCopyA_L(dst, tmp); }
static inline X_L* XSet0_L(X_L* x, int id, void* a, unsigned char k) { x->pairs[0].id = id; x->pairs[0].a = a; x->kind = k; return x; }
static inline X_L* Set5b_L(X_L* x, int a, int b, int c, int d, int e, void* act)
{
    return XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSet0_L(x, a, act, 1), 1, b, act, 1), 3, c, act, 1), 5, d, act, 1), 6, e, act, 1);
}
static inline void Install_L_gThrottle_474050(Act_L_gThrottle_474050* a, Sel_L* sel, Rate_L* r)
{
    int out;
    Y_L y;
    V4_L vec;
    V4_L rate;
    Ev_L e1;
    Ev_L e2;
    Sys_L* sys = &a->sys;
    Anim_L* an = &sys->anim;
    a->sys.anim.v.x = r->x;
    a->sys.anim.v.y = r->y;
    a->sys.anim.v.z = r->z;
    a->sys.anim.v.w = r->w;
    a->sys.anim.b5 = 1;
    cSkaPlaybackGroupId_ctor_int(&y, -1);
    cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(sel, &out, &y, an->model);
    if (out) {
        V4_L* p;
        if (an->b5)
            p = &an->v;
        else
            p = cSkaCrossFadeDuration_ctor_float(&rate, cSkaAnimationSet_DefaultCrossFadeDuration(an->model));
        cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&vec, p);
        an->b5 = 0;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        cSkaRequestStream_AddRequest(an, out, cSkaRequestStream_AnimationPacket_GetInstruction(sel), &vec, &y, &e1, &e2, cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(sel), cSkaRequestStream_AnimationPacket_GetDuration(sel), func_0018A2C0(sel));
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void Inst2_L_gThrottle_474050(Act_L_gThrottle_474050* a, Sel_L* sel, Rate_L* r) { Install_L_gThrottle_474050(a, sel, r); }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
static inline void Bind_L_gThrottle_474050(Act_L_gThrottle_474050* a, void* o, Msg_L* msg, int idx)
{
    char* s = (char*)a->s3310;
    if (s) {
        Plc_L t;
        void* p;
        void* m;
        Plc_L* pp = &msg->plc;
        *cArray_FixedSize_cGOBJPtr_3_opIndex(s + 0x1F0, idx) = o;
        cQuatVec_opAssign(cArray_FixedSize_cQuatVec_3_opIndex(s + 0x200, idx), pp);
        p = o ? cGOBJ_GetXform_void(o) : 0;
        if (p) m = cXform_GetMatrix(p); else m = cMatrix_GetUnit();
        cQuatVec_opAssign(cArray_FixedSize_cQuatVec_3_opIndex(s + 0x260, idx), cQuatVec_ctor_cMatrixR(&t, m));
        *func_00195DB0(s + 0x2C0, idx) = 1;
    }
}
static inline void BindW_L_gThrottle_474050(Act_L_gThrottle_474050* a, void* o, Msg_L* msg, int idx) { Bind_L_gThrottle_474050(a, o, msg, idx); }
static inline int FindAnchor_L_gThrottle_474050(Act_L_gThrottle_474050* actor, Name_L* key)
{
    It_L it;
    It_L end;
    Lib_L* lib = (Lib_L*)actor->sys.lib;
    cAssocArray_cString16N_3_int_Find(&it, &lib->tree, key);
    cAssocArray_cString16N_3_int_End(&end, &lib->tree);
    return cAssocArray_cString16N_3_int_ConstIterator_opNe(&it, &end) ? *cAssocArray_cString16N_3_int_ConstIterator_opMul(&it) : 0;
}
static inline int FindAnchorW_L_gThrottle_474050(Act_L_gThrottle_474050* actor, Name_L* key) { return FindAnchor_L_gThrottle_474050(actor, key); }
static inline int FindAnchorW2_L_gThrottle_474050(Act_L_gThrottle_474050* actor, Name_L* key) { return FindAnchorW_L_gThrottle_474050(actor, key); }
static inline int FindAnchorW3_L_gThrottle_474050(Act_L_gThrottle_474050* actor, Name_L* key) { return FindAnchorW2_L_gThrottle_474050(actor, key); }
static inline void BlkB_L_gThrottle_474050(Act_L_gThrottle_474050* actor, int anchor, int tok)
{
    Rate_L r;
    X_L x;
    X_L* px;
    XInit_L(&x);
    px = Set5_L(&x, tok, 0x5E, 0x5F, 0x60, 0x61, actor);
    {
        Sel_L sel;
        Sel_L* ps = &sel;
        ps->mode = 1;
        cString16N_3_ctor_void(ps->sub);
        ps->f40 = anchor;
        ps->f48 = 1;
        cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&ps->x, px);
        ps->f98 = -1.0f;
        ps->f9C = 0;
        RateDef_L(&r);
        Inst2_L_gThrottle_474050(actor, &sel, &r);
        XDtorN_L((X_L*)((char*)&sel + 0x4C));
    }
    XDtor_L(&x);
}
static inline void BlkC_L_gThrottle_474050(Act_L_gThrottle_474050* actor)
{
    Rate_L r;
    X_L x;
    XInit_L(&x);
    {
        Sel_L sel;
        Sel_L* ps = &sel;
        int id = actor->f326C;
        ps->mode = 2;
        cString16N_3_ctor_void(ps->sub);
        ps->f44 = id;
        ps->f48 = 0;
        cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&ps->x, &x);
        ps->f98 = -1.0f;
        ps->f9C = 0;
        RateDef_L(&r);
        Inst2_L_gThrottle_474050(actor, &sel, &r);
        XDtorN_L((X_L*)((char*)&sel + 0x4C));
    }
    XDtor_L(&x);
}
static inline void Send24_L_gThrottle_474050(Act_L_gThrottle_474050* actor) {
    Ev2_L m;
    Ev2_L* p = &m;
    cMessage_ctor_cMessageNameR(p, g_ActorActionMsgClass);
    p->vtable = D_004E0840;
    p->f24 = 0x24;
    p->f28 = 0;
    QueueMessage_cMessageR_cSystemP_int(p, actor, 1);
    m.vtable = D_004E0840;
    cMessage_dtor(p, 0);
}

typedef struct { char c[0x20]; } __attribute__((aligned(16))) Name2_L;
typedef struct { float a; float b; signed char f; } Pr_L;

extern "C" {
extern float D_004A0410; extern float D_004A0418;
extern char D_004C35B0[]; extern char D_004C35D0[]; extern char D_004C35F0[]; extern char D_004C3610[]; extern char D_004C3630[];
extern char D_004C3650[]; extern char D_004C3670[];
void cHuman_ClearMotionSettings(Act_L_gThrottle_474050* a, int b, int c, int d, int e);
void cHuman_GetLadderMotionRequests(Act_L_gThrottle_474050* a, unsigned char* s, unsigned char* u, unsigned char* d, unsigned char* x, unsigned char* y, unsigned char* z);
#if 0 /* merge_units */
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
#endif /* merge_units */
#define cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(a0) (cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace((a0))) /* merge_units */

#if 0 /* merge_units */
float* cQuatVec_Translation(void* p);
#endif /* merge_units */
#define cQuatVec_Translation(a0) ((float *)cQuatVec_Translation((a0))) /* merge_units */

float Libc_Fmodf(float x, float y);
unsigned char cSkaParams_HasJustArrivedAtTarget(void* a, int ch, float thr);
void cHuman_HandleLadderStepEvent(Act_L_gThrottle_474050* a);
void cSkaParams_SetSliderValue_int_float(void* a, int ch, float v);
unsigned char AnimPriority_Helper3(void* p, int i);
void AnimPriority_Helper2(void* p, int i, int f);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int i, unsigned char t);
void cString16N_3_ctor_cString16NR(void* p, void* name);
void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(It_L* out, void* map, Name2_L* key);
X_L* cSkaAnimCheckpoints_ScheduleEvent(X_L* x, Pr_L* p, unsigned char id, Act_L_gThrottle_474050* a);
void cHuman_LadderClearOneRungOff(Act_L_gThrottle_474050* a);
void cHuman_LadderSetOneRungOff(Act_L_gThrottle_474050* a, bool top);
void cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(Act_L_gThrottle_474050* a, float t);
#if 0 /* merge_units */
void cHuman_DismountFromLadder(Act_L_gThrottle_474050* a);
#endif /* merge_units */
#define cHuman_DismountFromLadder(a0) (cHuman_DismountFromLadder((Lad *)(a0))) /* merge_units */

}

static inline float Min_L(float a, float b) { asm { min.s b, a, b } return b; }
static inline float Max_L(float a, float b) { asm { max.s a, a, b } return a; }
static inline float Div_L(float a, float b) { return a * (1.0f / b); }
static inline float Abs_L(float x) { float r; asm { abs.s r, x } return r; }
static inline float Clamp01_L(float x) { float lo = 0.0f; float hi = 1.0f; float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }

static inline void QCopy2_L(void* dd, void* ss) { int n = 2; __int128 q; void* s = ss; void* d = dd;
    __asm__ volatile(".set noreorder\n" "1:\n lq %0, 0(%2)\n addiu %1, %1, 0x10\n addi %3, %3, -1\n addiu %2, %2, 0x10\n bgtz %3, 1b\n sq %0, -0x10(%1)" "\n.set reorder" : "=&r"(q) : "r"(d), "r"(s), "r"(n) : "memory");
}
static inline void QZero2_L(void* dd) { int n = 2; void* d = dd;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
#define NAME_COPYN(dst, src, N) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        char* ckc_s = (src); \
        for (; ckc_i < N; ckc_i++) { \
            if (ckc_s[ckc_i] == 0) ckc_end = 1; \
            if (ckc_end) ckc_c = 0; else ckc_c = ckc_s[ckc_i]; \
            (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }
static inline void Name2AssignT_L(Name2_L* dst, Name2_L* tmp, char* src) { NAME_COPYN(tmp->c, src, 0x1F) if (dst->c[0] || tmp->c[0]) QCopy2_L(dst, tmp); }
static inline void Name2Assign_L(Name2_L* dst, char* src) { Name2_L tmp; NAME_COPYN(tmp.c, src, 0x1F) if (dst->c[0] || tmp.c[0]) QCopy2_L(dst, &tmp); }

static inline bool NB_L(int v, int n) { return (v >> n) & 1; }
static inline bool Valid_L(Rung_L_gThrottle_474050* r) { return r->f990 > -3.4028235e38f && r->f998 < 3.4028235e38f; }
static inline bool InRange_L(float t) { bool b = t > 0.5f && t < 1.5f; return b; }
static inline bool RBit_L(Rung_L_gThrottle_474050* r, int i) { bool b = (r->bits[i / 32] >> (i & 31)) & 1; return b; }
static inline void PriReset_L(Act_L_gThrottle_474050* a)
{
    char* p = (char*)&a->pri;
    unsigned char t = AnimPriority_Helper3(p + 0xC, 0xE);
    AnimPriority_Helper2(p + 4, 0xE, 0);
    AnimPriority_Helper1(p);
    AnimPriority_Helper0(p, 0xE, t);
}
static inline void RungScan_L(Act_L_gThrottle_474050* a, int set)
{
    Rung_L_gThrottle_474050* r = a->s3310;
    if (r) {
        int i;
        if (set) r->bits[0] |= 0x100; else r->bits[0] &= ~0x100;
        for (i = 0xC; i >= 0 && !RBit_L(r, i); i--) {}
        if (!RBit_L(r, i)) r->f28 = -1; else r->f28 = i;
    }
}
static inline void RateM_L(Rate_L* r, float d)
{
    float z = 0.0f;
    r->x = d;
    r->y = Min_L(-d, d);
    r->z = z != r->x ? 1.0f / r->x : 3.4028235e38f;
    r->w = Recip_L(r->y);
}
static inline void InstallS_L(Sys_L* sys, Sel_L* sel, Rate_L* r)
{
    int out;
    Y_L y;
    V4_L vec;
    V4_L rate;
    Ev_L e1;
    Ev_L e2;
    Anim_L* an = &sys->anim;
    sys->anim.v.x = r->x;
    sys->anim.v.y = r->y;
    sys->anim.v.z = r->z;
    sys->anim.v.w = r->w;
    sys->anim.b5 = 1;
    cSkaPlaybackGroupId_ctor_int(&y, -1);
    cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(sel, &out, &y, an->model);
    if (out) {
        V4_L* p;
        if (an->b5)
            p = &an->v;
        else
            p = cSkaCrossFadeDuration_ctor_float(&rate, cSkaAnimationSet_DefaultCrossFadeDuration(an->model));
        cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&vec, p);
        an->b5 = 0;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        cSkaRequestStream_AddRequest(an, out, cSkaRequestStream_AnimationPacket_GetInstruction(sel), &vec, &y, &e1, &e2, cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(sel), cSkaRequestStream_AnimationPacket_GetDuration(sel), func_0018A2C0(sel));
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
struct ItC_L { int n; ItC_L() {} ItC_L(const ItC_L& o) : n(o.n) {} };
static inline X_L* MakeX_L(X_L* x, unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, Act_L_gThrottle_474050* act)
{
    XInit_L(x);
    return Set5_L(x, a, b, c, d, e, act);
}
static inline float ClampZ_L(float x, float z, float o) { float lo = z; float hi = o; float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline void PrInitZ_L(Pr_L* p, float t, float z, float o) { p->f = 0; p->a = p->b = ClampZ_L(t, z, o); }
static inline void PrInit_L(Pr_L* p, float v) { p->f = 0; p->a = p->b = Clamp01_L(v); }







extern "C" void cHuman_LadderMotion_NextFrame(Act_L_gThrottle_474050* actor, float dt)
{
    Sys_L* sys = &actor->sys;
    unsigned char slide, up, down, k3, k4, k5;
    ItC_L j3, j2, it;
    Pr_L p0, p1, p2, p3;
    Name_L tmp;
    Name2_L name;
    Name_L tname;
    bool none, act;
    bool nearTop, nearBot;
    cHuman_ClearMotionSettings(actor, 0, 0, 0, 0);
    if (((actor->f3248 >> 27) & 1) && !(cSkaParams_GetSliderValue(sys->f10, 0x15) < 0.6f)) {
        if (cHuman_ShouldLeftHandBeGraspingTheHigherRung(actor, 0))
            actor->f3248 |= 0x800000;
        else
            actor->f3248 |= 0x1000000;
        actor->f3248 &= ~0x8000000;
    }
    if (!((actor->pri.bits >> 12) & 1) && !((actor->pri.bits >> 15) & 1)) {
    cHuman_GetLadderMotionRequests(actor, &slide, &up, &down, &k3, &k4, &k5);
    none = !slide && !up && !down;
    act = (up && !NB_L(actor->f3248, 18)) || (down && !NB_L(actor->f3248, 19)) || (slide && !NB_L(actor->f3248, 20));
    nearTop = false;
    nearBot = false;
    if (actor->s3310 && Valid_L(actor->s3310)) {
        float y = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(actor->r3298))[2];
        Rung_L_gThrottle_474050* r = actor->s3310;
        float bot = r->f998 + D_004A0410;
        float top = r->f990;
        float dd = D_004A0418;
        float lim = 1.5f * dd;
        if (top - y < lim) {
            if (InRange_L(Libc_Fmodf(Div_L(Abs_L(top - r->f988), dd), 2.0f))) nearTop = true;
        }
        if (y - bot < lim) {
            { float h = actor->s3310->f988; if (InRange_L(Libc_Fmodf(Div_L(Abs_L(bot - h), D_004A0418), 2.0f))) nearBot = true; }
        }
    }
    if (cSkaParams_HasJustArrivedAtTarget(sys->f10, 0x15, 0.2f)) cHuman_HandleLadderStepEvent(actor);
    if ((actor->f3248 >> 20) & 1) {
        if (actor->b31B5)
            actor->f31D8 = Min_L(1.0f, actor->f31D8 + dt);
        else
            actor->f31D8 = Max_L(0.0f, actor->f31D8 - 2.0f * dt);
    } else {
        actor->f31D8 = 0.0f;
    }
    cSkaParams_SetSliderValue_int_float(sys->f10, 0x12, actor->f31D8);
    if (!((actor->pri.bits >> 13) & 1)) {
        if ((up && !nearTop && ((actor->f3248 >> 18) & 1)) || (down && !nearBot && ((actor->f3248 >> 19) & 1)) || (slide && ((actor->f3248 >> 20) & 1))) {
            actor->f3248 &= ~0x800000;
            actor->f3248 &= ~0x1000000;
            return;
        }
    }
    if ((((up && !nearTop) || (down && !nearBot)) && ((actor->pri.bits >> 13) & 1) && (!((actor->f3248 >> 22) & 1) || ((actor->f3248 >> 21) & 1)) &&
         !((actor->f3248 >> 25) & 1) && !((actor->f3248 >> 26) & 1) && !(cSkaParams_GetSliderValue(sys->f10, 0x15) <= 0.4f)) || slide) {
        signed char i0, i1, i2, i3, i4;
        signed char l, rr;
        PriReset_L(actor);
        RungScan_L(actor, 1);
        if (slide) {
            {
                Rate_L r;
                X_L x;
                X_L* px;
                NAME_COPYN(tmp.c, D_004C35B0, 0x2F)
                i0 = 0x55; i1 = 0x56; i2 = 0x57; i3 = 0x58; i4 = 0x59;
                px = MakeX_L(&x, i0, i1, i2, i3, i4, actor);
                {
                    Sel_L sel;
                    Sel_L* ps = &sel;
                    ps->mode = 0;
                    cString16N_3_ctor_cString16NR(ps->sub, &tmp);
                    ps->f48 = 1;
                    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&ps->x, px);
                    ps->f98 = -1.0f;
                    ps->f9C = 0;
                    RateM_L(&r, 0.2f);
                    InstallS_L(sys, &sel, &r);
                    XDtorN_L((X_L*)((char*)&sel + 0x4C));
                }
                XDtor_L(&x);
            }
            actor->f3248 |= 0x100000;
            actor->f3248 &= ~0x80000;
            actor->f3248 &= ~0x40000;
            cHuman_LadderClearOneRungOff(actor);
        } else {
            {
                Name2_L t0, t1, t2, t3;
                QZero2_L(&name);
                if (up) {
                    if (cHuman_ShouldLeftHandBeGraspingTheHigherRung(actor, 0)) { Name2AssignT_L(&name, &t0, D_004C35D0); l = 0x5B; rr = 0x5A; }
                    else { Name2AssignT_L(&name, &t1, D_004C35F0); l = 0x5A; rr = 0x5B; }
                    i0 = 0x50; i1 = 0x51; i2 = 0x52; i3 = 0x53; i4 = 0x54;
                } else {
                    if (cHuman_ShouldLeftHandBeGraspingTheHigherRung(actor, 0)) { Name2AssignT_L(&name, &t2, D_004C3610); l = 0x5B; rr = 0x5A; }
                    else { Name2AssignT_L(&name, &t3, D_004C3630); l = 0x5A; rr = 0x5B; }
                    i0 = 0x50; i1 = 0x51; i2 = 0x52; i3 = 0x53; i4 = 0x54;
                }
                {
                    Rate_L r;
                    X_L x;
                    X_L* px;
                    int anim;
                    X_L* q;
                    XInit_L(&x);
                    std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2((It_L*)&it, (char*)sys->lib + 0x44, &name);
                    {
                        j2 = it;
                        j3 = j2;
                        anim = *(int*)((char*)j3.n + 0x30);
                    }
                    px = Set5b_L(&x, (unsigned char)i0, (unsigned char)i1, (unsigned char)i2, (unsigned char)i3, (unsigned char)i4, actor);
                    { float lo = 0.0f; float xx = 0.9f; float z; float hi; z = lo; hi = 1.0f; p0.f = 0; asm { max.s lo, xx, lo; min.s lo, lo, hi } p0.a = p0.b = lo; { float o = 1.0f; PrInitZ_L(&p1, 0.4f, z, o); PrInitZ_L(&p2, 0.9f, z, o); PrInitZ_L(&p3, 0.4f, z, o); } }
                    q = cSkaAnimCheckpoints_ScheduleEvent(cSkaAnimCheckpoints_ScheduleEvent(cSkaAnimCheckpoints_ScheduleEvent(cSkaAnimCheckpoints_ScheduleEvent(px, &p0, l, actor), &p1, rr, actor), &p2, 0x5C, actor), &p3, 0x5C, actor);
                    {
                        Sel_L sel;
                        Sel_L* ps = &sel;
                        ps->mode = 2;
                        cString16N_3_ctor_void(ps->sub);
                        ps->f44 = anim;
                        ps->f48 = 1;
                        cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&ps->x, q);
                        ps->f98 = -1.0f;
                        ps->f9C = 0;
                        RateM_L(&r, 0.2f);
                        InstallS_L(sys, &sel, &r);
                        XDtorN_L((X_L*)((char*)&sel + 0x4C));
                    }
                    XDtor_L(&x);
                }
            }
            if (up) {
                actor->f3248 |= 0x40000;
                actor->f3248 &= ~0x80000;
            } else if (down) {
                actor->f3248 |= 0x80000;
                actor->f3248 &= ~0x40000;
            }
        }
        actor->f3248 &= ~0x800000;
        actor->f3248 &= ~0x1000000;
        cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(actor, dt);
        return;
    }
    if (((actor->pri.bits >> 14) & 1) && (((actor->f3248 >> 23) & 1) || ((actor->f3248 >> 24) & 1) || ((actor->f3248 >> 20) & 1)) &&
        (none || act || (up && nearTop) || (down && nearBot))) {
        actor->f3208 |= 1;
        PriReset_L(actor);
        RungScan_L(actor, 0);
        {
            Name_L u0, u1;
            QZero_L(&tname);
            if (cHuman_ShouldLeftHandBeGraspingTheHigherRung(actor, 0)) {
                actor->f3248 |= 0x10000;
                actor->f3248 &= ~0x20000;
                NameAssignT_L(&tname, &u0, D_004C3650);
            } else {
                actor->f3248 |= 0x20000;
                actor->f3248 &= ~0x10000;
                NameAssignT_L(&tname, &u1, D_004C3670);
            }
            {
                Rate_L r;
                X_L x;
                X_L* px;
                XInit_L(&x);
                px = Set5_L(&x, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, actor);
                {
                    Sel_L sel;
                    Sel_L* ps = &sel;
                    ps->mode = 0;
                    cString16N_3_ctor_cString16NR(ps->sub, &tname);
                    ps->f48 = 1;
                    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&ps->x, px);
                    ps->f98 = -1.0f;
                    ps->f9C = 0;
                    RateM_L(&r, 0.2f);
                    Install_L_gThrottle_474050(actor, &sel, &r);
                    XDtorN_L((X_L*)((char*)&sel + 0x4C));
                }
                XDtor_L(&x);
            }
        }
        if ((up && nearTop) || (down && nearBot)) cHuman_LadderSetOneRungOff(actor, nearBot);
        cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(actor, dt);
        return;
    }
    if (actor->b31B6) {
        actor->f3208 |= 1;
        cHuman_DismountFromLadder(actor);
        actor->b31B6 = 0;
        cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(actor, dt);
        return;
    }
    if ((up && ((actor->f3248 >> 25) & 1)) || (down && ((actor->f3248 >> 26) & 1))) {
        actor->f3208 |= 1;
        actor->f3248 |= 0x8000000;
        cHuman_LadderClearOneRungOff(actor);
        cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(actor, dt);
        return;
    }
    if (((down && nearBot && !((actor->f3248 >> 25) & 1)) || (up && nearTop && !((actor->f3248 >> 26) & 1))) && !((actor->f3248 >> 21) & 1) && ((actor->pri.bits >> 13) & 1)) {
        actor->f3208 |= 1;
        cHuman_LadderSetOneRungOff(actor, nearBot);
        cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(actor, dt);
        return;
    }
    if (!((actor->pri.bits >> 14) & 1)) {
        actor->f3208 |= 1;
        cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(actor, dt);
    }
    } else {
        if (!((actor->pri.bits >> 12) & 1) && !((actor->f3248 >> 21) & 1)) cHuman_InterpolateLadderAnchorPositionTowardNearestRung_And_TriggerGettingOffIfNecessary(actor, dt);
    }
}
#pragma pop
#undef cSkaParams_GetSliderValue /* merge_units */
#undef cHuman_ShouldLeftHandBeGraspingTheHigherRung /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace /* merge_units */
#undef cQuatVec_Translation /* merge_units */
#undef cHuman_DismountFromLadder /* merge_units */
static inline void merge_flush_NetMsgThrottle_474050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end NetMsgThrottle_474050 */
