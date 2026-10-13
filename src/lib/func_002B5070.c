extern int D_00506B60;
extern void ChangeThreadPriority(int h, int n);
int func_002B5070(int n)
{
    if (n <= 0)
        return 0x81010016;
    ChangeThreadPriority(D_00506B60, n);
    return 0;
}
