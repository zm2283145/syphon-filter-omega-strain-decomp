#include "types.h"

/* Returns the top `bits` bits of a 64-bit word. */
int func_00109F50(unsigned long long* word, int bits) {
    return *word >> (64 - bits);
}
