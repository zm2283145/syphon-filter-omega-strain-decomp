#include "types.h"
typedef struct { char pad[0x98]; void* a98; void* a9C; } S294B20;
extern void String_Copy(char* dst, char* src);
extern char* strchr(char* s, int c);
extern void func_0041BEB0(void* w, char* text, int f);
#pragma bool off
static inline int IsZero294B20(int c) { return (c != 0) ^ 1; }
static inline int IsSp294B20(int c) { return (char)c == ' '; }
#pragma opt_rotateloops off
void func_00294B20(S294B20* s, char* str)
{
    char* p;
    char buf[0x70];
    if (!str)
        return;
    String_Copy(buf, str);
    p = strchr(buf, ':');
    if (p) {
        *p = 0;
        func_0041BEB0(s->a98, buf, 0);
        p++;
        while (!IsZero294B20(*p) && IsSp294B20(*p))
            p++;
        if (p)
            func_0041BEB0(s->a9C, p, 0);
    } else {
        func_0041BEB0(s->a98, str, 0);
    }
}
#pragma opt_rotateloops reset
#pragma bool reset