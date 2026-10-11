#pragma cplusplus on

#include "types.h"
#include "owned_buffer8_dtor.h"

/* Deleting destructor of a vector of trivially destructible elements (two inlined null tests). */
extern "C" char D_004AA5B8[];
extern "C" OwnedBuffer8* func_003545C0(OwnedBuffer8* self, short deleteFlag)
{
    if (self) {
        if (self) {
            self->last = 0;
            void* p = self->buffer;
            if (p) {
                if (p) {
                    AllocGuard guard;
                    Mem_Free(0, p, D_004AA5B8, 0x64);
                }
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}