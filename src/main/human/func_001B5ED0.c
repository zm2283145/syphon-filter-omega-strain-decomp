#pragma cplusplus on
#include "types.h"
extern "C" { void operator_delete(void* p); void func_001BE690(void* p, int f); }
static inline void D3_1B5ED0(void* p) { if (p) func_001BE690(p, 0); }
static inline void D2_1B5ED0(void* p) { if (p) D3_1B5ED0(p); }
static inline void D1_1B5ED0(void* p) { if (p) D2_1B5ED0(p); }
extern "C" void* func_001B5ED0(void* self, short deleteFlag)
{
    if (self) {
        D1_1B5ED0(self);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}