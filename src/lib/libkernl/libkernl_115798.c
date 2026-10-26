#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

extern unsigned int sceSifGetReg(int reg);
extern void sceResetttyinit(void);
extern void sceSifExecNotifyHandler(int a, int b);

/* If status bit 0x40000 is set, acknowledges it and signals channels 1 and 0; returns whether it was set. */
int sceSifSyncIop(void)
{
    if ((sceSifGetReg(4) & 0x40000) == 0)
        return 0;
    sceResetttyinit();
    sceSifExecNotifyHandler(1, 1);
    sceSifExecNotifyHandler(0, 1);
    return 1;
}
