#include "types.h"
extern void std_tree_pair_int_value_compare_dtor_void(void* self, short del);
extern void operator_delete(void* p);
void* cAssocArray_int_netSystemField_dtor(void* self, short del)
{
    if (self) {
        if (self)
            std_tree_pair_int_value_compare_dtor_void(self, -1);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
