extern char D_004B0DE0[], D_004B0E18[], D_004B11C0[];
extern void func_00127358(const char *fmt, const char *file, int line, const char *msg);
extern int func_003111E0(void *a, int *p, int n);
int func_003130F8(void *a, int *p)
{
    if (p == 0) {
        func_00127358(D_004B0DE0, D_004B0E18, 0x48F, D_004B11C0);
        return 2;
    }
    *p = 0;
    return func_003111E0(a, p, 0x114);
}