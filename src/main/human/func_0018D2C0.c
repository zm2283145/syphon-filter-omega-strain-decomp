#pragma cplusplus on
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off

typedef struct { float x, y, z, w; } V4_L;
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_L;
typedef struct { float v[4]; } __attribute__((aligned(16))) Q_L;
typedef struct { float m[4][4]; } __attribute__((aligned(16))) Mtx_L;
typedef struct { Q_L q; Q_L p; } Plc_L;
typedef struct { int id; void* a; } Pair_L;
typedef struct { unsigned char kind; char pad[3]; Pair_L pairs[7]; char tail[0x10]; } X_L;
typedef struct { unsigned char mode; char pad1[0xF]; char sub[0x30]; int f40; int f44; unsigned char f48; char pad49[3]; X_L x; float f98; int f9C; } Sel_L;
typedef struct { float x, y, z, w; } Rate_L;
typedef struct { void* model; char pad4; unsigned char b5; char pad6[2]; V4_L v; } Anim_L;
typedef struct { void* lib; char pad4[0xC]; char f10[0x24]; Anim_L anim; } Sys_L;
typedef struct { int a, b; } Y_L;
typedef struct { char pad[0x40]; } Ev_L;
typedef struct { float lo, hi; unsigned char flag; } Range_L;
typedef struct { char pad[0x160]; int f160; } Root_L;
typedef struct { char pad[0x24]; int tree; } Lib_L;
typedef struct { char pad[0x24]; char* f24; } Anm_L;
typedef struct { int n; } It_L;
typedef struct { char pad[0x28]; int mode; int bits[1]; } Phys_L;

struct Ctl_L {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsPlayer();
};
struct Xf_L {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad4[0xC];
    Mtx_L m;
    unsigned char b50;
};
typedef struct { char pad[0x50]; Xf_L* xf; } Node_L;
typedef struct { char pad[0xA8]; Node_L* node; void* push; } Obj_L;

typedef struct {
    char pad0[0x14]; unsigned char b14; char pad15[0x58 - 0x15];
    Ctl_L* ctl; char pad5C[0x2EC0 - 0x5C];
    Sys_L sys; char pad2EF4_[0x320C - 0x2EC0 - sizeof(Sys_L)];
    char prio[4]; int f3210; char pad3214[0x324C - 0x3214];
    int f324C; char pad3250[0x326B - 0x3250];
    unsigned char b326B;
    int f326C; char pad3270[0x3290 - 0x3270];
    Root_L* r3290; Root_L* r3294; char pad3298[0x3310 - 0x3298];
    Phys_L* s3310; char pad3314[0x3474 - 0x3314];
    Obj_L* f3474;
} Act_L;

extern "C" char D_004DFD80[]; extern "C" char D_004E0840[]; extern "C" char D_004E0160[];
#define MSG_HDR \
    void* vtable; int f04; int f08; int f0C; int f10; int f14; int f18; int f1C; signed char f20; char pad21[3]
typedef struct { MSG_HDR; int type; unsigned char kind; char pad29[3]; int id; } Msg_L;
typedef struct { MSG_HDR; int type; signed char kind; char pad29[3]; int id; Name_L key; float val; unsigned char flag; } MsgA_L;
struct Msg3C_L { MSG_HDR; int type; signed char kind; char pad29[3]; int id; int anchor; float val; unsigned char flag;
    Msg3C_L() {}
    Msg3C_L(const Msg3C_L& src)
    {
        vtable = D_004DFD80;
        f04 = src.f04; f08 = src.f08; f0C = src.f0C; f10 = src.f10;
        f14 = src.f14; f18 = src.f18; f1C = src.f1C; f20 = src.f20;
        vtable = D_004E0840;
        type = src.type; kind = src.kind;
        vtable = D_004E0160;
        id = src.id;
        anchor = src.anchor;
        val = src.val;
        flag = src.flag;
    }
};
typedef struct { MSG_HDR; int f24; int f28; void* f2C; } Msg4_L;
typedef struct { MSG_HDR; int f24; unsigned char f28; char pad29[3]; int f2C; unsigned char f30; char pad31[3]; float f34; char pad38[8]; } AEv_L;

