#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

extern void func_0010D170(int sema); /* syscall 0x41: DeleteSema */
extern int D_0048B238; /* initialised flag */
extern int D_004FBB80; /* semaphore id */

/* Shutdown: if initialised, clears the flag and deletes the semaphore (if valid); returns 1, else 0. */
int func_0026A568(void)
{
    if (D_0048B238 == 0) return 0;
    D_0048B238 = 0;
    if (D_004FBB80 >= 0) func_0010D170(D_004FBB80);
    return 1;
}
