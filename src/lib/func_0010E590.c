typedef struct { int x0; int x4; int x8; char *xC; } SubE590;
typedef struct { int fd; volatile int x4; volatile unsigned int x8; volatile int xC; char *x10; unsigned char *x14; SubE590 *x18; } CtxE590;
extern char D_00498928[];
extern char D_00498950[];
extern char D_00498968[];
extern char D_00498980[];
extern int func_0010F350(const char *, ...);
extern int func_0010E3D0(int, void *, unsigned short);
extern int func_0010E408(int, void *, unsigned short);
extern void func_0010E510(SubE590 *);
void func_0010E590(int cmd, int n, CtxE590 *c)
{
    int r;
    switch (cmd) {
    case 1:
    case 2:
        if (n != 0) {
            if (c->x8 + n > 0x140)
                func_0010F350(D_00498928);
            {
                unsigned int off = c->x8;
                n = func_0010E3D0(c->fd, c->x14 + off, n);
            }
            if (n < 0)
                func_0010F350(D_00498950);
            c->x8 += n;
        } else {
            unsigned short *h = (unsigned short *)c->x14;
            for (n = 12; n < *h; n++) {
                *c->x18->xC = c->x14[n];
                func_0010E510(c->x18);
            }
            c->x8 = 0;
        }
        break;
    case 3:
        r = func_0010E408(c->fd, c->x10, c->x4);
        if (r < 0) {
            func_0010F350(D_00498968, r);
            c->xC = 0;
        } else {
            c->x10 += r;
            c->x4 -= r;
        }
        break;
    case 4:
        if (c->x4)
            func_0010F350(D_00498980, c->x4);
        c->xC = 0;
        break;
    }
}






