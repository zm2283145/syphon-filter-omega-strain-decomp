#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern int std_basic_string_char_char_traits_char_size(void* obj);
extern void std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR(void* obj, int value, int zero, int arg);

/* Forwards std_basic_string_char_char_traits_char_size's result to std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR. */
void std_basic_string_char_char_traits_char_append_basicstringR(void* obj, int arg) {
    std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR(obj, std_basic_string_char_char_traits_char_size(obj), 0, arg);
}

#pragma pop
