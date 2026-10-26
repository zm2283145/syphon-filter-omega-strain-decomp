extern int D_00506B60;
extern void iChangeThreadPriority(int h, int n);
int sceMc2iChangeThreadPriority(int n)
{
    if (n <= 0)
        return 0x81010016;
    iChangeThreadPriority(D_00506B60, n);
    return 0;
}
