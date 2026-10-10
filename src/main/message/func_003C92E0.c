#include "types.h"
typedef struct G6N3C { struct G6N3C* prev; struct G6N3C* next; } G6N3C;
void func_003C92E0(G6N3C** pp, int n)
{
    if (n >= 0) {
        while (n > 0) { *pp = (*pp)->next; n--; }
    } else {
        while (n < 0) { *pp = (*pp)->prev; n++; }
    }
}