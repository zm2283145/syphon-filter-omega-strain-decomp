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
typedef struct { char pad0[0x11]; unsigned char b11; char pad12[2]; unsigned char b14; char pad15[0x28 - 0x15]; int mode; int bits[1]; } Phys_L;

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

typedef struct { char pad[0x415]; unsigned char b415; } Ob2_L;
typedef struct {
    char pad0[0x14]; unsigned char b14; char pad15[0x2C - 0x15];
    unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x58 - 0x2F];
    Ctl_L* ctl; char pad5C[0x2DD0 - 0x5C];
    void* voice; int voiceId; char pad2DD8[0x2DEC - 0x2DD8]; int f2DEC; char pad2DF0[0x2EC0 - 0x2DF0];
    Sys_L sys; char pad2EF4_[0x3204 - 0x2EC0 - sizeof(Sys_L)];
    int f3204; char pad3208[4];
    char prio[4]; int f3210; char pad3214[0x324C - 0x3214];
    int f324C; char pad3250[0x326B - 0x3250];
    unsigned char b326B;
    int f326C; char pad3270[0x3290 - 0x3270];
    Root_L* r3290; Root_L* r3294; char pad3298[0x3310 - 0x3298];
    Phys_L* s3310; Ob2_L* s3314; char pad3318[0x33A5 - 0x3318];
    unsigned char b33A5; char pad33A6[0x3474 - 0x33A6];
    Obj_L* f3474; char pad3478[0x34E4 - 0x3478];
    int f34E4[12]; char pad3514[0x3590 - 0x3514];
    unsigned char b3590;
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
void MotionTokens_Init(void* p);
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
            ckc_c = 0; if (ckc_end) asm { .set reorder } else ckc_c = ckc_s[ckc_i]; (dst)[ckc_i] = ckc_c; \
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

