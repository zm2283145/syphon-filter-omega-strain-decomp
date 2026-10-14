#include "types.h"

/* Matches with EE-GCC 2.95 -O2 (check.py --gcc), not Metrowerks. */

extern int func_00357370(void* self, unsigned int* out);

/* Looks a value up; returns 0xFFFFFFFF when not found. */
unsigned int func_00357340(void* self)
{
    unsigned int value;
    if (!func_00357370(self, &value)) {
        return 0xFFFFFFFF;
    }
    return value;
}
