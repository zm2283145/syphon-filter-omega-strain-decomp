#include "types.h"
typedef struct { char unused; } Alloc0041BCE0; /* empty allocator object passed by value */
typedef struct { unsigned long long isLong : 1; unsigned long long size : 7; } Short0041BCE0;
typedef union { unsigned int flags; Short0041BCE0 s; struct { int f0; int length; char* data; } l; } Str0041BCE0;
extern void String_Replace(Str0041BCE0* str, int pos, int count, int a, int b, Alloc0041BCE0 alloc);
/* Forward (0, size) of the string to String_Replace. */
void func_00428250(Str0041BCE0* s, int a, int b)
{
    Alloc0041BCE0 alloc;
    int len;
    if (s->flags & 1) {
        len = s->l.length;
    } else {
        len = (unsigned char)s->s.size;
    }
    String_Replace(s, 0, len, a, b, alloc);
}