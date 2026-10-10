#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { char pad[0x2C]; short flag; char pad2E[0x38 - 0x2E]; float value; } Inner;
typedef struct { char pad[0x48]; Inner* inner; } Outer;

/* Sets inner->value and marks it dirty. */
void func_00318378(Outer* o, float value)
{
    Inner* in = o->inner;
    in->flag = 1;
    in->value = value;
}
