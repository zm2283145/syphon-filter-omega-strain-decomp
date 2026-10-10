#include "types.h"

/* Built at a lower optimization level (unscheduled loop). */
#pragma optimization_level 1

typedef struct { char data[0xC]; } Elem0C;
extern void func_00209E50(Elem0C* e, void* value);

/* Calls func_00209E50(e, value) on n consecutive 12-byte elements. */
void func_0020A690(Elem0C* e, int n, void* value)
{
    for (; n != 0; e++, n--)
        func_00209E50(e, value);
}
