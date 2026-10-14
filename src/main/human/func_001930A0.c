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
extern float D_0049D038; extern float D_004A03B8;
extern float D_0049D180; extern float D_0049D188; extern float D_0049D190;
extern signed char D_004EEF00; extern signed char D_004EEF08; extern signed char D_004EEF10;
void* func_0015AC90(int* p, int v);
unsigned char func_001960A0(int* a, int* b);
void* Object_LookupById(int* id);
void* func_00133330(void* o);
void* Transform_GetUpdated(void* p);
Plc_L* Mtx_ToPlacement(Plc_L* d, void* m);
void* Mtx_GetIdentity(void);
void Placement_ApplyParent(Plc_L* d, Plc_L* s, Plc_L* p);
void VecPair_Copy(Plc_L* d, Plc_L* s);
void Root_SetWorldPlacement(Root_L* r, Plc_L* p);
void* Root_GetWorldPlacement(Root_L* r);
void* Root_ResolveWorldPlacement(Root_L* r);
float* Placement_GetPosition(void* p);
void** func_00195DD0(void* p, int i);
void* func_00195DC0(void* p, int i);
unsigned char* func_00195DB0(void* p, int i);
void Transform_SetOrientation(void* t, Plc_L* p);
void func_0018A910(void* p);
void func_0018A8C0(void* p);
void func_0018A890(void* p);
void func_0018A710(void* d, void* s);
void func_0018A700(void* p, int v);
void MotionRequest_Construct(void* d, Name_L* n);
void Actor_ResolveMotionSelection(Sel_L* sel, int* out, Y_L* y, void* model);
float Model_GetFirstFloat(void* m);
V4_L* AnimRate_Init(V4_L* p, float f);
V4_L* Vec4_Copy_18A350(V4_L* d, V4_L* s);
void AnimEvent_Construct(Ev_L* e);
signed char func_0018A2F0(Sel_L* s);
void* func_0018A2E0(Sel_L* s);
float func_0018A2D0(Sel_L* s);
float func_0018A2C0(Sel_L* s);
void AnimCtl_InstallMotion(void* ctl, int id, signed char mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void func_0018A260(void* p, int f);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void func_00189F40(void* p, int f);
X_L* func_00190F90(X_L* x, Range_L* r, int a, void* b);
void func_00192730(P2_L* p, int a, void* b);
void func_00191040(Rec_L* d, Range_L* r, P2_L* p);
void func_00192700(void* v, Rec_L* r);
void func_00190FF0(Rec_L* r, int f);
int Motion_Lookup(void* lib, Name_L* n);
void* func_0018C6A0(Sys_L* s);
void func_0018C620(Y_L* y, int m);
unsigned char AnimPriority_Helper3(void* bits, int index);
void AnimPriority_Helper2(void* p, int index, int v);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
void Physical_SetModeBit(void* p, int b);
void Actor_SendCasAction(CMsg_L* m, int a, int b);
void Ledge_ToObjectPlacement(void* d, int a, void* p, int b);
void Event_Send(void* m, void* t, int f);
void cMessage_dtor(void* m, int f);
void Actor_CatchLedgeInAir(Act_L* a);
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

static inline void XInit_L(X_L* x) { x->kind = 0; func_0018A910(x->pairs); func_0018A8C0(x->tail); }
static inline X_L* XSetR_L(X_L* x, int i, int id, void* a, unsigned char k) { Pair_L* p = &x->pairs[i]; p->id = id; p->a = a; x->kind = k; return x; }
static inline void XDtor_L(X_L* x) { func_001BE5A0(x->tail, 0); __destroy_array(x->pairs, (void*)func_0018A210, 8, 7); }
static inline X_L* Set5_L(X_L* x, int a, int b, int c, int d, int e, void* act)
{
    return XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetR_L(x, 0, a, act, 1), 1, b, act, 1), 3, c, act, 1), 5, d, act, 1), 6, e, act, 1);
}
static inline void RateDef_L(Rate_L* r)
{
    float d = D_0049D038;
    r->x = d;
    r->y = d;
    r->z = Recip_L(d);
    r->w = Recip_L(D_0049D038);
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
    MotionRequest_Construct(s->sub, n);
    s->f48 = f;
    func_0018A710(&s->x, x);
    s->f98 = -1.0f;
    s->f9C = 0;
}
static inline void SelAuto_L(Sel_L* s, int v, X_L* x)
{
    s->mode = 2;
    func_0018A890(s->sub);
    s->f44 = v;
    s->f48 = 0;
    func_0018A710(&s->x, x);
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
    func_0018A700(&y, -1);
    Actor_ResolveMotionSelection(sel, &out, &y, an->model);
    if (out) {
        V4_L* p;
        if (an->b5)
            p = &an->v;
        else
            p = AnimRate_Init(&rate, Model_GetFirstFloat(an->model));
        Vec4_Copy_18A350(&vec, p);
        an->b5 = 0;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        AnimCtl_InstallMotion(an, out, func_0018A2F0(sel), &vec, &y, &e1, &e2, func_0018A2E0(sel), func_0018A2D0(sel), func_0018A2C0(sel));
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
    func_00189F40(&sel->x, -1);
}
static inline void Play_L(Sys_L* sys, int m, int mode, Rate_L* r, X_L* px)
{
    if (m) {
        Ev_L e1;
        Ev_L e2;
        Y_L y;
        void* ctl;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        ctl = func_0018C6A0(sys);
        func_0018C620(&y, m);
        AnimCtl_InstallMotion(ctl, m, mode, r, &y, &e1, &e2, px, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
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
    m = Motion_Lookup(sys->lib, &n);
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
        *func_00195DD0(s + 0x1F0, idx) = o;
        Transform_SetOrientation(func_00195DC0(s + 0x200, idx), pp);
        p = o ? func_00133330(o) : 0;
        if (p) m = Transform_GetUpdated(p); else m = Mtx_GetIdentity();
        Transform_SetOrientation(func_00195DC0(s + 0x260, idx), Mtx_ToPlacement(&t, m));
        *func_00195DB0(s + 0x2C0, idx) = 1;
    }
}
static inline void AddI_L(X_L* x, Range_L* r, int k, void* a)
{
    P2_L p;
    Rec_L rec;
    func_00192730(&p, k, a);
    func_00191040(&rec, r, &p);
    func_00192700(x->tail, &rec);
    func_00190FF0(&rec, -1);
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
                m = Motion_Lookup(sys->lib, &n);
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
        void* p = Root_ResolveWorldPlacement(actor->r3294);
        pm = &m;
        Actor_SendCasAction(pm, 0x14, 0xE);
        Ledge_ToObjectPlacement(pm->f30, 0, p, 0);
        pm->vtable = D_004E00E0;
        { int one = 1; m.kind = one; Event_Send(pm, actor, one); }
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
        obj = func_001960A0(&msg->id, (int*)func_0015AC90(pt, -1)) != 0 ? Object_LookupById(&msg->id) : 0;
        parent = obj ? func_00133330(obj) : 0;
        if (parent) {
            Placement_ApplyParent(&t790, &msg->plc, Mtx_ToPlacement(&t7B0, Transform_GetUpdated(parent)));
            src = &t790;
        } else {
            src = &msg->plc;
        }
        VecPair_Copy(pplc, src);
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
    o2 = IdNe_L(&msg->id, tm1) ? Object_LookupById(&msg->id) : 0;
    s6 = actor->r3290;
    s1 = actor->r3294;
    f1 = flags.w[0];
    if ((f1 >> 16) & 1 || (f1 >> 17) & 1)
        plc.p[2] -= 1.0f;
    Root_SetWorldPlacement(s1, &plc);
    s1->f160 = 0;
    BindW_L(actor, o2, msg, 1);
    f2 = flags.w[0];
    if ((f2 >> 12) & 1) {
        X_L x;
        Name_L name;
        BindW_L(actor, o2, msg, 2);
        {
            Root_L* r = actor->r3298;
            Root_SetWorldPlacement(r, &plc);
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
            AddW_L(func_00190F90(func_00190F90(&x, &r1, 0x5C, actor), &r2, 0x5C, actor), &r3, 0x5C, actor);
        } else if ((f3 >> 14) & 1 || (f3 >> 16) & 1 || (f3 >> 17) & 1) {
            float a;
            float b;
            Range_L ra;
            Range_L rb;
            {
                Root_L* r = actor->r3298;
                Root_SetWorldPlacement(r, &plc);
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
            AddW_L(func_00190F90(&x, &ra, 0x5C, actor), &rb, 0x5C, actor);
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
                Physical_SetModeBit(s + 0x18, 5);
                Physical_SetModeBit(actor->s3310 + 0x18, 3);
                Physical_SetModeBit(actor->s3310 + 0x18, 2);
            } }
        } else {
            Name_L name;
            char* src; { int b = ((f2 >> 2) & 1) != 0; src = b ? D_0049DEF0 : D_0049DF00; }
            if (src) NAME_COPY_N(name.c, src) else QZero_L(&name);
            SiteA_L(actor, &name);
            Auto_L(actor);
            Prio_L(actor->prio, 1, 1);
            { char* s = actor->s3310; if (s) {
                Physical_SetModeBit(s + 0x18, 5);
                Physical_SetModeBit(actor->s3310 + 0x18, 3);
                Physical_SetModeBit(actor->s3310 + 0x18, 2);
            } }
        }
    } else if ((f2 >> 3) & 1) {
        float z0 = Placement_GetPosition(Root_GetWorldPlacement(s6))[2];
        float dy = Placement_GetPosition(Root_GetWorldPlacement(s1))[2] - z0;
        if (dy < D_004A03B8) {
            SiteB_L(actor);
            Auto_L(actor);
            Prio_L(actor->prio, 1, 1);
            { char* s = actor->s3310; if (s) {
                Physical_SetModeBit(s + 0x18, 5);
                Physical_SetModeBit(actor->s3310 + 0x18, 3);
            } }        } else {
            float t;
            float d;
            float lim;
            if (!D_004EEF00) { D_0049D180 = 4.0f; D_004EEF00 = 1; }
            if (!D_004EEF08) { D_0049D188 = 7.0f; D_004EEF08 = 1; }
            if (!D_004EEF10) { float k = 1.0f / (D_0049D188 - D_0049D180); D_004EEF10 = 1; D_0049D190 = k; }
            { float o = 1.0f; t = ClampY_L(D_0049D190 * (dy - D_0049D180), 0.0f, o);
            d = D_0049D038;
            lim = Min_L(d, d * (o - 2.0f * t)); }
            SiteC_L(actor, d, lim);
            Auto_L(actor);
            Prio_L(actor->prio, 1, 1);
            { char* s = actor->s3310; if (s) {
                Physical_SetModeBit(s + 0x18, 5);
                Physical_SetModeBit(actor->s3310 + 0x18, 3);
            } }
        }
    } else if ((f2 >> 5) & 1 || (f2 >> 6) & 1) {
        SendCas_L(actor);
    } else if ((f2 >> 7) & 1) {
        Actor_CatchLedgeInAir(actor);
    }
}
#pragma pop
















