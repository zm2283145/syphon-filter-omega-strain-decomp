extern int D_0049147C;
extern int D_00491470;
extern void (*D_00491484)(int);
extern int D_0052AD00[];
extern char D_0052AD40[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_0010D170(int sema);
extern int func_00325F38(int, int *);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
int func_003251B0(void)
{
    if (D_0049147C != -1) {
        func_0010D1A0(D_0049147C);
        func_00325F38(0, 0);
        if (D_00491470) {
            if (D_00491484)
                D_00491484(D_00491470);
            D_00491470 = 0;
        }
        func_00110528(D_0052AD00, 0x16, 0, D_0052AD40, 0x20, D_0052AD40, 0, 0, 0);
        D_0052AD00[9] = 0;
        func_0010D180(D_0049147C);
        func_0010D170(D_0049147C);
        D_0049147C = -1;
    }
    return 0;
}