#include "types.h"
typedef struct G7N { struct G7N* prev; struct G7N* next; } G7N;
void func_003EB8F0(G7N** pp, int n)
{
    if (n >= 0) {
        while (n > 0) { *pp = (*pp)->next; n--; }
    } else {
        while (n < 0) { *pp = (*pp)->prev; n++; }
    }
}