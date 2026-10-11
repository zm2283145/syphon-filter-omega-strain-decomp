#pragma cplusplus on

#include "types.h"

/* Deleting destructor: payload at +0xB0 (two members), strings at +0x78/+0x6C, base func_0041F370. */
extern "C" {
extern char D_004DF020[];
extern char D_004DF0B0[];
void operator_delete(void* allocation);
void func_0036E220(void* self, int flags);
void* func_00138B70(void* self, short deleteFlag);
void* func_0041F370(void* self, short deleteFlag);
}
struct O3548B0 { void* vtable; };
extern "C" O3548B0* func_003548B0(O3548B0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DF020;
        char* p = (char*)self + 0xB0;
        if (p) {
            func_0036E220((char*)self + 0x194, -1);
            func_0036E220((char*)self + 0xF8, -1);
        }
        char* a = (char*)self + 0x78;
        if (a)
            func_00138B70(a, 0);
        char* b = (char*)self + 0x6C;
        if (b)
            func_00138B70(b, 0);
        if (self) {
            self->vtable = D_004DF0B0;
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}