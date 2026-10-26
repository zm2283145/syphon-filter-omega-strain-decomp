extern char D_00488A50[];
const unsigned int D_00487900[32] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
extern int D_004878A8;
extern int _sceCd_ncmd_prechk(int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int SignalSema(int);

int sceCdNcmdDiskReady(void)
{
    int r;
    if (!_sceCd_ncmd_prechk(2)) return 0;
    if (sceSifCallRpc(D_00488A50, 0xE, 0, 0, 0, ((int*)D_00487900), 4, 0, 0) < 0) {
        SignalSema(D_004878A8);
        return 0;
    }
    r = *(int *)((unsigned int)((int*)D_00487900) | 0x20000000);
    SignalSema(D_004878A8);
    return r;
}