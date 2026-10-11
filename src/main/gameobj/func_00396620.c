#pragma cplusplus on

#include "types.h"

/* Deleting destructor: destroy all elements, then the base. */
typedef struct { int w[8]; } Iter_396620;
typedef struct { unsigned char pad[0x14]; int count; } Arr_396620;

extern "C" {
void func_00397840(Iter_396620* out, Arr_396620* a, int index);
void Array_DestroyRange(Arr_396620* a, Iter_396620* first, Iter_396620* last);
void* func_003966B0(Arr_396620* a, short deleteFlag);
void operator_delete(void* allocation);
}

extern "C" Arr_396620* func_00396620(Arr_396620* self, short deleteFlag)
{
    if (self) {
        Iter_396620 first;
        Iter_396620 last;
        func_00397840(&last, self, self->count);
        func_00397840(&first, self, 0);
        Array_DestroyRange(self, &first, &last);
        func_003966B0(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}