#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off

typedef struct { float x, y, z, w; } V4_L;
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_L;
typedef struct { float q[4]; float p[4]; } __attribute__((aligned(16))) Plc_L;
typedef struct { float v[4]; } __attribute__((aligned(16))) Q16_L;
typedef struct { int id; void* a; } Pair_L;
typedef struct { unsigned char kind; char pad[3]; Pair_L pairs[7]; char tail[0x10]; } X_L;
typedef struct { unsigned char mode; char pad1[0xF]; char sub[0x34]; int f44; unsigned char f48; char pad49[3]; X_L x; float f98; int f9C; } Sel_L;
typedef struct { float x, y, z, w; } Rate_L;
typedef struct { void* model; char pad4; unsigned char b5; char pad6[2]; V4_L v; } Anim_L;
typedef struct { void* lib; char pad4[0x30]; Anim_L anim; } Sys_L;
typedef struct { int a, b; } Y_L;
typedef struct { char pad[0x40]; } Ev_L;
typedef struct { float lo, hi; unsigned char flag; } Range_L;
typedef struct { int a, b; } P2_L;
typedef struct { char pad[0x14]; } Rec_L;
typedef struct { char pad[0x160]; int f160; } Root_L;
typedef struct { char pad[0x980]; Plc_L dummy; } S3310_L;
typedef struct {
    char pad0[0x2EC0];
    Sys_L sys; char pad2EF4_[0x320C - 0x2EC0 - sizeof(Sys_L)];
    char prio[0x326C - 0x320C];
    int f326C; char pad3270[0x3290 - 0x3270];
    Root_L* r3290; Root_L* r3294; Root_L* r3298; char pad329C[0x3310 - 0x329C];
    char* s3310;
} Act_L;
typedef struct { char pad0[0x30]; int flags; int id; char pad38[8]; Plc_L plc; } Msg_L;
typedef struct { void* vtable; char pad4[0x1C]; unsigned char kind; char pad21[0xF]; char f30[0x20]; char pad50[0x10]; } CMsg_L;

extern "C" {
extern char D_0049DE50[]; extern char D_0049DE70[]; extern char D_0049DE90[]; extern char D_0049DEB0[];
extern char D_0049DED0[]; extern char D_0049DEF0[]; extern char D_0049DD30[]; extern char D_0049DCF0[];
extern char D_0049DF00[]; extern char D_0049DF10[]; extern char D_0049DF20[];
extern char D_004E00E0[]; extern char D_004E0840[];
extern float g_DefaultMotionTransition; extern float D_004A03B8;
extern float D_0049D180; extern float D_0049D188; extern float D_0049D190;
extern signed char D_004EEF00; extern signed char D_004EEF08; extern signed char D_004EEF10;
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
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(Root_L* r);
void* cSkaAnimAnchor_GetTransform(Root_L* r);
float* cQuatVec_Translation(void* p);
void** cArray_FixedSize_cGOBJPtr_3_opIndex(void* p, int i);
void* cArray_FixedSize_cQuatVec_3_opIndex(void* p, int i);
unsigned char* func_00195DB0(void* p, int i);
void cQuatVec_opAssign(void* t, Plc_L* p);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* p);
void cArray_cTimedEvent_ctor_void(void* p);
void cString16N_3_ctor_void(void* p);
void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(void* d, void* s);
void cSkaPlaybackGroupId_ctor_int(void* p, int v);
void cString16N_3_ctor_cString16NR(void* d, Name_L* n);
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
void cSkaAnimCheckpoints_dtor(void* p, int f);
X_L* cSkaAnimCheckpoints_ScheduleEvent(X_L* x, Range_L* r, int a, void* b);
void cSkaAnimEvent_ctor_char_cSystemR(P2_L* p, int a, void* b);
void func_00191040(Rec_L* d, Range_L* r, P2_L* p);
void cArray_cTimedEvent_PushBackActual(void* v, Rec_L* r);
void cSkaAnimCheckpoints_cTimedEvent_dtor(Rec_L* r, int f);
int cSkaAnimationSet_GetNode_cString16NR(void* lib, Name_L* n);
void* func_0018C6A0(Sys_L* s);
void nSka_GetPlaybackGroupId(Y_L* y, int m);
unsigned char AnimPriority_Helper3(void* bits, int index);
void AnimPriority_Helper2(void* p, int index, int v);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void cModeSwitch_WithHistory_12_ActivateMode_uint_2(void* p, int b);
void cCharActionMsg_ctor_int_eParamType(CMsg_L* m, int a, int b);
void cInteractParams_ctor_int_cQuatVecR_cGOBJP(void* d, int a, void* p, int b);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* t, int f);
void cMessage_dtor(void* m, int f);
void cHuman_GrabLedge(Act_L* a);
}

