#include "types.h"
float func_001D10A0(float a, float b) {
    float r;
    asm { max.s r, b, a }
    return r;
}
