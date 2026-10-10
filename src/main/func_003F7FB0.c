#include "types.h"
extern int D_0055C750;
/* Set a global setting if it is in range 1..6. */
void func_003F7FB0(int value)
{
    if (value > 0 && value < 7) {
        D_0055C750 = value;
    }
}
