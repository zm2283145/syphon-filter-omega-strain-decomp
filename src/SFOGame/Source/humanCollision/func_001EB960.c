#include "types.h"
#include "humanCollision_types.h"

/* Mask constructor: all bits set when all == 1, else none. */
HumanColMask* cBitArray_5_ctor_bool(HumanColMask* m, unsigned char all) {
    if (all == 1) {
        m->bits = -1;
    } else {
        m->bits = 0;
    }
    return m;
}
