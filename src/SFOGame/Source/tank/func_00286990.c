#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#define SOUND_EVENT_NO_PROTOS
#define CMSG_NO_PROTOS
#include "sound_event.h"
#pragma inline_depth(8)

/* lq/sq quadword copies (project convention, cf. mw38_00389FA0.c) */
struct V { inline V& operator*=(float k); inline float Length() const;
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V& operator=(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));

struct cEulerAngle;
struct M { float m[4][4]; M() {} M(const cEulerAngle& e); M(const M& o) { M* me = this; const M* s = &o; __int128 q0, q1; __asm__ volatile("lq %0, 0x0(%3)\n lq %1, 0x10(%3)\n sq %0, 0x0(%2)\n lq %0, 0x20(%3)\n sq %1, 0x10(%2)\n lq %1, 0x30(%3)\n sq %0, 0x20(%2)\n sq %1, 0x30(%2)" : "=&r"(q0), "=&r"(q1) : "r"(me), "r"(s) : "memory"); } M& operator=(const M& o) { M* me = this; const M* s = &o; __int128 q0, q1; __asm__ volatile("lq %0, 0x0(%3)\n lq %1, 0x10(%3)\n sq %0, 0x0(%2)\n lq %0, 0x20(%3)\n sq %1, 0x10(%2)\n lq %1, 0x30(%3)\n sq %0, 0x20(%2)\n sq %1, 0x30(%2)" : "=&r"(q0), "=&r"(q1) : "r"(me), "r"(s) : "memory"); return *this; } } __attribute__((aligned(16)));

struct TNode {
    VPAD16(a) VPAD4(b) virtual void Update();
    char pad04[0xC];
    M mat;          /* +0x10 */
    unsigned char dirty; /* +0x50 */
};

struct NIObj {
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d) virtual void MarkDirty();
    char pad04[0x4C];
    TNode* node;     /* +0x50 */
    char pad54[0x40];
    NIObj* parent;  /* +0x94 */
    char pad98[0x58];
    M localMat;     /* +0xF0 */
};

struct V;
struct Gobj {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual V GetTarget(int i);
    char pad04[8];
    int serial;     /* +0xC */
};

struct cTurret {
    NIObj* mTurret;
    NIObj* mGun;
    NIObj* mRecoil;
    NIObj* mTip;
    float mFireTimer;
    int mShotCounter;
    float mMinPitch;
    float mMaxPitch;
    float mMinRot;
    float mMaxRot;
    float mTurretMaxVel;
    float mTurretMaxAcc;
    float mTurretRot;
    float mTurretVel;
    float mPitch;
    float mPitchVel;
    V mOldDest;
    float mFireThreshold;
    unsigned char mStopFiring;
    unsigned char mSoundOn;
    char pad56[2];
    void* mOwner;
    Gobj* mEnemyP;
    int mEnemySerial;
    Gobj* mOldEnemy;
};

struct cEulerAngle {
    float x, y, z;
    cEulerAngle(float a, float b, float c) { x = a; y = b; z = c; }
} __attribute__((aligned(16)));

