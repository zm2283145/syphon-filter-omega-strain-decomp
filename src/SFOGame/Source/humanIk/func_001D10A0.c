#include "types.h"
float CLAMP_LOW(float a, float b) {
    float r;
    asm { max.s r, b, a }
    return r;
}
