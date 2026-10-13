extern char D_00489400[];
extern int D_00488A80[];
extern int D_004878AC;
extern int func_00119010(int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int SignalSema(int);
#define UNCACHED(p) (*(int *)((unsigned int)(p) | 0x20000000))
extern int D_00488EC0[];
int D_00489428 = 34;
int D_0048942C = 4;
int D_00489430 = 4;
extern void func_0010FB10(void *, int);

int func_00119D90(int x)
{
    int *p = D_00488EC0;
    int r;
    if (!func_00119010(0x22)) return 0;
    p[0] = x;
    func_0010FB10(p, 4);
    if (sceSifCallRpc(D_00489400, D_00489428, 0, p, D_0048942C, D_00488A80, D_00489430, 0, 0) < 0) {
        SignalSema(D_004878AC);
        return 0;
    }
    r = UNCACHED(D_00488A80);
    SignalSema(D_004878AC);
    return r;
}