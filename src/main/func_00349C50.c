#include "types.h"

typedef struct { char tag; } Alloc;
typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; } SsoString;

extern void std_basic_string_char_char_traits_char_do_replace(SsoString* self, int pos, int n, const char* first, const char* last, Alloc alloc);

/* Assigns [first, last) to the string by replacing its whole contents. */
void func_00349C50(SsoString* self, const char* first, const char* last)
{
    Alloc alloc;
    std_basic_string_char_char_traits_char_do_replace(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, first, last, alloc);
}
