extern int D_0048C4B0;
extern long func_00302B88(int, int *);
int func_002DD1F8(int a, int *out)
{
    int v = -2;
    if (a != 0) return 0x17;
    if (out == 0) return 0x17;
    *out = 0x100;
    if (func_00302B88(D_0048C4B0, &v) != 0) return 0x25;
    if (v == -2) return 1;
    *out = v;
    return 0;
}

