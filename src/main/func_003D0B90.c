#include "types.h"
extern void func_003D0A90(void* self, short del);
extern void func_003D0B10(void* self, short del);
extern void operator_delete(void* p);
void* func_003D0B90(void* self, short del)
{
    if (self) {
        void* a = (char*)self + 0x10;
        void* b;
        if (a)
            func_003D0A90(a, 0);
        b = (char*)self + 4;
        if (b)
            func_003D0B10(b, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
