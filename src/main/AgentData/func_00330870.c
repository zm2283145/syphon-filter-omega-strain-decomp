#include "types.h"

/* Tests bit `index` in a bit array of ints. */
int func_00330870(int* bits, int index) {
    return ((bits[index / 32] >> (index & 0x1F)) & 1) != 0;
}
