#include "types.h"
extern void func_0040B830(void* self, short del);
extern void operator_delete(void* p);
/* Deleting destructor: run the base destructor, then delete. */
void* func_0040C8E0(void* self, short del)
{
    if (self) {
        func_0040B830(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}