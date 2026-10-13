typedef struct N2F7DB8 { int a; int b; int c; int d; int e; int f; int g; } N2F7DB8;
extern void func_002FB2D8(void *, int);
/* Allocates and clears a 0x1C-byte node. */
N2F7DB8 *func_002F7DB8(void)
{
    N2F7DB8 *p = 0;
    func_002FB2D8(&p, 0x1C);
    if (p) {
        p->a = 0;
        p->b = 0;
        p->d = 0;
        p->e = 0;
        p->f = 0;
        p->g = 0;
        p->c = 0;
    }
    return p;
}