struct Flags_L { int w[1]; Flags_L() { int i; for (i = 0; i < 1; i++) w[i] = 0; } };
static inline int IdNe_L(int* a, int* b) { return *a != *b; }
/* 0x30-byte quadword copy idiom (lq/sq loop); $a0 is the retail scratch register */
static inline void QCopyA_L(void* d0, void* s0) { int n = 3; void* s = s0; void* d = d0;
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
static inline void QCp1_L(void* d, const void* s) { const void* ss = s; void* dd = d; __int128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
/* 0x30-byte quadword zero idiom (sq $zero loop) */
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
static inline void QZeroW_L(void* d) { QZero_L(d); }

/* bounded name copy; the empty asm is a scheduling barrier that keeps retail's branch shape */
#define NAME_COPY(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        char* ckc_s = (src); \
        for (; ckc_i < 0x2F; ckc_i++) { \
            if (ckc_s[ckc_i] == 0) ckc_end = 1; \
            ckc_c = 0; \
            if (ckc_end) asm { .set reorder } else ckc_c = ckc_s[ckc_i]; \
            (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }

#define NAME_COPY_N(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i; \
        for (ckc_i = 0; ckc_i < 0x2F; ckc_i++) { \
            if ((src)[ckc_i] == 0) ckc_end = 1; \
            { char ckc_c = 0; if (ckc_end) asm { .set reorder } else ckc_c = (src)[ckc_i]; (dst)[ckc_i] = ckc_c; } \
        } \
        (dst)[ckc_i] = 0; \
    }

/* max.s/min.s have no C equivalent */
static inline float Min_L(float a, float b) { float r; asm { min.s r, a, b } return r; }
static inline float Recip_L(float v) { return v != 0.0f ? 1.0f / v : 3.4028235e38f; }

static inline void XInit_L(X_L* x) { x->kind = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(x->pairs); cArray_cTimedEvent_ctor_void(x->tail); }
static inline X_L* XSetR_L(X_L* x, int i, int id, void* a, unsigned char k) { Pair_L* p = &x->pairs[i]; p->id = id; p->a = a; x->kind = k; return x; }
static inline void XDtor_L(X_L* x) { func_001BE5A0(x->tail, 0); __destroy_array(x->pairs, (void*)func_0018A210, 8, 7); }
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
static inline void Rate2_L(Rate_L* r, float a, float b)
{
    float m;
    float z = 0.0f;
    r->x = a;
    m = Min_L(b, a);
    r->y = m;
    { float v = r->x; r->z = z != v ? 1.0f / v : 3.4028235e38f; }
    r->w = Recip_L(r->y);
}
static inline float ClampZ_L(float x, float z, float o) { float lo = z; float hi = o; float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline void RangeInitZ_L(Range_L* r, float t, float z, float o) { r->flag = 0; r->lo = r->hi = ClampZ_L(t, z, o); }
static inline float ClampY_L(float x, float z, float o) { float lo = z; float hi = o; asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }
static inline void SelName_L(Sel_L* s, Name_L* n, X_L* x, unsigned char f)
{
    s->mode = 0;
    cString16N_3_ctor_cString16NR(s->sub, n);
    s->f48 = f;
    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&s->x, x);
    s->f98 = -1.0f;
    s->f9C = 0;
}
static inline void SelAuto_L(Sel_L* s, int v, X_L* x)
{
    s->mode = 2;
    cString16N_3_ctor_void(s->sub);
    s->f44 = v;
    s->f48 = 0;
    cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&s->x, x);
    s->f98 = -1.0f;
    s->f9C = 0;
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
    cSkaAnimCheckpoints_dtor(&sel->x, -1);
}
static inline void Play_L(Sys_L* sys, int m, int mode, Rate_L* r, X_L* px)
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
        cSkaRequestStream_AddRequest(ctl, m, mode, r, &y, &e1, &e2, px, -1.0f, 0.0f);
        cSkaAnimEndedMessage_dtor(&e2, -1);
        cSkaAnimEndedMessage_dtor(&e1, -1);
    }
}
static inline void Direct_L(Act_L* a, char* name, int mode, int i0, int i1, int i3, int i5, int i6)
{
    Name_L n;
    Rate_L r;
    X_L x;
    int m;
    X_L* px;
    Sys_L* sys;
    { X_L* p0 = &x; XInit_L(p0); }
    sys = &a->sys;
    RateDef_L(&r);
    px = Set5_L(&x, i0, i1, i3, i5, i6, a);

    NAME_COPY_N(n.c, name)
    m = cSkaAnimationSet_GetNode_cString16NR(sys->lib, &n);
    Play_L(sys, m, mode, &r, px);
    XDtor_L(&x);
}
static inline void InstallW_L(Act_L* a, Sel_L* sel, Rate_L* r) { Install_L(a, sel, r); }
static inline void Auto_L(Act_L* a)
{
    Rate_L r;
    X_L x;
    Sel_L sel;
    { X_L* p0 = &x; XInit_L(p0); }
    { Sel_L* ps = &sel; SelAuto_L(ps, a->f326C, &x); }
    RateDef_L(&r);
    InstallW_L(a, &sel, &r);
    XDtor_L(&x);
}
static inline void Prio_L(char* p, signed char k, int v)
{
    char* q = p;
    unsigned char on;
    on = AnimPriority_Helper3(q + 0xC, k);
    { int kk = k; AnimPriority_Helper2(q + 4, kk, kk); }
    AnimPriority_Helper1(q);
    AnimPriority_Helper0(q, k, on);
}
static inline void Bind_L(Act_L* a, void* o, Msg_L* msg, int idx)
{
    char* s = a->s3310;
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
static inline void AddI_L(X_L* x, Range_L* r, int k, void* a)
{
    P2_L p;
    Rec_L rec;
    cSkaAnimEvent_ctor_char_cSystemR(&p, k, a);
    func_00191040(&rec, r, &p);
    cArray_cTimedEvent_PushBackActual(x->tail, &rec);
    cSkaAnimCheckpoints_cTimedEvent_dtor(&rec, -1);
    func_0018A210(&p, -1);
}

static inline void BindW_L(Act_L* a, void* o, Msg_L* msg, int idx) { Bind_L(a, o, msg, idx); }
static inline void AddW_L(X_L* x, Range_L* r, int k, void* a) { AddI_L(x, r, k, a); }
static inline void NameAssign_L(Name_L* dst, char* src) { Name_L tmp; NAME_COPY(tmp.c, src) if (dst->c[0] || tmp.c[0]) QCopyA_L(dst, &tmp); }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
static inline void Dir19_L(Act_L* actor)
{
                Name_L n;
                Rate_L r;
                X_L x;
                int m;
                X_L* px;
                Sys_L* sys;
                { X_L* p0 = &x; XInit_L(p0); }
                sys = &actor->sys;
                RateDef_L(&r);
                px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(&x, 0, 0x19, actor, 1), 3, 0x1A, actor, 1), 5, 0x1B, actor, 1), 6, 0x1C, actor, 1);
                NAME_COPY(n.c, D_0049DCF0)
                m = cSkaAnimationSet_GetNode_cString16NR(sys->lib, &n);
                Play_L(sys, m, 0, &r, px);
                XDtor_L(&x);
            }
