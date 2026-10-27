#include "types.h"

typedef struct { char tag; } Alloc;
typedef struct { char* begin; char* end; char* cap; } String;

extern int strlen(const char* s); /* strlen */
extern void std_basic_string_char_char_traits_char_reserve(String* self, int n);
extern void std_basic_string_char_char_traits_char_do_replace(String* self, char* at, int unused, const char* first, const char* last, Alloc alloc);

/* Constructs a string from a C string; returns self. */
String* func_002AA180(String* self, const char* s)
{
    int len;
    Alloc alloc;
    self->begin = 0;
    self->end = 0;
    self->cap = 0;
    len = strlen(s);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, s, s + len, alloc);
    return self;
}
