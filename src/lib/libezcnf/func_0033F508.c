extern int D_004928E8;
extern int D_004928EC;
extern char D_004B9D00[];
extern char D_00533040[];
extern char D_004B9D10[], D_004B9D18[], D_004B9D28[], D_004B9D40[];
extern int func_0010F388(const char *, ...);
extern int func_00114F20(char *);
extern int func_00110358(char *, int, int);
int func_0033F508(void)
{
    int r, i;
    if ((D_004928E8 = func_00114F20(D_004B9D00)) < 0) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388(D_004B9D28, D_004B9D00);
    }
    for (;;) {
        r = func_00110358(D_00533040, 0x75499128, 0);
        i = 0x10000;
        if (r < 0) {
            func_0010F388(D_004B9D10, D_004B9D18);
            func_0010F388(D_004B9D40);
        }
        if (*(int *)(D_00533040 + 0x24)) break;
        while (--i != -1)
            ;
    }
    D_004928EC = 1;
    return r;
}
