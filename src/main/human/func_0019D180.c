#include "types.h"
extern float Libc_Atan2f(float y, float x);
float nSFOMath_GetZRotationFromXAxis(float* v) {
    return Libc_Atan2f(v[1], v[0]);
}
