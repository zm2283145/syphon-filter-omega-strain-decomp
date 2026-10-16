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
extern char D_004E0840[]; extern char D_0055D480[];
extern char D_004C3470[]; extern char D_004C3490[]; extern char D_004C34B0[]; extern char D_004C34D0[];
extern char D_004C34F0[]; extern char D_004C3510[]; extern char D_004C3530[]; extern char D_004C3550[];
extern char D_004C3570[]; extern char D_004C3590[];
extern float D_0049D038;
void* func_0015AC90(int* p, int v);
unsigned char func_001960A0(int* a, int* b);
void* Object_LookupById(int* id);
void* Camera_GetNode(void* o);
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
signed char MotionRequest_GetMode(Sel_L* s);
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
        AnimCtl_InstallMotion(an, out, MotionRequest_GetMode(sel), &vec, &y, &e1, &e2, func_0018A2E0(sel), func_0018A2D0(sel), func_0018A2C0(sel));
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
        p = o ? Camera_GetNode(o) : 0;
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
        parent = obj ? Camera_GetNode(obj) : 0;
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
static inline bool Busy_L(Act_L* a) { bool b; unsigned char s = a->GetState(); b = true; if (s != 3 && s != 2) b = false; return b; }
static inline int PBit_L(Pri_L* p, int n) { return (p->bits >> n) & 1; }
static inline float Cur_L(Act_L* a) { char* an = (char*)&a->sys; return AnimChannel_GetCurrent(an + 0x10, 0x15); }
#define Near_L(a, bit) ((((a)->f3248 >> (bit)) & 1) && Cur_L(a) < 0.15f)

extern "C" void Ladder_HandleExitAction(Act_L* actor0, Msg_L* msg)
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
        o2 = IdNe_L(&msg->id, tm1) ? Object_LookupById(&msg->id) : 0;
        s1 = actor->r3294;
        Root_SetWorldPlacement(s1, &plc);
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
                if (Ladder_HandParity(actor, 1)) NameAssign_L(&name, D_004C3470); else NameAssign_L(&name, D_004C3490);
                kind = 8;
                break;
            case 0x20:
                if (Ladder_HandParity(actor, 1)) NameAssign_L(&name, D_004C34B0); else NameAssign_L(&name, D_004C34D0);
                kind = 4;
                break;
            case 0x1F:
                if (Ladder_HandParity(actor, 1)) NameAssign_L(&name, D_004C34F0); else NameAssign_L(&name, D_004C3510);
                kind = 2;
                break;
            case 0x21:
            case 0x22:
                if ((signed char)sel == 0x21) {
                    if (Ladder_HandParity(actor, 1)) NameAssign_L(&name, D_004C3530); else NameAssign_L(&name, D_004C3550);
                } else if ((signed char)sel == 0x22) {
                    if (Ladder_HandParity(actor, 1)) NameAssign_L(&name, D_004C3570); else NameAssign_L(&name, D_004C3590);
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

