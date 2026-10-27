#pragma cplusplus on

#include "types.h"

/* List destructor (three inlined null tests): erase [first, sentinel), then delete. */
struct N37F950;
struct L37F950 { int count; N37F950* sentinelPrev; N37F950* first; };
extern "C" {
void operator_delete(void* allocation);
void std_list_deleter_tDataDelRec_erase_listdeleter_listdeleter(N37F950** result, L37F950* self, N37F950** first, N37F950** last);
}
extern "C" L37F950* std_list_tDataDelRec_dtor(L37F950* self, short deleteFlag)
{
    if (self) {
        if (self) {
            if (self) {
                N37F950* result;
                N37F950* first;
                N37F950* last;
                last = (N37F950*)&self->sentinelPrev;
                first = self->first;
                std_list_deleter_tDataDelRec_erase_listdeleter_listdeleter(&result, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}