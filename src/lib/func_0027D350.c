extern int D_0048B378;
extern int DIntr(void);
extern void EIntr(void);
extern int DeleteSema(int);

int sce_delete_sema(void)
{
    int s = DIntr();
    int sem = D_0048B378;
    D_0048B378 = -1;
    if (s) EIntr();
    if (sem >= 0) DeleteSema(sem);
    return 0;
}