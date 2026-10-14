#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

extern void func_00357150(unsigned int value);

/* Packs (prefix, value) with a prefix-length-dependent mask and passes it to func_00357150. */
void func_003575C8(unsigned int prefix, unsigned int value)
{
    if (prefix < 0x80)
        prefix = (prefix << 24) | (value & 0xFFFFFF);
    else if (prefix <= 0xFFFF)
        prefix = (prefix << 16) | (value & 0xFFFF);
    else if (prefix <= 0xFFFFFF)
        prefix = (prefix << 8) | (value & 0xFF);
    else
        prefix = prefix | value;
    func_00357150(prefix);
}
