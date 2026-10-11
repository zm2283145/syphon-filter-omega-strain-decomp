extern int D_0051F0D0;
extern char D_0048C440;
extern void func_002DB320(unsigned int, int);
void func_002DB388(unsigned int a)
{
    int i;
    if (a >= 4) return;
    if (D_0051F0D0)
        for (i = 0; i < 0x100; i++) func_002DB320(a, i);
    D_0048C440 = 0;
}