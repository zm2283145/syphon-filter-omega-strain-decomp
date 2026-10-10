#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct {
    char pad0[0x168];
    int state;
    char pad16C[0x1C4 - 0x16C];
    int pos;
    char pad1C8[0x864 - 0x1C8];
    int base;
    int max;
    int pending;
} Stream;

/* Advances the stream position by delta (handling a negative wrap) and tracks the maximum position. */
void func_00108678(Stream* s, int delta)
{
    int wrap = 0;
    int applied = 0;
    int max;
    if (s->state != 3 && delta != 0) {
        if (delta < 0)
            wrap = s->pending == 0;
        s->pending = 0;
        applied = delta;
    }
    s->pos = s->base + delta;
    if (wrap && applied >= delta)
        s->pos += 0x400;
    max = s->max;
    if (max < s->pos)
        max = s->pos;
    s->max = max;
}
