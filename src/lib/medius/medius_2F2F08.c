#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { void* ptr; int pad; } Arg;
extern void rt_memory_free(Arg* arg);

/* Passes a non-NULL pointer to rt_memory_free via a stack block. */
void DestroyPlayerRef(void* ptr)
{
    Arg arg;
    arg.ptr = ptr;
    if (ptr != 0)
        rt_memory_free(&arg);
}
