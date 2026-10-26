#include "types.h"

typedef struct { int words[4]; } Value16;
extern void cString_ctor_cStringR(Value16* dst, void* src);
extern void std_basic_string_char_char_traits_char_append_basicstringR(Value16* v, void* arg);
extern void String_Dtor_138350(Value16* v, int flags);

/* Builds a temporary from src, applies arg to it, copies it into dst, then destroys it; returns 0. */
int opAdd_cStringR_cStringR(void* dst, void* src, void* arg)
{
    Value16 tmp;
    cString_ctor_cStringR(&tmp, src);
    std_basic_string_char_char_traits_char_append_basicstringR(&tmp, arg);
    cString_ctor_cStringR(dst, &tmp);
    String_Dtor_138350(&tmp, -1);
    return 0;
}
