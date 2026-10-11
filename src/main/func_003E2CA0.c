#include "types.h"
typedef struct { int m0; int m4; int m8; } T2CA0;
extern void func_003E3320(int* out, T2CA0* self, int* first, int* last);
extern void operator_delete(void* p);
T2CA0* func_003E2CA0(T2CA0* self, short del)
{
    if (self) {
        if (self) {
            if (self) {
                int r;
                int first;
                int last;
                last = (int)&self->m4;
                first = self->m8;
                func_003E3320(&r, self, &first, &last);
            }
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
