extern char D_004B0DE0[], D_004B0E18[], D_004B11C0[];
extern void printf(const char *fmt, const char *file, int line, const char *msg);
extern int RtXml_Alloc(void *a, int *p, int n);
int func_003130F8(void *a, int *p)
{
    if (p == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x48F, D_004B11C0);
        return 2;
    }
    *p = 0;
    return RtXml_Alloc(a, p, 0x114);
}