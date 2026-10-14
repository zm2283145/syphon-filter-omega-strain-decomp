#include "types.h"
int Net_TranslateSendFlags(signed char flags, unsigned char* out) {
    if (out == 0) return 0x17;
    *out = 0;
    if (flags & 0x10) *out = 2;
    if (flags & 0x40) *out |= 4;
    if (flags & 0x80) *out |= 1;
    return 0;
}