
extern void sceMc2Sync2(int a, int b, int* result);
extern int func_002B5948(int a, int b, unsigned short c, int d);
int sceMc2Chmod(int a, int b, int c, int d)
{
    int r = func_002B5948(a, b, c, d);
    if (r != 0)
        return r;
    sceMc2Sync2(0, 0, &r);
    return r;
}
