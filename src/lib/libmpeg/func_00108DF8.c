typedef struct { char pad[0xF4]; int xF4; int xF8; int xFC; } Mpeg8DF8;
typedef struct { int x0; int x4; int x8; int xC; int x10; } Pic8DF8;
extern char D_00498610[];
extern int sprintf(char *, const char *, ...);
extern void func_0010BD90(Mpeg8DF8 *, char *);
int func_00108DF8(Mpeg8DF8 *m, Pic8DF8 *p)
{
    char buf[256];
    int ok;
    if (m->xF8) ok = m->xF4 >= p->x4 && m->xF8 >= p->x8;
    else ok = m->xFC >= p->xC * p->x10;
    if (!ok) {
        sprintf(buf, D_00498610, p->x4, p->x8);
        func_0010BD90(m, buf);
    }
    return ok;
}
