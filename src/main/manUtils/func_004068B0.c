#include "types.h"
typedef union { __int128 q; struct { char tag; char name[15]; } s; } P8B0Name;
typedef struct { P8B0Name a; P8B0Name b; } P8B0Pair;
typedef struct { char pad[0x40]; P8B0Pair pairs[1]; } P8B0Obj;
extern int String_CompareN(const char* a, const char* b, int n);
/* Pair index by type prefix. */
int func_004068B0(P8B0Obj* o, const char* key) {
    P8B0Pair* p = o->pairs;
    int i = 0;
    while ((long long)p->a.q != 0) {
        if (String_CompareN(p->a.s.name, key, 5) == 0)
            return i;
        p++;
        i++;
    }
    if (String_CompareN(p->b.s.name, key, 5) == 0)
        return i;
    i = -1;
    return i;
}


