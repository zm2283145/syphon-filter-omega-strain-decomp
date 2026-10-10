#include "types.h"

typedef struct { char pad[0x64]; int start; int remain; int pad6C; int end; } Range;
extern void func_0043E290(Range* r);

/* Recomputes the remaining span (end - start, clamped at 0) and continues in func_0043E290. */
void func_002AEC60(Range* r)
{
    r->remain = r->end - r->start;
    if (r->remain < 0)
        r->remain = 0;
    func_0043E290(r);
}
