#include "types.h"

/* Short-string-optimized string: bit 0 of the first byte marks heap storage. */
typedef struct SsoString {
    union {
        struct { unsigned char isLong : 1; unsigned char shortLen : 7; } s;
        int flags;
    } h;
    int longLen;
    char* longData;
} SsoString;

extern int strlen(const char* s); /* strlen */
extern int String_Compare(SsoString* a, int pos, int len, const char* data, int n);

/* Compares the string with a C string (compare(0, size(), text, strlen(text))). */
int String_CompareCStr(SsoString* self, const char* text)
{
    int n = strlen(text);
    int len;
    if (!(self->h.flags & 1))
        len = (unsigned char)self->h.s.shortLen;
    else
        len = self->longLen;
    return String_Compare(self, 0, len, text, n);
}
