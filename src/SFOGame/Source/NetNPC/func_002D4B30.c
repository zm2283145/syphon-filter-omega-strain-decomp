/* cNetNPC::AimNoFire(cGOBJ& target): aim-only variant of cNetNPC_AimFire. With a manual aim
 * point in mTargetInfo, aim there (pushed 20 units along the view direction when the actor stands
 * within 3 units of it); otherwise aim at the target's aim point. Then send the "stop firing"
 * action. */
#pragma cplusplus on
/* the scale below is a GCC-style asm inline; MW leaves it out of line without this */
#pragma always_inline on
#include "types.h"
#include "cmessage.h"
#include "alloc_guard.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { w = d; x = a; y = b; z = c; }
    cVector(float a, float b, float c, int d) { x = a; y = b; z = c; w = d; }
    /* lq/sq quadword copy: 128-bit moves have no C equivalent */
    cVector(const cVector& o) { const cVector* ps = &o; cVector* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    /* lq/sq quadword copy */
    cVector& operator=(const cVector& o) { const cVector* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } return *this; }
    float LengthSq() const;
} __attribute__((aligned(16)));
struct cMatrix {
    cVector r[4];
    const cVector& Row(int i) const { const cVector* p = &r[i]; return *p; }
};
class cGOBJ {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45();
    virtual cVector GetAimPoint(int bone);       /* vtable +0xC0 */
    virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55();
    virtual cMatrix GetWorldMatrix();            /* vtable +0xE8 */
    virtual void v57(); virtual void v58();
    virtual cMatrix GetViewMatrix();             /* vtable +0xF4 */
};
struct cTargetInfo { unsigned char bManualAim; char pad1[0xF]; float X, Y, Z; };
struct cNetNPC {
    char pad0[0x30];
    cGOBJ* mGobj;                /* +0x30 (cGobjController) */
    char pad34[0x1E0 - 0x34];
    cTargetInfo* mTargetInfo;    /* +0x1E0 */
};
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0140[];
/* actor action messages, built as temporaries (their slots sit among the call temporaries) */
struct cAimActionMsg : CMsg {
    int action; unsigned char mode; char pad29[7]; cVector pos;
    cAimActionMsg(const cVector& p)
    {
        cAimActionMsg* pm = this;
        cMessage_ctor_cMessageNameR(pm, g_ActorActionMsgClass);
        pm->vtable = D_004E0840;
        pm->action = 0x39;
        pm->mode = 4;
        pm->vtable = D_004E0140;
        pm->pos = p;
    }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~cAimActionMsg() { vtable = D_004E0840; cMessage_dtor(this, 0); }
};
struct cStopFireActionMsg : CMsg {
    int action; unsigned char mode; char pad29[3];
    cStopFireActionMsg()
    {
        cStopFireActionMsg* pm = this;
        cMessage_ctor_cMessageNameR(pm, g_ActorActionMsgClass);
        pm->vtable = D_004E0840;
        pm->action = 0x3F;
        pm->mode = 0;
    }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~cStopFireActionMsg() { vtable = D_004E0840; cMessage_dtor(this, 0); }
};
extern "C" {
void QueueMessage_cMessageR_cSystemP_int_int(void*, void*, int, int);
void cNetNPC_AimNoFire(cNetNPC* self, cGOBJ* target);
}
static inline void Queue(const CMsg& m, cGOBJ* to, int a, int b) { QueueMessage_cMessageR_cSystemP_int_int((void*)&m, to, a, b); }

/* VU0 vector add (COP2) */
static inline void operator+=(cVector& a, const cVector& b)
{
    cVector* pd = &a; const cVector* pa = &a; const cVector* pb = &b;
    asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pd) }
}
/* VU0 x*x + y*y + z*z (COP2) */
static inline float SumSq(const cVector& v)
{
    const cVector* p = &v;
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(p)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
inline float cVector::LengthSq() const { return SumSq(*this); }
/* VU0 scale (COP2); scalar first so the constant is not loaded before the call that yields v */
static inline cVector operator*(float k, const cVector& v)
{
    cVector r; cVector* pr = &r; const cVector* pv = &v; int t;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder"
                     : "=&r"(t) : "r"(pr), "r"(pv), "f"(k) : "memory");
    return r;
}
static inline cVector MakePoint(const cTargetInfo* p) { cVector r(p->X, p->Y, p->Z, 1.0f); return r; }
static inline cVector ManualAimPoint(const cTargetInfo* p) { return MakePoint(p); }
/* manual aim point minus the world position; VU0 vsub (COP2) */
static inline cVector OffsetFrom(const cTargetInfo* p, const cMatrix& world)
{
    const cMatrix* pm = &world;
    cVector a(p->X, p->Y, p->Z, 1);
    cVector r;
    const cVector* pa = &a;
    cVector* pr = &r;
    const cVector* pb = &pm->Row(3);
    asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
    return r;
}

void cNetNPC_AimNoFire(cNetNPC* self, cGOBJ* target)
{
    if (self->mTargetInfo->bManualAim) {
        cVector aimPos = ManualAimPoint(self->mTargetInfo);
        cVector toAim = OffsetFrom(self->mTargetInfo, self->mGobj->GetWorldMatrix());
        if (toAim.LengthSq() < 9.0f) {
            aimPos += 20.0f * self->mGobj->GetViewMatrix().Row(1);
        }
        Queue(cAimActionMsg(aimPos), self->mGobj, 1, 0);
        Queue(cStopFireActionMsg(), self->mGobj, 0, 0);
    } else {
        Queue(cAimActionMsg(target->GetAimPoint(-1)), self->mGobj, 1, 0);
        Queue(cStopFireActionMsg(), self->mGobj, 0, 0);
    }
}
