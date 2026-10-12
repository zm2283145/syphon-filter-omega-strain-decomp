#include "types.h"
float Math_MinF(float a, float b) {
    float r;
    asm { min.s r, a, b }
    return r;
}
