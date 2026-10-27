/*
 * Libs/SFOLib/Source/mem: 1 file, 0036B250
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036B250 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Releases a heap's pending block and clears its bookkeeping slot. */
struct Heap36B250 { char b[0x804]; char* blk; int f808; int f80C; int f810; int id; };
extern "C" {
extern Heap36B250 D_00533CB0[];
extern char D_004BBE50[];
void cMemBin_Deallocate(Heap36B250* heap, void* p, char* file, int line);
void cMemMan_ReleaseBin(int h);
}
void cMemMan_ReleaseBin(int h)
{
    if (D_00533CB0[h].id != -1) {
        char* p = D_00533CB0[h].blk;
        {
            AllocGuard guard;
            if (p) {
                char heap = p[-12] & 0xF;
                cMemBin_Deallocate(&D_00533CB0[heap], p, D_004BBE50, 0x244);
            }
        }
        D_00533CB0[h].f808 = 0;
D_00533CB0[h].blk = 0;
D_00533CB0[h].f80C = 0;
D_00533CB0[h].f810 = 0;
D_00533CB0[h].id = -1;
    }
}
static inline void merge_flush_func_0036B250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036B250 */
