#pragma cplusplus on

#include "types.h"

/* Deleting destructor: own cleanup, then the base destructor. */
extern "C" void operator_delete(void* allocation);
extern "C" void FStream_CancelRequests(void* self);
extern "C" void* ReceiverList_Dtor_3EB9D0(void* self, short deleteFlag);

extern "C" void* func_003EB960(void* self, short deleteFlag)
{
    if (self) {
        FStream_CancelRequests(self);
        if (self)
            ReceiverList_Dtor_3EB9D0(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}