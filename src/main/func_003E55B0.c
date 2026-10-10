#include "types.h"

extern int func_002E9A10(void);
extern int func_003FF2C0(void);
extern int func_002E9A98(void* buf, void* end, int size, int count);
extern int func_002E9F08(void* obj, void* callback);
extern char D_0055A220[];
extern void func_003E4F70();

/* Runs the setup sequence; returns 1 only if every step succeeds. */
unsigned char func_003E55B0(void) {
    unsigned char ok = 0;
    char buf[0xC];
    if (!func_002E9A10() && func_003FF2C0() && !func_002E9A98(buf, buf + 0xC, 4, 1)
        && !func_002E9F08(D_0055A220, func_003E4F70)) {
        ok = 1;
    }
    return ok;
}
