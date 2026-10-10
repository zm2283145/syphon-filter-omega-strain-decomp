#include "types.h"
typedef struct G6N36 { unsigned int size : 28; unsigned int flags : 4; int x; struct G6N36* next; struct G6N36* prev; } G6N36;
typedef struct { G6N36 bins[128]; G6N36* last; } G6H36;
unsigned int func_0036C810(G6H36* h)
{
    G6N36* n;
    unsigned int max;
    G6N36* end;
    G6N36* b;
    end = h->last;
    b = h->bins;
    max = 0;
    for (; b <= end; b++) {
        for (n = b->next; n != b; n = n->next) {
            if (n->size > max) max = n->size;
        }
    }
    return max;
}