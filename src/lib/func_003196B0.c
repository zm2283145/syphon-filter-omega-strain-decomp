#include "types.h"
void func_003196B0(float* vec, int n, float* mat, float* out, int rows) {
    int r;
    int j;
    float sum;
    for (r = 0; r < rows; r++) {
        sum = 0.0f;
        for (j = 0; j < n; j++) {
            sum += mat[j] * vec[j];
        }
        *out++ = sum;
        mat += n;
    }
}