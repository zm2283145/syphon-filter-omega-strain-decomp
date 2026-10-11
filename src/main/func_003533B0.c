#pragma cplusplus on

#include "types.h"

/* Deleting destructor: string at +0x80, nested member at +0x6C, base func_0041F370. */
extern "C" {
extern char D_004DEF90[];
extern char D_004DF0B0[];
void operator_delete(void* allocation);
void* func_00138B70(void* self, short deleteFlag);
void* func_00299360(void* self, short deleteFlag);
void* func_0041F370(void* self, short deleteFlag);
}
struct O3533B0 { void* vtable; };
extern "C" O3533B0* func_003533B0(O3533B0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DEF90;
        char* a = (char*)self + 0x80;
        if (a)
            func_00138B70(a, 0);
        char* m = (char*)self + 0x6C;
        if (m) {
            if (m) {
                if (m)
                    func_00299360(m, 0);
            }
        }
        if (self) {
            self->vtable = D_004DF0B0;
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}