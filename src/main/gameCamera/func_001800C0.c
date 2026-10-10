#include "types.h"
extern char D_004E1D88;
extern Vec4 D_004E1D90;
void VecCurve_ZeroDerivative(Vec4* out) {
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f;
        D_004E1D88 = 1;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    *out = D_004E1D90;
}