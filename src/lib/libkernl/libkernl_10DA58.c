/*
 * lib/libkernl: 2 files, 0010DA58-0010DAD8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010DA58 */
extern int DIntr(void);
extern int EIntr(void);
extern void _sceSDC(unsigned int, unsigned int);
void SyncDCache(unsigned int a, unsigned int b)
{
    int s;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    s &= 0x10000;
    if (s) DIntr();
    _sceSDC(a & ~0x3F, b & ~0x3F);
    if (s) EIntr();
}
/* merge_units: end func_0010DA58 */

/* merge_units: begin func_0010DAD8 */
#include "types.h"
#if 0 /* merge_units */
void _sceSDC(int, int);
#endif /* merge_units */
#define _sceSDC(a0, a1) (_sceSDC((unsigned int)(a0), (unsigned int)(a1))) /* merge_units */


void iSyncDCache(int a0, int a1)
{
    _sceSDC(a0 & 0xFFFFFFC0, a1 & 0xFFFFFFC0);
}
#undef _sceSDC /* merge_units */
/* merge_units: end func_0010DAD8 */
