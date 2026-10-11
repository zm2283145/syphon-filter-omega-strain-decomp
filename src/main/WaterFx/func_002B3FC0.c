#include "types.h"
typedef struct { void* p; } It2B3FC0;
typedef struct { int vt; char list[4]; char end[4]; void* first; } O2B3FC0;
extern void func_002B4860(It2B3FC0* out, void* list, It2B3FC0* first, It2B3FC0* last);
extern void func_002B2AF0(void* p, int f);
extern void operator_delete(void* p);
O2B3FC0* func_002B3FC0(O2B3FC0* self, short del)
{
    if (self) {
        It2B3FC0 out;
        It2B3FC0 first;
        It2B3FC0 last;
        last.p = self->end;
        first.p = self->first;
        func_002B4860(&out, self->list, &first, &last);
        if (self->list)
            func_002B2AF0(self->list, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}