/* SFOGame/Source/humanCollision (asm unit 001E7110-001E8760): cHumanCollisionRoutine::Transport_StartOfFrameUpdate
 * and cHumanCollisionRoutine::DetectForAndHandleCollisionWithOtherHumans, in retail order. */
#pragma push
/* cHumanCollisionRoutine::Transport_StartOfFrameUpdate(cVector*, cVector*, cQuatVec*, float) (humanCollision.cc) */
#pragma cplusplus on
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma always_inline on
#pragma inline_depth(10)

static inline void GCopy(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0,0(%2); sq %0,0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V(const V& o, int) { void* xx = this; V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V(const V& o, short) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } void* xx = this; }
    V(const V& o, char) { __int128 q; __asm__ volatile("lq %0,0(%2); sq %0,0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { GCopy(this, &o); return *this; }
    V& PreMul(const V& q);
} __attribute__((aligned(16)));
struct PlcC;
struct NodeC;
struct MtxC { V r0; V r1; V r2; V r3; };
extern "C" PlcC* cQuatVec_ctor_cQuatVecR(PlcC*, const PlcC*);
extern "C" PlcC* cQuatVec_Transform(PlcC*, const PlcC*);
extern "C" PlcC* cQuatVec_InvertAssumingUnitQuat(PlcC*);
extern "C" const V* cQuatVec_Rotation(const PlcC*);
extern "C" const V* cQuatVec_Translation(const PlcC*);
extern "C" PlcC* cQuatVec_Rotate(PlcC*, const V*);
extern "C" PlcC* cQuatVec_Translate(PlcC*, const V*);
struct PlcC {
    V rot; V pos;
    PlcC() {}
    PlcC(const PlcC& o) { cQuatVec_ctor_cQuatVecR(this, &o); void* xx = this; }
    PlcC& operator*=(const PlcC& o) { return *cQuatVec_Transform(this, &o); }
    PlcC(const MtxC& m);
    static PlcC M3(const PlcC& a, const PlcC& b) { PlcC t; return *cQuatVec_ctor_cQuatVecR(&t, &a) *= b; }
    static PlcC M2(const PlcC& a, const PlcC& b) { return M3(a, b); }
    static PlcC M1(const PlcC& a, const PlcC& b) { return M2(a, b); }
    PlcC operator*(const PlcC& b) const { return M1(*this, b); }
    static PlcC I3(const PlcC& a) { PlcC t; return *cQuatVec_InvertAssumingUnitQuat(cQuatVec_ctor_cQuatVecR(&t, &a)); }
    static PlcC I2(const PlcC& a) { return I3(a); }
    PlcC Inverse() const { return I2(*this); }
    PlcC& operator=(const PlcC& o) { { V* pd = &rot; __int128 q; __asm__ volatile("lq %0,0(%2); sq %0,0(%1)" : "=r"(q) : "r"(pd), "r"(&o.rot) : "memory"); } GCopy(&pos, &o.pos); return *this; }
    PlcC& RotM(const PlcC& c) { cQuatVec_Rotate(this, cQuatVec_Rotation(&c)); return *this; }
    PlcC& TransM(const PlcC& c) { cQuatVec_Translate(this, cQuatVec_Translation(&c)); return *this; }
};
struct NodeC {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char p4[0xC]; MtxC mtx; unsigned char dirty;
    const MtxC& GetMatrix() { if (dirty) Update(); return mtx; }
};
template <class T, int N> struct FA { T e[N]; T& operator[](int i) { return e[i]; } };
static inline const PlcC& RotBy(const PlcC& d, const PlcC& c) { cQuatVec_Rotate((PlcC*)&d, cQuatVec_Rotation(&c)); return d; }
static inline const PlcC& TransBy(const PlcC& d, const PlcC& c) { cQuatVec_Translate((PlcC*)&d, cQuatVec_Translation(&c)); return d; }
static inline PlcC MulB(PlcC b, const PlcC& a) { return PlcC::M1(a, b); }
struct GobjC { char p0[0x50]; NodeC* node; };
struct AnchorC { char p0[0xB0]; void* parent; char pB4[0x160 - 0xB4]; int f160; };
struct SysC { char p0[0xB0]; char coll[4]; };
struct R {
    char p0[0xC]; SysC* sys; char p10[0xE8 - 0x10];
    unsigned char floorDetected; char pE9[0x1F0 - 0xE9];
    FA<GobjC*, 3> transports; char p1FC[4];
    FA<PlcC, 3> anchorXf;
    FA<PlcC, 3> prevXf;
};
extern "C" {
AnchorC* RootCollection_FindByKey(void*, void*);
PlcC* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(AnchorC*);
void cSkaAnimAnchor_TreeNode_SetTransformRotation_WorldSpace(AnchorC*, const V*);
void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(AnchorC*, const PlcC*);
float Libc_Atan2f(float, float);
float Libc_Cosf(float);
float Libc_Sinf(float);
void cQuaternion_ctor_void(V*);
void cQuaternion_VU0Multiply(V*, const V*, const V*);
void cQuaternion_ctor_cQuaternionR(V*, const V*);
}
extern char D_004A03C8[];
extern char D_004A03D0[];
extern char D_004A03D8[];

static inline PlcC* MtxToPlc(PlcC* out, const MtxC* m) {
    const MtxC* mp = m;
    PlcC* op = out;
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(mp)
        lqc2 vf2, 0x10(mp)
        lqc2 vf3, 0x20(mp)
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
        sqc2 vf9, 0x0(op)
        .set reorder
    }
    GCopy(&out->pos, &m->r3);
    return out;
}
inline PlcC::PlcC(const MtxC& m) { MtxToPlc(this, &m); }

