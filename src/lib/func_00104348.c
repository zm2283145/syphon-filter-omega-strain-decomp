#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { char pad[0x10]; unsigned int limit; } Ctx;
extern void func_00103C58(Ctx* ctx, unsigned int value, int arg);

/* Mode 1: returns whether ctx->limit < value; otherwise calls func_00103C58(ctx, value, arg) and returns 0. */
int func_00104348(Ctx* ctx, unsigned int value, int mode, int arg)
{
    int result;
    if (mode == 1)
        result = ctx->limit < value;
    else {
        func_00103C58(ctx, value, arg);
        result = 0;
    }
    return result;
}
