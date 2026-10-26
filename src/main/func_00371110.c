#include "types.h"
typedef struct { char pad[0x1030]; int n; int pad1034; int base; int* arr; int pend; } S371110;
int XLib_ValidateBatch(S371110* o)
{
    if (o->n > 0 && o->pend > 0) {
        o->arr[o->n - 1] = o->pend;
        o->pend = 0;
    }
    return o->arr[o->n - o->base] > 0;
}