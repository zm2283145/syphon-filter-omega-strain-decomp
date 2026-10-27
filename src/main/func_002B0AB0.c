#include "types.h"
typedef struct { char unused; } Alloc002B0AB0; /* empty allocator object passed by value */
typedef struct { unsigned long long isLong : 1; unsigned long long size : 7; } Short002B0AB0;
typedef union { unsigned int flags; Short002B0AB0 s; struct { int f0; int length; char* data; } l; } Str002B0AB0;
extern void std_basic_string_char_char_traits_char_do_replace(Str002B0AB0* str, int pos, int count, int a, int b, Alloc002B0AB0 alloc);
/* Forward (0, size) of the string to std_basic_string_char_char_traits_char_do_replace. */
void func_002B0AB0(Str002B0AB0* s, int a, int b)
{
    Alloc002B0AB0 alloc;
    int len;
    if (s->flags & 1) {
        len = s->l.length;
    } else {
        len = (unsigned char)s->s.size;
    }
    std_basic_string_char_char_traits_char_do_replace(s, 0, len, a, b, alloc);
}