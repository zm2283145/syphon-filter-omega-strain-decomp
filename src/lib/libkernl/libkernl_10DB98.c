/*
 * lib/libkernl: 2 files, 0010DB98-0010DC18
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010DB98 */
extern int DIntr(void);
extern int EIntr(void);
extern void func_0010DAF0(unsigned int, unsigned int);
void InvalidDCache(unsigned int a, unsigned int b)
{
    int s;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) DIntr();
    func_0010DAF0(a & ~0x3F, b & ~0x3F);
    if (s) EIntr();
}
/* merge_units: end func_0010DB98 */

/* merge_units: begin func_0010DC18 */
#include "types.h"
#if 0 /* merge_units */
void func_0010DAF0(int, int);
#endif /* merge_units */
#define func_0010DAF0(a0, a1) (func_0010DAF0((unsigned int)(a0), (unsigned int)(a1))) /* merge_units */


void func_0010DC18(int a0, int a1)
{
    func_0010DAF0(a0 & 0xFFFFFFC0, a1 & 0xFFFFFFC0);
}
#undef func_0010DAF0 /* merge_units */
/* merge_units: end func_0010DC18 */
