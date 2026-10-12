#include "types.h"
extern int D_0053DBF8;
extern int D_00542878;
extern int D_00542990;
extern int D_0053DE80;
extern char D_0053DE84[];
extern int D_005428C0;
extern char D_005428C4[];
extern char D_00542850[];
extern char D_004BCA30[];
extern void func_00127358(char*);
extern void String_Copy(char*, char*);
extern void func_0010DA58(int*, char*);
extern int func_00110720(char*);
extern void func_003A85E0(void);
extern void func_0010D3E0(int);
extern int strlen(const char*);
extern int func_00110528(char*, int, int, int*, int, int*, int, int, int);
int snd_BankLoad(char* name, int arg) {
    int r;
    D_0053DBF8 = 0;
    if (D_00542878) {
        if (!D_00542990) func_00127358("snd_BankLoad: Load already in progress!\n");
        return 0;
    }
    D_0053DE80 = arg;
    String_Copy(D_0053DE84, name);
    D_005428C0 = -1;
    func_0010DA58(&D_005428C0, D_005428C4);
    while (func_00110720(D_00542850)) {
        if (!D_00542990) func_00127358(D_004BCA30);
        func_003A85E0();
        func_0010D3E0(0);
    }
    if (func_00110528(D_00542850, 2, 1, &D_0053DE80, strlen(name) + 5, &D_005428C0, 4, 0, 0) < 0) {
        if (!D_00542990) func_00127358("989snd.c: RPC call has failed inside snd_BankLoad\n");
        D_0053DBF8 = 0x106;
        return 0;
    }
    while ((r = D_005428C0) == -1) func_0010D3E0(0);
    return r;
}
