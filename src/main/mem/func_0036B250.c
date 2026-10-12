#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Releases a heap's pending block and clears its bookkeeping slot. */
struct Heap36B250 { char b[0x804]; char* blk; int f808; int f80C; int f810; int id; };
extern "C" {
extern Heap36B250 D_00533CB0[];
extern char D_004BBE50[];
void Mem_HeapFree(Heap36B250* heap, void* p, char* file, int line);
void func_0036B250(int h);
}
void func_0036B250(int h)
{
    if (D_00533CB0[h].id != -1) {
        char* p = D_00533CB0[h].blk;
        {
            AllocGuard guard;
            if (p) {
                char heap = p[-12] & 0xF;
                Mem_HeapFree(&D_00533CB0[heap], p, D_004BBE50, 0x244);
            }
        }
        D_00533CB0[h].f808 = 0;
D_00533CB0[h].blk = 0;
D_00533CB0[h].f80C = 0;
D_00533CB0[h].f810 = 0;
D_00533CB0[h].id = -1;
    }
}
