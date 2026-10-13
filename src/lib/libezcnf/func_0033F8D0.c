extern int D_004928EC;
extern char D_00533080[];
extern char D_00533040[];
extern char D_004B9D10[];
extern char D_004B9D18[];
extern char D_004B9D60[];
extern int func_0010F388(const char *, ...);
extern int sceSifCallRpc(char *, int, int, void *, int, void *, int, void *, void *);
extern void String_Copy(char *, char *);
int ezNetCnfGetProperties(char *n1, char *n2, int x)
{
    char *res = D_00533080;
    if (!D_004928EC) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388(D_004B9D60);
        return -1;
    }
    String_Copy(res + 0x10, n1);
    String_Copy(res + 0x110, n2);
    ((int *)res)[0] = x;
    sceSifCallRpc(D_00533040, 2, 0, res, 0x130, res, 0x130, 0, 0);
    func_0010F388(D_004B9D10, D_004B9D18);
    func_0010F388("ezNetCnfGetProperties returned %d\n", *(int *)res);
    return *(int *)res;
}
