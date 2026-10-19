extern int D_0048B378;
extern int DIntr(void);
extern void EIntr(void);
extern int DeleteSema(int);

int func_0027D350(void)
{
    int s = DIntr();
    int sem = D_0048B378;
    D_0048B378 = -1;
    if (s) EIntr();
    if (sem >= 0) DeleteSema(sem);
    return 0;
}