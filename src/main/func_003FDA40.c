#include "types.h"
typedef union { __int128 q; char c[16]; } NA40;
extern void* memset(void* d, int c, unsigned int n);
extern char* strncpy(char* d, const char* s, unsigned int n);
extern unsigned int strlen(const char* s);
extern char String_ToLower(char c);
__int128 func_003FDA40(const char* s)
{
    NA40 r;
    char* p;
    int n;
    int i;
    memset(r.c, 0, 16);
    strncpy(r.c, s, 16);
    p = r.c;
    n = strlen(p);
    for (i = 0; i < n; i++, p++)
        *p = String_ToLower(*p);
    return r.q;
}