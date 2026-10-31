#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off

static inline void RQ(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void SQZ(void* d) { __asm__ volatile("sq $0, 0(%0)" : : "r"(d) : "memory"); }
static inline void RQ3(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)\n sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
static inline void RQ4(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void RQ2(void* d, const void* s) { const __int128* sp = (const __int128*)s; __int128* dp = (__int128*)d; *dp = *sp; }


struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { RQ(this, &o); }
    V& operator=(const V& o) { RQ(this, &o); return *this; }
    V operator+(const V& b) const { V r; const V* s = this; V* pr = &r; const V* pb = &b; asm { lqc2 vf1, 0x0(s); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) } return r; }
    V operator-(const V& b) const { V r; const V* s = this; const V* pb = &b; V* pr = &r; asm { lqc2 vf1, 0x0(s); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) } return r; }
    V& operator+=(const V& b) { V* d = this; V* s = this; const V* pb = &b; asm { lqc2 vf1, 0x0(s); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } return *this; }
} __attribute__((aligned(16)));
struct M44;
struct Q {
    float x, y, z, w;
    Q() {}
    Q(const Q& o) { RQ2(this, &o); }
    inline Q(const M44& m);
} __attribute__((aligned(16)));
struct M34 { float m[3][4]; };
struct M44;
static inline void MtxToQuat(const void* m, void* out);
static inline void QuatToMtx(void* a_, const void* b);
extern "C" void Mtx44_FromMtx34(M44* d, const M34* s);
struct M44 { float m[4][4]; const V& Row(int i) const { return *(const V*)m[i]; } M44() {} M44(const M34& s) { Mtx44_FromMtx34(this, &s); } M44(const Q& q) { QuatToMtx(this, &q); } } __attribute__((aligned(16)));

extern "C" { void Event_Construct(void* m, void* t); void Event_Send(void* m, void* t, int f); void cMessage_dtor(void* m, int f); }
extern char D_0055D480[], D_004E0840[];
struct ActMsg {
    void* vtable; char pad4[0x1C]; unsigned char kind; char pad21[3]; int action; unsigned char on; char pad29[7];
    ActMsg(int a) { ActMsg* m = this; Event_Construct(m, D_0055D480); m->vtable = D_004E0840; m->action = a; m->on = 0; kind = 1; }
    ~ActMsg() { vtable = D_004E0840; cMessage_dtor(this, 0); }
} __attribute__((aligned(16)));
static inline void Send(const ActMsg& m, void* t) { Event_Send((void*)&m, t, 1); }
struct Root { char pad0[0xB0]; void* parent; char padB4[0xD0 - 0xB4]; float weight; };
struct Comp {
    virtual void v0(); virtual void v1(); virtual void SetRotation(M44* m); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void Translate(const V& d);
};
struct MCtx { char pad0[0x28]; Comp* comp; };
struct Ctrl {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void OnTeleport(V* d); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual unsigned char Kind();
};
struct Hist { int key; float angle; };
struct Phys { char pad0[0x11]; unsigned char f11; char pad12[0x2F0 - 0x12]; V f2F0; V f300; V f310; V f320; V f330; };
extern "C" void Actor_LandFromAir(void* a, int f);
static inline void PhysReset(Phys* p) { SQZ(&p->f330); SQZ(&p->f320); RQ(&p->f300, &p->f2F0); SQZ(&p->f310); }
struct Act {
    char pad0[0x58]; Ctrl* ctrl; char pad5C[0x2E50 - 0x5C];
    MCtx mc; char pad2E7C[0x3030 - 0x2E7C];
    char heading[0x58]; char hist[0x10]; int histIdx; char pad309C[4]; int f30A0; float f30A4; int f30A8; char pad30AC[0x3210 - 0x30AC]; int flags; char pad3214[0x3290 - 0x3214];
    Root* flor; Root* edge; Root* ladd; char pad329C[0x3310 - 0x329C];
    Phys* phys; char pad3314[0x34C0 - 0x3314];
    V f34C0;
};
struct Msg {
    char pad0[0x24]; unsigned char mode; char pad25[0x30 - 0x25];
    M34 m; V row3;
    V Trans() const { return row3; }
};

