#include "types.h"

extern int Math_Atan2Kernel(float, float);

int Math_Atan2f(float f12, float f13) {
    return Math_Atan2Kernel(f12, f13);
}