extern "C" {
extern char D_004DFD80[]; extern char D_004E0840[]; extern char D_004DA910[]; extern char D_004E0160[];
extern char D_0055D480[]; extern char D_0055A1D8[]; extern char D_004DA950[];
extern char D_00542B60[]; extern char D_004DA930[];
extern char D_004FFB50[];
extern int D_0049D040; extern int D_0049D048;
extern char D_0049DC30[]; extern char D_0049DC50[];
extern char D_0049DC70[]; extern char D_0049DC90[]; extern char D_0049DCB0[]; extern char D_0049DCD0[];
extern char D_0049DCF0[]; extern char D_0049DD00[]; extern char D_0049DD30[]; extern char D_0049DD50[];
extern Name_L D_0049D1A0; extern Name_L D_0049D1D0; extern Name_L D_0049D200; extern Name_L D_0049D230;
extern Name_L D_0049D260; extern Name_L D_0049D290; extern Name_L D_0049D2C0; extern Name_L D_0049D2F0;
extern Name_L D_0049D320;
extern signed char D_004EEF90; extern signed char D_004EEF98; extern signed char D_004EEFA0; extern signed char D_004EEFA8;
extern signed char D_004EEFB0; extern signed char D_004EEFB8; extern signed char D_004EEFC0;
extern signed char D_004EEFC8; extern signed char D_004EEFD0;
extern float D_0049D038;
void Event_Construct(void* m, void* t);
void Event_Send(void* m, void* t, int f);
void cMessage_dtor(void* m, int f);
void ModelCtx_FindNodeById(It_L* out, int* tree, Name_L* key);
void NodeMap_End(It_L* out, int* tree);
int NodeMapIter_NotEqual(It_L* a, It_L* b);
int* NodeMapIter_Value(It_L* a);
Obj_L* Object_LookupById(int* id);
void ActorObj_BuildNodeMatrix(Mtx_L* out, Node_L* n);
Anm_L* ModelCtx_GetAnchorById(void* lib, int id);
Anm_L* Motion_Lookup(void* lib, Name_L* n);
int func_001914A0(Anm_L* a, int b);
void Actor_RequestTeleport(Act_L* a, Mtx_L* m);
void Root_SetWorldPlacement(Root_L* r, Plc_L* p);
Plc_L* Root_ResolveWorldPlacement(Root_L* r);
void* ModelCtx_FindNodeByName(Sys_L* s, Name_L* n);
void* func_00190F40(void* p);
int func_00190F30(void* p);
void Motion_GetStartPlacement(Plc_L* out, void* node, int k);
void VecPair_Copy(Plc_L* d, Plc_L* s);
void Root_BaseConstruct(Plc_L* p);
void World_PushObjectFromAction(void* w, void* p);
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
signed char MotionRequest_GetMode(Sel_L* s);
void* func_0018A2E0(Sel_L* s);
float func_0018A2D0(Sel_L* s);
float func_0018A2C0(Sel_L* s);
void AnimCtl_InstallMotion(void* ctl, void* id, signed char mode, void* range, void* pair, void* m1, void* m2, void* x, float f0, float f1);
void func_0018A260(void* p, int f);
void func_001BE5A0(void* p, int f);
void __destroy_array(void* p, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
X_L* func_00190F90(X_L* x, Range_L* r, int a, void* b);
void* func_0018C6A0(Sys_L* s);
void func_0018C620(Y_L* y, Anm_L* m);
unsigned char AnimPriority_Helper3(void* bits, int index);
void AnimPriority_Helper2(void* p, int index, int v);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int index, unsigned char on);
}

