#include "types.h"

/* Fatal path: reset the IOP, wait until it is back, then hang. */
extern int D_004934C8;
extern void WaitSema(void);
extern void func_0010D0D0(int a);
extern int func_00113D88(const char* path, int mode, int a2, int a3, int t0, int t1);
extern int func_00119CD8(int* status);

void func_003A6460(void)
{
    int status;
    WaitSema();
    func_0010D0D0(D_004934C8);
    while (func_00113D88("dev9x:", 0x4402, 0, 0, 0, 0) < 0)
        ;
    do {
        while (!func_00119CD8(&status))
            ;
    } while (status != 0);
    for (;;)
        ;
}