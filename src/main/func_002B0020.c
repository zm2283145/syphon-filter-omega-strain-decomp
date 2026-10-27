#include "types.h"

typedef struct { char unused; } Alloc;
typedef struct { int w0; int w1; int w2; } String;
extern int strlen(const char* s);
extern void std_basic_string_char_char_traits_char_reserve(String* str, int capacity);
extern void std_basic_string_char_char_traits_char_do_replace(String* str, int pos, int n, const char* first, const char* last, Alloc alloc);

/* String constructor from a C string. */
String* func_002B0020(String* self, const char* cstr)
{
    Alloc alloc;
    int len;
    self->w0 = 0;
    self->w1 = 0;
    self->w2 = 0;
    len = strlen(cstr);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, cstr, cstr + len, alloc);
    return self;
}
