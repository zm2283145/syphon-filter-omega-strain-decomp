typedef struct { unsigned char bits[0x24]; int f24; int f28; } Set;
typedef struct { char p[0x400]; int f400; char p2[0x40]; int f444; } Ctx;
extern int func_002E51B8(unsigned int, Ctx **);
extern int func_002DB188(int *, unsigned int, int);
extern void func_002DDDD0(Set *, int);
void func_002DDE30(Set *s, unsigned int a, int (*cb)(int, int))
{
    Ctx *ctx[1];
    int x[1];
    int i;
    ctx[0] = 0;
    if (a >= 4) return;
    if (cb == 0) return;
    if (s == 0) return;
    s->f24 = 0x100;
    s->f28 = -1;
    if (func_002E51B8(a, ctx)) return;
    if (ctx[0] == 0) return;
    s->f24 = ctx[0]->f444;
    {
        unsigned char *p = &s->bits[0x20];
        int n = 0x20;
        do { n--; *p-- = 0; } while (n >= 0);
    }
    for (i = 0; i < ctx[0]->f444; i++) {
        x[0] = 0;
        func_002DB188(x, a, i);
        if (x[0] && i != ctx[0]->f400 && cb(i, ctx[0]->f400)) func_002DDDD0(s, i);
    }
}

