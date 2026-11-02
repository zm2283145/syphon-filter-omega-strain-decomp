/* cHuman::HandleJumpInit(const nMSGLIB::cCharActionMsg&) (human.cc) */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"

typedef struct { float x, y, z, w; } V4_L;
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_L;
typedef struct { char c[0x20]; } __attribute__((aligned(16))) Name2_L;
typedef struct { float q[4]; float p[4]; } __attribute__((aligned(16))) Plc_L;
typedef struct { float v[4]; } __attribute__((aligned(16))) Q16_L;
typedef struct { int id; void* a; } Pair_L;
typedef struct { unsigned char kind; char pad[3]; Pair_L pairs[7]; char tail[0x10]; } X_L;
typedef struct { float x, y, z, w; } Rate_L;
typedef struct { void* model; char pad4; unsigned char b5; char pad6[2]; V4_L v; } Anim_L;
typedef struct { char* lib; char pad4[0x30]; Anim_L anim; } Sys_L;
typedef struct { int a, b; } Y_L;
typedef struct { char pad[0x40]; } Ev_L;
typedef struct { float lo, hi; unsigned char flag; } Range_L;
typedef struct { int a, b; } P2_L;
typedef struct { char pad[0x14]; } Rec_L;
typedef struct { char pad[0x160]; int f160; } Root_L;
class Ctl_L { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsActive(); };
typedef struct { unsigned char type; char pad[0xF]; Plc_L plc; } Jump_L;
class Act_L { public:
    VPAD32(a) virtual void* GetBox(); VPAD16(b) VPAD4(c) VPAD1(d) virtual void GetPosition(); VPAD8(e) VPAD1(f) virtual unsigned char GetState();
    char pad4[0x10];
    unsigned char b14; char pad15[0x58 - 0x15];
    Ctl_L* ctl; char pad5C[0x2EC0 - 0x5C];
    Sys_L sys; char pad2EF4_[0x31DD - 0x2EC0 - sizeof(Sys_L)];
    unsigned char sex; char pad31DE[0x320C - 0x31DE];
    int prio; char pad3210[0x3248 - 0x3210];
    int flags; char pad324C[0x3290 - 0x324C];
    Root_L* r3290; Root_L* r3294; char pad3298[0x3490 - 0x3298];
    Jump_L jump;
};
typedef struct {
    void* vt; int f4, f8, fC, f10, f14, f18, f1C; signed char f20; char pad21[3];
    int action; signed char paramType; char pad29[7];
    Q16_L vec;
} Msg_L;
typedef struct { void* vt; char pad4[0x20]; int f24; unsigned char f28; char pad29[3]; int f2C; unsigned char f30; char pad31[3]; int f34; char pad38[8]; } AMsg_L;

extern "C" {
extern unsigned char g_IsMultiplayer;
extern signed char D_004EEF18; extern char D_004EEF20[];
extern signed char D_004EEF50; extern char D_004EEF60[];
extern char D_0049DD70[]; extern char D_0049DDA0[]; extern char D_0049DAC0[];
extern char D_0049DDD0[]; extern char D_0049DDF0[]; extern char D_0049DE10[]; extern char D_0049DE30[];
extern char D_004DFD80[]; extern char D_004E0840[]; extern char D_004E0140[];
extern char D_00542B60[]; extern char D_004DA930[];
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(Root_L* r);
float* cQuatVec_Translation(void* p);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
X_L* cSkaAnimCheckpoints_ScheduleEvent(X_L* x, Range_L* r, int a, void* b);
Range_L* cSkaTimeSpan_Normalized_ctor_float_float_bool(Range_L* r, float lo, float hi, unsigned char f);
int cSkaAnimationSet_GetNode_cString16NR(char* lib, char* n);
void cSkaAnimEndedMessage_ctor_void(Ev_L* e);
void cSkaAnimEndedMessage_dtor(void* p, int f);
void* func_0018C6A0(Sys_L* s);
void nSka_GetPlaybackGroupId(Y_L* y, int m);
void cSkaRequestStream_AddRequest(void* ctl, int id, signed char mode, void* range, void* pair, const AMsg_L& m1, const AMsg_L& m2, void* x, float f0, float f1);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
unsigned char AnimPriority_Helper3(void* bits, int index);
void AnimPriority_Helper2(void* p, int index, int v);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* t, int f);
void cMessage_dtor(void* m, int f);
float Libc_Cosf(float);
float Libc_Sinf(float);
float Math_Clampf(float v, float lo, float hi);
void cSkaAnimEvent_ctor_char_cSystemR(P2_L* p, int a, void* b);
void func_00191040(Rec_L* d, Range_L* r, P2_L* p);
void cArray_cTimedEvent_PushBackActual(void* v, Rec_L* r);
void cSkaAnimCheckpoints_cTimedEvent_dtor(Rec_L* r, int f);
void* cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(void* it, void* arr, Name2_L* n);
int** cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(void* it);
void cMessage_ctor_cMessageNameR(void* m, void* name);
void cHuman_HandleJumpInit(Act_L* self, Msg_L* msg);
}

