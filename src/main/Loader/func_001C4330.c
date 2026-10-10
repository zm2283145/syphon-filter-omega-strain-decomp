#include "types.h"
typedef struct { char unused; } Alloc; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } String;
extern int strlen(const char* s);
extern String* String_Replace(String* str, int pos, int count, const char* first, const char* last, Alloc alloc);
/* Replaces count characters at pos with the C string s. */
String* func_001C4330(String* str, int pos, int count, const char* s)
{
    Alloc alloc;
    return String_Replace(str, pos, count, s, s + strlen(s), alloc);
}