/* VU0 vector ops */
static inline void SubM(const V* a, const V* b, V* d) { asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(b); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline V operator-(const V& a, const V& b) { V r; SubM(&a, &b, &r); return r; }
static inline void MulT(V* d, const V* p, float s) { __int128 t = 0; asm { .set noreorder; lqc2 vf1, 0(p); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(d); .set reorder } }
static inline void Scale(V& r, const V& v, float s) { MulT(&r, &v, s); }
static inline V Sc(V& r, const V& v, float s) { __int128 t = 0; V* d = &r; const V* p = &v; asm { .set noreorder; lqc2 vf1, 0(p); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(d); .set reorder } return *d; }
static inline V operator*(const V& v, float s) { V r; return Sc(r, v, s); }
static inline void QMulM(V* d, const V* a, const V* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(d)
    }
}
static inline V QMul(const V& a, const V& b) { V r; QMulM(&r, &a, &b); return r; }
static inline V operator*(const V& a, const V& b) { return QMul(a, b); }
static inline V& PreMul2(const V& q, const V& b) { V& bb = (V&)b; V t = QMul(q, bb); bb = t; return bb; }
static inline void ConjM(V* d) { asm { lqc2 vf1, 0x0(d); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(d) } }
static inline V Inv2(const V& q) { V r; GCopy(&r, &q); V* p = &r; ConjM(p); return V(*p, 0); }
static inline V Inverse(const V& q) { return Inv2(q); }
static inline void NormM(V* d) {
    asm {
        lqc2 vf1, 0x0(d)
        vmul.xyzw vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddaz.w ACC, vf0, vf2z
        vmaddw.w vf3, vf0, vf2w
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyzw vf4, vf1, Q
        sqc2 vf4, 0x0(d)
    }
}
static inline void VAdd3S(const V* s, V* d) { asm { lqc2 vf1, 0x0(d); lqc2 vf2, 0x0(s); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void QRot(V* v, const V* q) {
    asm {
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
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3(V* d, const V* s) { const V* ss = s; VAdd3S(ss, d); }

struct MtxQ {
    V r0, r1, r2, r3;
    MtxQ(const V& q) {
        MtxQ* mp = this;
        const V* rp = &q;
        asm {
            lqc2 vf1, 0x0(rp)
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
            sqc2 vf10, 0x20(mp)
        }
    }
};
static inline float ZRotFromX(const V& x) { float b = x.x; float a = x.y; return Libc_Atan2f(a, b); }
static inline float ZRotFromY(const V& y) { return Libc_Atan2f(-y.x, y.y); }
static inline float Yaw(const MtxQ& m) {
    V xa = m.r0;
    V ya = m.r1;
    float yz = ya.z; float xz = xa.z;
    if (xz < yz) return ZRotFromX(xa);
    return ZRotFromY(ya);
}
struct AA { float x, y, z, a; AA(float vx, float vy, float vz, float an) { x = vx; y = vy; z = vz; a = an; } } __attribute__((aligned(16)));
struct QA {
    float x, y, z, w;
    QA(const AA& aa) {
        float h = 0.5f * aa.a;
        float c = Libc_Cosf(h);
        float s = Libc_Sinf(h);
        w = c;
        x = s * aa.x;
        y = s * aa.y;
        z = s * aa.z;
    }
} __attribute__((aligned(16)));

static inline void SetZero(V* d) { asm { sq zero, 0x0(d) } }
static inline void SetUnit(V* d) { asm { sqc2 vf0, 0x0(d) } }

struct QT {
    float x, y, z, w;
    QT() { cQuaternion_ctor_void((V*)this); }
    QT(const QT& o) { cQuaternion_ctor_cQuaternionR((V*)this, (const V*)&o); void* xx = this; }
} __attribute__((aligned(16)));
static inline QT QMulO(const QT& a, const QT& b) { QT m; cQuaternion_VU0Multiply((V*)&m, (const V*)&a, (const V*)&b); return m; }
static inline void TB3(PlcC* p, const PlcC* ip) {
    const V* q = &ip->rot;
    QT r = QMulO(*(const QT*)q, *(const QT*)&p->rot);
    p->rot = *(const V*)&r;
    QRot(&p->pos, q);
    VAdd3(&p->pos, &ip->pos);
}
static inline void TB2(PlcC* p, const PlcC* ip) { TB3(p, ip); }
static inline void TB1(PlcC* p, const PlcC* ip) { TB2(p, ip); }
static inline void TransformBy_old(PlcC* p, const PlcC* ip) {
    V r;
    V m;
    cQuaternion_ctor_void(&m);
    cQuaternion_VU0Multiply(&m, &ip->rot, &p->rot);
    cQuaternion_ctor_cQuaternionR(&r, &m);
    { void* xx = &r; }
    GCopy(&p->rot, &r);
    QRot(&p->pos, &ip->rot);
    VAdd3(&p->pos, &ip->pos);
}
static inline PlcC Delta(const PlcC& prev, const PlcC& curr) {
    PlcC t;
    PlcC d = *cQuatVec_InvertAssumingUnitQuat(cQuatVec_ctor_cQuatVecR(&t, &prev));
    cQuatVec_Rotate(&d, cQuatVec_Rotation(&curr));
    cQuatVec_Translate(&d, cQuatVec_Translation(&curr));
    return d;
}

extern "C" void cHumanCollisionRoutine_Transport_StartOfFrameUpdate(R* self, V* deltaPos, V* vel, PlcC* deltaXf, float oneOverTimeStep)
{
    int i;
    for (i = 0; i < 3; i++) {
        SetZero(&deltaPos[i]);
        SetZero(&vel[i]);
        SetUnit(&deltaXf[i].rot);
        SetUnit(&deltaXf[i].pos);
    }
    if (self->floorDetected) {
        GobjC* floorAnchorTransport = self->transports[0];
        if (floorAnchorTransport) {
            NodeC* xform = floorAnchorTransport->node;
            if (xform) {
                PlcC prev = self->anchorXf[0] * self->prevXf[0];
                PlcC curr = MulB(PlcC(xform->GetMatrix()), self->anchorXf[0]);
                deltaPos[0] = curr.pos - prev.pos;
                vel[0] = deltaPos[0] * oneOverTimeStep;
                AnchorC& floorAnchor = *RootCollection_FindByKey(self->sys->coll, D_004A03C8);
                V deltaRot(PreMul2(curr.rot, Inverse(prev.rot)));
                V rot = deltaRot * *cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&floorAnchor));
                if (!floorAnchor.parent) {
                    cSkaAnimAnchor_TreeNode_SetTransformRotation_WorldSpace(&floorAnchor, (V*)&QA(AA(0.0f, 0.0f, 1.0f, Yaw(MtxQ(rot)))));
                    floorAnchor.f160 = 0;
                }
            }
        }
    }
    {
        GobjC* ledgeAnchorTransport = self->transports[1];
        if (ledgeAnchorTransport) {
            NodeC* xform = ledgeAnchorTransport->node;
            if (xform) {
                PlcC prev = self->anchorXf[1] * self->prevXf[1];
                PlcC curr = MulB(PlcC(xform->GetMatrix()), self->anchorXf[1]);
                deltaPos[1] = curr.pos - prev.pos;
                vel[1] = deltaPos[1] * oneOverTimeStep;
                AnchorC& ledgeAnchor = *RootCollection_FindByKey(self->sys->coll, D_004A03D0);
                deltaXf[1] = prev.Inverse().RotM(curr).TransM(curr);
                PlcC transform;
                transform = *cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&ledgeAnchor);
                TB1(&transform, &deltaXf[1]);
                V* pr = &transform.rot; NormM(pr);
                if (!ledgeAnchor.parent) {
                    cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(&ledgeAnchor, (PlcC*)pr);
                    ledgeAnchor.f160 = 0;
                }
            }
        }
    }
    {
        GobjC* ladderAnchorTransport = self->transports[2];
        if (ladderAnchorTransport) {
            NodeC* xform = ladderAnchorTransport->node;
            if (xform) {
                PlcC prev = self->anchorXf[2] * self->prevXf[2];
                PlcC curr = MulB(PlcC(xform->GetMatrix()), self->anchorXf[2]);
                deltaPos[2] = curr.pos - prev.pos;
                vel[2] = deltaPos[2] * oneOverTimeStep;
                AnchorC& ladderAnchor = *RootCollection_FindByKey(self->sys->coll, D_004A03D8);
                deltaXf[2] = prev.Inverse().RotM(curr).TransM(curr);
                PlcC transform;
                transform = *cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&ladderAnchor);
                TB1(&transform, &deltaXf[2]);
                V* pr = &transform.rot; NormM(pr);
                if (!ladderAnchor.parent) {
                    cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(&ladderAnchor, (PlcC*)pr);
                    ladderAnchor.f160 = 0;
                }
            }
        }
    }
}

