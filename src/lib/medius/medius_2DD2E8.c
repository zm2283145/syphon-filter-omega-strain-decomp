/*
 * lib/medius: 2 files, 002DD2E8-002DD328
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DD2E8 */
extern int Net_AllocZeroed(int* out, unsigned long n);
extern void printf(const char* msg);
int func_002DD2E8(unsigned int n)
{
    int p = 0;
    if (Net_AllocZeroed(&p, n))
        printf("rt_memory_allocate failed 
");
    return p;
}
/* merge_units: end func_002DD2E8 */

/* merge_units: begin func_002DD328 */
#include "types.h"
extern void func_002FB3C0(int* p);
void func_002DD328(int* p) {
    if (*p != 0) func_002FB3C0(p);
}
/* merge_units: end func_002DD328 */
