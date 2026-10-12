#include "types.h"
typedef struct G6N36 { unsigned int size : 28; unsigned int flags : 4; int x; struct G6N36* next; struct G6N36* prev; } G6N36;
typedef struct { G6N36 bins[128]; G6N36* last; } G6H36;
int func_0036C880(G6H36* h, char* lo, int hi)
{
    char* e;
    G6N36* n;
    unsigned int w;
    G6N36* b;
    G6N36* end;
    end = h->last;
    for (b = h->bins; b <= end; b++) {
        for (n = b->next; n != b; n = n->next) {
            w = *(unsigned int*)n;
            if (w & 0x80000000) {
                if ((int)n < hi && lo < (char*)n + (w & 0x0FFFFFFF)) return 1;
            } else {
                if ((int)n < hi && lo < (char*)(n + 1)) return 1;
                e = (char*)n + (w & 0x0FFFFFFF);
                if ((unsigned)(e - 4) < hi && lo < e) return 1;
            }
        }
    }
    return 0;
}
