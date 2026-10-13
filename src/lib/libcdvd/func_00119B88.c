extern char D_00489400[];
extern int D_00488A80[];
extern int D_004878AC;
extern int func_00119010(int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int SignalSema(int);

int func_00119B88(void)
{
    int r;
    if (!func_00119010(3)) return -1;
    if (sceSifCallRpc(D_00489400, 4, 0, 0, 0, D_00488A80, 4, 0, 0) < 0) {
        SignalSema(D_004878AC);
        return -1;
    }
    r = *(int *)((unsigned int)D_00488A80 | 0x20000000);
    SignalSema(D_004878AC);
    return r;
}