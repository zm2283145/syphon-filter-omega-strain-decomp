extern int D_004E1D50;
extern void func_003232E0(void);
int func_003231D8(int mode)
{
    int ret = 0;
    switch (mode) {
    case 0:
    case 1:
        D_004E1D50 = mode;
        break;
    case 2:
        D_004E1D50 = mode;
        func_003232E0();
        break;
    case 3:
        D_004E1D50 = mode;
        break;
    default:
        D_004E1D50 = 0;
        ret = -1;
        break;
    }
    return ret;
}
