extern char D_00489400[];
extern int D_00488A80[];
extern int D_004878AC;
extern int func_00119010(int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int SignalSema(int);
#define UNCACHED(p) (*(int *)((unsigned int)(p) | 0x20000000))
int func_00119CD8(int *out)
{
    int r;
    if (!func_00119010(0x21)) return 0;
    if (sceSifCallRpc(D_00489400, 0x21, 0, 0, 0, D_00488A80, 8, 0, 0) < 0) {
        SignalSema(D_004878AC);
        return 0;
    }
    *out = UNCACHED(&D_00488A80[1]);
    r = UNCACHED(D_00488A80);
    SignalSema(D_004878AC);
    return r;
}