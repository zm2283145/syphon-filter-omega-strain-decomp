#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Release the owned record at +0xA0 (string member at +0x14) under the allocator guard, clear +0xA0/+0xA4. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_00138B70(void* self, short flags);
void func_00424A50(void* self);
}
struct O348AD0 { char pad[0xA0]; char* aA0; int aA4; };
extern "C" void func_00348AD0(O348AD0* o)
{
    char* p;
    func_00424A50(o);
    p = o->aA0;
    {
        AllocGuard guard;
        if (p) {
            char* s = p + 0x14;
            if (s)
                func_00138B70(s, 0);
        }
        Mem_Free(0, p, "GuiNetMessages.cc", 0xC1);
    }
    o->aA0 = 0;
    o->aA4 = 0;
}