#include "types.h"
typedef struct { char pad[0x40]; int value; } Node_18A670;
typedef struct { Node_18A670* n; } It_18A670;
typedef struct { char pad[0x24]; int tree; } Map_18A670;
extern void Tree_Compare(It_18A670* out, int* tree, int key);
extern void std_map_cString16N_3_int_cAllocator_pair_end_void(It_18A670* out, int* tree);
extern void cAssocArray_cString16N_3_int_ConstIterator_ctor(It_18A670* out, It_18A670* in);
int NodeNameMap_Find(Map_18A670* m, int key)
{
    It_18A670 c;
    It_18A670 f;
    It_18A670 e;
    Node_18A670* n;
    Tree_Compare(&f, &m->tree, key);
    n = f.n;
    std_map_cString16N_3_int_cAllocator_pair_end_void(&e, &m->tree);
    cAssocArray_cString16N_3_int_ConstIterator_ctor(&c, &e);
    if (n == c.n) return 0;
    return n->value;
}

