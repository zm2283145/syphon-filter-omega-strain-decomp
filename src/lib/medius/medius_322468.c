/*
 * lib/medius: 6 files, 00322468-00322518
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00322468 */
#include "types.h"
typedef void (*Hook_00322468)(void);
extern unsigned short D_004E1D4C;
extern Hook_00322468 D_004E1D38;
extern void Libc_Free(void);
int nciSetFreeFunction(Hook_00322468 fn)
{
    if (D_004E1D4C) return 0x184C;
    if (!fn) fn = (Hook_00322468)Libc_Free;
    D_004E1D38 = fn;
    return 0;
}
/* merge_units: end func_00322468 */

/* merge_units: begin func_00322498 */
typedef void (*Hook_00322498)(void);
extern Hook_00322498 D_004E1D3C;
extern void memset(void);
int nciSetMemsetFunction(Hook_00322498 fn)
{
    if (!fn) fn = (Hook_00322498)memset;
    D_004E1D3C = fn;
    return 0;
}
/* merge_units: end func_00322498 */

/* merge_units: begin func_003224B8 */
typedef void (*Hook_003224B8)(void);
extern Hook_003224B8 D_004E1D40;
extern void memcpy(void);
int nciSetMemcpyFunction(Hook_003224B8 fn)
{
    if (!fn) fn = (Hook_003224B8)memcpy;
    D_004E1D40 = fn;
    return 0;
}
/* merge_units: end func_003224B8 */

/* merge_units: begin func_003224D8 */
typedef void (*Hook_003224D8)(void);
extern Hook_003224D8 D_004E1D44;
extern void Math_Cos(void);
int nciSetCosFunction(Hook_003224D8 fn)
{
    if (!fn) fn = (Hook_003224D8)Math_Cos;
    D_004E1D44 = fn;
    return 0;
}
/* merge_units: end func_003224D8 */

/* merge_units: begin func_003224F8 */
typedef void (*Hook_003224F8)(void);
extern Hook_003224F8 D_004E1D48;
extern void Math_Sin(void);
int nciSetSinFunction(Hook_003224F8 fn)
{
    if (!fn) fn = (Hook_003224F8)Math_Sin;
    D_004E1D48 = fn;
    return 0;
}
/* merge_units: end func_003224F8 */

/* merge_units: begin func_00322518 */
extern void func_00322630(float *re, float *im, int n);
void NellyFftCenter512(float *src, int n, int shift, float *re, float *im)
{
    int q = n >> 2;
    int half = n >> 1;
    int m = 1 << shift;
    float *pr = re + (256 - q);
    float *pi = im + (256 - q);
    int i, cnt;
    for (i = 0; i < q; i++) {
        *pr++ = *src++;
        *pi++ = *src++;
    }
    pr = re;
    pi = im;
    cnt = (n - q * 2) >> 1;
    for (i = 0; i < cnt; i++) {
        *pr++ = *src++;
        *pi++ = *src++;
    }
    if (n != half * 2) {
        *pr++ = *src++;
        i++;
        *pi++ = 0;
    }
    for (; i < 256 - q; i++) {
        *pr++ = 0;
        *pi++ = 0;
    }
    func_00322630(re, im, m);
}
/* merge_units: end func_00322518 */
