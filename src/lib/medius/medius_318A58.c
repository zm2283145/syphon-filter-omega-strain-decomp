/*
 * lib/medius: 4 files, 00318A58-00318B08
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00318A58 */
#include "types.h"

const float D_004B3968[74] = { 8.0f, 8.625f, 9.375f, 10.25f, 11.25f, 12.5625f, 13.6875f, 14.625f, 15.625f, 16.8125f, 18.1875f, 19.0f, 19.8125f, 20.4375f, 21.0625f, 21.75f, 22.5f, 23.25f, 24.125f, 25.0f, 26.0f, 26.75f, 27.625f, 28.5f, 29.4375f, 30.4375f, 31.5f, 32.625f, 33.625f, 34.6875f, 35.8125f, 37.0f, 38.25f, 39.625f, 40.8125f, 42.125f, 43.5f, 44.9375f, 46.5625f, 47.9375f, 49.5f, 51.125f, 52.875f, 54.4375f, 56.1875f, 58.0f, 59.9375f, 61.8125f, 63.75f, 65.875f, 67.875f, 70.0f, 72.3125f, 74.5f, 76.8125f, 79.3125f, 81.75f, 84.3125f, 86.875f, 89.5625f, 92.375f, 95.25f, 98.25f, 101.1875f, 104.375f, 107.5f, 110.875f, 114.1875f, 117.75f, 125.125f, 133.0f, 141.25f, 150.0625f, 159.4375f };

void GetPitchTable(int a0, int a1) {
    *(int*)((char*)a1) = 74;
    *(int*)((char*)a0) = (int)((char*)D_004B3968);
}
/* merge_units: end func_00318A58 */

/* merge_units: begin func_00318A70 */
typedef struct { float f; int i; } P8A70;
extern P8A70* (*D_004E1D34)(int, int);
int NellyInitLDPDA(P8A70** out)
{
    P8A70* p = D_004E1D34(1, 8);
    *out = p;
    if (p == 0)
        return 1;
    p->i = 0;
    p->f = 100.0f;
    return 0;
}
/* merge_units: end func_00318A70 */

/* merge_units: begin func_00318AC8 */
#include "hook_free_ptr.h"

/* compiler: ee-gcc 2.96 -O2 */
/* Free a pointer through the hook and clear it. */
DEFINE_HOOK_FREE_PTR_RET0(NellyFreeLDPDA)
/* merge_units: end func_00318AC8 */

/* merge_units: begin func_00318B08 */
extern volatile float D_004E1BB8;
int FindBaseBand(float *a, int n)
{
    int last = n - 1;
    int i;
    float sum = 0.0f;
    float acc;
    for (i = last; i >= 0; i--)
        sum += a[i];
    sum *= D_004E1BB8;
    acc = 0.0f;
    for (i = last; i >= 0; i--) {
        acc = a[i] + acc;
        if (sum <= acc) break;
    }
    i += 2;
    if (i < 76) i = 76;
    return i;
}
/* merge_units: end func_00318B08 */
