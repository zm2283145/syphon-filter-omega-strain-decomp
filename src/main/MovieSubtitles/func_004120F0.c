#include "types.h"

typedef struct { char pad[0x13C]; int value; } Entry140; /* size 0x140 */
typedef struct { char pad[0x60]; Entry140* entries; char pad64[4]; int current; } Table;

/* Returns the value of the current 0x140-byte entry. */
int func_004120F0(Table* t)
{
    return t->entries[t->current].value;
}
