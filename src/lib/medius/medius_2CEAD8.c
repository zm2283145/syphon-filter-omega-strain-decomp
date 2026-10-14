extern int D_0048C3D8;
extern int D_0048C384;
extern int func_002CE758(void);
extern void func_002CE748(int);
extern void func_002CEAC8(int *);
extern void func_002CE9E8(char *);
extern void func_002CE840(char *);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_002CEAD8(void)
{
    char buf[0x50];
    int st;
    int r = 0;
    if (func_002CE758() == 1) {
        func_002CE748(0);
        func_002CEAC8(&st);
        if (st == 0) {
            func_002CE9E8(buf);
            func_002CE840(buf + 0x1C);
            r = Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C384, 0x4C, buf);
        }
        if (r != 0) return -5;
    } else if (func_002CE758() == 3) return -0xE;
    else if (func_002CE758() == 2) return -5;
    return 0;
}

