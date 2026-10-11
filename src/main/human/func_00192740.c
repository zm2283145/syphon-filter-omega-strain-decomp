#include "types.h"
float func_00192740(float x, float lo, float hi) {
    float r;
    asm { max.s r, x, lo
 min.s r, r, hi }
    return r;
}
