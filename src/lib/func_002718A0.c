typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam18A0;
typedef struct E18A0 { char p0[0x14]; int x14; void *x18; int x1C; int x20; int x24; int x28; int x2C; int x30; int x34; } E18A0;
typedef struct { int x0; void *x4; int x8; int xC; int x10; int x14; int x18; int x1C; int x20; int x24; int x28; int x2C; } C18A0;
extern char D_004A8CF0[];
extern char D_004A8D18[];
extern char D_004A8D50[];
extern char D_004A8D60[];
extern char D_004FFB00[];
extern int scePrintf(const char *, ...);
extern int WaitSema(int);
extern void DeleteSema(int);
extern E18A0 *func_002713C0(void *);
extern int CreateSema(SemaParam18A0 *);
extern void func_00271468(E18A0 *);
extern int func_0010F948(unsigned int, void *, int, int, int, int);
extern void func_0010FB10(int, int);
int sceSifMCallRpc(C18A0 *cd, int rpc_number, int mode, int send, int ssize, int receive, int rsize, int end_function, int end_param)
{
    SemaParam18A0 sp;
    E18A0 *e;
    int s;
    int g;
    if (mode) {
        scePrintf(D_004A8CF0);
        return -1;
    }
    WaitSema(cd->x28);
    if (send & 0x3F) {
        scePrintf(D_004A8D18, D_004A8D50, send);
        return -1;
    }
    if (receive & 0x3F) {
        scePrintf(D_004A8D60, D_004A8D50, receive);
        return -1;
    }
    e = func_002713C0(D_004FFB00);
    if (e == 0) return -1;
    cd->x20 = end_param;
    cd->x4 = e->x18;
    cd->x0 = (int)e;
    cd->x1C = end_function;
    __asm__ volatile("move %0, $gp" : "=r"(g));
    cd->x18 = g;
    e->x20 = rpc_number;
    e->x14 = (int)e;
    e->x24 = ssize;
    e->x28 = receive;
    e->x2C = rsize;
    e->x1C = (int)cd;
    e->x34 = cd->x24;
    if (send == receive) {
        func_0010FB10(send, ssize < rsize ? rsize : ssize);
    } else {
        if (ssize > 0) func_0010FB10(send, ssize);
        if (rsize > 0) func_0010FB10(receive, rsize);
    }
    if (mode & 1) {
        if (end_function == 0) e->x30 = 0;
        else e->x30 = 1;
        cd->x8 = -1;
        if (func_0010F948(0x8000001A, e, 0x40, send, cd->x14, ssize) == 0) {
            func_00271468(e);
            return -2;
        }
        return 0;
    }
    sp.initCount = 0;
    sp.maxCount = 1;
    sp.option = 0;
    s = CreateSema(&sp);
    cd->x8 = s;
    if (s < 0) {
        func_00271468(e);
        return -3;
    }
    e->x30 = 1;
    if (func_0010F948(0x8000001A, e, 0x40, send, cd->x14, ssize) == 0) {
        func_00271468(e);
        DeleteSema(s);
        return -2;
    }
    WaitSema(s);
    DeleteSema(s);
    return 0;
}
