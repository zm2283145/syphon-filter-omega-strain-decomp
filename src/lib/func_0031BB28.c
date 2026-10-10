#include "types.h"
void func_0031BB28(float* a, int n, int* outIdx, float* outVal) {
    float m = *a;
    int idx = 0;
    int i;
    a++;
    for (i = 1; i < n; i++) {
        if (m < *a) { m = *a; idx = i; }
        a++;
    }
    *outIdx = idx;
    *outVal = m;
}