static inline void SiteA_L(Act_L* actor, Name_L* pname)
{
{
    Rate_L r;
    X_L x;
    Sel_L sel;
    X_L* px; { X_L* p0 = &x; XInit_L(p0); } px = Set5_L(&x, 0x33, 0x34, 0x35, 0x36, 0x37, actor);
    { Sel_L* ps = &sel; SelName_L(ps, pname, px, 1); }
    RateDef_L(&r);
    InstallW_L(actor, &sel, &r);
    XDtor_L(&x);
}
}
static inline void SiteB_L(Act_L* actor)
{
    Rate_L r;
    Name_L n;
    X_L x;
    Sel_L sel;
    X_L* px; { X_L* p0 = &x; XInit_L(p0); } px = Set5_L(&x, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, actor);
    NAME_COPY_N(n.c, D_0049DF10)
    { Name_L* pn = &n; Sel_L* ps = &sel; SelName_L(ps, pn, px, 1); }
    RateDef_L(&r);
    InstallW_L(actor, &sel, &r);
    XDtor_L(&x);
}
static inline void SiteC_L(Act_L* actor, float d, float lim)
{
{
    Rate_L r;
    Name_L n;
    X_L x;
    Sel_L sel;
    X_L* px; { X_L* p0 = &x; XInit_L(p0); } px = Set5_L(&x, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, actor);
    NAME_COPY_N(n.c, D_0049DF20)
    { Name_L* pn = &n; Sel_L* ps = &sel; SelName_L(ps, pn, px, 1); }
    Rate2_L(&r, d, lim);
    InstallW_L(actor, &sel, &r);
    XDtor_L(&x);
}
}
static inline void Sel1_L(Act_L* actor, Name_L* pn, X_L* px0)
{
            Rate_L r;
            Sel_L sel;
            { Sel_L* ps = &sel; SelName_L(ps, pn, px0, 1); }
            RateDef_L(&r);
            Install_L(actor, &sel, &r);
}
static inline void Sel2_L(Act_L* actor)
{
            Rate_L r;
            Name_L n2;
            X_L x2;
            Sel_L sel;
            X_L* px;
            { X_L* p0 = &x2; XInit_L(p0); }
            px = Set5_L(&x2, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, actor);
            NAME_COPY_N(n2.c, D_0049DED0)
            { Name_L* pn = &n2; Sel_L* ps = &sel; SelName_L(ps, pn, px, 0); }
            RateDef_L(&r);
            Install_L(actor, &sel, &r);
            XDtor_L(&x2);
        }
