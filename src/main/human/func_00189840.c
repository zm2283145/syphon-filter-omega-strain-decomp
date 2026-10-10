#include "types.h"
void AnimPriority_Helper2(unsigned int* bits, int idx, int set) {
    if (set) {
        bits[idx / 32] |= 1 << (idx & 31);
    } else {
        bits[idx / 32] &= ~(1 << (idx & 31));
    }
}