extern "C" {
extern signed char D_004E1D88;
extern int D_004E1D90;
extern int D_004E1D94;
extern int D_004E1D98;
extern int D_004E1D9C;
void* SceneRoot_GetPoseCache(Root* r);
void* Root_GetWorldPlacement(Root* r);
V* Placement_GetPosition(void* p);
Q* Placement_GetQuat(void* p);
V* Vec4_Assign(V* d, const V* s);
V* Actor_AddTeleportXyz(V* a, const V* b);
void SceneRoot_SetPoseCachePos(Root* r, V* p);
void Root_PublishPosition(Root* r, V* p);
void Actor_AddTeleportLanes(void* p, const V* d);
void ModelCtx_ComputeBounds(MCtx* m);
void ModelCtx_ComputeCentroid(MCtx* m);
float Math_Atan2f(float y, float x);
Hist* History_At(void* h, int i);
void ActorHeading_RetargetLast(void* h, float t);
Q* func_00132800(Q* d, Q* s);
Q* Quat_Conjugate(Q* d, Q* s);
Q* Quat_MulInPlace(Q* a, const Q* b);
void SceneRoot_SetPoseCacheRot(Root* r, Q* q);
void Root_SetWorldOrientationReset(Root* r, const Q* q);
}

static inline void MtxToQuat(const void* m, void* out) {
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
}
static inline void QuatToMtx(void* a_, const void* b) {
    void* a = a_;
    __asm__ volatile("lqc2 vf1, 0x0(%1); vadd.xyzw vf2, vf1, vf1; vaddw.xyz vf3, vf0, vf0w; vmulx.w vf8, vf0, vf0x; vmulx.w vf9, vf0, vf0x; vmuly.xyzw vf5, vf1, vf2y; vmulz.xyzw vf6, vf1, vf2z; vmulx.xyzw vf4, vf1, vf2x; vmulx.w vf10, vf0, vf0x; vsubay.x ACC, vf3, vf5y; vmsubz.x vf8, vf3, vf6z; vsubw.x vf9, vf5, vf6w; vaddw.x vf10, vf6, vf5w; vaddw.y vf8, vf4, vf6w; vsubax.y ACC, vf3, vf4x; vmsubz.y vf9, vf3, vf6z; vsubw.y vf10, vf6, vf4w; vsubw.z vf8, vf4, vf5w; vaddw.z vf9, vf5, vf4w; vsubax.z ACC, vf3, vf4x; vmsuby.z vf10, vf3, vf5y; sqc2 vf0, 0x30(%0); sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0)" : : "r"(a), "r"(b) : "memory");
}
inline Q::Q(const M44& m) { const M44* pm = &m; Q* q = this; MtxToQuat(pm, q); }
static inline Q QMul(const Q& q0, const Q& p0) {
    Q r; Q* pr = &r; const Q* q = &q0; const Q* p = &p0;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vmul.xyzw vf3, vf1, vf2; vopmula.xyz ACC, vf1, vf2; vmaddaw.xyz ACC, vf1, vf2w; vmaddaw.xyz ACC, vf2, vf1w; vopmsub.xyz vf4, vf2, vf1; vsubaz.w ACC, vf3, vf3z; vmsubay.w ACC, vf0, vf3y; vmsubx.w vf4, vf0, vf3x; sqc2 vf4, 0x0(%0)" : : "r"(pr), "r"(q), "r"(p) : "memory");
    return r;
}

