#include "types.h"
extern void func_003FDEE0(void* self, short del);
extern void operator_delete(void* p);
void* func_003FEFD0(void* self, short del)
{
    if (self) {
        if (self)
            func_003FDEE0(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
