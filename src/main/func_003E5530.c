#include "types.h"

typedef struct { int words[3]; } Reader;
extern char D_0055A1E0[];
extern void func_003E4E90();
extern int func_002E9A10(void);
extern unsigned char func_003FF2C0(void);
extern int func_002E9A98(Reader* r, void* out, int size, int count);
extern int func_002E9F08(void* table, void (*cb)());

/* Startup check chain; returns 1 when every step succeeds. */
unsigned char func_003E5530(void)
{
    Reader r;
    int value;
    unsigned char ok = 0;
    if (func_002E9A10() == 0 && func_003FF2C0() && func_002E9A98(&r, &value, 4, 1) == 0
        && func_002E9F08(D_0055A1E0, func_003E4E90) == 0)
        ok = 1;
    return ok;
}
