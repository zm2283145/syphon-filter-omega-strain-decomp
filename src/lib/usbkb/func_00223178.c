typedef struct { int mode; char p[0x34]; } E3178;
typedef struct { int x0; E3178 *x4; char p[0x88]; int x90; int x94; int x98; } S30A0;
extern int D_0048AB18;
extern S30A0 D_004F5780;
extern unsigned char D_004F5880[];
extern char D_004F5820[];
extern char D_004F58C0[];
extern void func_00223400(void);
extern void WaitSema(int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_0010F388(const char *, ...);
int sceUsbKbSetLEDMode(int a, unsigned int b)
{
    int r;
    if (D_0048AB18 == -1) return -1;
    if (a >= D_004F5780.x0) return -11;
    if (b >= 3) return -12;
    D_004F5780.x4[a].mode = b;
    D_004F5880[0] = a;
    D_004F5880[1] = b;
    WaitSema(D_0048AB18);
    r = sceSifCallRpc(D_004F5820, 5, 1, D_004F5880, 0x10, D_004F58C0, 0x10, func_00223400, 0);
    if (r) {
        func_0010F388("sceUsbKbSetLEDMode: sceSifCallRpc -> %d
", r);
        return -2;
    }
    D_004F5780.x94 = a;
    D_004F5780.x90 = 5;
    D_004F5780.x98 = 0;
    return 0;
}