extern "C" {
extern float D_0048B390;
extern float D_0048B388;
extern float D_0048B3E0;
extern char D_004A93D8[];
extern char g_Game[];
extern char D_004DAE30[];
extern char D_004DADF0[];
void cMatrix_InvertRot(M* m);
int cMatrix_IsZeroTranslation(M* m);
V* func_00133EC0(M* m);
void cVector_ctor_cVectorR(V* d, V* s);
void cVector_NegateXYZ(V* v);
void cVector_Rotate_cMatrixR(V* v, M* m);
void cMatrix_SetTranslation(M* m, V* v);
float Libc_Atan2f(float y, float x);
void cTurret_Achieve(cTurret* self, float des, float* vel, float* ang, float timeStep, float minA, float maxA);
float COS(float a);
float SIN(float a);
void cMatrix_Set_ColumnMajorForm(M* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
void cSndFx_ctor_int_charP_cGOBJP_int(void* req, int type, const char* name, void* voice, int x180);
void cPlaySoundMsg_ctor_cSndFxR(void* ev, void* req, void* owner);
void cStopSoundMsg_ctor_cSndFxR_cGOBJP(void* ev, void* req, void* owner);
void QueueMessage_cMessageR_cSystemP_int(void* ev, void* to, int f);
void cMessage_dtor(void* msg, int flags);
}

static inline bool IEq(int a, int b) { return a == b; }
static inline bool HValid(cTurret* t) { return !t->mEnemyP || IEq(t->mEnemyP->serial, t->mEnemySerial); }
static inline Gobj* HGet(cTurret* t) { return HValid(t) ? t->mEnemyP : 0; }
static inline bool HIs(cTurret* t, Gobj* o) { return HGet(t) == o; }

static inline void NodeUpdate(TNode* n) { if (n->dirty) n->Update(); }
static inline void MarkDirty(NIObj* o) { o->MarkDirty(); }
static inline const M& WorldMat(TNode* n) { NodeUpdate(n); return n->mat; }
static inline const V& WorldPos(TNode* n) { NodeUpdate(n); return *(const V*)&n->mat.m[3][0]; }

/* VU0 macro-mode vector ops and abs.s: not expressible in C */
static inline void Apply(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void AddV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
static inline float Len(V* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }

static inline V Sub(const V& a, const V& b) { V r; const V* ap = &a; const V* bp = &b; SubV(&r, ap, bp); return r; }
inline V& V::operator*=(float k) { ScaleV(this, this, k); return *this; }
inline float V::Length() const { return Len((V*)this); }

static inline void FixTrans(M& m)
{
    V t;
    cVector_ctor_cVectorR(&t, func_00133EC0(&m));
    cVector_NegateXYZ(&t);
    cVector_Rotate_cMatrixR(&t, &m);
    cMatrix_SetTranslation(&m, &t);
}
static inline void InvertMat(M& m)
{
    cMatrix_InvertRot(&m);
    if (!cMatrix_IsZeroTranslation(&m))
        FixTrans(m);
}

inline M::M(const cEulerAngle& e)
{
    float ey = e.y;
    float ex = e.x;
    float ez = e.z;
    float cy = COS(ey);
    float sy = SIN(ey);
    float cx = COS(ex);
    float sx = SIN(ex);
    float cz = COS(ez);
    float sz = SIN(ez);
    float czcy = cz * cy;
    float czsy = cz * sy;
    float szcy = sz * cy;
    float szsy = sz * sy;
    cMatrix_Set_ColumnMajorForm(this, czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                      szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                      -cx * sy, sx, cx * cy);
}

static inline void SetRot(M* dst, const M& m)
{
    dst->m[0][0] = m.m[0][0];
    dst->m[0][1] = m.m[0][1];
    dst->m[0][2] = m.m[0][2];
    dst->m[1][0] = m.m[1][0];
    dst->m[1][1] = m.m[1][1];
    dst->m[1][2] = m.m[1][2];
    dst->m[2][0] = m.m[2][0];
    dst->m[2][1] = m.m[2][1];
    dst->m[2][2] = m.m[2][2];
    dst->m[0][3] = m.m[0][3];
    dst->m[1][3] = m.m[1][3];
    dst->m[2][3] = m.m[2][3];
}

extern "C" unsigned char cTurret_Aim(cTurret* self, float timeStep)
{
    NIObj* turret = self->mTurret;
    M* turretLocalMat = &turret->localMat;
    M* gunLocalMat = &self->mGun->localMat;
    float desPitch;
    float desRot;

    if (HGet(self)) {
        M aimMat = WorldMat(self->mTurret->parent->node);
        *(V*)&aimMat.m[3][0] = WorldPos(self->mTurret->node);
        InvertMat(aimMat);
        V dest = HGet(self)->GetTarget(-1);
        Apply(&dest, &aimMat, &dest);
        float xylen = V(dest.x, dest.y, 0.0f, 0.0f).Length();
        if (HIs(self, self->mOldEnemy) && !(xylen <= D_0048B390)) {
            V diff = Sub(dest, self->mOldDest);
            diff *= D_0048B388;
            V& old = self->mOldDest;
            old = dest;
            AddV(&dest, &dest, &diff);
            xylen = V(dest.x, dest.y, 0.0f, 0.0f).Length();
        } else {
            self->mOldDest = dest;
        }
        desPitch = Libc_Atan2f(dest.z, xylen);
        desRot = Libc_Atan2f(-dest.x, dest.y);
    } else {
        desPitch = 0.0f;
        desRot = desPitch;
    }
    self->mOldEnemy = HGet(self);

    cTurret_Achieve(self, desPitch, &self->mPitchVel, &self->mPitch, timeStep, self->mMinPitch, self->mMaxPitch);
    SetRot(gunLocalMat, M(cEulerAngle(self->mPitch, 0.0f, 0.0f)));
    MarkDirty(self->mGun);
    cTurret_Achieve(self, desRot, &self->mTurretVel, &self->mTurretRot, timeStep, self->mMinRot, self->mMaxRot);
    SetRot(turretLocalMat, M(cEulerAngle(0.0f, 0.0f, self->mTurretRot)));
    MarkDirty(self->mTurret);

    if (self->mMinRot == self->mMaxRot) {
        if (!(Abs(self->mTurretVel) <= D_0048B3E0)) {
            if (!self->mSoundOn) {
                self->mSoundOn = 1;
                SoundRequest req;
                SoundEventP ev;
                cSndFx_ctor_int_charP_cGOBJP_int(&req, 0, D_004A93D8, 0, 0);
                cPlaySoundMsg_ctor_cSndFxR(&ev, &req, self->mTurret);
                ev.kind = 1;
                QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
                ev.vtable = D_004DAE30;
                cFileMan_dtor(&ev.req.b, -1);
                cFileMan_dtor(&ev.req.a, -1);
                cMessage_dtor(&ev, 0);
                cFileMan_dtor(&req.b, -1);
                cFileMan_dtor(&req.a, -1);
            }
        } else if (self->mSoundOn) {
            self->mSoundOn = 0;
            SoundRequest req;
            SoundEvent ev;
            cSndFx_ctor_int_charP_cGOBJP_int(&req, 0, D_004A93D8, 0, 0);
            cStopSoundMsg_ctor_cSndFxR_cGOBJP(&ev, &req, self->mTurret);
            ev.kind = 1;
            QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
            ev.vtable = D_004DADF0;
            cFileMan_dtor(&ev.req.b, -1);
            cFileMan_dtor(&ev.req.a, -1);
            cMessage_dtor(&ev, 0);
            cFileMan_dtor(&req.b, -1);
            cFileMan_dtor(&req.a, -1);
        }
    }

    unsigned char aimed = 0;
    if (HGet(self)) {
        M aimMat = WorldMat(self->mGun->node);
        InvertMat(aimMat);
        V dest = HGet(self)->GetTarget(-1);
        Apply(&dest, &aimMat, &dest);
        desRot = Libc_Atan2f(-dest.x, dest.y);
        if (Abs(desRot) < self->mFireThreshold) {
            float y = dest.y;
            desPitch = Libc_Atan2f(dest.z, y);
            if (Abs(desPitch) < self->mFireThreshold)
                aimed = 1;
        }
    }
    return aimed;
}
