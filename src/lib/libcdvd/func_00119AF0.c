extern char D_00489400[];
extern int D_00488A80[];
extern int D_004878AC;
extern int func_00119010(int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int SignalSema(int);

int func_00119AF0(void)
{
    int r;
    if (!func_00119010(1)) return 0;
    if (sceSifCallRpc(D_00489400, 3, 0, 0, 0, D_00488A80, 4, 0, 0) < 0) {
        SignalSema(D_004878AC);
        return 0;
    }
    r = *(int *)((unsigned int)D_00488A80 | 0x20000000);
    SignalSema(D_004878AC);
    return r;
}