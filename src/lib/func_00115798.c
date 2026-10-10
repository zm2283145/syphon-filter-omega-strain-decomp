#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

extern unsigned int func_0010D570(int reg);
extern void func_0010D5E0(void);
extern void func_00118310(int a, int b);

/* If status bit 0x40000 is set, acknowledges it and signals channels 1 and 0; returns whether it was set. */
int func_00115798(void)
{
    if ((func_0010D570(4) & 0x40000) == 0)
        return 0;
    func_0010D5E0();
    func_00118310(1, 1);
    func_00118310(0, 1);
    return 1;
}
