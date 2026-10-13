#pragma cplusplus on

#include "types.h"

/* Deleting destructor: nested member at 0x4C, then the base destructor. */
extern "C" {
void operator_delete(void* allocation);
void* func_00351070(void* self, short deleteFlag);
void* String_Dtor(void* self, short deleteFlag);
void* func_0034F720(void* self, short deleteFlag);
}
void* func_0034F720(void* self, short deleteFlag)
{
    if (self) {
        char* m = (char*)self + 0x4C;
        if (m) {
            if (m) {
                if (m)
                    func_00351070(m, 0);
            }
        }
        if (self)
            String_Dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}