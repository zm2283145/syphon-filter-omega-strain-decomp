extern signed char D_0058C178[];
extern void func_002DEA68(int);
int func_002DF8E8(void)
{
    int i;
    for (i = 0; i < 0x1000; i++) {
        if (D_0058C178[i] == 2) func_002DEA68(i);
        D_0058C178[i] = 0;
    }
    return 0;
}