static inline float Recip_L(float v) { float r; if (v != 0.0f) r = 1.0f / v; else { r = 3.4028235e38f; asm { .set reorder } } return r; }
static inline float ClampY_L(float x, float z, float o) { float lo = z; float hi = o; float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline void RangeInitY_L(Range_L* r, float t, float z, float o) { float v; v = 0.0f; r->flag = 0; v = ClampY_L(t, z, o); r->hi = v; r->lo = v; }

static inline X_L* XInit_L(X_L* x) { X_L* px = x; px->kind = 0; MotionTokens_Init(px->pairs); func_0018A8C0(px->tail); return px; }
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

typedef struct { char pad[0x11]; unsigned char b11; char pad12[0x3D0 - 0x12]; unsigned char b3D0; } PhM_L;
typedef struct { void* vt; char pad[0x1C]; unsigned char b20; char pad2[0x19F]; } SMsg_L;
typedef struct { char pad[0x190]; } SReq_L;
typedef struct { MSG_HDR; unsigned char f24; char pad25[0xB]; Mtx_L m; } MsgM_L;
typedef struct { MSG_HDR; void* f24; signed char f28; } MsgE_L;
struct MA_L;
struct V4C_L { V4_L v; V4C_L() {} };
struct MtxC_L { Mtx_L m; MtxC_L() {} };
struct MV_L {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual V4C_L GetPos();
    virtual void v56(); virtual void v57(); virtual void v58();
    virtual MtxC_L GetMtx();
    virtual void v60(); virtual void v61();
    virtual void Hit(MA_L* src, int k, int n, float f, int z0, int z1, int z2);
    virtual void v63();
    virtual unsigned char Kind();
};
typedef struct {
    char pad0[0x14]; unsigned char b14; char pad15[0x58 - 0x15];
    Ctl_L* ctl; char pad5C[0x2EC0 - 0x5C];
    Sys_L sys; char pad2EF4_[0x326C - 0x2EC0 - sizeof(Sys_L)];
    int f326C; char pad3270[0x3310 - 0x3270];
    PhM_L* s3310; Ob2_L* s3314; char pad3318[0x33CC - 0x3318];
    int f33CC; char pad33D0[0x33E8 - 0x33D0];
    unsigned char b33E8; char pad33E9[0x3524 - 0x33E9];
    void* inv;
} MAD_L;
struct MA_L : MV_L {
    char pad4[0x14 - 4]; unsigned char b14; char pad15[0x58 - 0x15];
    Ctl_L* ctl; char pad5C[0x2EC0 - 0x5C];
    Sys_L sys; char pad2EF4_[0x326C - 0x2EC0 - sizeof(Sys_L)];
    int f326C; char pad3270[0x3310 - 0x3270];
    PhM_L* s3310; Ob2_L* s3314; char pad3318[0x33CC - 0x3318];
    int f33CC; char pad33D0[0x33E8 - 0x33D0];
    unsigned char b33E8; char pad33E9[0x3524 - 0x33E9];
    void* inv;
};
typedef struct { char pad[0x24]; float f24; } Cam_L;
extern "C" {
unsigned char WeaponInv_GetHeldClass(void* inv);
Range_L* func_00192750(Range_L* r, float f0, float f1, unsigned char z);
void Actor_SetDeathMotionOverride(MA_L* a, char* n, int f);
unsigned char Secondary_RequestOneShot(Ob2_L* o, Name_L* n, unsigned char kind, AEv_L* p);
void SoundPosRequest_Ctor(SMsg_L* m, void* req, V4_L* pos);
void FileMan_Release(void* p, int f);
void World_PushObject(void* w, MA_L* a, int f);
extern float D_0048A268; extern float D_0048A278;
extern Cam_L* D_004FFBD0;
extern char D_0049DF38[]; extern char D_0049DF48[]; extern char D_0049DF58[];
extern char D_0049DF70[]; extern char D_0049DF88[]; extern char D_0049DFA0[];
extern char D_0049DFB8[]; extern char D_0049DFC8[];
extern char D_004D9360[]; extern char D_004DA8F0[]; extern char D_004DAE30[]; extern char D_004DCF10[];
extern char D_004EEEE8[]; extern char D_0055D4E0[];
extern char D_004F2310[]; extern char D_004F2650[];
extern float D_004EEEB0; extern float D_004EEEB8; extern float D_004EEEC0; extern float D_004EEEC8;
}
static inline void RateF_L(Rate_L* r, float s) { r->x = s; r->y = s; r->z = Recip_L(s); r->w = Recip_L(s); }
static inline void MNameP_L(Name_L* n, char* s)
{
    if (s) NAME_COPY(n->c, s)
    else QZero_L(n);
}
static inline void MulV_L(V4_L* v, Mtx_L* m)
{
    __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory");
}
typedef void (*VRet_F)(void* out, MA_L* a);
#define VCALL_RET(a, off, out) ((VRet_F)(*(void***)(a))[(off) / 4])(out, a)
static inline bool Stun_L(int k) { bool r = 1; if (k != 3 && k != 2) r = 0; return r; }
static inline bool Blunt_L(int c) { bool r = 1; if (c != 4 && c != 0xA) r = 0; return r; }
static inline bool Stun2_L(MA_L* t) { bool r; int k = t->Kind(); r = 1; if (k != 3 && k != 2) r = 0; return r; }
static inline bool Blunt2_L(int c) { bool r; int cc = c; r = 1; if (cc != 4 && cc != 0xA) r = 0; return r; }
static inline bool Blunt4_L(bool* tw, int c) { bool r = 1; if (c != 4 && c != 0xA) r = 0; return r; }
static inline void VSet_L(V4_L* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
static inline void VSet2_L(V4_L* v, float x, float y, float z, float w) { v->z = z; v->w = w; v->y = y; v->x = x; }
static inline void VSet3_L(V4_L* v, float x, float y) { v->z = 0.0f; v->w = 1.0f; v->y = y; v->x = x; }
static inline int MId_L(MA_L* t) { int tmp; int* p; if (t) p = (int*)((char*)t + 0xC); else { tmp = -1; p = &tmp; } return *p; }
static inline Range_L* Rng_L(float d) { Range_L rg; return func_00192750(&rg, d, d, 0); }
static inline void Blk1_L(MA_L* a, char* n0, int mode, float dist)
{
    Name_L n;
    Rate_L r;
    X_L x;
    X_L* px;
    Anm_L* m;
    Sys_L* sys;
    Name_L* pn;
    XInit_L(&x);
    sys = &a->sys;
    RateDef_L(&r);
    px = XSetR_L(XSetR_L(XSetR_L(XSetR_L(&x, 0, 0x94, a, 1), 5, 0x96, a, 1), 3, 0x95, a, 1), 6, 0x97, a, 1);
    MNameP_L(&n, n0);
    pn = &n;
    { X_L* py = func_00190F90(px, Rng_L(dist), mode & 0xFF, a);
    m = Motion_Lookup(sys->lib, pn);
    Mot2_L(sys, m, 3, &r, py); }
    XDtor_L(&x);
}
static inline void MtxEv_L(MA_L* t, Mtx_L* mt)
{
    MsgM_L e;
    MsgM_L* pe = &e;
    Event_Construct(pe, D_0055D4E0);
    pe->vtable = D_004D9360;
    pe->f24 = 2;
    Q4(&pe->m, mt);
    Event_Send(&e, t, 1);
    e.vtable = D_004D9360;
    cMessage_dtor(&e, 0);
}
static inline void Blk3_L(MA_L* t, char* n1)
{
    Name_L n;
    Rate_L r;
    X_L x;
    Anm_L* m;
    Sys_L* sys;
    XInit_L(&x);
    sys = &t->sys;
    RateF_L(&r, 0.01f);
    MNameP_L(&n, n1);
    m = Motion_Lookup(sys->lib, &n);
    Mot2_L(sys, m, 1, &r, &x);
    XDtor_L(&x);
}
static inline unsigned char SndReq_L(MA_L* a, char* sn)
{
    Name_L n;
    AEv_L e;
    unsigned char ok;
    AEv_L* pe = &e;
    Event_Construct(pe, D_00542B60);
    pe->vtable = D_004DA930;
    pe->f24 = 4;
    pe->f28 = 0;
    pe->f2C = (int)a;
    pe->f30 = 0;
    pe->f34 = 0.0f;
    MNameP_L(&n, sn);
    ok = Secondary_RequestOneShot(a->s3314, &n, 3, &e);
    e.vtable = D_004DA930;
    cMessage_dtor(&e, 0);
    return ok;
}
#pragma push
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
extern "C" void Melee_StartAttack(MA_L* a, MA_L* t, int flag)
{
    bool r;
    int cls = WeaponInv_GetHeldClass(a->inv);
    bool two = cls == 0xB;
    int blunt;
    float dist;
    int mode;
    r = 1; if (cls != 4 && cls != 0xA) r = 0; blunt = (unsigned char)r;
    if (two) dist = D_0048A278; else dist = D_0048A268;
    mode = 0x99;
    /* empty asm: scheduling barrier keeps retail beqz/delay-slot shape */
    if (two) asm { .set reorder } else mode = 0x98;
    if (a->b33E8 == 0 && (a->b14 == 0 || D_004FFBD0->f24 <= 0.0f)) {
        if (blunt == 0 && flag != 0 && t != 0) {
            if (!Stun2_L(t)) {
                char* n0 = D_0049DF38;
                char* n1 = D_0049DF48;
                char* n2 = D_0049DF58;
                if (two) {
                    n0 = D_0049DF70;
                    n1 = D_0049DF88;
                    n2 = D_0049DFA0;
                }
                { PhM_L* p = a->s3310; if (p) p->b3D0 = 0; }
                if (t) { PhM_L* p = t->s3310; if (p) p->b3D0 = 0; }
                Blk1_L(a, n0, mode, dist);
                { PhM_L* p = a->s3310; if (p) p->b11 = 1; }
                B4_L((Act_L*)(void*)a);
                if (t) {
                    {
                        MtxC_L mc = a->GetMtx();
                        V4_L v;
                        VSet_L(&v, D_004EEEB0, D_004EEEB8, 0.0f, 1.0f);
                        if (two) { v.x = D_004EEEC0; v.y = D_004EEEC8; }
                        MulV_L(&v, &mc.m);
                        Q1_L(mc.m.m[3], &v);
                        MtxEv_L(t, &mc.m);
                    }
                    Blk3_L(t, n1);
                    {
                        int h = 0xA;
                        /* empty asm: scheduling barrier keeps retail beqz/delay-slot shape */
                        if (two) asm { .set reorder } else h = 9;
                        Actor_SetDeathMotionOverride(t, n2, 1);
                        t->Hit(a, 2, h, 10000.0f, 0, 0, 0);
                    }
                }
                if (a->b14) {
                    Ctl_L* c = a->ctl;
                    bool p = 0;
                    if (c && c->IsPlayer()) p = 1;
                    if (p) World_PushObject(D_004FFB50, a, 0);
                }
                a->b33E8 = 1;
                a->f33CC = MId_L(t);
                goto done;
            }
        }
        if (!two) {
            char* sn;
            if (blunt) sn = D_0049DFB8; else sn = D_0049DFC8;
            if (a->s3314) {
                if (SndReq_L(a, sn)) {
                    if (blunt) {
                        V4C_L pos = a->GetPos();
                        SMsg_L m;
                        SoundPosRequest_Ctor(&m, D_004F2310, &pos.v);
                        m.b20 = 1;
                        Event_Send(&m, D_004FFB50, 0);
                        m.vt = D_004DAE30;
                        FileMan_Release((char*)&m + 0x114, -1);
                        FileMan_Release((char*)&m + 0x78, -1);
                        cMessage_dtor(&m, 0);
                    } else if (t == 0) {
                        V4C_L pos = a->GetPos();
                        SMsg_L m;
                        SoundPosRequest_Ctor(&m, D_004F2650, &pos.v);
                        m.b20 = 1;
                        Event_Send(&m, D_004FFB50, 0);
                        m.vt = D_004DAE30;
                        FileMan_Release((char*)&m + 0x114, -1);
                        FileMan_Release((char*)&m + 0x78, -1);
                        cMessage_dtor(&m, 0);
                    }
                    a->b33E8 = 1;
                    a->f33CC = MId_L(t);
                }
            }
        }
    done:
        if (a->b33E8 == 1 && a->b14) {
            MsgE_L e;
            MsgE_L* pe = &e;
            Event_Construct(pe, D_004EEEE8);
            pe->vtable = D_004DCF10;
            pe->vtable = D_004DA8F0;
            pe->f24 = t;
            pe->f28 = flag;
            pe->f20 = 4;
            e.f1C = 0x40;
            Event_Send(&e, a, 0);
            e.vtable = D_004DCF10;
            cMessage_dtor(&e, 0);
        }
    }
}
#pragma pop
