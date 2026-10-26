extern int D_00506B60;
extern void ChangeThreadPriority(int h, int n);
int sceMc2ChangeThreadPriority(int n)
{
    if (n <= 0)
        return 0x81010016;
    ChangeThreadPriority(D_00506B60, n);
    return 0;
}
