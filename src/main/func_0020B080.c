#include "types.h"

/* Built at a lower optimization level (unscheduled loop). */
#pragma optimization_level 1

typedef struct { char data[0x24]; } Elem0C;
extern void func_0020B0F0(Elem0C* e, void* value);

/* Calls func_0020B0F0(e, value) on n consecutive 12-byte elements. */
void func_0020B080(Elem0C* e, int n, void* value)
{
    for (; n != 0; e++, n--)
        func_0020B0F0(e, value);
}
