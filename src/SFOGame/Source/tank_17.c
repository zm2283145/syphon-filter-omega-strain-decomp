/*
 * SFOGame/Source/tank: 7 files, 00287420-00287910
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00287420 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_two_member_dtor.h"
#pragma pop

#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_00287420, D_004DADF0)
static inline void merge_flush_func_00287420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00287420 */

/* merge_units: begin func_002874B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_002874B0, D_004DAE30)
static inline void merge_flush_func_002874B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002874B0 */

/* merge_units: begin func_00287540 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct cTurret {
    void* mTurret;
    void* mGun;
    void* mRecoil;
    void* mTip;
    float mFireTimer;
    int mShotCounter;
    float mMinPitch;
    float mMaxPitch;
    float mMinRot;
    float mMaxRot;
    float mTurretMaxVel;
    float mTurretMaxAcc;
} cTurret;

extern float D_0048B380;
extern float D_0048B398;
extern float D_0048B3A0;
extern float D_0048B3A8;

/* max.s/min.s: C has no expression that emits these. */
static inline float Clamp(float v, float lo, float hi)
{
    float r;
    asm {
        max.s r, v, lo
        min.s r, r, hi
    }
    return r;
}


/* abs.s: C has no expression that emits it. */
static inline float Fabs(float x) { float r; asm { abs.s r, x } return r; }

static inline float Sign(float x)
{
    if (x > 0.0f)
        return 1.0f;
    return -1.0f;
}

static inline int ISign(float x) { if (x > 0.0f) return 1; return -1; }
static inline float Sq(float x) { return x * x; }
static inline float SignSq(float x) { return Sign(x) * (x * x); }
static inline float SSq(float x) { float sq = x * x; if (x > 0.0f) return 1.0f * sq; return -1.0f * sq; }

static inline float NormalizeAngle(float a)
{
    if (a < -3.1415927f)
        a += 6.2831855f;
    else if (!(a <= 3.1415927f))
        a -= 6.2831855f;
    return a;
}

extern "C" void cTurret_Achieve(cTurret* self, float desRot, float* curVel, float* curAng, float timeStep, float minAng, float maxAng)
{
    float diffRot;
    float desVel;
    float diffVel;
    float maxAccel;

    diffRot = NormalizeAngle(desRot - *curAng);
    desVel = diffRot * D_0048B3A8;
    desVel -= *curVel * D_0048B398;
    desVel = D_0048B3A0 * (Sign(desVel) * Sq(desVel));
    diffVel = desVel - *curVel;
    maxAccel = self->mTurretMaxAcc;
    if (Fabs(desVel) < Fabs(*curVel))
        maxAccel *= D_0048B380;

    {
    float dv = Clamp(diffVel, -maxAccel, maxAccel);
    dv *= timeStep;
    *curVel += dv;
    }
    {
    /* Reference (not a copy) colors maxVel f1 / result f0 like retail. */
    const float& maxVel = self->mTurretMaxVel;
    *curVel = Clamp(*curVel, -maxVel, maxVel);
    }
    *curAng += *curVel * timeStep;
    if (minAng != maxAng) {
        if (*curAng < minAng)
            *curAng = minAng;
        else if (!(*curAng <= maxAng))
            *curAng = maxAng;
    }
    *curAng = NormalizeAngle(*curAng);
}
static inline void merge_flush_func_00287540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00287540 */

/* merge_units: begin func_00287710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

struct V4 { union { __int128 q; struct { float x, y, z, w; } f; }; V4() {} };
typedef union { __int128 q; struct { float x, y, z, w; } f; } GV4;
struct Mtx { GV4 r[3]; GV4 t; };
struct Node_00287710 { VPAD16(a) VPAD4(b) virtual void Refresh(); int pad4[3]; Mtx m; unsigned char dirty; };
struct Ctl { VPAD16(a) VPAD2(b) VPAD1(c) virtual int Active(); };
struct Tgt {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d)
    virtual V4 GetPos(int a); /* 0xC0 */
    char p4[0x2C - 4];
    bool x2C; bool x2D; bool x2E; char p2F;
    char p30[0x58 - 0x30];
    Ctl* x58;
    bool Alive() { bool r = 0; if (x2D && x2C) r = 1; return r; }
    bool Live() { return !x2E; }
    bool Targetable() { bool r = 0; if (Alive() && Live()) r = 1; return r; }
};
struct Owner { char p[0x50]; Node_00287710* node; };
struct Self { Owner* owner; char p4[0x18 - 4]; float lo; float hi; };
struct It {
    Tgt** p;
    bool operator==(const It& o) const { Tgt** b = o.p; return p == b; }
    bool operator!=(const It& o) const { return !(*this == o); }
};