static inline void Q4s(void* d0, const void* s0) { const void* s = s0; void* d = d0; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void Q4(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
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
static inline void QCopy_L(void* dd, void* ss) { int n = 3; __int128 q; void* s = ss; void* d = dd;
    asm {
        .set noreorder
    lp:
        lq q, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq q, -0x10(d)
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

#define NAME_ASSIGN(dst, src) \
    { \
        Name_L tmp; \
        NAME_COPY(tmp.c, src) \
        if ((dst).c[0] || tmp.c[0]) QCopy_L(&(dst), &tmp); \
    }

#define STATIC_NAME(guard, dst, src) \
    if (!guard) { NAME_COPY((dst).c, src) guard = 1; }

static inline float Recip_L(float v) { return v != 0.0f ? 1.0f / v : 3.4028235e38f; }
static inline float ClampY_L(float x, float z, float o) { float lo = z; float hi = o; float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline void RangeInitY_L(Range_L* r, float t, float z, float o) { float v; v = 0.0f; r->flag = 0; v = ClampY_L(t, z, o); r->hi = v; r->lo = v; }

static inline X_L* XInit_L(X_L* x) { X_L* px = x; px->kind = 0; func_0018A910(px->pairs); func_0018A8C0(px->tail); return px; }
static inline void XSet_L(X_L* x, int i, int id, void* a) { Pair_L* p = &x->pairs[i]; p->id = id; p->a = a; x->kind = 1; }
static inline X_L* XSetR_L(X_L* x, int i, int id, void* a, unsigned char k) { Pair_L* p = &x->pairs[i]; p->id = id; p->a = a; x->kind = k; return x; }
static inline void XDtor_L(X_L* x) { func_001BE5A0(x->tail, 0); __destroy_array(x->pairs, (void*)func_0018A210, 8, 7); }
static inline void D3_L(void* p) { if (p) func_001BE5A0(p, 0); }
static inline void D2_L(void* p) { if (p) D3_L(p); }
static inline void XDtorN_L(X_L* p) {
    void* t = p->tail;
    if (t) { if (t) { if (t) func_001BE5A0(t, 0); } }
    if (p->pairs) __destroy_array(p->pairs, (void*)func_0018A210, 8, 7);
}
static inline void PairSet_L(Pair_L* p, int id, void* a) { p->id = id & 0xFF; p->a = a; }
static inline X_L* XSetP_L(X_L* x, int i, int id, void* a) { PairSet_L(&x->pairs[i], id, a); x->kind = 1; return x; }
static inline X_L* XSetQ_L(X_L* x, int i, int id, void* a) { Pair_L* pp = &x->pairs[i]; PairSet_L(pp, id, a); x->kind = 1; return x; }
static inline X_L* XSetQR_L(X_L* x, int i, int id, void* a, unsigned char k) { Pair_L* pp = &x->pairs[i]; PairSet_L(pp, id, a); x->kind = k; return x; }
static inline void SelAuto_L(Sel_L* s, int v, X_L* x) { s->mode = 2; func_0018A890(s->sub); s->f44 = v; s->f48 = 0; func_0018A710(&s->x, x); }
static inline X_L* Set5P_L(X_L* x, int a, int b, int c, int d, int e, void* act)
{
    return XSetQ_L(XSetQ_L(XSetQ_L(XSetQ_L(XSetP_L(x, 0, a, act), 1, b, act), 3, c, act), 5, d, act), 6, e, act);
}
static inline X_L* Set5_L(X_L* x, int a, int b, int c, int d, int e, void* act)
{
    unsigned char k = 1;
    return XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetR_L(x, 0, a, act, k), 1, b, act, k), 3, c, act, k), 5, d, act, k), 6, e, act, k);
}
static inline void RateDef_L(Rate_L* r)
{
    float d = D_0049D038;
    r->x = d;
    r->y = d;
    r->z = Recip_L(d);
    r->w = Recip_L(D_0049D038);
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
        AnimCtl_InstallMotion(an, (void*)out, MotionRequest_GetMode(sel), &vec, &y, &e1, &e2, func_0018A2E0(sel), func_0018A2D0(sel), func_0018A2C0(sel));
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
}
static inline void DirectP_L(Act_L* a, Name_L* n, int mode, int i0, int i1, int i3, int i5, int i6)
{
    X_L x;    Rate_L r;    X_L* px;    Sys_L* sys;    Anm_L* m;
    XInit_L(&x);
    { unsigned char k = 1; px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetQR_L(&x, 0, i0, a, k), 1, i1, a, k), 3, i3, a, k), 5, i5, a, k), 6, i6, a, k); }
    RateDef_L(&r);
    sys = &a->sys;
    m = Motion_Lookup(sys->lib, n);
    if (m) {
        Ev_L e1;
        Ev_L e2;
        Y_L y;
        void* ctl;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        ctl = func_0018C6A0(sys);
        func_0018C620(&y, m);
        AnimCtl_InstallMotion(ctl, m, mode, &r, &y, &e1, &e2, px, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
    XDtor_L(&x);
}
static inline void Prio_L(char* p, signed char k, int v)
{
    char* q = p;
    unsigned char on;
    on = AnimPriority_Helper3(q + 0xC, k);
    AnimPriority_Helper2(q + 4, k, v);
    AnimPriority_Helper1(q);
    AnimPriority_Helper0(q, k, on);
}
static inline bool FTest_L(int w, int n) { return ((w >> n) & 1) != 0; }
static inline bool FClr_L(int w, int n) { return !FTest_L(w, n); }
static inline bool CanAct_L(Act_L* a) { bool r = 0; if (FClr_L(a->f3210, 27) && FClr_L(a->f3210, 31)) r = 1; return r; }
static inline int Ready_L(Act_L* a) { bool r = 0; if (CanAct_L(a) && FClr_L(a->f3210, 23)) r = 1; return r; }
static inline unsigned char PTest_L(Phys_L* p, int n) { return ((p->bits[n / 32] >> (n & 31)) & 1) != 0; }
static inline void PSetBit_L(Phys_L* p, int bit)
{
    int i;
    p->bits[bit / 32] |= 1 << (bit & 31);
    for (i = 12; i >= 0 && !PTest_L(p, i); i--) {
    }
    if (!PTest_L(p, i)) {
        p->mode = -1;
    } else {
        p->mode = i;
    }
}
static inline void SetRoot_L(Root_L* r, Plc_L* p) { Root_SetWorldPlacement(r, p); r->f160 = 0; }
static inline void Q1_L(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline Plc_L* ToPlc_L(Plc_L* out, Mtx_L* m)
{
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

    return out;
}
static inline void SetRootM_L(Root_L* r, Mtx_L* m) { Plc_L p; ToPlc_L(&p, m); Q1_L(&p.p, m->m[3]); SetRoot_L(r, &p); }
static inline void StartPlc_L(Plc_L* out, Act_L* a, Name_L* n)
{
    Sys_L* s = &a->sys;
    void* nd = ModelCtx_FindNodeByName(s, n);
    if (nd) {
        Plc_L t;
        Motion_GetStartPlacement(&t, nd, func_00190F30(func_00190F40(s->f10)));
        VecPair_Copy(out, &t);
    } else {
        Root_BaseConstruct(out);
    }
}
static inline void AEvInit_L(AEv_L* e)
{
    Event_Construct(e, D_00542B60);
    e->vtable = D_004DA930;
    e->f24 = 0;
    e->f28 = 0;
    e->f2C = 0;
    e->f30 = 0;
    e->f34 = 0.0f;
}
static inline void Copy3C_L(Msg3C_L* d, Msg3C_L* src)
{
    d->vtable = D_004DFD80;
    d->f04 = src->f04; d->f08 = src->f08; d->f0C = src->f0C; d->f10 = src->f10;
    d->f14 = src->f14; d->f18 = src->f18; d->f1C = src->f1C; d->f20 = src->f20;
    d->vtable = D_004E0840;
    d->type = src->type; d->kind = src->kind;
    d->vtable = D_004E0160;
    d->id = src->id;
    d->anchor = src->anchor;
    d->val = src->val;
    d->flag = src->flag;
}
static inline int IsEmpty_L(Name_L* n) { return n->c[0] == 0; }
static inline void CopyA_L(MsgA_L* d, MsgA_L* src)
{
    d->vtable = D_004DFD80;
    d->f04 = src->f04; d->f08 = src->f08; d->f0C = src->f0C; d->f10 = src->f10;
    d->f14 = src->f14; d->f18 = src->f18; d->f1C = src->f1C; d->f20 = src->f20;
    d->vtable = D_004E0840;
    d->type = src->type; d->kind = src->kind;
    d->vtable = D_004DA910;
    d->id = src->id;
    {
        int n = 3; void* s = &src->key; void* dd = &d->key; __int128 q;
        asm {
            .set noreorder
        lp:
            lq q, 0(s)
            addiu dd, dd, 0x10
            addi n, n, -1
            addiu s, s, 0x10
            bgtz n, lp
            sq q, -0x10(dd)
            .set reorder
        }
    }
    d->val = src->val;
    d->flag = src->flag;
}
static inline int FindAnchor_L(Act_L* actor, Name_L* key)
{
    It_L it;
    It_L end;
    Lib_L* lib = (Lib_L*)actor->sys.lib;
    ModelCtx_FindNodeById(&it, &lib->tree, key);
    NodeMap_End(&end, &lib->tree);
    return NodeMapIter_NotEqual(&it, &end) ? *NodeMapIter_Value(&it) : 0;
}

static inline void NodeMtx_L(Mtx_L* mt, Node_L* nd) { Mtx_L t; ActorObj_BuildNodeMatrix(&t, nd); Q4(mt, &t); }
static inline void NameAssign_L(Name_L* dst, char* src) { Name_L tmp; NAME_COPY(tmp.c, src) if (dst->c[0] || tmp.c[0]) QCopy_L(dst, &tmp); }
static inline void Inst2_L(Act_L* a, Sel_L* sel, Rate_L* r) { Install_L(a, sel, r); }
static inline void BlkA_L(Act_L* actor, Name_L* name, int id0, int id1, float speed)
{
    Sel_L* ps;
    Rate_L r;
    X_L x;
    Range_L rg;
    X_L* px;
    XInit_L(&x);
    { X_L* q = Set5P_L(&x, id0, id1, 0x68, 0x69, 0x6A, actor);
    RangeInitY_L(&rg, 0.5f, 0.0f, 1.0f);
    px = func_00190F90(q, &rg, 0x67, actor); }
    {
        Sel_L sel;
        ps = &sel;
        ps->mode = 0;
        MotionRequest_Construct(ps->sub, name);
        ps->f48 = 1;
        func_0018A710(&ps->x, px);
        ps->f98 = speed;
        ps->f9C = 0;
        RateDef_L(&r);
        Inst2_L(actor, &sel, &r);
        XDtorN_L((X_L*)((char*)&sel + 0x4C));
    }
    XDtor_L(&x);
}
static inline void BlkB_L(Act_L* actor, int anchor, int id0, int id1, float speed)
{
    Sel_L* ps;
    Rate_L r;
    X_L x;
    Range_L rg;
    X_L* px;
    XInit_L(&x);
    { X_L* q = Set5P_L(&x, id0, id1, 0x68, 0x69, 0x6A, actor);
    RangeInitY_L(&rg, 0.5f, 0.0f, 1.0f);
    px = func_00190F90(q, &rg, 0x67, actor); }
    {
        Sel_L sel;
        ps = &sel;
        ps->mode = 1;
        func_0018A890(ps->sub);
        ps->f40 = anchor;
        ps->f48 = 1;
        func_0018A710(&ps->x, px);
        ps->f98 = speed;
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
        SelAuto_L(ps, actor->f326C, &x);
        ps->f98 = -1.0f;
        ps->f9C = 0;
        RateDef_L(&r);
        Inst2_L(actor, &sel, &r);
        XDtorN_L((X_L*)((char*)&sel + 0x4C));
    }
    XDtor_L(&x);
}
static inline void SendMsg4_L(Obj_L* obj, Act_L* actor)
{
    Msg4_L m;
    Msg4_L* p = &m;
    Event_Construct(p, D_0055A1D8);
    p->vtable = D_004DA950;
    p->f24 = 0xD;
    p->f28 = -1;
    p->f2C = actor;
    { int one = 1; m.f20 = one; Event_Send(&m, obj, one); }
    m.vtable = D_004DA950;
    cMessage_dtor(&m, 0);
}
static inline void Mot_L(Sys_L* sys, Anm_L* m, int mode, Rate_L* r, X_L* px)
{
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
static inline void Mot2_L(Sys_L* sys, Anm_L* m, int mode, Rate_L* r, X_L* px) { if (m) Mot_L(sys, m, mode, r, px); }
static inline void DP_L(Act_L* a, Name_L* n, int mode, int i0, int i1, int i3, int i5, int i6)
{
    Rate_L r;    X_L x;    X_L* px;    Sys_L* sys;    Anm_L* m;
    XInit_L(&x);
    { unsigned char k = 1; px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetQR_L(&x, 0, i0, a, k), 1, i1, a, k), 3, i3, a, k), 5, i5, a, k), 6, i6, a, k); }
    RateDef_L(&r);
    sys = &a->sys;
    m = Motion_Lookup(sys->lib, n);
    Mot2_L(sys, m, mode, &r, px);
    XDtor_L(&x);
}
static inline X_L* XSetQL_L(X_L* x, int i, int id, void* a, unsigned char k) { Pair_L* pp = &x->pairs[i]; x->kind = k; PairSet_L(pp, id, a); return x; }
static inline void DP3_L(Act_L* a, Name_L* n, unsigned char k, int mode, int i0, int i1, int i3, int i5, int i6)
{
    Rate_L r;    X_L x;    X_L* px;    Sys_L* sys;    Anm_L* m;
    XInit_L(&x);
    { px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetQR_L(&x, 0, i0, a, k), 1, i1, a, k), 3, i3, a, k), 5, i5, a, k), 6, i6, a, k); }
    RateDef_L(&r);
    sys = &a->sys;
    m = Motion_Lookup(sys->lib, n);
    Mot2_L(sys, m, mode, &r, px);
    XDtor_L(&x);
}
#define NAME_COPY3(dst, src) \
    { \
        unsigned char ckc_end = 0; \
        int ckc_i = 0; \
        char ckc_c; \
        for (; ckc_i < 0x2F; ckc_i++) { \
            if ((src)[ckc_i] == 0) ckc_end = 1; \
            if (ckc_end) ckc_c = 0; else ckc_c = (src)[ckc_i]; \
            (dst)[ckc_i] = ckc_c; \
        } \
        (dst)[ckc_i] = 0; \
    }
