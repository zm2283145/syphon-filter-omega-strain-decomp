#include "types.h"
typedef struct { char p[0x90]; unsigned char lvl; } L3FA380;
typedef struct { char p[0x500]; L3FA380* l; unsigned char b504; char p505[7]; void* h; unsigned char b510, b511, b512; char p513[0x9]; float f51C; } S3FA380;
extern void func_003D0850(void* h, float a, float b);
void func_003FA380(S3FA380* s, unsigned char v)
{
    if (s->l && s->l->lvl < v) {
        s->b511 = 0;
s->b510 = 0;
s->b512 = 1;
        func_003D0850(s->h, 0.0f, s->f51C);
    }
    s->b504 = v;
}
