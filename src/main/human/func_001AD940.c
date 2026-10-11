#pragma opt_strength_reduction off
#include "types.h"

typedef struct { int pad0; int count; int* data; } PtrVec_1AD940;
extern void PtrVector_Resize(PtrVec_1AD940* v, int n, int* fill);

void func_001AD940(PtrVec_1AD940* v, int* value)
{
    int i;
    int last = v->count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &v->data[i];
        if (*e == *value) {
            *e = v->data[last];
            last--;
        }
    }
    fill = 0;
    PtrVector_Resize(v, last + 1, &fill);
}
#pragma opt_strength_reduction reset