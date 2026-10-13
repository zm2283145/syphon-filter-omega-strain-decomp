#include "types.h"
typedef struct { union { struct { unsigned int word; unsigned int length; char* data; } l; struct { unsigned char isLong : 1; unsigned char len : 7; } s; } u; } Str_40FE50;
extern int func_003CBF70(void* a, Str_40FE50* s, int c);
extern char* String_CStr(void* a);
static inline unsigned int Len_40FE50(Str_40FE50* s) { return (s->u.l.word & 1) ? s->u.l.length : (unsigned char)s->u.s.len; }
#pragma opt_rotateloops off
char* func_0040FE50(void* a, Str_40FE50* s)
{
    char* p = 0;
    int r = func_003CBF70(a, s, 0);
    if (r > -1) {
        p = String_CStr(a) + r + Len_40FE50(s);
        while (*p == ' ' || *p == '\t') p++;
    }
    return p;
}
#pragma opt_rotateloops reset