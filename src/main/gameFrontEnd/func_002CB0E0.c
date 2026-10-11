#pragma cplusplus on
#include "types.h"
extern "C" {
void operator_delete(void* p);
void func_00138B70(void* m, int flags);
}
extern "C" void* func_002CB0E0(void* self, short deleteFlag)
{
    if (self) {
        void* m;
        m = (char*)self + 0x14;
        if (m) func_00138B70(m, 0);
        m = (char*)self + 0x8;
        if (m) func_00138B70(m, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}