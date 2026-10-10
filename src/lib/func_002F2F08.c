#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { void* ptr; int pad; } Arg;
extern void func_002FB3C0(Arg* arg);

/* Passes a non-NULL pointer to func_002FB3C0 via a stack block. */
void func_002F2F08(void* ptr)
{
    Arg arg;
    arg.ptr = ptr;
    if (ptr != 0)
        func_002FB3C0(&arg);
}
