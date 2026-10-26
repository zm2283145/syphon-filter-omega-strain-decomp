#include "types.h"

/* Built at a lower optimization level (unscheduled loop). */
#pragma optimization_level 1

typedef struct { char data[0x24]; } Elem0C;
extern void cSkaTransBLEND_opAssign(Elem0C* e, void* value);

/* Calls cSkaTransBLEND_opAssign(e, value) on n consecutive 12-byte elements. */
void std_fill_n_cSkaTransBLEND_int_fill_n(Elem0C* e, int n, void* value)
{
    for (; n != 0; e++, n--)
        cSkaTransBLEND_opAssign(e, value);
}
