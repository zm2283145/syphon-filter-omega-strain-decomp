extern volatile int D_0048B378;
extern int func_0010D1A0(int);
extern int func_0010D1B0(int);
extern int func_0027D350(void);

int func_0027D438(int mode)
{
    int r = 1;
    if (D_0048B378 < 0) return -1;
    switch (mode) {
    case 0:
        func_0010D1A0(D_0048B378);
        r = 0;
        func_0027D350();
        break;
    case 1:
        if (func_0010D1B0(D_0048B378) == -1) break;
        r = 0;
        func_0027D350();
        break;
    default:
        return -0x65;
    }
    return r;
}