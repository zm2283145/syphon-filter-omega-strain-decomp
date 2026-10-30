#pragma cplusplus on
#pragma peephole off
#pragma opt_rotateloops off


#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
#pragma opt_propagation off


#include "types.h"

struct cVector { float x, y, z, w; } __attribute__((aligned(16)));

extern "C" {
long long Libc_Cos(long long x);
long long Libc_Sin(long long x);
long long SoftFloat_FloatToDouble(float f);
long long SoftFloat_DoubleMultiply(long long a, long long b);
float SoftFloat_DoubleToFloat(long long a);
void CreateSphereNormals(cVector* outNorms, int num);
}

static inline float Sqrt(float x) { asm { sqrt.s x, x } return x; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void Normalize(cVector* a) { cVector* r = a;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(r)
    }
}

#define DEG2RAD(a) (0.017453292f * (a))
/* MW's implicit fptodp/dpmul/dptofp runtime calls, named explicitly */
#define D(a) SoftFloat_FloatToDouble(a)
#define F(a) SoftFloat_DoubleToFloat(a)
#define MUL(a, b) SoftFloat_DoubleMultiply(a, b)

void CreateSphereNormals(cVector* outNorms, int num)
{
float naxis;
 float dtheta, dphi, theta, phi;
 float b;
 float a;
phi = 0.0f; naxis = Sqrt(num); dtheta = 180.0f / naxis; dphi = 360.0f / naxis; theta = -90.0f;
    
    int cnt = num;
    int ray = 0;
    while (cnt) {
        cVector& norm = outNorms[ray++];
        norm.x = F(MUL(Libc_Cos(D(DEG2RAD(theta))), Libc_Cos(D(DEG2RAD(phi)))));
        norm.y = F(MUL(Libc_Cos(D(DEG2RAD(theta))), Libc_Sin(D(DEG2RAD(phi)))));
        norm.z = F(Libc_Sin(D(DEG2RAD(theta))));
        *(int*)&norm.w = 0;
        Normalize(&norm);
        float full = 360.0f;
        phi += dphi;
        if (!(phi < full)) {
            phi -= full;
            theta += dtheta;
        }
        cnt--;
    }
}




