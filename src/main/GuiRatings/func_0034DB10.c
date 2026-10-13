#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Release the owned record at +0xDC (string member at +0x14) under the allocator guard, reset +0x10. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* String_Dtor(void* self, short flags);
void func_0041EBF0(void* self);
}
struct O34DB10 { char pad[0x10]; int a10; char pad14[0xC8]; char* aDC; };
extern "C" void func_0034DB10(O34DB10* o)
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
                    String_Dtor(s, 0);
            }
            Mem_Free(0, p, "GuiRatings.cc", 0x96);
        }
        o->aDC = 0;
    }
    o->a10 = -1;
}