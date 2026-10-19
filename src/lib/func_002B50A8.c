extern int D_00506B60;
extern void iChangeThreadPriority(int h, int n);
int func_002B50A8(int n)
{
    if (n <= 0)
        return 0x81010016;
    iChangeThreadPriority(D_00506B60, n);
    return 0;
}
