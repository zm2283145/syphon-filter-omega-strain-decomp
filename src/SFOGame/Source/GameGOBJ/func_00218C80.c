#pragma cplusplus on
#include "vslot_pad.h"

struct cQuaternion {
    float x, y, z, w;
    cQuaternion() {}
} __attribute__((aligned(16)));

struct cMatrix {
    float m[16];
    cMatrix() {}
    cMatrix(const cQuaternion& q)
    {
        cMatrix* m = this;
        const cQuaternion* qp = &q;
        __asm__(
            "lqc2 $vf1, 0x0(%1); vadd.xyzw $vf2, $vf1, $vf1; vaddw.xyz $vf3, $vf0, $vf0w; vmulx.w $vf8, $vf0, $vf0x; vmulx.w $vf9, $vf0, $vf0x;"
            "vmuly.xyzw $vf5, $vf1, $vf2y; vmulz.xyzw $vf6, $vf1, $vf2z; vmulx.xyzw $vf4, $vf1, $vf2x; vmulx.w $vf10, $vf0, $vf0x;"
            "vsubay.x $ACC, $vf3, $vf5y; vmsubz.x $vf8, $vf3, $vf6z; vsubw.x $vf9, $vf5, $vf6w; vaddw.x $vf10, $vf6, $vf5w;"
            "vaddw.y $vf8, $vf4, $vf6w; vsubax.y $ACC, $vf3, $vf4x; vmsubz.y $vf9, $vf3, $vf6z; vsubw.y $vf10, $vf6, $vf4w;"
            "vsubw.z $vf8, $vf4, $vf5w; vaddw.z $vf9, $vf5, $vf4w; vsubax.z $ACC, $vf3, $vf4x; vmsuby.z $vf10, $vf3, $vf5y;"
            "sqc2 $vf0, 0x30(%0); sqc2 $vf8, 0x0(%0); sqc2 $vf9, 0x10(%0); sqc2 $vf10, 0x20(%0)"
            : : "r"(m), "r"(qp) : "memory");
    }
} __attribute__((aligned(16)));

extern "C" {
float func_001E50E0(const cQuaternion* a, const cQuaternion* b);
cQuaternion cQuaternion_opSub(const cQuaternion* q);
cQuaternion LerpAndNormalize(const cQuaternion* a, const cQuaternion* b, float t);
}

static inline cQuaternion Interp(const cQuaternion& q0, const cQuaternion& q1, float t)
{
    if (func_001E50E0(&q0, &q1) >= 0.0f) return LerpAndNormalize(&q0, &q1, t);
    return LerpAndNormalize(&q0, &cQuaternion_opSub(&q1), t);
}

struct cArray {
    int mUnk;
    volatile int mCount;
    cQuaternion* volatile mData;
    int mCap;
    int Size() const { return mCount; }
    const cQuaternion& Get(int i) const
    {
        if (i < 0) i = 0;
        int n = mCount;
        if (i < n) { int o = i * (int)sizeof(cQuaternion); return *(const cQuaternion*)((const char*)mData + o); }
        i = n - 1;
        int o = i * (int)sizeof(cQuaternion);
        return *(const cQuaternion*)((const char*)mData + o);
    }
};

struct cGOBJ {
    VPAD8(a) VPAD1(b)
    virtual cMatrix GetRot();
};

struct cPathedGOBJ {
    char pad0[0x50];
    cGOBJ* mGob;
    char pad54[0x50];
    cArray mPathQuats;
};

#pragma opt_propagation off
extern "C" cMatrix cPathedGOBJ_GetAdjustedRot(cPathedGOBJ* self, int fromPoint, int toPoint, float currFraction)
{
    if (self->mPathQuats.Size()) {
        const cQuaternion& a = self->mPathQuats.Get(toPoint);
        const cQuaternion& b = self->mPathQuats.Get(fromPoint);
        cQuaternion currQuat = Interp(a, b, currFraction);
        return cMatrix(currQuat);
    }
    return self->mGob->GetRot();
}



