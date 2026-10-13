extern int D_004E1D50;
extern void func_003232E0(void);
int func_00323270(void)
{
    int ret = 0;
    switch (D_004E1D50) {
    case 0:
        break;
    case 1:
        func_003232E0();
        break;
    case 2:
        break;
    case 3:
        func_003232E0();
        break;
    default:
        D_004E1D50 = 0;
        ret = -1;
        break;
    }
    return ret;
}
