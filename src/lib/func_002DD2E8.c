extern char D_004ADB30[];
extern int Net_AllocZeroed(int* out, unsigned long n);
extern void func_00127358(const char* msg);
int func_002DD2E8(unsigned int n)
{
    int p = 0;
    if (Net_AllocZeroed(&p, n))
        func_00127358(D_004ADB30);
    return p;
}
