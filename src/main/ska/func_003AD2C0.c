#include "types.h"

typedef struct HandlePair {
    int first;
    int second;
} HandlePair;

/* True when first is non-zero or second is not -1. */
int func_003AD2C0(HandlePair* p) {
    return p->first != 0 || ~p->second != 0;
}
