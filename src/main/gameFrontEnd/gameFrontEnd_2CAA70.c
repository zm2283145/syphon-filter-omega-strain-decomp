/*
 * main/gameFrontEnd: range (2 files, 002CAA70-002CAB40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_002CAA70 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void* Mem_Alloc(int pool, void* p, char* file, int line);
}
extern "C" void* Sfo_Malloc(void* p)
{
    AllocGuard g;
    char f[] = "sfo_malloc: should only be used in rtime lib";
    return Mem_Alloc(2, p, f, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CAA70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CAA70 */

/* merge_units: begin func_002CAB40 */
#pragma push /* merge_units */
extern void func_002A7DD0(int, int);

void func_002CAB40(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 600);
    cond = a0 == 0;
    if (cond) goto L002CAB60;
    func_002A7DD0(a0, a1);
L002CAB60:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CAB40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CAB40 */
