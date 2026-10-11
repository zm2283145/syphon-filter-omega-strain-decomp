typedef struct { int f0; int f4; int f8; int mode; int f10; int f14; int f18; int f1c; unsigned short s20; unsigned short buf[4]; char pad2[2]; int wr; int rd; int count; } E223F80;
typedef struct { int count; E223F80* tbl; int f8; int fc; int f10; } G223F80;
extern G223F80 D_004F5780;
int func_00223F80(int i, unsigned int mode)
{
    E223F80* e; int off;
    if (i >= D_004F5780.count) return -11;
    if (mode >= 2) return -12;
    off = i * sizeof(E223F80);
    e = (E223F80*)(off + (int)D_004F5780.tbl);
    if (mode != e->mode) {
        e->f14 = 0;
        e->wr = 0;
        e->rd = 0;
        D_004F5780.f10 = 0;
        e->s20 = 0;
    }
    e->mode = mode;
    return 0;
}