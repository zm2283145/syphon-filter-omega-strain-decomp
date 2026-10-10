#include "types.h"

typedef struct { int words[2]; } Reader;
extern unsigned int D_0055D488;
extern int func_003C9C30(Reader* r);
extern int func_002E9A98(Reader* r, unsigned char* out, int size, int count);

/* Opens a reader and reads two bytes; on success clears D_0055D488 and returns 1. */
unsigned char func_003FF2C0(void)
{
    Reader r;
    unsigned char bytes[8]; /* header buffer; only the first two bytes are read here */
    unsigned char ok = 0;
    if (func_003C9C30(&r) && func_002E9A98(&r, &bytes[0], 1, 1) == 0 && func_002E9A98(&r, &bytes[1], 1, 1) == 0) {
        ok = 1;
        D_0055D488 = 0;
    }
    return ok;
}
