#pragma cplusplus on

#include "types.h"

/* Deleting destructor: own cleanup, then the base destructor. */
extern "C" void operator_delete(void* allocation);
extern "C" void cFileStreamMan_Purge(void* self);
extern "C" void* std_list_cFSDataPtr_dtor(void* self, short deleteFlag);

extern "C" void* cFileStreamMan_dtor(void* self, short deleteFlag)
{
    if (self) {
        cFileStreamMan_Purge(self);
        if (self)
            std_list_cFSDataPtr_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}