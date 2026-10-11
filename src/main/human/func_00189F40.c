#pragma cplusplus on
#include "types.h"
extern "C" { void __destroy_array(void* p, void* dtor, int size, int n); void func_0018A210(void); void operator_delete(void* p); void func_001BE5A0(void* p, int f); }
struct In3_189F40 { int x; };
static inline void D3_189F40(void* p) { if (p) func_001BE5A0(p, 0); }
static inline void D2_189F40(void* p) { if (p) D3_189F40(p); }
static inline void D1_189F40(void* p) { if (p) D2_189F40(p); }
struct O_189F40 { int vt; char arr[0x38]; char m[4]; };
extern "C" void* func_00189F40(O_189F40* self, short deleteFlag)
{
    if (self) {
        D1_189F40(self->m);
        if (self->arr) __destroy_array(self->arr, (void*)func_0018A210, 8, 7);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}