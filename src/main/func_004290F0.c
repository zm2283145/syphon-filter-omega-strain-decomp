#include "types.h"

extern int D_005721A0;
extern int func_002E9A10(void);
extern int func_003C9C30(int*);
extern int func_002E9F08(void*, void*);
extern void func_00429190(void);

/* Registers the func_00429190 handler when the preconditions hold; returns 1 on success. */
unsigned char func_004290F0(void) {
    unsigned char ok = 0;
    int tmp[2];
    if (func_002E9A10() == 0 && func_003C9C30(tmp) != 0 &&
        func_002E9F08(&D_005721A0, func_00429190) == 0) {
        ok = 1;
    }
    return ok;
}
