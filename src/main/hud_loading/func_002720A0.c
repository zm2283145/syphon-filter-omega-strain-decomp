#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
void func_003E79F0(void* p, int flag);
}
struct OwnedPtrHolder { void* p; };
extern "C" OwnedPtrHolder* func_002720A0(OwnedPtrHolder* self, short deleteFlag) {
    if (self) {
        void* p = self->p;
        {
            AllocGuard guard;
            func_003E79F0(p, -1);
            Mem_Free(0, p, "hud_loading.cc", 0x5B);
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}