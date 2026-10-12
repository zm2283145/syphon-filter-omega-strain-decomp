typedef struct { float f0; int x4; void *buf; } Obj7680;
extern void *(*D_004E1D34)(int n, int size);
extern void *(*D_004E1D3C)(void *d, int c, int n);
int func_00317680(Obj7680 **out)
{
    Obj7680 *o;
    void *b;
    if (out == 0) return 1;
    *out = 0;
    o = D_004E1D34(1, 0xC);
    if (o == 0) return 1;
    *out = o;
    b = D_004E1D34(0xD, 4);
    o->buf = b;
    if (b == 0) return 1;
    o->x4 = 0;
    o->f0 = 1000.0f;
    D_004E1D3C(b, 0, 0x34);
    return 0;
}
