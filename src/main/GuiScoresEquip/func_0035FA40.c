#include "types.h"
typedef struct { char unused; } Alloc; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } String;
extern int strlen(const char* s);
extern void String_Reserve(String* str, int n);
extern void String_Replace(String* str, int pos, int count, const char* first, const char* last, Alloc alloc);
/* Construct a string from a C string. */
String* func_0035FA40(String* str, const char* s)
{
    Alloc alloc;
    int n;
    str->w0 = 0;
    str->w4 = 0;
    str->w8 = 0;
    n = strlen(s);
    String_Reserve(str, n);
    String_Replace(str, 0, 0, s, s + n, alloc);
    return str;
}
