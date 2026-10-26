typedef struct { int x0; char p[0x8C]; int x90; int x94; int x98; } S30A0;
extern int D_0048AB18;
extern S30A0 D_004F5780;
extern unsigned char D_004F5880[];
extern char D_004F5820[];
extern char D_004F58C0[];
extern void rpccall_end(void);
extern void WaitSema(int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int scePrintf(const char *, ...);
int sceUsbKbSetLEDStatus(int a, unsigned char b)
{
    int r;
    if (D_0048AB18 == -1) return -1;
    if (a >= D_004F5780.x0) return -11;
    D_004F5880[0] = a;
    D_004F5880[1] = b;
    WaitSema(D_0048AB18);
    r = sceSifCallRpc(D_004F5820, 4, 1, D_004F5880, 0x10, D_004F58C0, 0x10, rpccall_end, 0);
    if (r) {
        scePrintf("sceUsbKbSetLEDStatus: sceSifCallRpc -> %d
", r);
        return -2;
    }
    D_004F5780.x94 = a;
    D_004F5780.x90 = 4;
    D_004F5780.x98 = 0;
    return 0;
}