#pragma cplusplus on

#include "types.h"

/* List destructor (three inlined null tests): erase [first, sentinel), then delete. */
struct N37F950;
struct L37F950 { int count; N37F950* sentinelPrev; N37F950* first; };
extern "C" {
void operator_delete(void* allocation);
void func_0037FA60(N37F950** result, L37F950* self, N37F950** first, N37F950** last);
}
extern "C" L37F950* func_0037F950(L37F950* self, short deleteFlag)
{
    if (self) {
        if (self) {
            if (self) {
                N37F950* result;
                N37F950* first;
                N37F950* last;
                last = (N37F950*)&self->sentinelPrev;
                first = self->first;
                func_0037FA60(&result, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}