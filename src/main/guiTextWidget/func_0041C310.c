#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Release the owned record at +0xDC (string member at +0x14) under the allocator guard, reset +0x10. */
extern "C" {
extern char D_004BF2D0[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_00138B70(void* self, short flags);
void func_0041EBF0(void* self);
}
struct O34DB10 { char pad[0x10]; int a10; char pad14[0x64]; char* aDC; };
extern "C" void func_0041C310(O34DB10* o)
{
    char* p;
    func_0041EBF0(o);
    p = o->aDC;
    if (p) {
        {
            AllocGuard guard;
            if (p) {
                char* s = p + 0x14;
                if (s)
                    func_00138B70(s, 0);
            }
            Mem_Free(0, p, D_004BF2D0, 0x56);
        }
        o->aDC = 0;
    }

}