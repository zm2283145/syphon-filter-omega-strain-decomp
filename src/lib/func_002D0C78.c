extern short D_0048C414;
extern int D_0048C3D8;
extern int D_0048C3D0;
extern int D_0048C400;
extern int func_002D0EB8(char *, int);
extern int func_002CEBC0(void);
extern void func_002CE840(char *);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_002D0C78(char *a, int b)
{
    int r;
    func_002D0EB8(a, 0x15);
    if (*(int *)(a + 0x1C) < 0) return -0xD;
    if (D_0048C414 != 1) return -0xC;
    if (func_002CEBC0() == 1 || func_002CEBC0() == 2) {
        func_002CE840(a + 0x20);
    } else if (func_002CEBC0() == 0 || func_002CEBC0() == 4) {
        *(int *)(a + 0x20) = 0;
        *(int *)(a + 0x38) = 0;
    } else {
        return -0xD;
    }
    r = Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3D0, 0x50, a);
    D_0048C400 = b;
    return r ? -5 : 0;
}