static inline bool HasParent(Root* r) { return r->parent != 0; }
static inline bool Free(Root* r) { return !(HasParent(r) != 0); }
static inline bool Free2(Act* a) { bool r = false; bool f = Free(a->flor); if (f && Free(a->edge)) r = true; return r; }
static inline bool AllFree(Act* a) { bool r = false; if (Free2(a) && Free(a->ladd)) r = true; return r; }
static inline const V& WorldPos(Root* r) { return *Placement_GetPosition(Root_GetWorldPlacement(r)); }
static inline void MovePose(Root* r, const V& d) { V p; Vec4_Assign(&p, Placement_GetPosition(SceneRoot_GetPoseCache(r))); Actor_AddTeleportXyz(&p, &d); SceneRoot_SetPoseCachePos(r, &p); }
static inline void MoveWorld(Root* r, const V& d) { V p; Vec4_Assign(&p, Placement_GetPosition(Root_GetWorldPlacement(r))); Actor_AddTeleportXyz(&p, &d); Root_PublishPosition(r, &p); }
static inline void RootTranslate(Root* r, const V& d) { MovePose(r, d); MoveWorld(r, d); }
static inline void MoveRoot(Root* r, const V& d) {
    RootTranslate(r, d);
}
static inline void Translate(Act* a, const V& d) { MCtx* mc = &a->mc; mc->comp->Translate(d); ModelCtx_ComputeBounds(mc); ModelCtx_ComputeCentroid(mc); }
static inline float Atan2(float y, float x) { return Math_Atan2f(y, x); }
static inline float HeadingOfT(const M44& m) {
    V r0; { V* dp=&r0; RQ(dp, m.m[0]); } __asm__ volatile("" : : "r"(&m));
    V r1(*(const V*)m.m[1]);
    float z1 = r1.z;
    if (r0.z < z1) return Atan2(r0.y, r0.x);
    else return Atan2(-r1.x, r1.y);
}
static inline float HeadingOf(const M44& m) {
    V r0(*(const V*)m.m[0]);
    V r1(*(const V*)m.m[1]);
    float z1 = r1.z;
    if (r0.z < z1) return Atan2(r0.y, r0.x);
    else return Atan2(-r1.x, r1.y);
}
static inline void SetPoseRot(Root* flor, const Q* q) {
    Q pa; func_00132800(&pa, Placement_GetQuat(SceneRoot_GetPoseCache(flor)));
    Q pb; Quat_Conjugate(&pb, Placement_GetQuat(Root_GetWorldPlacement(flor)));
    Quat_MulInPlace(Quat_MulInPlace(&pa, &pb), q);
    SceneRoot_SetPoseCacheRot(flor, &pa);
}
static inline void SetRot(Root* flor, const Q* q) { SetPoseRot(flor, q); Root_SetWorldOrientationReset(flor, q); }
static inline void Rotate(Act* a, Root* flor, const Q& q0) { const Q* q = &q0;
    SetRot(flor, q);
    const Q* pq = Placement_GetQuat(SceneRoot_GetPoseCache(flor));
    MCtx* mc = &a->mc;
    M44 m(*pq);
    mc->comp->SetRotation(&m); ModelCtx_ComputeBounds(mc); ModelCtx_ComputeCentroid(mc);
}
static inline void Lanes(void* p, const V& d) { Actor_AddTeleportLanes(p, &d); }
static inline Q WorldQ(Act* a, const Q& q) { return QMul(*Placement_GetQuat(Root_GetWorldPlacement(a->flor)), q); }
static inline void SetAngle(void* h, int i, float v) { History_At(h, i)->angle = v; }
static inline bool IsMove(int m) { return m == 0 || m == 2; }
static inline bool IsRot(int m) { return m == 1 || m == 2; }

extern "C" int cHuman_HandleMoveMessage_cMoveMsgTemplateR(Act* a, Msg* msg0) {
    if (!AllFree(a)) return 1;
    Root* edge = a->edge;
    Root* ladd = a->ladd;
    Root* flor = a->flor;
    Msg* msg = msg0;
    if (D_004E1D88 == 0) {
        D_004E1D90 = 0;
        D_004E1D88 = 1;
        D_004E1D94 = 0;
        D_004E1D98 = 0;
        D_004E1D9C = 0;
    }
    V delta; { V* dp=&delta; RQ3(dp, &D_004E1D90); }
    if (msg->mode == 3) {
        V target = WorldPos(flor) + msg->Trans();
        MoveRoot(flor, msg->Trans());
        MoveRoot(edge, msg->Trans());
        MoveRoot(ladd, msg->Trans());
        if (a->phys) Lanes(a->phys, msg->Trans());
        Translate(a, msg->Trans());
        a->f34C0 += msg->Trans();
        delta = msg->Trans();
    } else if (IsMove(msg->mode)) {
        V d = msg->Trans() - WorldPos(flor);
        MoveRoot(flor, d);
        MoveRoot(edge, d);
        MoveRoot(ladd, d);
        if (a->phys) Lanes(a->phys, d);
        Translate(a, d);
        a->f34C0 += d;
        delta = d;
    }
    if (flor->weight != 0.0f) {
        if (msg->mode == 4) {
            M44 m(QMul(*Placement_GetQuat(Root_GetWorldPlacement(a->flor)), Q(M44(msg->m))));
            int i = a->histIdx; History_At(a->hist, i)->angle = HeadingOf(m);
            ActorHeading_RetargetLast(a->heading, -1.0f);
            Rotate(a, flor, Q(m));
        } else if (IsRot(msg->mode)) {
            int i = a->histIdx; History_At(a->hist, i)->angle = HeadingOfT(M44(msg->m));
            ActorHeading_RetargetLast(a->heading, -1.0f);
            Rotate(a, flor, Q(M44(msg->m)));
        }
    }
    {
        Ctrl* c = a->ctrl;
        if (c && c->Kind() != 2 && c->Kind() != 4) c->OnTeleport(&delta);
    }
    if (0) Send(ActMsg(0x13), a);
    if (0) Send(ActMsg(0x24), a);
    return 1;
}
