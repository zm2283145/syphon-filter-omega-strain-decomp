#include "types.h"

extern int func_002E9320(char* buffer);
extern int func_002EC168(int first, int second);
extern unsigned char D_005724B0;

/* Read the library version and update connection state when setup returns zero. */
void func_0042AFC0(void)
{
    char version[16];
    func_002E9320(version);
    if (!func_002EC168(0x6000, 0x6000))
        D_005724B0 = 1;
}
