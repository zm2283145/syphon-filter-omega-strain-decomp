#include "types.h"
typedef struct { char p[0x91]; unsigned char b91; char p92[0xE]; } Sl3FA1E0;
typedef struct { Sl3FA1E0 s[8]; Sl3FA1E0* cur; char p504[8]; void* h; unsigned char b510, b511, b512; } M3FA1E0;
extern void func_003D08B0(void* h, void* c);
extern void func_003D0850(void* h, float a, float b);
extern char D_004BE220[];
void func_003FA1E0(M3FA1E0* m)
{
    Sl3FA1E0* s = m->s;
    int i;
    for (i = 0; i < 8; i++, s++) {
        if (s == m->cur) {
            m->cur->b91 = 0;
            m->cur = 0;
            func_003D08B0(m->h, D_004BE220);
            func_003D0850(m->h, 1.0f, 0.0f);
            m->b512 = 0;
            m->b511 = 0;
            m->b510 = 0;
        } else s->b91 = 0;
    }
}
