extern int D_0048C458;
extern unsigned int D_0058DF78;
extern int D_00590318[];
extern int D_00598358[];
extern int D_00598398[];
int func_002ED448(int *out, int a, int b, int c)
{
    int i;
    if (D_0048C458 == 0) return 0x11;
    if (D_0058DF78 >= 0x10) return 0x16;
    if (out == 0) return 0x17;
    *out = -1;
    i = D_0058DF78;
    *out = i;
    D_00598358[i] = a;
D_00598398[i] = b;
D_00590318[i] = c;
    D_0058DF78++;
    return 0;
}