#include "types.h"
typedef struct G7N { struct G7N* prev; struct G7N* next; } G7N;
void std_advance_listR_int(G7N** pp, int n)
{
    if (n >= 0) {
        while (n > 0) { *pp = (*pp)->next; n--; }
    } else {
        while (n < 0) { *pp = (*pp)->prev; n++; }
    }
}