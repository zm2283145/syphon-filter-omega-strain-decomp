#include "types.h"
typedef struct { int count; int items[1]; } A_183070;
int* InlinePtrArray_Find(A_183070* a, int* key)
{
    int* it = a->items;
    int* end = a->items + a->count;
    for (; it != end; it++) {
        if (*it == *key) return it;
    }
    return end;
}