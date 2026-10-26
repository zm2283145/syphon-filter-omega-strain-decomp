/*
 * lib/libkernl: 3 files, 0010EA70-0010EB58
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010EA70 */
static unsigned int dat_004861A0[1] = { 0x0 };
extern char D_004E2C00[];
extern void kputs(char *);
void deci2Putchar(int c)
{
    int n;
    if ((*(int*)dat_004861A0) >= 0x7E) {
        (*(int*)dat_004861A0) = 0;
        D_004E2C00[0x7F] = 0;
        kputs(D_004E2C00);
    }
    if (c == '\n') {
        n = (*(int*)dat_004861A0);
        (*(int*)dat_004861A0) = 0;
        D_004E2C00[n] = c;
        D_004E2C00[n + 1] = 0;
        kputs(D_004E2C00);
    } else {
        D_004E2C00[(*(int*)dat_004861A0)++] = c;
    }
}
/* merge_units: end func_0010EA70 */

/* merge_units: begin func_0010EB20 */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int kputchar();                                 

void serialPutchar(int arg0) {
    if (arg0 == 0xA) {
        kputchar(0xD);
        kputchar(0xA);
        return;
    }
    kputchar();
}
/* merge_units: end func_0010EB20 */

/* merge_units: begin func_0010EB58 */
int ftoi(unsigned long x)
{
    long e = (x << 1) >> 53;
    e -= 0x433;
    if (e < -53)
        return 0;
    if (e >= 13)
        return 9999;
    x = (x << 12) >> 12;
    x |= 1UL << 52;
    if (e < 0) {
        e = -e;
        x >>= e - 2;
        if ((x & 3) == 3)
            x = (x >> 2) + 1;
        else
            x >>= 2;
    } else {
        x <<= e;
    }
    return x;
}
/* merge_units: end func_0010EB58 */
