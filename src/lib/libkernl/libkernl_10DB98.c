/*
 * lib/libkernl: 2 files, 0010DB98-0010DC18
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010DB98 */
extern int DIntr(void);
extern int EIntr(void);
extern void _sceIDC(unsigned int, unsigned int);
void InvalidDCache(unsigned int a, unsigned int b)
{
    int s;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) DIntr();
    _sceIDC(a & ~0x3F, b & ~0x3F);
    if (s) EIntr();
}
/* merge_units: end func_0010DB98 */

/* merge_units: begin func_0010DC18 */
#include "types.h"
#if 0 /* merge_units */
void _sceIDC(int, int);
#endif /* merge_units */
#define _sceIDC(a0, a1) (_sceIDC((unsigned int)(a0), (unsigned int)(a1))) /* merge_units */


void iInvalidDCache(int a0, int a1)
{
    _sceIDC(a0 & 0xFFFFFFC0, a1 & 0xFFFFFFC0);
}
#undef _sceIDC /* merge_units */
/* merge_units: end func_0010DC18 */
