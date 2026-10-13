extern int D_0048C450;
extern int *D_0051F0D0;
int func_002DB188(int *out, unsigned int a, unsigned int i)
{
    if (out == 0) return 0x17;
    *out = 0;
    if (i >= 0x100) return 0x17;
    if (a >= 4) return 0x17;
    if (a != D_0048C450) return 0;
    if (D_0051F0D0 != 0) {
        *out = D_0051F0D0[i];
        return 0;
    }
    return 0x15;
}