/* 0x20-byte quadword zero / copy idioms (sq/lq loops) */
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
static inline void QCopy2_L(void* d0, void* s0) { int n = 2; void* s = s0; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq $a0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $a0, -0x10(d)
        .set reorder
    }
}
static inline void QCpR_L(void* d, const void* s) { void* pd = d; const void* ps = s; __int128 q; asm volatile { .set reorder; lq q, 0(ps); sq q, 0(pd) } }
static inline void QCpT_L(void* d, const void* s) { const void* ps = s; asm volatile { lq ps, 0(ps); sq ps, 0(d) } }
static inline void QCp1_L(void* d, const void* s) { void* pd = d; const void* ps = s; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }

/* bounded name copy; the empty asm is a scheduling barrier that keeps retail's branch shape */
#define NAME_COPY_LEN(dst, src, len) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        char* ckc_s = (src); \
        for (; ckc_i < (len); ckc_i++) { \
            if (ckc_s[ckc_i] == 0) ckc_end = 1; \
            ckc_c = 0; \
            if (ckc_end) asm { .set reorder } else ckc_c = ckc_s[ckc_i]; \
            (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }

/* max.s/min.s have no C equivalent */
static inline float Recip_L(float v) { return v != 0.0f ? 1.0f / v : 3.4028235e38f; }
static inline float ClampZ_L(float x, float z, float o) { float lo = z; float hi = o; float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float ClampQ_L(float x) { float r = 0.0f; float lo = 0.0f; float hi = 1.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline void RangeInitQ_L(Range_L* r, float t) { r->flag = 0; r->lo = r->hi = ClampQ_L(t); }
static inline void RangeInitZ_L(Range_L* r, float t) { r->flag = 0; r->lo = r->hi = ClampZ_L(t, 0.0f, 1.0f); }
static inline void RangeTS_L(Range_L* r, float lo, float hi, unsigned char f, float z, float o)
{
    r->lo = lo; r->hi = hi; r->flag = f;
    if (r->flag) r->hi = Math_Clampf(r->hi, z, o); else r->hi = Math_Clampf(r->hi, r->lo, o);
    if (r->flag) r->lo = Math_Clampf(r->lo, 0.0f, 1.0f); else r->lo = Math_Clampf(r->lo, 0.0f, r->hi);
}
static inline void RangeInit2_L(Range_L* r, float lo, float hi, unsigned char f)
{
    r->lo = lo; r->hi = hi; r->flag = f;
    if (r->flag) r->hi = Math_Clampf(r->hi, 0.0f, 1.0f); else r->hi = Math_Clampf(r->hi, r->lo, 1.0f);
    if (r->flag) r->lo = Math_Clampf(r->lo, 0.0f, 1.0f); else r->lo = Math_Clampf(r->lo, 0.0f, r->hi);
}

static inline void XInit_L(X_L* x) { x->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(x->pairs); cArray_cTimedEvent_ctor_void(x->tail); }
static inline X_L* XSetR_L(X_L* x, int i, int id, void* a, unsigned char k) { Pair_L* p = &x->pairs[i]; p->id = id; p->a = a; x->kind = k; return x; }
static inline void XDtor_L(X_L* x) { func_001BE5A0(x->tail, 0); __destroy_array(x->pairs, (void*)func_0018A210, 8, 7); }
static inline X_L* XSetN_L(X_L* x, int i, int id, void* a, unsigned char k) { x->pairs[i].id = id; x->pairs[i].a = a; x->kind = k; return x; }
static inline X_L* Set5_L(X_L* x, int a, int b, int c, int d, int e, void* act)
{
    return XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetN_L(x, 0, a, act, 1), 1, b, act, 1), 3, c, act, 1), 5, d, act, 1), 6, e, act, 1);
}
static inline X_L* Set5N_L(X_L* x, int a, int b, int c, int d, int e, void* act)
{
    return XSetN_L(XSetN_L(XSetN_L(XSetN_L(XSetN_L(x, 0, a, act, 1), 1, b, act, 1), 3, c, act, 1), 5, d, act, 1), 6, e, act, 1);
}
static inline X_L* Set4_L(X_L* x, int a, int c, int d, int e, void* act)
{
    return XSetR_L(XSetR_L(XSetR_L(XSetR_L(x, 0, a, act, 1), 3, c, act, 1), 5, d, act, 1), 6, e, act, 1);
}
static inline void RateC2_L(Rate_L* r) { r->x = 0.2f; r->y = 0.2f; r->z = 5.0f; r->w = 5.0f; }
static inline void RateC_L(Rate_L* r) { r->x = 0.2f; r->y = 0.2f; r->z = 5.0f; r->w = 5.0f; }
static inline void RateV_L(Rate_L* r)
{
    float d = 0.2f;
    r->x = d;
    r->y = d;
    r->z = Recip_L(d);
    r->w = Recip_L(d);
}
static inline void Play0_L(Sys_L* sys, int m, int mode, Rate_L* r, X_L* px)
{
    if (m) {
        Ev_L e1;
        Ev_L e2;
        Y_L y;
        void* ctl;
        cSkaAnimEndedMessage_ctor_void(&e1);
        cSkaAnimEndedMessage_ctor_void(&e2);
        ctl = func_0018C6A0(sys);
        nSka_GetPlaybackGroupId(&y, m);
        cSkaRequestStream_AddRequest(ctl, m, mode, r, &y, *(AMsg_L*)&e1, *(AMsg_L*)&e2, px, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void Play1_L(Sys_L* sys, int m, int mode, Rate_L* r, X_L* px) { Play0_L(sys, m, mode, r, px); }
static inline void RateC1_L(Rate_L* r) { r->x = 0.2f; r->y = 0.2f; r->z = 5.0f; r->w = 5.0f; }
static inline X_L* SetX_L(X_L* x, int a, int b, int c, int d, int e, void* act) { return XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetN_L(x, 0, a, act, 1), 1, b, act, 1), 3, c, act, 1), 5, d, act, 1), 6, e, act, 1); }
static inline void Play_L(Sys_L* sys, int m, int mode, Rate_L* r, X_L* px) { Play1_L(sys, m, mode, r, px); }
static inline void Prio_L(int* pp, signed char k, int v)
{
    char* q = (char*)pp;
    unsigned char on;
    on = AnimPriority_Helper3(q + 0xC, k);
    AnimPriority_Helper2(q + 4, k, v);
    AnimPriority_Helper1(q);
    AnimPriority_Helper0(q, k, on);
}
static inline void AddI0_L(X_L* x, Range_L* r, int k, void* a)
{
    P2_L p;
    Rec_L rec;
    cSkaAnimEvent_ctor_char_cSystemR(&p, k, a);
    func_00191040(&rec, r, &p);
    cArray_cTimedEvent_PushBackActual(x->tail, &rec);
    cSkaAnimCheckpoints_cTimedEvent_dtor(&rec, -1);
    func_0018A210(&p, -1);
}
static inline void AddI1_L(X_L* x, Range_L* r, int k, void* a) { AddI0_L(x, r, k, a); }
static inline void AddI_L(X_L* x, Range_L* r, int k, void* a) { AddI1_L(x, r, k, a); }
static inline void NameAssign2_L(Name2_L* dst, char* src) { Name2_L tmp; NAME_COPY_LEN(tmp.c, src, 0x1F) if (dst->c[0] || tmp.c[0]) QCopy2_L(dst, &tmp); }
static inline void AMsgInit_L(AMsg_L* m)
{
    cMessage_ctor_cMessageNameR(m, D_00542B60);
    m->vt = D_004DA930;
    m->f24 = 0; m->f28 = 0; m->f2C = 0; m->f30 = 0; m->f34 = 0;
}
static inline void AMsgDtor_L(AMsg_L* m) { m->vt = D_004DA930; cMessage_dtor(m, 0); }
static inline void AddR_L(void* s, int* b, signed char mode, void* r, const AMsg_L& m1, const AMsg_L& m2, void* x, float f0, float f1) { void* pg = b + 1; cSkaRequestStream_AddRequest(s, b[0], mode, r, pg, m1, m2, x, f0, f1); }
static inline void Blend_L(Act_L* self, X_L* x, Name2_L* name, int mode, Rate_L* r)
{
    char it[4];
    AMsg_L e1;
    AMsg_L e2;
    int* blend;
    Sys_L* sys;
    X_L* xx;
    AMsg_L* p1;
    AMsg_L* p2;
    xx = x;
    cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(it, self->sys.lib + 0x44, name);
    blend = *cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(it);
    sys = &self->sys;
    p1 = &e1;
    AMsgInit_L(p1);
    p2 = &e2;
    AMsgInit_L(p2);
    AddR_L(&sys->anim, blend, mode, r, e1, e2, xx, -1.0f, 0.0f);
    AMsgDtor_L(&e2);
    AMsgDtor_L(&e1);
}
static inline void BlendS_L(Act_L* self, X_L* x, Name2_L* name, int mode, Rate_L* r, Sys_L*& sys, int*& blend)
{
    char it[4];
    AMsg_L e1;
    AMsg_L e2;
    X_L* xx;
    AMsg_L* p1;
    AMsg_L* p2;
    cAssocArray_cString16N_2_cSkaAnimationBlendPtr_Find(it, self->sys.lib + 0x44, name);
    blend = *cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ConstIterator_opMul(it);
    sys = &self->sys;
    xx = x;
    p1 = &e1;
    AMsgInit_L(p1);
    p2 = &e2;
    AMsgInit_L(p2);
    AddR_L(&sys->anim, blend, mode, r, e1, e2, xx, -1.0f, 0.0f);
    AMsgDtor_L(&e2);
    AMsgDtor_L(&e1);
}
static inline unsigned char IsDying_L(Act_L* a)
{
    unsigned char r; unsigned char s = a->GetState();
    r = 1;
    if (s != 3 && s != 2) r = 0;
    return r;
}
static inline unsigned char IsActive_L(Act_L* a)
{
    unsigned char r = 0;
    Ctl_L* c = a->ctl;
    if (c && c->IsActive()) r = 1;
    return r;
}

