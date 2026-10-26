/*
 * lib/medius: 2 files, 002DD2E8-002DD328
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DD2E8 */
extern int Net_AllocZeroed(int* out, unsigned long n);
extern void printf(const char* msg);
int Rt_MemoryAllocate(unsigned int n)
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
extern void rt_memory_free(int* p);
void DmeFree(int* p) {
    if (*p != 0) rt_memory_free(p);
}
/* merge_units: end func_002DD328 */
