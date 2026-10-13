typedef struct { int x0; int x4; int x8; int xC; char *x10; int *x14; } SAF48;
int func_002FAF48(SAF48 *s)
{
    int *p = (int *)(s->x10 + s->x4);
    int a, c;
    p[0] = 0;
    p[1] = 0;
    a = s->x4;
    c = s->xC;
    __asm__("" : "+r"(p) : "r"(a), "r"(c)); /* scheduling barrier (emits no code) */
    s->x14 = p;
    s->x4 = a + 8;
    s->xC = c + 8;
    return 0;
}