static inline void MsgCopy_L(Msg_L* pc, const Msg_L* m)
{
    asm volatile { nop }
    __int128* pd = (__int128*)&pc->vec; const __int128* ps = (const __int128*)&m->vec;
    pc->vt = D_004DFD80;
    pc->f4 = m->f4; pc->f8 = m->f8; pc->fC = m->fC; pc->f10 = m->f10;
    pc->f14 = m->f14; pc->f18 = m->f18; pc->f1C = m->f1C; pc->f20 = m->f20;
    pc->vt = D_004E0840;
    pc->action = m->action; pc->paramType = m->paramType;
    pc->vt = D_004E0140;
    *pd = *ps;
}
static inline float HalfW_L(const Q16_L& v) { return 0.5f * v.v[3]; }
static inline void V4Set_L(Q16_L* p, float x, float y, float z, float w) { p->v[0] = x; p->v[1] = y; p->v[2] = z; p->v[3] = w; }
static inline void QAA_L(Q16_L* q, const Q16_L* axis, float angle)
{
    float half = 0.5f * angle;
    float c = Libc_Cosf(half);
    float s = Libc_Sinf(half);
    q->v[3] = c;
    q->v[0] = s * axis->v[0]; q->v[1] = s * axis->v[1]; q->v[2] = s * axis->v[2];
}
static inline void CpA_L(void* d, const void* s) { void* pd = d; const void* ps = s; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
static inline void CpB_L(void* d, const void* s) { void* pd = d; const void* ps = s; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
static inline void CpA1_L(void* d, const void* s) { CpA_L(d, s); }
static inline void AsPoint0_L(Q16_L* t, const Q16_L* v) { Q16_L pos; Q16_L* p; CpA1_L(&pos, v); p = &pos; p->v[3] = 1.0f; CpB_L(t, p); }
static inline void AsPoint_L(Q16_L* t, const Q16_L* v) { AsPoint0_L(t, v); }
static inline void JumpSet_L(Jump_L* j, unsigned char type, const Plc_L* t) { j->type = type; QCp1_L(j->plc.q, t->q); QCp1_L(j->plc.p, t->p); }
#define NAME_COPY2(dst, src, len) { unsigned char ckc_end = 0; int ckc_i = 0; char ckc_c; for (; ckc_i < (len); ckc_i++) { if ((src)[ckc_i] == 0) ckc_end = 1; ckc_c = 0; if (ckc_end) asm { .set reorder } else ckc_c = (src)[ckc_i]; (dst)[ckc_i] = ckc_c; } (dst)[ckc_i] = 0; }
#define NAME_ASSIGN(dst, src) { Name2_L tmp; NAME_COPY_LEN(tmp.c, src, 0x1F) if ((dst).c[0] || tmp.c[0]) QCopy2_L(&(dst), &tmp); }

extern "C" void cHuman_HandleJumpInit(Act_L* self, Msg_L* msg)
{
    Plc_L transform;
    Name2_L takeOffAnimName;
    Name2_L inAirIdleAnimName;
    if (IsDying_L(self)) return;
    if (self->prio == 4) return;
    if (self->prio == 5) return;
    switch (msg->action) {
    case 20: {
        Root_L* ledgeAnchor;
        float ledgeHeight;
        char* pointerAnimName;
        if ((unsigned char)msg->paramType != 14) return;
        ledgeAnchor = self->r3294;
        {
            float z0 = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(self->r3290))[2];
            ledgeHeight = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(ledgeAnchor))[2] - z0;
        }
        if (ledgeHeight < 10.0f) {
            if (!D_004EEF18) { NAME_COPY_LEN(D_004EEF20, D_0049DD70, 0x2F) D_004EEF18 = 1; }
            pointerAnimName = D_004EEF20;
        } else {
            if (!D_004EEF50) { NAME_COPY_LEN(D_004EEF60, D_0049DDA0, 0x2F) D_004EEF50 = 1; }
            pointerAnimName = D_004EEF60;
        }
        JumpSet_L(&self->jump, 2, (Plc_L*)cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(ledgeAnchor));
        {
            Rate_L r;
            X_L x;
            Range_L r1;
            Range_L r2;
            int m;
            X_L* px;
            Sys_L* sys;
            X_L* p1;
            X_L* p2;
            { X_L* p0 = &x; XInit_L(p0); }
            sys = &self->sys;
            RateC1_L(&r);
            p1 = SetX_L(&x, 9, 10, 13, 14, 15, self);
            RangeInitQ_L(&r1, 0.5f);
            p2 = cSkaAnimCheckpoints_ScheduleEvent(p1, &r1, 11, self);
            px = cSkaAnimCheckpoints_ScheduleEvent(p2, cSkaTimeSpan_Normalized_ctor_float_float_bool(&r2, 0.5f, 0.7f, 0), 12, self);
            Play_L(sys, cSkaAnimationSet_GetNode_cString16NR(sys->lib, pointerAnimName), 1, &r, px);
            XDtor_L(&x);
        }
        {
            Name_L n;
            Rate_L r;
            X_L x;
            int m;
            X_L* px;
            Sys_L* sys;
            { X_L* p0 = &x; XInit_L(p0); }
            sys = &self->sys;
            RateC2_L(&r);
            px = Set4_L(&x, 16, 17, 18, 19, self);
            NAME_COPY2(n.c, D_0049DAC0, 0x2F)
            m = cSkaAnimationSet_GetNode_cString16NR(sys->lib, n.c);
            Play_L(sys, m, 0, &r, px);
            XDtor_L(&x);
        }
        Prio_L(&self->prio, 4, 1);
        self->flags |= 0x400;
        self->flags &= ~0x800;
        self->flags &= ~0x1000;
        self->flags &= ~0x2000;
        return;
    }
    case 21:
    case 22: {
        unsigned char paramsValid = 0;
        if (msg->action == 21) {
            if ((unsigned char)msg->paramType == 4) {
                if (g_IsMultiplayer && self->b14 && IsActive_L(self)) {
                    Msg_L copy;
                    { Msg_L* pc = &copy; MsgCopy_L(pc, msg); }
                    copy.f20 = 4;
                    QueueMessage_cMessageR_cSystemP_int(&copy, self, 0);
                    copy.vt = D_004E0840;
                    cMessage_dtor(&copy, 0);
                }
                self->jump.type = 1;
                QCp1_L(self->jump.plc.p, &msg->vec);
                paramsValid = 1;
            }
        } else if (msg->action == 22) {
            if ((unsigned char)msg->paramType == 4) {
                Q16_L q;
                Q16_L axis;
                Q16_L trans;
                float half;
                float c;
                float s;
                AsPoint_L(&trans, &msg->vec);
                { const Q16_L* v = &msg->vec; float ang = v->v[3]; V4Set_L(&axis, 0.0f, 0.0f, 1.0f, 0.0f); QAA_L(&q, &axis, ang); }
                QCp1_L(transform.q, &q);
                QCp1_L(transform.p, &trans);
                JumpSet_L(&self->jump, 2, &transform);
                paramsValid = 1;
            }
        }
        if (!paramsValid) return;
        Prio_L(&self->prio, 4, 1);
        if (msg->action == 21) {
            self->flags |= 0x800;
            self->flags &= ~0x1000;
        } else if (msg->action == 22) {
            self->flags |= 0x1000;
            self->flags &= ~0x800;
        }
        self->flags &= ~0x400;
        self->flags &= ~0x2000;
        QZero2_L(&takeOffAnimName);
        QZero2_L(&inAirIdleAnimName);
        if (self->sex == 1) {
            NAME_ASSIGN(takeOffAnimName, D_0049DDD0)
            NAME_ASSIGN(inAirIdleAnimName, D_0049DDF0)
        } else {
            NAME_ASSIGN(takeOffAnimName, D_0049DE10)
            NAME_ASSIGN(inAirIdleAnimName, D_0049DE30)
        }
        {
            Rate_L r;
            X_L x;
            Range_L r1;
            Range_L r2;
            Sys_L* bsys;
            int* bblend;
            X_L* px;
            { X_L* p0 = &x; XInit_L(p0); }
            px = Set5N_L(&x, 9, 10, 13, 14, 15, self);
            { float lo = 0.0f; float a = 0.8f; float o = 1.0f; float z; z = lo; r1.flag = 0; asm { max.s lo, a, lo; min.s lo, lo, o } r1.lo = r1.hi = lo; RangeTS_L(&r2, 0.8f, 0.8f, 0, z, o); }
            AddI_L(px, &r1, 11, self);
            AddI_L(px, &r2, 12, self);
            RateV_L(&r);
            BlendS_L(self, px, &takeOffAnimName, 1, &r, bsys, bblend);
            XDtor_L(&x);
        }
        {
            Rate_L r;
            X_L x;
            Sys_L* bsys;
            int* bblend;
            X_L* px;
            { X_L* p0 = &x; XInit_L(p0); }
            px = Set4_L(&x, 16, 17, 18, 19, self);
            RateV_L(&r);
            BlendS_L(self, px, &inAirIdleAnimName, 0, &r, bsys, bblend);
            XDtor_L(&x);
        }
        break;
    }
    }
}
