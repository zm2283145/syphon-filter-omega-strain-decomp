extern void *memset(void *, int, unsigned long);
typedef struct { int x0; char p4[0x14]; short x18; short p1a; int p1c; int x20, x24, x28, x2C, x30; short x34; short p36; int p38; int x3C, x40, x44, x48; } S2FD8F0;
int func_002FD8F0(S2FD8F0 *s)
{
    if (s == 0) return 2;
    memset(s, 0, 0x4C);
    s->x0 = 0;
    s->x18 = 0x275B;
    s->x20 = 0x3A98;
    s->x24 = 0x1E;
    s->x30 = 0;
    s->x34 = 0;
    s->x3C = 0;
    s->x40 = 0;
    s->x44 = 0;
    s->x2C = 0x8000;
    s->x28 = 0x8000;
    return 0;
}
