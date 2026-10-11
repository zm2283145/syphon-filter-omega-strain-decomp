#include "types.h"
typedef struct { int m0; int m4; int m8; } T0B10;
extern void func_003D10B0(int* out, T0B10* self, int* first, int* last);
extern void operator_delete(void* p);
T0B10* func_003D0B10(T0B10* self, short del)
{
    if (self) {
        if (self) {
            if (self) {
                int r;
                int first;
                int last;
                last = (int)&self->m4;
                first = self->m8;
                func_003D10B0(&r, self, &first, &last);
            }
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
