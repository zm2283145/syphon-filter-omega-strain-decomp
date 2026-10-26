#include "types.h"
typedef struct { int m0; void* m4; } TCCC0;
extern void std_tree_pair_int_value_compare_destroy_nodeP_2(TCCC0* t, void* n);
extern void operator_delete(void* p);
TCCC0* std_tree_pair_int_value_compare_dtor_void(TCCC0* t, short del)
{
    if (t) {
        if (t->m4)
            std_tree_pair_int_value_compare_destroy_nodeP_2(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
