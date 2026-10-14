extern int D_0051FEE8[];
extern void func_002DD328(int *);
int func_002E5158(void)
{
    unsigned int i;
    int *p = D_0051FEE8;
    for (i = 0; i < 0x100; i++, p++) {
        if (*p) {
            func_002DD328(p);
            *p = 0;
        }
    }
    return 0;
}