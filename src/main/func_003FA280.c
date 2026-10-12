#include "types.h"
typedef struct { char p[0x90]; unsigned char b90; unsigned char b91; char p92[0xE]; } Sl3FA280;
typedef struct { Sl3FA280 s[8]; Sl3FA280* cur; char p504[8]; void* h; unsigned char b510, b511, b512; char p513[9]; float f51C; } M3FA280;
extern void func_003D08B0(void* h, void* c);
extern void func_003D0850(void* h, float a, float b);
extern char D_004BE220[];
void func_003FA280(M3FA280* m, unsigned char type, int flag)
{
    Sl3FA280* s = m->s;
    int i;
    for (i = 0; i < 8; i++, s++) {
        if (s->b91 && s->b90 == type) {
            if (s == m->cur) {
                if (flag) {
                    m->cur->b91 = 0;
                    m->cur = 0;
                    func_003D08B0(m->h, D_004BE220);
                    func_003D0850(m->h, 1.0f, 0.0f);
                    m->b512 = 0;
                    m->b511 = 0;
                    m->b510 = 0;
                } else {
                    m->b511 = 0;
                    m->b510 = 0;
                    m->b512 = 1;
                    func_003D0850(m->h, 0.0f, m->f51C);
                }
            } else s->b91 = 0;
        }
    }
}
