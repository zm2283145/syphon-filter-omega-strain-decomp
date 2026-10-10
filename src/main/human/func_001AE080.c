#include "types.h"
typedef struct { int unk0; int bits[1]; } BitSet001AE080;
/* Test bit `index` of a bitset that starts at offset 4. */
int BitSet_Test(BitSet001AE080* set, unsigned char index)
{
    unsigned int i = index;
    return ((set->bits[i >> 5] >> (i & 0x1F)) & 1) != 0;
}
