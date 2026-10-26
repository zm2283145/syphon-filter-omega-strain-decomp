
extern void func_002B5EA8(int a, int b, int* result);
extern int func_002B5948(int a, int b, unsigned short c, int d);
int sceMc2Chmod(int a, int b, int c, int d)
{
    int r = func_002B5948(a, b, c, d);
    if (r != 0)
        return r;
    func_002B5EA8(0, 0, &r);
    return r;
}
