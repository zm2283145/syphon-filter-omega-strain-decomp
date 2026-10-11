extern char D_00488A50[];
extern int D_00487900[];
extern int D_004878A8;
extern int func_00118CF8(int);
extern int func_00110528(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_0010D180(int);

int func_00118E68(void)
{
    int r;
    if (!func_00118CF8(2)) return 0;
    if (func_00110528(D_00488A50, 0xE, 0, 0, 0, D_00487900, 4, 0, 0) < 0) {
        func_0010D180(D_004878A8);
        return 0;
    }
    r = *(int *)((unsigned int)D_00487900 | 0x20000000);
    func_0010D180(D_004878A8);
    return r;
}