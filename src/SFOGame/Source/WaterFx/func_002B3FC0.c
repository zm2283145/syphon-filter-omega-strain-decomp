#include "types.h"
typedef struct { void* p; } It2B3FC0;
typedef struct { int vt; char list[4]; char end[4]; void* first; } O2B3FC0;
extern void std_list_deleter_tNode_erase_listdeleter_listdeleter(It2B3FC0* out, void* list, It2B3FC0* first, It2B3FC0* last);
extern void std_list_tNode_dtor(void* p, int f);
extern void operator_delete(void* p);
O2B3FC0* cWake_dtor(O2B3FC0* self, short del)
{
    if (self) {
        It2B3FC0 out;
        It2B3FC0 first;
        It2B3FC0 last;
        last.p = self->end;
        first.p = self->first;
        std_list_deleter_tNode_erase_listdeleter_listdeleter(&out, self->list, &first, &last);
        if (self->list)
            std_list_tNode_dtor(self->list, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}