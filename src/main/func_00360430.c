#pragma cplusplus on

#include "types.h"

/* Deleting destructor: subobject at +0x88 with strings at +0xC4/+0xB8, base func_0033D430. */
extern "C" {
extern char D_004DF350[];
void operator_delete(void* allocation);
void* func_00138B70(void* self, short deleteFlag);
void* func_0033D430(void* self, short deleteFlag);
}
struct O360430 { void* vtable; };
extern "C" O360430* func_00360430(O360430* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DF350;
        char* p = (char*)self + 0x88;
        if (p) {
            char* a = (char*)self + 0xC4;
            if (a)
                func_00138B70(a, 0);
            char* b = (char*)self + 0xB8;
            if (b)
                func_00138B70(b, 0);
        }
        func_0033D430(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}