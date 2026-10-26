#include "types.h"

extern void sceInsockAbortGethostbyname(int value);
extern void sceInsockAbortGethostbyaddr(int first, int second, int third);

/* Invoke the zero-argument sound setup path. */
int sceNetGlueAbortResolver(void)
{
    sceInsockAbortGethostbyname(0);
    sceInsockAbortGethostbyaddr(0, 0, 0);
    return 0;
}
