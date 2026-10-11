typedef struct { int x0; unsigned short x4, x6, x8, xA, xC; } N2DB470;
extern signed char D_0058C178[];
extern int func_002DD9B0(unsigned char **, unsigned int);
void func_002DB470(N2DB470 *n)
{
    int i;
    unsigned char *e;
    if (n == 0) return;
    if (n->x6 < 0x1000) {
        for (i = 0; i < n->x8; i++)
            if (D_0058C178[i + n->x6] == 0) D_0058C178[i + n->x6] = 1;
    }
    if (n->xA < 0x800) {
        for (i = 0; i < n->xC; i++) {
            func_002DD9B0(&e, i + n->xA);
            if (e) *e = 1;
        }
    }
}
