#include "types.h"
float MAX(float a, float b) {
    float r;
    asm { max.s r, a, b }
    return r;
}
