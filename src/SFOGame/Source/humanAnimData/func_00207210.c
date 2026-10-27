#include "types.h"
extern int std_basic_string_char_char_traits_char_is_long(void* obj);
extern int* std_basic_string_char_char_traits_char_long_size(void* obj);
extern unsigned char std_basic_string_char_char_traits_char_short_size(void* obj);
/* Return the stored value if present, else a default byte value. */
int std_basic_string_char_char_traits_char_size(void* obj)
{
    if (std_basic_string_char_char_traits_char_is_long(obj)) {
        return *std_basic_string_char_char_traits_char_long_size(obj);
    }
    return std_basic_string_char_char_traits_char_short_size(obj);
}
