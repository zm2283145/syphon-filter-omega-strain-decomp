extern char D_00489400[];
extern int D_00488A80[];
extern volatile int D_004878AC;
extern volatile int D_004878D8;
extern int func_00119010(int);
extern int func_00110528(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_0010D180(int);

int func_00119C20(void)
{
    int r;
    if (!func_00119010(0x1E)) return 0;
    D_004878D8 = 8;
    if (func_00110528(D_00489400, 0x16, 0, 0, 0, D_00488A80, 4, 0, 0) < 0) {
        func_0010D180(D_004878AC);
    D_004878D8 = 0;
        return 0;
    }
    D_004878D8 = 0;
    r = *(int *)((unsigned int)D_00488A80 | 0x20000000);
    func_0010D180(D_004878AC);
    return r;
}