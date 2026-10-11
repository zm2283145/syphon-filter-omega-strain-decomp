#include "types.h"
float func_001F1350(float a, float b) {
    float r;
    asm { max.s r, a, b }
    return r;
}
