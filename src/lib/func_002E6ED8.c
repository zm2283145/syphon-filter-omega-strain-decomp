extern void (*D_0058DF84)(char *, int);
extern void func_002DD440(char *, int *);
int func_002E6ED8(int a, int b, int c, int *k)
{
    char buf[16];
    if (k == 0) return -1;
    {
        void (**pf)(char *, int) = &D_0058DF84;
        if (*pf != 0) {
            func_002DD440(buf, k + 1);
            (*pf)(buf, k[0]);
        }
    }
    return 8;
}