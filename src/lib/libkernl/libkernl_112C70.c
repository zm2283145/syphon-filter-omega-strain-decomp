typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam2C70;
typedef struct { int sema; int *res; int size; int xC; } S2C70;
extern S2C70 D_004E4800;
extern int D_0048623C;
extern char D_004E5F00[];
extern char D_004E5440[];
extern int func_001111B0(int);
extern void func_001112E0(void);
extern void func_001111E0(void);
extern int CreateSema(SemaParam2C70 *);
extern void WaitSema(int);
extern void DeleteSema(int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
int func_00112C70(int a)
{
    S2C70 *p = &D_004E4800;
    SemaParam2C70 sp;
    int result;
    int s, r;
    func_001111B0(0xF);
    if (D_0048623C == 0) func_001112E0();
    p->xC = a;
    sp.initCount = 0;
    sp.maxCount = 1;
    sp.option = 0;
    s = CreateSema(&sp);
    D_004E4800.sema = s;
    p->res = &result;
    p->size = 4;
    if (sceSifCallRpc(D_004E5F00, 0xF, 0, p, 0x10, D_004E5440, 4, 0, 0) < 0) {
        DeleteSema(s);
        func_001111E0();
        return -1;
    }
    r = *(int *)((int)D_004E5440 | 0x20000000);
    func_001111E0();
    if (r == 0) {
        DeleteSema(s);
        return -1;
    }
    WaitSema(s);
    DeleteSema(s);
    return result;
}