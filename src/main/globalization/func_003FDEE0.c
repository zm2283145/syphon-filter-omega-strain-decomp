#include "types.h"
extern void func_003FEEE0(void* self, short del);
extern void operator_delete(void* p);
void* func_003FDEE0(void* self, short del)
{
    if (self) {
        func_003FEEE0(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
