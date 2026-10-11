#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Release the owned record at +0xA0 (string member at +0x14) under the allocator guard, clear +0xA0/+0xA4. */
extern "C" {
extern char D_004C0110[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_00138B70(void* self, short flags);
void func_0041F090(void* self);
}
struct O348AD0 { char pad[0x48]; char* aA0; int aA4; };
extern "C" void func_0043E0E0(O348AD0* o)
{
    char* p;
    func_0041F090(o);
    p = o->aA0;
    {
        AllocGuard guard;
        if (p) {
            char* s = p + 0x14;
            if (s)
                func_00138B70(s, 0);
        }
        Mem_Free(0, p, D_004C0110, 0x67);
    }
    o->aA0 = 0;

}