#pragma pop

#pragma push
/* cHumanCollisionRoutine::DetectForAndHandleCollisionWithOtherHumans(cVector&, const cVector&, float) (humanCollision.cc) */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { const cVector* s = &o; cVector* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    cVector& operator=(const cVector& o) { const cVector* s = &o; cVector* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline void SubV(cVector* r, const cVector* a, const cVector* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline cVector operator-(const cVector& a, const cVector& b) { cVector r; SubV(&r, &a, &b); return r; }

struct cMatrix { float m[16]; } __attribute__((aligned(16)));
struct cBox {
    cVector min, max;
    cBox(const cBox& o) : min(o.min), max(o.max) {}
};
extern "C" {
cVector* cVector_ctor_cVectorR(cVector* d, const cVector* s);
void cVector_WSet1(cVector* v);
void cBox_Empty(cBox* b);
cVector cVector_GetTransformed(const cVector* v, const cMatrix* m);
cVector* cVector_Transform_cMatrixR(cVector* v, const cMatrix* m);
cVector* cVector_ctor_float_float_float_float(cVector* o, float x, float y, float z, float w);
void cBox_Include(cBox* b, const cVector* v);
}
static inline void TB0(cBox* b, const cMatrix* m)
{
    cVector mn; cVector_ctor_cVectorR(&mn, &b->min); cVector_WSet1(&mn);
    cVector mx; cVector_ctor_cVectorR(&mx, &b->max); cVector_WSet1(&mx);
    cBox_Empty(b);
    { cVector t = cVector_GetTransformed(&mn, m); cBox_Include(b, &t); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mn.x, mn.y, mx.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mn.x, mx.y, mn.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mn.x, mx.y, mx.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mx.x, mn.y, mn.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mx.x, mn.y, mx.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mx.x, mx.y, mn.z, 1.0f), m)); }
    { cVector t = cVector_GetTransformed(&mx, m); cBox_Include(b, &t); }
}
static inline void TB1(cBox* b, const cMatrix* m) { TB0(b, m); }
static inline void TB(cBox* b, const cMatrix* m) { TB1(b, m); }
struct cXform {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad4[0xC];
    cMatrix mMatrix;
    unsigned char mDirty;
    const cMatrix& GetMatrix() { if (mDirty) Update(); return mMatrix; }
};
struct cController {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual unsigned char IsActive();
    virtual unsigned char Is58();
    virtual unsigned char Is5C();
};
struct cSkaAnimAnchor { char pad[0xD0]; float weight; };
struct cSkaAnimAnchorList;
extern "C" cSkaAnimAnchor* cSkaAnimAnchorList_Find(cSkaAnimAnchorList* l, const void* name);
struct cSkaSystem { char pad[0xB0]; char anchors[4]; cSkaAnimAnchor& Find(const void* n) { return *cSkaAnimAnchorList_Find((cSkaAnimAnchorList*)anchors, n); } };
struct cObjectId { int id; };

