#include "types.h"

typedef union SsoHeader {
    unsigned char raw;
    struct { unsigned char isLong : 1; unsigned char len : 7; } bits;
} SsoHeader;

extern SsoHeader* func_002071B0(void* self);

/* Returns the short-string length stored in the SSO header byte. */
unsigned char func_00207280(void* self)
{
    return func_002071B0(self)->bits.len;
}
