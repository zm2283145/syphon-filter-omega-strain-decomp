#include "types.h"
typedef struct { char unused; } Alloc0043CB90; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } Str0043CB90;
extern int strlen(const char* s);
extern void String_Reserve(Str0043CB90* str, int n);
extern void String_Replace(Str0043CB90* str, int pos, int count, const char* first, const char* last, Alloc0043CB90 alloc);
/* Construct a string from a C string. */
Str0043CB90* func_0043CB90(Str0043CB90* str, const char* s)
{
    Alloc0043CB90 alloc;
    int n;
    str->w0 = 0;
    str->w4 = 0;
    str->w8 = 0;
    n = strlen(s);
    String_Reserve(str, n);
    String_Replace(str, 0, 0, s, s + n, alloc);
    return str;
}
