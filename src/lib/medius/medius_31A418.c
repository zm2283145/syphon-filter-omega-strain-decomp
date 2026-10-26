#include "types.h"
void PeakPick(float* a, int start, int end, int max, int* out, int* count) {
    int n = 0;
    int i;
    for (i = start + 1; i < end - 1; i++) {
        if (a[i - 1] <= a[i] && a[i + 1] < a[i]) {
            n++;
            *out++ = i++;
            if (n == max) break;
        }
    }
    *count = n;
}