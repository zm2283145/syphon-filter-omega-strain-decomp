#include "types.h"
typedef struct { float a; float b; } A5_00373BA0;
int func_00373BA0(A5_00373BA0* x, A5_00373BA0* y) {
    float b = y->b, a = x->b;
    if (a < b) return -1;
    else if (a > b) return (unsigned char)(a > b);
    return (unsigned char)(a > b);
}
