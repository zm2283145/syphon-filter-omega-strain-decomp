extern int D_00492C34;
extern char D_005332C0[];
extern char D_00533280[];
extern char D_004BADB8[];
extern char D_004BADC0[];
extern char D_004BAE08[];
extern int func_0010F388(const char *, ...);
extern int sceSifCallRpc(char *, int, int, void *, int, void *, int, void *, void *);
extern void String_Copy(char *, char *);
int ezNetCtlSetCombination(char *n1, char *n2)
{
    char *res = D_005332C0;
    int r;
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE08);
        return -1;
    }
    String_Copy(res + 0x10, n1);
    String_Copy(res + 0x110, n2);
    sceSifCallRpc(D_00533280, 2, 0, res, 0x130, res, 0x130, 0, 0);
    r = *(int *)res;
    func_0010F388(D_004BADB8, D_004BADC0);
    func_0010F388("ezNetCtlSetCombination returned %d\n", r);
    return r;
}
