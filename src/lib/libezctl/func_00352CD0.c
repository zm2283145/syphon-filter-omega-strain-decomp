extern int D_00492C30;
extern int D_00492C34;
extern char D_004BADA8[];
extern char D_00533280[];
extern char D_004BADB8[], D_004BADC0[], D_004BADD0[], D_004BADE8[];
extern int func_0010F388(const char *, ...);
extern int func_00114F20(char *);
extern int func_00110358(char *, int, int);
int func_00352CD0(void)
{
    int r, i;
    if ((D_00492C30 = func_00114F20(D_004BADA8)) < 0) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BADD0, D_004BADA8);
    }
    for (;;) {
        r = func_00110358(D_00533280, 0x75488909, 0);
        i = 0x10000;
        if (r < 0) {
            func_0010F388(D_004BADB8, D_004BADC0);
            func_0010F388(D_004BADE8);
        }
        if (*(int *)(D_00533280 + 0x24)) break;
        while (--i != -1)
            ;
    }
    D_00492C34 = 1;
    return r;
}
