#include "types.h"

/* Library code (RSA MD5): matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
} MD5_CTX;

/* MD5Init: sets the initial chaining values and clears the bit count. */
void func_002F2C28(MD5_CTX* context)
{
    context->count[0] = context->count[1] = 0;
    context->state[0] = 0x67452301;
    context->state[1] = 0xefcdab89;
    context->state[2] = 0x98badcfe;
    context->state[3] = 0x10325476;
}
