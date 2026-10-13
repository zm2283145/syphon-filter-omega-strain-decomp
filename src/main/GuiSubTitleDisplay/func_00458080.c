#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Release the owned record at +0xA0 (string member at +0x14) under the allocator guard, clear +0xA0/+0xA4. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* String_Dtor(void* self, short flags);
void func_0041EBF0(void* self);
}
struct O348AD0 { char pad[0x48]; char* aA0; int aA4; };
extern "C" void func_00458080(O348AD0* o)
{
    char* p;
    func_0041EBF0(o);
    p = o->aA0;
    {
        AllocGuard guard;
        if (p) {
            char* s = p + 0x14;
            if (s)
                String_Dtor(s, 0);
        }
        Mem_Free(0, p, "GuiSubTitleDisplay.cc", 0x15E);
    }
    o->aA0 = 0;

}