#include "types.h"

/* compiler: ee-gcc -O2 (check.py --gcc) */

extern int sceInsockGetpeername(int a0, int a1, int a2);

/* Forwards its arguments to sceInsockGetpeername. */
void sceNetGlueGetpeername(int a0, int a1, int a2)
{
    sceInsockGetpeername(a0, a1, a2);
}
