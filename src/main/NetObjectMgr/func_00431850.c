#include "types.h"

extern volatile unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern unsigned char D_00572400;

/* Set the network state flag while holding the shared operation guard. */
int func_00431850(void)
{
    if (D_005723C8 == 0)
        D_005723C8 = 1;
    if (D_005721D0 != 0)
        D_00572400 = 1;
    D_005723C8 = 0;
    return 8;
}
