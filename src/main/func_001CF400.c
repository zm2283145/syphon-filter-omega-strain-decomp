#include "types.h"
typedef struct { float x, y, z, w; } B8V_1B28E0;
typedef struct { char pad[0x40]; float s; float inv; } B8S_1B28E0;
extern void cQuaternion_opMul_float(B8V_1B28E0* out, B8V_1B28E0* in, float s);
extern void cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR_cQuaternionR_cQuaternionR(B8S_1B28E0* p, int a, B8V_1B28E0* b, int c, B8V_1B28E0* d);
void cHermiteSplineWithScaledDuration_cQuaternion_Reset_cQuaternionR_cQuaternionR_cQuaternionR_cQuaternionR(void* pv, int a, B8V_1B28E0* b, int c, B8V_1B28E0* d) {
    B8V_1B28E0 v1;
    B8V_1B28E0 v2;
    float s;
    float inv;
    B8S_1B28E0* p = (B8S_1B28E0*)pv;
    if (p) {
        s = ((B8S_1B28E0*)pv)->s;
        cQuaternion_opMul_float(&v1, b, s);
        cQuaternion_opMul_float(&v2, d, s);
        cHermiteSpline_cQuaternion_ctor_cQuaternionR_cQuaternionR_cQuaternionR_cQuaternionR(p, a, &v1, c, &v2);
        p->s = s;
        inv = (s != 0.0f) ? 1.0f / s : 0.0f;
        p->inv = inv;
    }
}