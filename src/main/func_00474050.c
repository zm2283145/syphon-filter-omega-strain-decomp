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
typedef struct { char pad[0x28]; int f28; int bits[1]; char pad30[0x988 - 0x30]; float f988; float p98C; float f990; float p994; float f998; char pad99C[2]; unsigned char b99E; unsigned char b99F; unsigned char b9A0; unsigned char b9A1; unsigned char b9A2; char pad9A3; unsigned char b9A4; } Rung_L;


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
    Rung_L* s3310; char pad3314[0x3514 - 0x3314];
    int f3514;
    signed char b3518;
};

#define MSG_HDR \
    void* vtable; int f04; int f08; int f0C; int f10; int f14; int f18; int f1C; signed char f20; char pad21[3]
typedef struct { MSG_HDR; int act; unsigned char type; char pad29[7]; int flags; int id; char pad38[8]; Plc_L plc; } Msg_L;
typedef struct { MSG_HDR; int f24; unsigned char f28; char pad29[3]; } Ev2_L;

extern "C" {
extern char D_004E0840[]; extern char D_0055D480[];
extern char D_004C3470[]; extern char D_004C3490[]; extern char D_004C34B0[]; extern char D_004C34D0[];
extern char D_004C34F0[]; extern char D_004C3510[]; extern char D_004C3530[]; extern char D_004C3550[];
extern char D_004C3570[]; extern char D_004C3590[];
extern float D_0049D038;
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
void** func_00195DD0(void* p, int i);
void* func_00195DC0(void* p, int i);
unsigned char* func_00195DB0(void* p, int i);
void Transform_SetOrientation(void* t, Plc_L* p);
void func_0018A910(void* p);
void func_0018A8C0(void* p);
void func_0018A890(void* p);
void func_0018A710(void* d, void* s);
void func_0018A700(void* p, int v);
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
float AnimChannel_GetCurrent(void* p, int i);
int Ladder_HandParity(Act_L* a, int f);
void Event_Construct(void* m, void* t);
void Event_Send(void* m, void* t, int f);
void cMessage_dtor(void* m, int f);
void ModelCtx_FindNodeById(It_L* out, int* tree, Name_L* key);
void NodeMap_End(It_L* out, int* tree);
int NodeMapIter_NotEqual(It_L* a, It_L* b);
int* NodeMapIter_Value(It_L* a);
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
static inline void NameAssignT_L(Name_L* dst, Name_L* tmp, char* src) {
    unsigned char ckc_end = 0; int ckc_i = 0; char ckc_c;
    for (; ckc_i < 0x2F; ckc_i++) { if (src[ckc_i] == 0) ckc_end = 1; if (ckc_end) ckc_c = 0; else ckc_c = src[ckc_i]; tmp->c[ckc_i] = ckc_c; }
    tmp->c[ckc_i] = 0;
    if (dst->c[0] || tmp->c[0]) QCopyA_L(dst, tmp); }
static inline void NameAssign_L(Name_L* dst, char* src) { Name_L tmp; NAME_COPY(tmp.c, src) if (dst->c[0] || tmp.c[0]) QCopyA_L(dst, &tmp); }

static inline float Recip_L(float v) { return v != 0.0f ? 1.0f / v : 3.4028235e38f; }
static inline X_L* XInit_L(X_L* x) { X_L* px = x; px->kind = 0; func_0018A910(px->pairs); func_0018A8C0(px->tail); return px; }
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
static inline X_L* XSet0_L(X_L* x, int id, void* a, unsigned char k) { x->pairs[0].id = id; x->pairs[0].a = a; x->kind = k; return x; }
static inline X_L* Set5b_L(X_L* x, int a, int b, int c, int d, int e, void* act)
{
    return XSetR_L(XSetR_L(XSetR_L(XSetR_L(XSet0_L(x, a, act, 1), 1, b, act, 1), 3, c, act, 1), 5, d, act, 1), 6, e, act, 1);
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
        AnimCtl_InstallMotion(an, out, func_0018A2F0(sel), &vec, &y, &e1, &e2, func_0018A2E0(sel), func_0018A2D0(sel), func_0018A2C0(sel));
        func_0018A260(&e2, -1);
        func_0018A260(&e1, -1);
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
        *func_00195DD0(s + 0x1F0, idx) = o;
        Transform_SetOrientation(func_00195DC0(s + 0x200, idx), pp);
        p = o ? func_00133330(o) : 0;
        if (p) m = Transform_GetUpdated(p); else m = Mtx_GetIdentity();
        Transform_SetOrientation(func_00195DC0(s + 0x260, idx), Mtx_ToPlacement(&t, m));
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
static inline int FindAnchor_L(Act_L* actor, Name_L* key)
{
    It_L it;
    It_L end;
    Lib_L* lib = (Lib_L*)actor->sys.lib;
    ModelCtx_FindNodeById(&it, &lib->tree, key);
    NodeMap_End(&end, &lib->tree);
    return NodeMapIter_NotEqual(&it, &end) ? *NodeMapIter_Value(&it) : 0;
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
        func_0018A890(ps->sub);
        ps->f40 = anchor;
        ps->f48 = 1;
        func_0018A710(&ps->x, px);
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
        func_0018A890(ps->sub);
        ps->f44 = id;
        ps->f48 = 0;
        func_0018A710(&ps->x, &x);
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
    Event_Construct(p, D_0055D480);
    p->vtable = D_004E0840;
    p->f24 = 0x24;
    p->f28 = 0;
    Event_Send(p, actor, 1);
    m.vtable = D_004E0840;
    cMessage_dtor(p, 0);
}

typedef struct { char c[0x20]; } __attribute__((aligned(16))) Name2_L;
typedef struct { float a; float b; signed char f; } Pr_L;

extern "C" {
extern float D_004A0410; extern float D_004A0418;
extern char D_004C35B0[]; extern char D_004C35D0[]; extern char D_004C35F0[]; extern char D_004C3610[]; extern char D_004C3630[];
extern char D_004C3650[]; extern char D_004C3670[];
void Actor_PrepareNeutralChannels(Act_L* a, int b, int c, int d, int e);
void Ladder_Intent(Act_L* a, unsigned char* s, unsigned char* u, unsigned char* d, unsigned char* x, unsigned char* y, unsigned char* z);
void* Root_GetWorldPlacement(void* r);
float* Placement_GetPosition(void* p);
float Math_FMod(float x, float y);
unsigned char Ladder_ChannelArrived(void* a, int ch, float thr);
void Actor_SendSoundImmediate(Act_L* a);
void AnimChannel_SetDirect(void* a, int ch, float v);
unsigned char AnimPriority_Helper3(void* p, int i);
void AnimPriority_Helper2(void* p, int i, int f);
void AnimPriority_Helper1(void* p);
void AnimPriority_Helper0(void* p, int i, unsigned char t);
void MotionRequest_Construct(void* p, void* name);
void NamedRootMap_Find(It_L* out, void* map, Name2_L* key);
X_L* func_00190F90(X_L* x, Pr_L* p, unsigned char id, Act_L* a);
void Ladder_ReleaseAlignment(Act_L* a);
void Ladder_AlignTopBottom(Act_L* a, bool top);
void Ladder_BlendToTarget(Act_L* a, float t);
void Ladder_Dismount(Act_L* a);
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
static inline bool Valid_L(Rung_L* r) { return r->f990 > -3.4028235e38f && r->f998 < 3.4028235e38f; }
static inline bool InRange_L(float t) { bool b = t > 0.5f && t < 1.5f; return b; }
static inline bool RBit_L(Rung_L* r, int i) { bool b = (r->bits[i / 32] >> (i & 31)) & 1; return b; }
static inline void PriReset_L(Act_L* a)
{
    char* p = (char*)&a->pri;
    unsigned char t = AnimPriority_Helper3(p + 0xC, 0xE);
    AnimPriority_Helper2(p + 4, 0xE, 0);
    AnimPriority_Helper1(p);
    AnimPriority_Helper0(p, 0xE, t);
}
static inline void RungScan_L(Act_L* a, int set)
{
    Rung_L* r = a->s3310;
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
}
struct ItC_L { int n; ItC_L() {} ItC_L(const ItC_L& o) : n(o.n) {} };
static inline X_L* MakeX_L(X_L* x, unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, Act_L* act)
{
    XInit_L(x);
    return Set5_L(x, a, b, c, d, e, act);
}
static inline float ClampZ_L(float x, float z, float o) { float lo = z; float hi = o; float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline void PrInitZ_L(Pr_L* p, float t, float z, float o) { p->f = 0; p->a = p->b = ClampZ_L(t, z, o); }
static inline void PrInit_L(Pr_L* p, float v) { p->f = 0; p->a = p->b = Clamp01_L(v); }







extern "C" void Ladder_Update(Act_L* actor, float dt)
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
    Actor_PrepareNeutralChannels(actor, 0, 0, 0, 0);
    if (((actor->f3248 >> 27) & 1) && !(AnimChannel_GetCurrent(sys->f10, 0x15) < 0.6f)) {
        if (Ladder_HandParity(actor, 0))
            actor->f3248 |= 0x800000;
        else
            actor->f3248 |= 0x1000000;
        actor->f3248 &= ~0x8000000;
    }
    if (!((actor->pri.bits >> 12) & 1) && !((actor->pri.bits >> 15) & 1)) {
    Ladder_Intent(actor, &slide, &up, &down, &k3, &k4, &k5);
    none = !slide && !up && !down;
    act = (up && !NB_L(actor->f3248, 18)) || (down && !NB_L(actor->f3248, 19)) || (slide && !NB_L(actor->f3248, 20));
    nearTop = false;
    nearBot = false;
    if (actor->s3310 && Valid_L(actor->s3310)) {
        float y = Placement_GetPosition(Root_GetWorldPlacement(actor->r3298))[2];
        Rung_L* r = actor->s3310;
        float bot = r->f998 + D_004A0410;
        float top = r->f990;
        float dd = D_004A0418;
        float lim = 1.5f * dd;
        if (top - y < lim) {
            if (InRange_L(Math_FMod(Div_L(Abs_L(top - r->f988), dd), 2.0f))) nearTop = true;
        }
        if (y - bot < lim) {
            { float h = actor->s3310->f988; if (InRange_L(Math_FMod(Div_L(Abs_L(bot - h), D_004A0418), 2.0f))) nearBot = true; }
        }
    }
    if (Ladder_ChannelArrived(sys->f10, 0x15, 0.2f)) Actor_SendSoundImmediate(actor);
    if ((actor->f3248 >> 20) & 1) {
        if (actor->b31B5)
            actor->f31D8 = Min_L(1.0f, actor->f31D8 + dt);
        else
            actor->f31D8 = Max_L(0.0f, actor->f31D8 - 2.0f * dt);
    } else {
        actor->f31D8 = 0.0f;
    }
    AnimChannel_SetDirect(sys->f10, 0x12, actor->f31D8);
    if (!((actor->pri.bits >> 13) & 1)) {
        if ((up && !nearTop && ((actor->f3248 >> 18) & 1)) || (down && !nearBot && ((actor->f3248 >> 19) & 1)) || (slide && ((actor->f3248 >> 20) & 1))) {
            actor->f3248 &= ~0x800000;
            actor->f3248 &= ~0x1000000;
            return;
        }
    }
    if ((((up && !nearTop) || (down && !nearBot)) && ((actor->pri.bits >> 13) & 1) && (!((actor->f3248 >> 22) & 1) || ((actor->f3248 >> 21) & 1)) &&
         !((actor->f3248 >> 25) & 1) && !((actor->f3248 >> 26) & 1) && !(AnimChannel_GetCurrent(sys->f10, 0x15) <= 0.4f)) || slide) {
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
                    MotionRequest_Construct(ps->sub, &tmp);
                    ps->f48 = 1;
                    func_0018A710(&ps->x, px);
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
            Ladder_ReleaseAlignment(actor);
        } else {
            {
                Name2_L t0, t1, t2, t3;
                QZero2_L(&name);
                if (up) {
                    if (Ladder_HandParity(actor, 0)) { Name2AssignT_L(&name, &t0, D_004C35D0); l = 0x5B; rr = 0x5A; }
                    else { Name2AssignT_L(&name, &t1, D_004C35F0); l = 0x5A; rr = 0x5B; }
                    i0 = 0x50; i1 = 0x51; i2 = 0x52; i3 = 0x53; i4 = 0x54;
                } else {
                    if (Ladder_HandParity(actor, 0)) { Name2AssignT_L(&name, &t2, D_004C3610); l = 0x5B; rr = 0x5A; }
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
                    NamedRootMap_Find((It_L*)&it, (char*)sys->lib + 0x44, &name);
                    {
                        j2 = it;
                        j3 = j2;
                        anim = *(int*)((char*)j3.n + 0x30);
                    }
                    px = Set5b_L(&x, (unsigned char)i0, (unsigned char)i1, (unsigned char)i2, (unsigned char)i3, (unsigned char)i4, actor);
                    { float lo = 0.0f; float xx = 0.9f; float z; float hi; z = lo; hi = 1.0f; p0.f = 0; asm { max.s lo, xx, lo; min.s lo, lo, hi } p0.a = p0.b = lo; { float o = 1.0f; PrInitZ_L(&p1, 0.4f, z, o); PrInitZ_L(&p2, 0.9f, z, o); PrInitZ_L(&p3, 0.4f, z, o); } }
                    q = func_00190F90(func_00190F90(func_00190F90(func_00190F90(px, &p0, l, actor), &p1, rr, actor), &p2, 0x5C, actor), &p3, 0x5C, actor);
                    {
                        Sel_L sel;
                        Sel_L* ps = &sel;
                        ps->mode = 2;
                        func_0018A890(ps->sub);
                        ps->f44 = anim;
                        ps->f48 = 1;
                        func_0018A710(&ps->x, q);
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
        Ladder_BlendToTarget(actor, dt);
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
            if (Ladder_HandParity(actor, 0)) {
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
                    MotionRequest_Construct(ps->sub, &tname);
                    ps->f48 = 1;
                    func_0018A710(&ps->x, px);
                    ps->f98 = -1.0f;
                    ps->f9C = 0;
                    RateM_L(&r, 0.2f);
                    Install_L(actor, &sel, &r);
                    XDtorN_L((X_L*)((char*)&sel + 0x4C));
                }
                XDtor_L(&x);
            }
        }
        if ((up && nearTop) || (down && nearBot)) Ladder_AlignTopBottom(actor, nearBot);
        Ladder_BlendToTarget(actor, dt);
        return;
    }
    if (actor->b31B6) {
        actor->f3208 |= 1;
        Ladder_Dismount(actor);
        actor->b31B6 = 0;
        Ladder_BlendToTarget(actor, dt);
        return;
    }
    if ((up && ((actor->f3248 >> 25) & 1)) || (down && ((actor->f3248 >> 26) & 1))) {
        actor->f3208 |= 1;
        actor->f3248 |= 0x8000000;
        Ladder_ReleaseAlignment(actor);
        Ladder_BlendToTarget(actor, dt);
        return;
    }
    if (((down && nearBot && !((actor->f3248 >> 25) & 1)) || (up && nearTop && !((actor->f3248 >> 26) & 1))) && !((actor->f3248 >> 21) & 1) && ((actor->pri.bits >> 13) & 1)) {
        actor->f3208 |= 1;
        Ladder_AlignTopBottom(actor, nearBot);
        Ladder_BlendToTarget(actor, dt);
        return;
    }
    if (!((actor->pri.bits >> 14) & 1)) {
        actor->f3208 |= 1;
        Ladder_BlendToTarget(actor, dt);
    }
    } else {
        if (!((actor->pri.bits >> 12) & 1) && !((actor->f3248 >> 21) & 1)) Ladder_BlendToTarget(actor, dt);
    }
}
#pragma pop
