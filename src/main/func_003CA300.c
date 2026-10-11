#include "types.h"
extern void func_003CA3F0(void* self, short del);
extern void operator_delete(void* p);
void* func_003CA300(void* self, short del)
{
    if (self) {
        if (self)
            func_003CA3F0(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
