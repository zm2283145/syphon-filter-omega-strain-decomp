/*
 * lib/medius: 2 files, 00317080-003170A8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00317080 */
#include "types.h"

extern char D_004B35D0[];
extern float ScalarLUT(int, int, int);

float UnQuanGainSC3(int a0) {
    return ScalarLUT((int)D_004B35D0, 64, a0);
}
/* merge_units: end func_00317080 */

/* merge_units: begin func_003170A8 */
const float D_004B36D0[8] = { 0.0f, 0.142999992f, 0.28599999f, 0.429f, 0.571f, 0.714f, 0.857f, 1.0f };
int QuanPvSC3(float a, float b, float c)
{
    int hi = 0, best = 0, i;
    float bd = c - ((float*)D_004B36D0)[0];
    bd = bd * bd;
    for (i = 1; i < 8; i++) {
        float d = c - ((float*)D_004B36D0)[i];
        d = d * d;
        if (d < bd) { bd = d; best = i; }
    }
    if ((((float*)D_004B36D0)[best] - b) * (((float*)D_004B36D0)[best] - b) < (a - b) * (a - b)) hi = 1;
    return best + hi * 8;
}
/* merge_units: end func_003170A8 */
