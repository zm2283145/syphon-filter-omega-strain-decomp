#include "types.h"

extern int func_002E9A10(void);
extern int func_003FF2C0(void);
extern int func_002E9A98(void* buf, void* end, int size, int count);
extern int func_002E9F08(void* obj, void* callback);
extern char D_0055A1F0[];
extern void func_003E4CC0();

/* Runs the setup sequence; returns 1 only if every step succeeds. */
unsigned char func_003E53F0(void) {
    unsigned char ok = 0;
    char buf[0xC];
    int err;
    if (!func_002E9A10() && func_003FF2C0() && !(err = func_002E9A98(buf, buf + 0xC, 4, 1)) && !err
        && !func_002E9F08(D_0055A1F0, func_003E4CC0)) {
        ok = 1;
    }
    return ok;
}
