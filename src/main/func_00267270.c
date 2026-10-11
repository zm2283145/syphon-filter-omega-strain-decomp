#pragma cplusplus on
#include "guarded_buffer_dtor.h"

extern "C" char D_004A8250[];
extern "C" GuardedBuffer* func_00267270(GuardedBuffer* self, short deleteFlag)
{
    if (self) {
        self->count = 0;
        GUARDED_BUFFER_FREE(self, D_004A8250)
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}