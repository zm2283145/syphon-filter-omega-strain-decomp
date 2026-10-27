#include "types.h"

typedef union SsoHeader {
    unsigned char raw;
    struct { unsigned char isLong : 1; unsigned char len : 7; } bits;
} SsoHeader;

extern SsoHeader* details_compressed_pair_imp_rep_s_2_first_void(void* self);

/* Returns the short-string length stored in the SSO header byte. */
unsigned char std_basic_string_char_char_traits_char_short_size(void* self)
{
    return details_compressed_pair_imp_rep_s_2_first_void(self)->bits.len;
}
