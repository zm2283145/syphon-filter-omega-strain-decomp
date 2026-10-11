#include "types.h"
extern void func_003FCCC0(void* self, short del);
extern void operator_delete(void* p);
void* func_003FCDD0(void* self, short del)
{
    if (self) {
        if (self)
            func_003FCCC0(self, -1);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
