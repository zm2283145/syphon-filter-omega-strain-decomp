#include "types.h"
typedef union { __int128 q; char c[16]; } NA40;
extern void* memset(void* d, int c, unsigned int n);
extern char* strncpy(char* d, const char* s, unsigned int n);
extern unsigned int strlen(const char* s);
extern char Libc_Tolower(char c);
__int128 nGlobalization_MakeTag(const char* s)
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
        *p = Libc_Tolower(*p);
    return r.q;
}