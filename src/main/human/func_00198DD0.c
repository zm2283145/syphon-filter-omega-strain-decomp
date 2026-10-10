#include "types.h"

typedef struct IntPair {
    int a;
    int b;
} IntPair;

/* Compares two int pairs for equality. */
int func_00198DD0(IntPair* x, IntPair* y) {
    return x->a == y->a && x->b == y->b;
}
