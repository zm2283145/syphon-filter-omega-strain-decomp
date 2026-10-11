extern int D_004928EC;
extern char D_00533080[];
extern char D_00533040[];
extern char D_004B9D10[], D_004B9D18[], D_004B9D60[], D_004B9DB0[];
extern int func_0010F388(const char *, ...);
extern int func_00110528(char *, int, int, void *, int, void *, int, void *, void *);
extern void String_Copy(char *, char *);
int ezNetCnfGetCombinationList(char *name, int a, int b)
{
    char *res = D_00533080;
    if (!D_004928EC) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388(D_004B9D60);
        return -1;
    }
    String_Copy(res + 0x10, name);
    ((int *)res)[0] = b;
    ((int *)res)[1] = a;
    func_00110528(D_00533040, 1, 0, res, 0x130, res, 0x130, 0, 0);
    func_0010F388(D_004B9D10, D_004B9D18);
    func_0010F388(D_004B9DB0, *(int *)res);
    return *(int *)res;
}
