#pragma cplusplus on

#include "types.h"

/* Deleting destructor: string member at +0xA8, middle class with a member at +0x60, base func_0041F370. */
extern "C" {
extern char D_004DEB80[];
extern char D_004E0D20[];
void operator_delete(void* allocation);
void* func_00138B70(void* self, short deleteFlag);
void* func_0013B2E0(void* self, short deleteFlag);
void* func_0041F370(void* self, short deleteFlag);
}
struct O3490F0 { void* vtable; };
extern "C" O3490F0* func_003490F0(O3490F0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DEB80;
        char* m = (char*)self + 0xA8;
        if (m)
            func_00138B70(m, 0);
        if (self) {
            self->vtable = D_004E0D20;
            func_0013B2E0((char*)self + 0x60, -1);
            func_0041F370(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}