#pragma cplusplus on
#include "types.h"

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