static inline void B2_L(Act_L* actor)
{
    Name_L nm;
    Rate_L r;
    X_L x;
    X_L* px;
    Sys_L* sys;
    Anm_L* m;
    XInit_L(&x);
    sys = &actor->sys;
    RateDef_L(&r);
    { px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetQR_L(&x, 0, 0x14, actor, 1), 1, 0x15, actor, 1), 3, 0x16, actor, 1), 5, 0x17, actor, 1), 6, 0x18, actor, 1); }
    NAME_COPY3(nm.c, D_0049DD30)
    m = Motion_Lookup(sys->lib, &nm);
    Mot2_L(sys, m, 0, &r, px);
    XDtor_L(&x);
}
static inline void B3_L(Act_L* actor)
{
    Rate_L r;    X_L x;    X_L* px;    Sys_L* sys;    Anm_L* m;
    XInit_L(&x);
    { px = XSetR_L(XSetR_L(XSetR_L(XSetQR_L(&x, 0, 0x19, actor, 1), 3, 0x1A, actor, 1), 5, 0x1B, actor, 1), 6, 0x1C, actor, 1); }
    RateDef_L(&r);
    sys = &actor->sys;
    m = Motion_Lookup(sys->lib, &D_0049D260);
    Mot2_L(sys, m, 0, &r, px);
    XDtor_L(&x);
}
static inline void* YOf_L(int* p) { return p + 1; }
static inline void AEvRun_L(Act_L* actor, Rate_L* r, X_L* x, int* s2, Sys_L* sys)
{
    AEv_L e1;
    AEv_L e2;
    { AEv_L* p1 = &e1; AEvInit_L(p1); }
    { AEv_L* p2 = &e2; AEvInit_L(p2); }
    AnimCtl_InstallMotion(&sys->anim, (void*)*s2, 0, r, YOf_L(s2), &e1, &e2, x, -1.0f, 0.0f);
    e2.vtable = D_004DA930;
    cMessage_dtor(&e2, 0);
    e1.vtable = D_004DA930;
    cMessage_dtor(&e1, 0);
}
static inline void B4_L(Act_L* actor)
{
    Rate_L r;
    X_L x;
    int* s2;
    Sys_L* sys;
    XInit_L(&x);
    RateDef_L(&r);
    s2 = (int*)actor->f326C;
    sys = &actor->sys;
    AEvRun_L(actor, &r, &x, s2, sys);
    XDtor_L(&x);
}
static inline void SP2_L(Plc_L* out, Act_L* a, Name_L* n) { StartPlc_L(out, a, n); }
static inline void SP1_L(Plc_L* out, Act_L* a, Name_L* n) { SP2_L(out, a, n); }
static inline void DP31_L(Act_L* a, Name_L* n, int id)
{
    Rate_L r;    X_L x;    X_L* px;    Sys_L* sys;    Anm_L* m;
    XInit_L(&x);
    { unsigned char k = 1; px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetQR_L(&x, 0, id, a, k), 1, 0x6D, a, k), 3, 0x6E, a, k), 5, 0x6F, a, k), 6, 0x70, a, k); }
    RateDef_L(&r);
    sys = &a->sys;
    m = Motion_Lookup(sys->lib, n);
    Mot2_L(sys, m, 1, &r, px);
    XDtor_L(&x);
}
static inline void DP31b_L(Act_L* a, Name_L* n, int id)
{
    Rate_L r;    X_L x;    X_L* px;    Sys_L* sys;    Anm_L* m;
    XInit_L(&x);
    { unsigned char k = 1; px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetQR_L(&x, 0, id, a, k), 1, 0x6D, a, k), 3, 0x6E, a, k), 5, 0x6F, a, k), 6, 0x70, a, k); }
    RateDef_L(&r);
    sys = &a->sys;
    m = Motion_Lookup(sys->lib, n);
    if (m) {
        Ev_L e1;
        Ev_L e2;
        Y_L y;
        void* ctl;
        AnimEvent_Construct(&e1);
        AnimEvent_Construct(&e2);
        ctl = func_0018C6A0(sys);
        func_0018C620(&y, m);
        AnimCtl_InstallMotion(ctl, m, 1, &r, &y, &e1, &e2, px, -1.0f, 0.0f);
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
    }
    XDtor_L(&x);
}
static inline void Mot1_L(Sys_L* sys, Anm_L* m, Rate_L* r, X_L* px)
{
    Ev_L e1;
    Ev_L e2;
    Y_L y;
    void* ctl;
    AnimEvent_Construct(&e1);
    AnimEvent_Construct(&e2);
    ctl = func_0018C6A0(sys);
    func_0018C620(&y, m);
    AnimCtl_InstallMotion(ctl, m, 1, r, &y, &e1, &e2, px, -1.0f, 0.0f);
    func_0018A260(&e2, -1);
    func_0018A260(&e1, -1);
}
static inline void DP31c_L(Act_L* a, Name_L* n, int id)
{
    Rate_L r;    X_L x;    X_L* px;    Sys_L* sys;    Anm_L* m;
    XInit_L(&x);
    { unsigned char k = 1; px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetQR_L(&x, 0, id, a, k), 1, 0x6D, a, k), 3, 0x6E, a, k), 5, 0x6F, a, k), 6, 0x70, a, k); }
    RateDef_L(&r);
    sys = &a->sys;
    m = Motion_Lookup(sys->lib, n);
    if (m) Mot_L(sys, m, 1, &r, px);
    XDtor_L(&x);
}
static inline void DP31d_L(Act_L* a, Name_L* n, int id)
{
    Rate_L r;    X_L x;    X_L* px;    Sys_L* sys;    Anm_L* m;
    XInit_L(&x);
    { unsigned char k = 1; px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSetQR_L(&x, 0, id, a, k), 1, 0x6D, a, k), 3, 0x6E, a, k), 5, 0x6F, a, k), 6, 0x70, a, k); }
    RateDef_L(&r);
    sys = &a->sys;
    m = Motion_Lookup(sys->lib, n);
    if (m) Mot1_L(sys, m, &r, px);
    XDtor_L(&x);
}

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
extern "C" void Actor_HandleObjectAction(Act_L* actor, Msg_L* msg)
{
    int type = msg->type;
    Obj_L* obj;
    Obj_L* s6;
    Mtx_L* pm;
    unsigned char ok;
    unsigned char ok2;
    int dummy;
    if ((type == 0x25 || type == 0x26 || type == 0x27) && msg->kind == 0xA) {
        MsgA_L c;
        Msg3C_L m;
        int anchor;
        { MsgA_L* pc = &c; CopyA_L(pc, (MsgA_L*)msg); }
        anchor = IsEmpty_L(&c.key) ? -1 : FindAnchor_L(actor, &c.key);
        {
            Msg3C_L* p = &m;
            int* idp;
            unsigned char flag = c.flag;
            float val = c.val;
            signed char t = (signed char)c.type;
            idp = &c.id;
            Event_Construct(p, D_0055D480);
            p->vtable = D_004E0840;
            p->type = t;
            p->kind = 7;
            p->vtable = D_004E0160;
            p->id = *idp;
            p->anchor = anchor;
            p->val = val;
            p->flag = flag;
        }
        m.f20 = 5;
        m.f1C = 0x40;
        Event_Send(&m, actor, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
        c.vtable = D_004E0840;
        cMessage_dtor(&c, 0);
        return;
    }
    ok2 = Ready_L(actor);
    switch (type) {
    case 0x25: case 0x26: case 0x27: dummy = 1; break;
    case 0x31: case 0x34: case 0x35: dummy = 2; break;
    case 0x33: case 0x37: case 0x38: dummy = 3; break;
    }
    obj = 0;
    {
        unsigned char k = msg->kind;
        if (k == 5) {
            obj = Object_LookupById(&msg->id);
        } else if (k == 7) {
            { int* idp = &msg->id; if (*idp != -1) obj = Object_LookupById(idp); else obj = 0; }
        }
    }
    if (ok2) {
        Mtx_L mt;
        pm = 0;
        s6 = 0;
        if (obj) {
            Node_L* nd = obj->node;
            s6 = obj;
            if (nd) {
                if (nd) {
                    NodeMtx_L(&mt, nd);
                    pm = &mt;
                } else {
                    Xf_L* xf = nd->xf;
                    if (xf->b50) xf->Update();
                    Q4s(&mt, &xf->m);
                    pm = &mt;
                }
            }
        }
        switch (type) {
        case 0x25: case 0x26: case 0x27: {
            Name_L name;
            int anchor;
            float speed;
            int id0;
            int id1;
            unsigned char hold;
            Anm_L* anim;
            int* key;
            Prio_L(actor->prio, 0x14, 1);
            anchor = -1;
            QZero_L(&name);
            speed = -1.0f;
            id0 = 0;
            id1 = 0;
            hold = 0;
            if (msg->kind == 7) {
                Msg3C_L c;
                { Msg3C_L* pc = &c; Copy3C_L(pc, (Msg3C_L*)msg); }
                anchor = c.anchor;
                speed = (int)c.val;
                hold = c.flag != 0;
                c.vtable = D_004E0840;
                cMessage_dtor(&c, 0);
            }
            if (hold) actor->f324C |= 1;
            else actor->f324C &= ~1;
            if (anchor == -1) {
                switch (msg->type) {
                case 0x25: case 0x26: NameAssign_L(&name, D_0049DC30); break;
                case 0x27: NameAssign_L(&name, D_0049DC50); break;
                }
            }
            if (anchor != -1) {
                anim = ModelCtx_GetAnchorById(actor->sys.lib, anchor);
                anim = func_001914A0(anim, 0) ? anim : 0;
            } else {
                anim = Motion_Lookup(actor->sys.lib, &name);
                anim = func_001914A0(anim, 0) ? anim : 0;
            }
            key = anim ? (int*)(anim->f24 + 0x24) : &D_0049D048;
            if (*key == D_0049D040) {
                if (pm) Actor_RequestTeleport(actor, pm);
                id0 = 0x63;
                id1 = 0x65;
            } else if (*key == D_0049D048) {
                if (pm) {
                    Plc_L p;
                    SetRootM_L(actor->r3294, pm);
                    id0 = 0x63;
                    id1 = 0x66;
                } else {
                    SetRoot_L(actor->r3294, Root_ResolveWorldPlacement(actor->r3290));
                    id0 = 0x64;
                    id1 = 0x65;
                }
            }
            if (anchor == -1) BlkA_L(actor, &name, id0, id1, speed);
            else BlkB_L(actor, anchor, id0, id1, speed);
            BlkC_L(actor);
            break;
        }
        case 0x31: case 0x35: {
            Name_L* n1;
            Name_L* n2;
            int id;
            STATIC_NAME(D_004EEF90, D_0049D1A0, D_0049DC70)
            STATIC_NAME(D_004EEF98, D_0049D1D0, D_0049DC90)
            STATIC_NAME(D_004EEFA0, D_0049D200, D_0049DCB0)
            STATIC_NAME(D_004EEFA8, D_0049D230, D_0049DCD0)
            n1 = 0;
            n2 = 0;
            id = 0;
            switch (type) {
            case 0x31: n1 = &D_0049D1A0; n2 = &D_0049D200; id = 0x6B; break;
            case 0x35: n1 = &D_0049D1D0; n2 = &D_0049D230; id = 0x6C; break;
            }
            if (n1 && n2) {
                DP3_L(actor, n1, 1, 1, id, 0x6D, 0x6E, 0x6F, 0x70);
                if (pm) {
                    Plc_L a;
                    Plc_L b;
                    Plc_L p;
                    SP1_L(&a, actor, n1);
                    SP1_L(&b, actor, n2);
                    SetRootM_L(actor->r3294, pm);
                    if (actor->s3310) PSetBit_L(actor->s3310, 5);
                }
            }
            break;
        }
        case 0x33: case 0x37: {
            Name_L* n;
            STATIC_NAME(D_004EEFB0, D_0049D260, D_0049DCF0)
            STATIC_NAME(D_004EEFB8, D_0049D290, D_0049DCB0)
            STATIC_NAME(D_004EEFC0, D_0049D2C0, D_0049DD00)
            n = type == 0x33 ? &D_0049D290 : &D_0049D2C0;
            DP_L(actor, n, 1, 0x3D, 0x3E, 0x3F, 0x40, 0x41);
            B2_L(actor);
            B3_L(actor);
            if (pm) {
                Plc_L p;
                SetRootM_L(actor->r3294, pm);
            }
            break;
        }
        case 0x34: case 0x38: {
            Name_L* n;
            STATIC_NAME(D_004EEFC8, D_0049D2F0, D_0049DD50)
            STATIC_NAME(D_004EEFD0, D_0049D320, D_0049DCD0)
            n = type == 0x34 ? &D_0049D2F0 : &D_0049D320;
            DP_L(actor, n, 1, 0x3D, 0x42, 0x43, 0x44, 0x45);
            B4_L(actor);
            if (pm) {
                Plc_L p;
                SetRootM_L(actor->r3294, pm);
            }
            break;
        }
        }
        actor->f3474 = s6;
        if (s6) {
            void* p = s6->push;
            if (p) {
                unsigned char isP = 0;
                Ctl_L* c = actor->ctl;
                if (c && c->IsPlayer()) isP = 1;
                if (isP && actor->b14 && !actor->b326B) {
                    World_PushObjectFromAction(D_004FFB50, p);
                    actor->b326B = 1;
                }
            }
        }
    } else if (obj) {
        SendMsg4_L(obj, actor);
    }
}
#pragma pop
