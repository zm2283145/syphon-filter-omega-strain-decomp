extern int D_0048B378;
extern int func_001161A0(void);
extern void func_001161F8(void);
extern int DeleteSema(int);

int func_0027D350(void)
{
    int s = func_001161A0();
    int sem = D_0048B378;
    D_0048B378 = -1;
    if (s) func_001161F8();
    if (sem >= 0) DeleteSema(sem);
    return 0;
}