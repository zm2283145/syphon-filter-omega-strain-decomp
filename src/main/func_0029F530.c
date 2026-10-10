#include "types.h"
typedef struct { char unused; } Alloc0029F530; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } Str0029F530;
extern int strlen(const char* s);
extern void String_Reserve(Str0029F530* str, int n);
extern void String_Replace(Str0029F530* str, int pos, int count, const char* first, const char* last, Alloc0029F530 alloc);
/* Construct a string from a C string. */
Str0029F530* func_0029F530(Str0029F530* str, const char* s)
{
    Alloc0029F530 alloc;
    int n;
    str->w0 = 0;
    str->w4 = 0;
    str->w8 = 0;
    n = strlen(s);
    String_Reserve(str, n);
    String_Replace(str, 0, 0, s, s + n, alloc);
    return str;
}
