#include "types.h"
typedef struct { unsigned long long isLong : 1; unsigned long long size : 7; } Short002987A0;
typedef union { unsigned int flags; Short002987A0 s; struct { int f0; int length; char* data; } l; } Str002987A0;
extern int strlen(const char* s);
extern void String_Compare(Str002987A0* str, int pos, int count, const char* s, int n);
/* Replace the whole string with the C string s. */
void func_002987A0(Str002987A0* str, const char* s)
{
    String_Compare(str, 0, (str->flags & 1) ? str->l.length : (unsigned char)str->s.size, s, strlen(s));
}
