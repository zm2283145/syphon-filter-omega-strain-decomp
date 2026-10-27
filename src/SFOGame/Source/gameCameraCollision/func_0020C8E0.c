#include "types.h"
#pragma optimization_level 1

extern void cSkaSwitchItem_dtor(int, int);

/* Calls cSkaSwitchItem_dtor(b, -1). */
void cAllocator_cSkaSwitchItem_destroy(int a, int b) {
    cSkaSwitchItem_dtor(b, -1);
}
