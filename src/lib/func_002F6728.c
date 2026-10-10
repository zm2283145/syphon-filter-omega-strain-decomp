#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { void* ptr; int pad; } Arg;
extern int func_002FB3C0(Arg* arg);

/* Returns 2 for NULL, else whether func_002FB3C0 succeeded (non-zero). */
int func_002F6728(void* ptr)
{
    Arg arg;
    int r = 2;
    arg.ptr = ptr;
    if (ptr != 0)
        r = func_002FB3C0(&arg) != 0;
    return r;
}
