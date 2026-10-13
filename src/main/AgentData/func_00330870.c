#include "types.h"

/* Tests bit `index` in a bit array of ints. */
int AgentData_TestObjectiveBit(int* bits, int index) {
    return ((bits[index / 32] >> (index & 0x1F)) & 1) != 0;
}