static inline void SendCas_L(Act_L* actor)
{
        CMsg_L m;
        CMsg_L* pm;
        void* p = cSkaAnimAnchor_GetTransform(actor->r3294);
        pm = &m;
        cCharActionMsg_ctor_int_eParamType(pm, 0x14, 0xE);
        cInteractParams_ctor_int_cQuatVecR_cGOBJP(pm->f30, 0, p, 0);
        pm->vtable = D_004E00E0;
        { int one = 1; m.kind = one; QueueMessage_cMessageR_cSystemP_int(pm, actor, one); }
        m.vtable = D_004E0840;
        cMessage_dtor(pm, 0);
}
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
extern "C" void Actor_HandleLedgeAction(Act_L* actor, Msg_L* msg)
{
    Flags_L flags;
    int tm1[1];
    int t;
    Plc_L plc;
    void* o2;
    Root_L* s1;
    Root_L* s6;
    int f1;
    int f;
    int f2;
    flags.w[0] = msg->flags;
    GetPlcW_L(&plc, msg, &t);
    tm1[0] = -1;
    o2 = IdNe_L(&msg->id, tm1) ? nGobjManager_LookupGOBJ_cObjectIdR(&msg->id) : 0;
    s6 = actor->r3290;
    s1 = actor->r3294;
    f1 = flags.w[0];
    if ((f1 >> 16) & 1 || (f1 >> 17) & 1)
        plc.p[2] -= 1.0f;
    cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(s1, &plc);
    s1->f160 = 0;
    BindW_L(actor, o2, msg, 1);
    f2 = flags.w[0];
    if ((f2 >> 12) & 1) {
        X_L x;
        Name_L name;
        BindW_L(actor, o2, msg, 2);
        {
            Root_L* r = actor->r3298;
            cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(r, &plc);
            r->f160 = 0;
        }
        { X_L* p0 = &x; XInit_L(p0); Set5_L(&x, 0x46, 0x47, 0x48, 0x49, 0x4A, actor); }
        QZeroW_L(&name);
        {int f3 = flags.w[0];
        if ((f3 >> 13) & 1) {
            Range_L r1;
            Range_L r2;
            Range_L r3;
            NameAssign_L(&name, D_0049DE50);
            { float lo = 0.0f; float z; float hi; float xx = 0.6f; z = lo; hi = 1.0f; r1.flag = 0; asm { max.s lo, xx, lo; min.s lo, lo, hi } r1.lo = r1.hi = lo; { float o = 1.0f; RangeInitZ_L(&r2, 0.625f, z, o); RangeInitZ_L(&r3, 0.975f, z, o); } }
            AddW_L(cSkaAnimCheckpoints_ScheduleEvent(cSkaAnimCheckpoints_ScheduleEvent(&x, &r1, 0x5C, actor), &r2, 0x5C, actor), &r3, 0x5C, actor);
        } else if ((f3 >> 14) & 1 || (f3 >> 16) & 1 || (f3 >> 17) & 1) {
            float a;
            float b;
            Range_L ra;
            Range_L rb;
            {
                Root_L* r = actor->r3298;
                cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(r, &plc);
                r->f160 = 0;
            }
            a = 0.0f;
            b = a;
            {int f4 = flags.w[0];
            if ((f4 >> 14) & 1) {
                NameAssign_L(&name, D_0049DE70);
                a = 0.33f;
                b = 0.85f;
            } else if ((f4 >> 16) & 1) {
                NameAssign_L(&name, D_0049DE90);
                a = 0.6f;
                b = 0.65f;
            } else if ((f4 >> 17) & 1) {
                NameAssign_L(&name, D_0049DEB0);
                a = 0.55f;
                b = 0.65f;
            }}
            { float lo = 0.0f; float o = 1.0f; float z; z = lo; ra.flag = 0; asm { max.s lo, a, lo; min.s lo, lo, o } ra.lo = ra.hi = lo; RangeInitZ_L(&rb, b, z, o); }
            AddW_L(cSkaAnimCheckpoints_ScheduleEvent(&x, &ra, 0x5C, actor), &rb, 0x5C, actor);
        }}
        Sel1_L(actor, &name, &x);
        Sel2_L(actor);
        { char* s = actor->s3310; if (s) { QCp1_L(s + 0x980, plc.p); } }
        XDtor_L(&x);
    } else if ((f2 >> 1) & 1) {
        if ((f2 >> 8) & 1) {
            Direct_L(actor, D_0049DEF0, 1, 0x38, 0x39, 0x3A, 0x3B, 0x3C);
            Direct_L(actor, D_0049DD30, 0, 0x14, 0x15, 0x16, 0x17, 0x18);
            Dir19_L(actor);
            Prio_L(actor->prio, 1, 1);
            { char* s = actor->s3310; if (s) {
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(s + 0x18, 5);
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(actor->s3310 + 0x18, 3);
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(actor->s3310 + 0x18, 2);
            } }
        } else {
            Name_L name;
            char* src; { int b = ((f2 >> 2) & 1) != 0; src = b ? D_0049DEF0 : D_0049DF00; }
            if (src) NAME_COPY_N(name.c, src) else QZero_L(&name);
            SiteA_L(actor, &name);
            Auto_L(actor);
            Prio_L(actor->prio, 1, 1);
            { char* s = actor->s3310; if (s) {
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(s + 0x18, 5);
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(actor->s3310 + 0x18, 3);
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(actor->s3310 + 0x18, 2);
            } }
        }
    } else if ((f2 >> 3) & 1) {
        float z0 = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(s6))[2];
        float dy = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(s1))[2] - z0;
        if (dy < D_004A03B8) {
            SiteB_L(actor);
            Auto_L(actor);
            Prio_L(actor->prio, 1, 1);
            { char* s = actor->s3310; if (s) {
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(s + 0x18, 5);
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(actor->s3310 + 0x18, 3);
            } }        } else {
            float t;
            float d;
            float lim;
            if (!D_004EEF00) { D_0049D180 = 4.0f; D_004EEF00 = 1; }
            if (!D_004EEF08) { D_0049D188 = 7.0f; D_004EEF08 = 1; }
            if (!D_004EEF10) { float k = 1.0f / (D_0049D188 - D_0049D180); D_004EEF10 = 1; D_0049D190 = k; }
            { float o = 1.0f; t = ClampY_L(D_0049D190 * (dy - D_0049D180), 0.0f, o);
            d = g_DefaultMotionTransition;
            lim = Min_L(d, d * (o - 2.0f * t)); }
            SiteC_L(actor, d, lim);
            Auto_L(actor);
            Prio_L(actor->prio, 1, 1);
            { char* s = actor->s3310; if (s) {
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(s + 0x18, 5);
                cModeSwitch_WithHistory_12_ActivateMode_uint_2(actor->s3310 + 0x18, 3);
            } }
        }
    } else if ((f2 >> 5) & 1 || (f2 >> 6) & 1) {
        SendCas_L(actor);
    } else if ((f2 >> 7) & 1) {
        cHuman_GrabLedge(actor);
    }
}
#pragma pop
















