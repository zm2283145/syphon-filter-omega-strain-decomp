#include "types.h"

typedef struct Quad4 {
    int a, b, c, d;
} Quad4;

/* Swaps two 16-byte records word by word. */
void func_003B9B80(Quad4* x, Quad4* y) {
    int t;
    if (x == y) return;
    t = x->a; x->a = y->a; y->a = t;
    t = x->b; x->b = y->b; y->b = t;
    t = x->c; x->c = y->c; y->c = t;
    t = x->d; x->d = y->d; y->d = t;
}
