#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

extern void sceInsockAbortGethostbyname(int arg);

/* Calls sceInsockAbortGethostbyname(0). */
void sceInsockAbortGethostbyaddr(void)
{
    sceInsockAbortGethostbyname(0);
}
