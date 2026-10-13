#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Free every pending deferred heap block (heap index in the block header). */
struct Heap36C960 { char b[0x818]; };
extern "C" {
extern int D_00533C90;
extern char* D_00533890[];
extern Heap36C960 D_00533CB0[];
extern char D_004BBE50[];
void Mem_HeapFree(Heap36C960* heap, void* p, char* file, int line);
void Mem_PumpDeferredFrees(void);
}
void Mem_PumpDeferredFrees(void)
{
    while (D_00533C90) {
        char* p;
        D_00533C90--;
        p = D_00533890[D_00533C90];
        {
            AllocGuard guard;
            if (p) {
                char heap = p[-12] & 0xF;
                Mem_HeapFree(&D_00533CB0[heap], p, D_004BBE50, 0x46);
            }
        }
    }
}