#include "types.h"
typedef struct { int x0[0x38/4]; int* x38; int x3C[3]; int* x48; } ScrDC4F0;
int Script_ResolveType(ScrDC4F0* s, int t) {
    if (t >= 100) { t -= 100; t = s->x38[t]; }
    else if (t >= 10) { t -= 10; t = s->x48[t]; }
    return t;
}