class cSKM_GOBJ {
public:
    VPAD32(a)
    virtual cBox& GetBox();
    VPAD16(b) VPAD4(c) VPAD1(d)
    virtual cVector GetPosition() const;
    VPAD8(e) VPAD1(f)
    virtual unsigned char GetState();
    int pad4[2];
    cObjectId mId;               /* 0x0C */
    int pad10;
    unsigned char b14;           /* 0x14 */
    char pad15[0x49 - 0x15];
    unsigned char b49;           /* 0x49 */
    char pad4A[2];
    void* classKey;              /* 0x4C */
    cXform* mXform;              /* 0x50 */
    int pad54;
    cController* mController;    /* 0x58 */
    char pad5C[0x2EC0 - 0x5C];
    cSkaSystem mSkaSystem;       /* 0x2EC0 */
    cSkaSystem* GetSkaSystem() const { return (cSkaSystem*)&mSkaSystem; }
    char pad[0x3204 - 0x2EC0 - sizeof(cSkaSystem)];
    int mStateBits[8];           /* 0x3204 */
};
struct cGobjController { char pad[0x30]; cSKM_GOBJ* gobj; };
struct cNpc { char pad[0xC]; int id; char pad10[0x58 - 0x10]; cGobjController* controller; };
struct cHandle { cNpc* obj; int id; };
struct cLLNode { int pad0; cLLNode* next; cHandle* value; };
struct LIt;
struct cConstLListIterator { cLLNode* p; cConstLListIterator(const LIt& i); };

