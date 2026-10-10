#include "types.h"
typedef struct { char unused; } Alloc003491C0; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } Str003491C0;
extern int strlen(const char* s);
extern void String_Reserve(Str003491C0* str, int n);
extern void String_Replace(Str003491C0* str, int pos, int count, const char* first, const char* last, Alloc003491C0 alloc);
/* Construct a string from a C string. */
Str003491C0* func_003491C0(Str003491C0* str, const char* s)
{
    Alloc003491C0 alloc;
    int n;
    str->w0 = 0;
    str->w4 = 0;
    str->w8 = 0;
    n = strlen(s);
    String_Reserve(str, n);
    String_Replace(str, 0, 0, s, s + n, alloc);
    return str;
}
