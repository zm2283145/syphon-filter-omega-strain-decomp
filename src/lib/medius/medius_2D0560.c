extern short D_0048C414;
extern int D_0048C3D8;
extern int D_0048C380;
extern char D_004AD398[];
extern void func_002CEC00(char *);
extern void printf(char *, ...);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_002D0560(char *a)
{
    int r;
    if (*(short *)(a + 0x16) < 0) return -0xC;
    if (*(short *)(a + 0x12) < 0) return -0xC;
    if (*(short *)(a + 0x18) < 0) return -0xC;
    if (*(short *)(a + 0x14) < 0) return -0xC;
    if (*(unsigned int *)(a + 0x1C) >= 4) *(int *)(a + 0x1C) = 0;
    if (D_0048C414 != 1) return -0xC;
    func_002CEC00(a);
    r = Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C380, 0x20, a);
    if (r) {
        printf(D_004AD398, r);
        return -5;
    }
    return 0;
}
