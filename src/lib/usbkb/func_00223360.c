extern int D_0048AB18;
extern char D_004F5820[];
extern void WaitSema(int);
extern void SignalSema(int);
extern int func_00223410(void);
extern int sceSifCheckStatRpc(void *);
int func_00223360(int mode, int *out)
{
    if (D_0048AB18 == -1) return -1;
    switch (mode) {
    case 0:
        WaitSema(D_0048AB18);
        *out = func_00223410();
        SignalSema(D_0048AB18);
        return 0;
    case 1:
        if (sceSifCheckStatRpc(D_004F5820) == 0) {
            *out = func_00223410();
            return 0;
        }
        return 1;
    }
    return -11;
}