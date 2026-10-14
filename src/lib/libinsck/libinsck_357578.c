#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

extern int func_00357150(void);

/* Reads a value and masks it to 24, 16 or 8 bits depending on its top bits. */
int func_00357578(void)
{
    unsigned int v = func_00357150();
    if ((v & 0x80000000) == 0)
        return v & 0xFFFFFF;
    if ((v & 0xC0000000) == 0x80000000)
        return v & 0xFFFF;
    return v & 0xFF;
}
