#include "types.h"
extern void SyncDCache(int*, char*);
extern void func_0010DB98(int*, char*);
extern int func_00118F00(int);
extern int func_003A85E0(void);
extern void func_00127358(char* fmt, ...);
extern int func_00110720(void* sema);
extern void func_0010D3E0(int);
extern int func_00110528(void* cd, int fn, int mode, void* send, int ssize, void* recv, int rsize, int a, int b);
extern int D_0053DBF8;
extern int D_0053DC00;
extern int D_0053DC18;
extern int D_00542800;
extern int D_00542878;
extern int D_00542990;
extern char D_0054283F;
extern int D_005428C0;
extern char D_005428C4;
extern int D_00542900;
extern int D_00542904;
extern char D_00542850[];
extern char D_004BCA30[];
static inline unsigned char Done3A8260(void) { return !D_00542800; }
static inline int Poll3A8260(char* k) {
    int t;
    func_0010DB98(&D_00542800, k);
    t = Done3A8260();
    D_0053DC18 = t;
    return t;
}
static inline int Check3A8260(int w) {
    if (D_0053DC00 == 0) return func_00118F00(w);
    if (Poll3A8260(&D_0054283F) == 1) return 0;
    return 1;
}
#pragma push
#pragma bool off
int snd_BankLoadByLoc(int loc, int size)
{
    D_0053DBF8 = 0;
    if (D_00542878) {
        if (!D_00542990) func_00127358("snd_BankLoadByLoc: Load already in progress!\n");
        return 0;
    }
    if (Check3A8260(1) == 1) {
        if (!D_00542990) func_00127358("snd_BankLoadByLoc: CD BUSY!\n");
        return 0;
    }
    D_005428C0 = -1;
    SyncDCache(&D_005428C0, &D_005428C4);
    D_00542900 = loc;
    D_00542904 = size;
    while (func_00110720(D_00542850)) {
        if (!D_00542990) func_00127358(D_004BCA30);
        func_003A85E0();
        func_0010D3E0(0);
    }
    if (func_00110528(D_00542850, 3, 1, &D_00542900, 8, &D_005428C0, 4, 0, 0) < 0) {
        if (!D_00542990) func_00127358("989snd.c: RPC call has failed inside snd_BankLoadByLoc\n");
        D_0053DBF8 = 0x106;
        return 0;
    }
    while (D_005428C0 == -1) func_0010D3E0(0);
    return D_005428C0;
}
#pragma pop
