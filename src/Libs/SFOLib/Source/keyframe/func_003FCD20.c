#include "types.h"
typedef struct { int m0; void* m4; } TCD20;
extern void std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_3(TCD20* t, void* n);
extern void operator_delete(void* p);
TCD20* std_tree_pair_int_value_compare_cAllocator_pair_dtor(TCD20* t, short del)
{
    if (t) {
        if (t->m4)
            std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_3(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
