#include "types.h"
#pragma peephole off

typedef struct Pair10 {
    char pad[0x10];
    int a;
    int b;
} Pair10;

typedef struct Link2 {
    char pad[8];
    Pair10* first;
    Pair10* second;
} Link2;

/* Clears the two words at +0x10/+0x14 of both linked objects. */
void func_003D1E70(Link2* l) {
    Pair10* a = l->first;
    Pair10* b = l->second;
    a->a = 0;
    a->b = 0;
    b->a = 0;
    b->b = 0;
}
