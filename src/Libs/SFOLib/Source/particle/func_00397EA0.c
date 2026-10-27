#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void std_vector_intPtr_dtor(void* p, int flags);
void operator_delete(void* p);
}
extern "C" void* cEffectRequest_dtor(void* self, short flag)
{
    if (self) {
        void* b = *(void**)self;
        {
            AllocGuard g;
            cMemMan_Deallocate(0, b, "particle.cc", 0x11A0);
        }
        {
            void* m = (char*)self + 4;
            if (m)
                std_vector_intPtr_dtor(m, -1);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}