#include "types.h"

/* Send IOP command 0x37 when the sound IOP is up, else fall back. */
extern int D_0053DC00;
extern int func_00119C20(void);
extern void snd_SendIOPCommandNoWait(int cmd, int size, void* data, int a3, int t0);

int func_003A6F10(void)
{
    if (D_0053DC00 == 0)
        return func_00119C20();
    snd_SendIOPCommandNoWait(0x37, 0, 0, 0, 0);
    return 1;
}