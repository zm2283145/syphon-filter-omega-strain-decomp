typedef struct { int f0; int f4; int f8; int size; int h10; int p14; int h18; int p1C; int f20; int f24; } NetPool_F80;
extern int func_002FB4A8(int *h, int size, int align);
extern int func_002FB3C0(int *h);
int func_0034CF80(NetPool_F80 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    ret = 1;
    if (o->size + 0x40 > 0x2000) return ret;
    if (func_002FB4A8(&o->h10, 0x2040, 0x40) != 0) return 3;
    o->f20 = o->p14;
    if (func_002FB4A8(&o->h18, 0x2040, 0x40) != 0) {
        func_002FB3C0(&o->h10);
        return 3;
    }
    o->f24 = o->p1C;
    return 0;
}