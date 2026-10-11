#include "types.h"
extern void func_00408EA0(void* self);
extern void operator_delete(void* p);
/* Deleting destructor: run the member destructor, then delete. */
void* func_00409520(void* self, short del)
{
    if (self) {
        func_00408EA0(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}