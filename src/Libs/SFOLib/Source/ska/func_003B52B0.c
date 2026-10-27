#include "types.h"

extern void std_basic_string_char_char_traits_char_substr(void* tmp);
extern void std_basic_string_char_char_traits_char_ctor_basicstringR(void* self, void* tmp);
extern void String_Dtor(void* tmp, int flag);

/* Builds a temporary object, applies it to self, then destroys it; returns 0. */
int cString_Substr(void* self) {
    char tmp[16];
    std_basic_string_char_char_traits_char_substr(tmp);
    std_basic_string_char_char_traits_char_ctor_basicstringR(self, tmp);
    String_Dtor(tmp, -1);
    return 0;
}
