extern int D_00492C34;
extern char D_005332C0[];
extern char D_00533280[];
extern char D_004BADB8[], D_004BADC0[], D_004BAE08[], D_004BAED0[];
extern int func_0010F388(const char *, ...);
extern int func_00110528(char *, int, int, void *, int, void *, int, void *, void *);
extern void String_Copy(char *, char *);
int ezNetCtlPreloadModemCnf(char *name)
{
    char *res = D_005332C0;
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE08);
        return -1;
    }
    String_Copy(res + 0x10, name);
    func_00110528(D_00533280, 7, 0, res, 0x130, res, 0x130, 0, 0);
    func_0010F388(D_004BADB8, D_004BADC0);
    func_0010F388(D_004BAED0, *(int *)res);
    return *(int *)res;
}