struct cHumanCollisionRoutine {
    void* vt;
    cSKM_GOBJ* mGobj;
    void* skeleton;
    cSkaSystem* animationSystem;
    char pad10[0x20 - 0x10];
    int mMode;                   /* 0x20 */
    char pad24[0x3D0 - 0x24];
    unsigned char mDoCollisionWithHumans;
};
struct cSystem;
struct cMessage { void* vt; char pad[0x4C]; };
extern "C" {
struct DelIt { cLLNode* p; };
struct LIt { cLLNode* p; };
DelIt std_list_deleter_voidPtr_begin_void_2(void*);
DelIt std_list_deleter_voidPtr_end_void_2(void*);
LIt std_list_cActiveListItemPtr_generic_iterator_1_ctor(cLLNode*);
extern void* g_HumanActorClassKey;
extern char g_NpcThinkList[];
extern char g_Game[];
extern char D_004EE5C0[];
extern char D_004D92A0[];
extern char D_004A03D0[];
extern char D_004A03D8[];
cSystem* cSystemContainer_GetSystem(void*, void*);
void cAISoundSystemGobjToGobjMessage_ctor(cMessage*, cObjectId*, cObjectId*, int);
void QueueMessage_cMessageR_cSystemP_int(cMessage*, cSystem*, int);
void cMessage_dtor(cMessage*, int);
cSKM_GOBJ* cNetObj_GetPlayer(int);
unsigned char cHumanCollisionRoutine_DetectForAndHandleCollisionWithHuman(cHumanCollisionRoutine* self, cVector& pos, const cBox& box, cSKM_GOBJ& g, float scale);
}

