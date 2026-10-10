#include "types.h"

/* Converts four floats to ints scaled by 128. */
int* func_0025C9D0(int* out, float* in) {
    out[0] = (int)(128.0f * in[0]);
    out[1] = (int)(128.0f * in[1]);
    out[2] = (int)(128.0f * in[2]);
    out[3] = (int)(128.0f * in[3]);
    return out;
}
