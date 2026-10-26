#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

typedef struct { char pad[0x18C]; int mode; } Inner;
typedef struct { char pad[0x40]; Inner* inner; } Ctx;
extern int _decodeOrSkipField(Ctx* ctx, int a, int b);
extern int _decodeOrSkipFrame(Ctx* ctx, int a, int b);

/* Dispatches on the inner mode: mode 3 -> _decodeOrSkipFrame, otherwise _decodeOrSkipField (args passed through). */
int _decodeOrSkip(Ctx* ctx, int a, int b)
{
    if (ctx->inner->mode == 3)
        return _decodeOrSkipFrame(ctx, a, b);
    return _decodeOrSkipField(ctx, a, b);
}