extern "C" {
extern char* g_ActorList;
void* cObjList_cHumanPtr_GetList(char* self);
void cArray_cHumanPtr_Begin(It* out, void* v);
void cArray_cHumanPtr_End(It* out, void* v);
void GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(Mtx* m, V4* v, V4* out);
}

static inline void Q4(void* d0, const void* s0) { void* d = d0; __int128 qa, qb; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(qa), "=&r"(qb) : "r"(s), "r"(d) : "memory"); }
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }

extern "C" Tgt* cTurret_GetClosestEnemy(Self* self) {
    It it;
    It end;
    Mtx m;
    V4 hd;
    Node_00287710* n = self->owner->node;
    if (n->dirty) n->Refresh();
    { Mtx* src = &n->m; Mtx* dst = &m; Q4(dst, src); }
    char* reg = g_ActorList;
    cArray_cHumanPtr_Begin(&it, cObjList_cHumanPtr_GetList(reg));
    cArray_cHumanPtr_End(&end, cObjList_cHumanPtr_GetList(reg));
    float best = 1000.0f;
    Tgt* found = 0;
    for (; it != end; it.p++) {
        Tgt* t = *it.p;
        if (t->Targetable()) {
            bool ok = 0;
            if (t->x58 && t->x58->Active()) ok = 1;
            if (ok) {
                V4 pos = t->GetPos(-1);
                GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(&m, &pos, &hd);
                
                if (0.3f + hd.f.x > self->lo && hd.f.x - 0.3f < self->hi) {
                    float d = Abs(hd.f.z);
                    if (d < best) {
                        best = d;
                        found = t;
                    }
                }
            }
        }
    }
    return found;
}
static inline void merge_flush_func_00287710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00287710 */

/* merge_units: begin func_00287910 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_00287910(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_00287930(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_00287940(char* self) {
    return self + 4;
}
static inline void merge_flush_func_00287910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00287910 */

/* merge_units: begin func_00287950 */
#pragma push /* merge_units */
#pragma opt_propagation off
typedef struct Handle {
    int ptr;
    int id;
} Handle;

typedef struct Turret {
    int a0;
    int a4;
    int a8;
    int aC;
    int x10;
    int x14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    int x30;
    int x34;
    int x38;
    int x3C;
    int x40;
    int x44;
    int x48;
    int pad4C;
    float f50;
    unsigned char b54;
    unsigned char b55;
    char pad56[2];
    int x58;
    Handle h;
    int pad64;
    int x68;
} Turret;

Turret* cTurret_ctor(Turret* t, int a, int b, int c, int d, int e)
{
    int tmp;
    int* pt;
    t->h.id = -2;
    t->h.ptr = 0;
    t->a0 = a;
    t->a4 = b;
    t->a8 = c;
    t->aC = d ? d : b;
    t->h.ptr = 0;
    tmp = -1;
    pt = &tmp;
    t->h.id = *pt;
    t->x68 = 0;
    t->x30 = 0;
    t->x34 = 0;
    t->x38 = 0;
    t->x3C = 0;
    t->x10 = 0;
    t->x14 = 0;
    t->f50 = 0.1f;
    t->f18 = -0.06f;
    t->f1C = 0.03f;
    t->f20 = -2.0f;
    t->f24 = -2.0f;
    t->f28 = 10.0f;
    t->f2C = 0.5f;
    t->x58 = e;
    t->x48 = 0;
    t->x44 = 0;
    t->x40 = 0;
    t->b55 = 0;
    t->b54 = 0;
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00287950(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00287950 */

/* merge_units: begin func_00287A20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct TgtA20 { char pad[0x14]; float x; float y; };
struct EntA20 { TgtA20* p; float x; float y; };
struct OwnA20 { char pad[0x144]; float t; };
struct SelfA20 { void* obj; OwnA20* own; EntA20 e[2]; int n; float last; unsigned char on; };
extern float D_0048B3D0;
extern "C" unsigned char cTread_ctor(SelfA20*);
extern "C" void cTread_NextFrame(SelfA20* s)
{
    int i;
    if (cTread_ctor(s)) {
        float d;
        float t;
        t = s->own->t;
        d = t - s->last;
        s->last = t;
        d = d * D_0048B3D0;
        for (i = 0; i < s->n; i++) {
            TgtA20* p = s->e[i].p;
            float a = d * s->e[i].x;
            float b = d * s->e[i].y;
            p->x = a;
            p->y = b;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00287A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00287A20 */
