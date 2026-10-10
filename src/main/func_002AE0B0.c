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

typedef struct { char unused; } Allocator; /* empty allocator object passed by value */
extern unsigned int strlen(const char* s);
extern void String_Reserve(SsoString* str, unsigned int n);
extern void* String_Replace(SsoString* str, int pos, int count, const char* first, const char* last, Allocator alloc);

/* Constructs the string from a C string. */
SsoString* func_002AE0B0(SsoString* str, const char* text)
{
    Allocator alloc;
    unsigned int len;
    str->h.flags = 0;
    str->longLen = 0;
    str->longData = 0;
    len = strlen(text);
    String_Reserve(str, len);
    String_Replace(str, 0, 0, text, text + len, alloc);
    return str;
}
