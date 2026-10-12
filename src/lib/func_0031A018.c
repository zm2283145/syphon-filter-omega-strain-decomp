typedef struct { int n; int x4; void *buf; } ObjA018;
extern void *(*D_004E1D34)(int n, int size);
int func_0031A018(int n, ObjA018 **out)
{
    ObjA018 *o = D_004E1D34(1, 0xC);
    if (o == 0) return 1;
    *out = o;
    o->n = n;
    o->x4 = 0;
    o->buf = D_004E1D34(n, 4);
    return 0;
}
