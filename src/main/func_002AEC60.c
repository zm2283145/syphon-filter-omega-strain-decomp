#include "types.h"

typedef struct { char pad[0x64]; int start; int remain; int pad6C; int end; } Range;
extern void MLTextWidget_UpdateScrollBar(Range* r);

/* Recomputes the remaining span (end - start, clamped at 0) and continues in MLTextWidget_UpdateScrollBar. */
void func_002AEC60(Range* r)
{
    r->remain = r->end - r->start;
    if (r->remain < 0)
        r->remain = 0;
    MLTextWidget_UpdateScrollBar(r);
}
