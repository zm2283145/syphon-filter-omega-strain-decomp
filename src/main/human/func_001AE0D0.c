#include "types.h"

typedef struct BitSetOwner {
    char pad0000[0x3204];
    int bits[8]; /* 0x3204 */
} BitSetOwner;

/* Tests bit `index` in the 256-bit set at +0x3204. */
int func_001AE0D0(BitSetOwner* obj, unsigned char index) {
    return ((obj->bits[(unsigned int)index >> 5] >> (index & 0x1F)) & 1) != 0;
}
