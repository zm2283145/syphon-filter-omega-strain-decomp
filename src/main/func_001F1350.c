#include "types.h"
float Math_MaxF(float a, float b) {
    float r;
    asm { max.s r, a, b }
    return r;
}