inline cConstLListIterator::cConstLListIterator(const LIt& i) { p = i.p; }
static inline LIt LBegin(char* l) { return std_list_cActiveListItemPtr_generic_iterator_1_ctor(std_list_deleter_voidPtr_begin_void_2(l).p); }
static inline LIt LEnd(char* l) { return std_list_cActiveListItemPtr_generic_iterator_1_ctor(std_list_deleter_voidPtr_end_void_2(l).p); }
static inline float MinF(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float MinF2(float b, float a) { float r = 0.0f; asm volatile { .set reorder; min.s r, a, b } return r; }
static inline unsigned char IsHuman(cSKM_GOBJ* g) { void* k = g_HumanActorClassKey; return g->classKey == k; }
static inline unsigned char CheckState(cSKM_GOBJ* g, unsigned char i) { return ((g->mStateBits[(unsigned int)i >> 5] >> (i & 0x1F)) & 1) != 0; }
static inline unsigned char IsPlayerHuman(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    if (IsHuman(g) && CheckState(g, 0)) r = 1;
    return r;
}
static inline unsigned char IsActive(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    cController* c = g->mController;
    if (c && c->IsActive()) r = 1;
    return r;
}
static inline unsigned char Is58(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    cController* c = g->mController;
    if (c && c->Is58()) r = 1;
    return r;
}
static inline unsigned char Is5C(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    cController* c = g->mController;
    if (c && c->Is5C()) r = 1;
    return r;
}
static inline unsigned char IsDying(cSKM_GOBJ* g)
{
    bool r; unsigned char s = g->GetState();
    r = 1;
    if (s != 3 && s != 2) r = 0;
    return r;
}
static inline cNpc* Deref(cHandle* h) { unsigned char ok = !h->obj || (unsigned char)(h->obj->id == h->id); return ok ? h->obj : 0; }

static inline bool OnLedge(cSkaSystem* sys) { bool r = 1; if (sys->Find(D_004A03D0).weight <= 0.0f && sys->Find(D_004A03D8).weight <= 0.0f) r = 0; return r; }
static inline bool IsHumanB(cSKM_GOBJ* g) { void* k = g_HumanActorClassKey; return g->classKey == k; }
static inline unsigned char IsHumanU(cSKM_GOBJ* g) { return IsHumanB(g); }
static inline unsigned char IsPH(cSKM_GOBJ* g) { unsigned char r = 0; if (IsHumanU(g) && CheckState(g, 0)) r = 1; return r; }
extern "C" unsigned char cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans(cHumanCollisionRoutine* self, cVector& collisionResponse, const cVector& originalPosition, float timeStep)
{
    unsigned char collisionDetected = 0;
    cVector newPosition = originalPosition;
    unsigned char isPlayerHuman = IsPH(self->mGobj);
    float rate = MinF2(15.0f * timeStep, 1.0f);
    float rateHuman = MinF2(22.0f * timeStep, 1.0f);
    if (self->mGobj->GetState() != 3 && !(IsDying(self->mGobj) && !IsActive(self->mGobj)) && self->mMode != 9 && self->mDoCollisionWithHumans) {
        cBox& box = self->mGobj->GetBox();
        cBox box_WorldSpace = box;
        TB(&box_WorldSpace, &self->mGobj->mXform->GetMatrix());
        {
            char* npcActiveList = g_NpcThinkList;
            cConstLListIterator curr(LBegin(npcActiveList));
            cConstLListIterator end(LEnd(npcActiveList));
            for (; curr.p != end.p; curr.p = curr.p->next) {
                if (!Deref(curr.p->value)) continue;
                cGobjController* gobjController = Deref(curr.p->value)->controller;
                if (!gobjController) continue;
                cSKM_GOBJ* gobj = gobjController->gobj;
                if (!gobj) continue;
                if (gobj->b49 != 2) continue;
                {
                    unsigned char otherIsPlayerHuman = IsPlayerHuman(gobj);
                    unsigned char collisionDetectedWithCurrGobj = cHumanCollisionRoutine_DetectForAndHandleCollisionWithHuman(self, newPosition, box_WorldSpace, *gobj,
                        IsActive(self->mGobj) ? (otherIsPlayerHuman ? rateHuman : rate) : rate);
                    collisionDetected = collisionDetectedWithCurrGobj || collisionDetected;
                    if (collisionDetectedWithCurrGobj && self->mGobj->b14 && (Is58(gobj) || Is5C(gobj))) {
                        cSystem* aiSoundSystem = cSystemContainer_GetSystem(g_Game, D_004EE5C0);
                        cMessage msg;
                        cAISoundSystemGobjToGobjMessage_ctor(&msg, &self->mGobj->mId, &gobj->mId, 7);
                        QueueMessage_cMessageR_cSystemP_int(&msg, aiSoundSystem, 0);
                        msg.vt = D_004D92A0;
                        cMessage_dtor(&msg, 0);
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            cSKM_GOBJ* gobj = cNetObj_GetPlayer(i);
            if (!gobj) continue;
            if (gobj->b49 != 2) continue;
            {
                cSKM_GOBJ& skmGobj = *gobj;
                unsigned char onLedge = OnLedge(skmGobj.GetSkaSystem());
                unsigned char collisionDetectedWithCurrGobj = cHumanCollisionRoutine_DetectForAndHandleCollisionWithHuman(self, newPosition, box_WorldSpace, skmGobj,
                    IsActive(self->mGobj) ? rate : (isPlayerHuman ? (onLedge ? rate : 0.0f) : rate));
                collisionDetected = collisionDetectedWithCurrGobj || collisionDetected;
            }
        }
    }
    collisionResponse = newPosition - originalPosition;
    return collisionDetected;
}

#pragma pop
