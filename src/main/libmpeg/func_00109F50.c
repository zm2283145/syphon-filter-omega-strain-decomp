#include "types.h"

/* Returns the top `bits` bits of a 64-bit word. */
int _sysbitNext(unsigned long long* word, int bits) {
    return *word >> (64 - bits);
}
