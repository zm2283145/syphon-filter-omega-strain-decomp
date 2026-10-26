#include "types.h"

/* Matches with EE-GCC 2.95 -O2 (check.py --gcc), not Metrowerks. */

extern int sceInsockInetAton(void* self, unsigned int* out);

/* Looks a value up; returns 0xFFFFFFFF when not found. */
unsigned int sceInsockInetAddr(void* self)
{
    unsigned int value;
    if (!sceInsockInetAton(self, &value)) {
        return 0xFFFFFFFF;
    }
    return value;
}
