#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

typedef struct { char pad[0x18C]; int mode; } Inner;
typedef struct { char pad[0x40]; Inner* inner; } Ctx;
extern int func_0010B9B0(Ctx* ctx, int a, int b);
extern int func_0010B848(Ctx* ctx, int a, int b);

/* Dispatches on the inner mode: mode 3 -> func_0010B848, otherwise func_0010B9B0 (args passed through). */
int func_0010B968(Ctx* ctx, int a, int b)
{
    if (ctx->inner->mode == 3)
        return func_0010B848(ctx, a, b);
    return func_0010B9B0(ctx, a, b);
}
