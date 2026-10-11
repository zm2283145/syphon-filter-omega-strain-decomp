#include "types.h"
extern void func_003CA300(void* self, short del);
extern void operator_delete(void* p);
void* func_003CA940(void* self, short del)
{
    if (self) {
        void* m = (char*)self + 4;
        if (m)
            func_003CA300(m, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
