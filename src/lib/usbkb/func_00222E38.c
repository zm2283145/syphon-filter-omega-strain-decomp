typedef struct { char pad[0x90]; int x90; int x94; void *x98; } KbState;
extern int D_0048AB18;
extern char D_004F5820[];
extern char D_004F5880[];
extern char D_004F58C0[];
extern KbState D_004F5780;
extern int WaitSema(int);
extern int scePrintf(const char *, ...);
extern void func_00223400(void *);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);

int sceUsbKbGetInfo(void *info)
{
    int r;
    if (D_0048AB18 == -1) return -1;
    WaitSema(D_0048AB18);
    r = sceSifCallRpc(D_004F5820, 1, 1, D_004F5880, 0x10, D_004F58C0, 0x90, func_00223400, 0);
    if (r != 0) {
        scePrintf("sceUsbKbGetInfo: sceSifCallRpc -> %d
", r);
        return -2;
    }
    D_004F5780.x90 = 1;
    D_004F5780.x98 = info;
    return 0;
}