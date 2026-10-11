#include "types.h"
typedef struct { int pad0; int value; int pad8; int padC; } E376FF0;
typedef struct { char pad[0xC]; E376FF0* ents; int count; } S376FF0;
int func_00376FF0(S376FF0* o, int* out, int max)
{
    int n = 0;
    int i;
    for (i = 0; i < o->count; i++) {
        int v = o->ents[i].value;
        if (v) {
            if (n >= max) break;
            *out = v; n++; out++;
        }
    }
    return n;
}
