#include "types.h"
typedef struct { char p0[0x23D8]; int h[11]; } S4538D0;
extern void func_0044F6B0(int h);
extern void func_0044F810(void* p);
static inline void Release4538D0(int* h) { int t = *h; if (t != 0) func_0044F6B0(t); *h = 0; }
#pragma push
#pragma opt_common_subs off
void func_004538D0(S4538D0* s)
{
    char* b = (char*)s;
    Release4538D0(&s->h[0]); Release4538D0(&s->h[1]); Release4538D0(&s->h[2]); Release4538D0(&s->h[3]);
    Release4538D0(&s->h[4]); Release4538D0(&s->h[5]); Release4538D0(&s->h[6]); Release4538D0(&s->h[7]);
    Release4538D0(&s->h[8]); Release4538D0(&s->h[9]); Release4538D0(&s->h[10]);
    func_0044F810(b + 0x70);
    func_0044F810(b + 0xFC);
    func_0044F810(b + 0x118);
    func_0044F810(b + 0x8C);
    func_0044F810(b + 0xA8);
    func_0044F810(b + 0xC4);
    func_0044F810(b + 0xE0);
    func_0044F810(b + 0x134);
    func_0044F810(b + 0x150);
    func_0044F810(b);
}
#pragma pop
