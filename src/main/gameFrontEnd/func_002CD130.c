#include "types.h"

/* String object: three words, zeroed before construction. */
typedef struct StrObj {
    int w0;
    int w1;
    int w2;
} StrObj;

extern int strlen(const char* s); /* strlen */
extern void std_basic_string_char_char_traits_char_reserve(StrObj* str, int capacity);
extern void std_basic_string_char_char_traits_char_do_replace(StrObj* str, int pos, int count, const char* first, const char* last, char alloc);

/* String constructor from a C string. */
StrObj* func_002CD130(StrObj* self, const char* cstr) {
    volatile char alloc[4];
    int len;
    self->w0 = 0;
    self->w1 = 0;
    self->w2 = 0;
    len = strlen(cstr);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, cstr, cstr + len, alloc[0]);
    return self;
}
