#include "types.h"
typedef struct { int m0; int m4; int m8; } TA3F0;
extern void func_003C9EA0(int* out, TA3F0* self, int* first, int* last);
extern void operator_delete(void* p);
TA3F0* func_003CA3F0(TA3F0* self, short del)
{
    if (self) {
        int r;
        int first;
        int last;
        last = (int)&self->m4;
        first = self->m8;
        func_003C9EA0(&r, self, &first, &last);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
