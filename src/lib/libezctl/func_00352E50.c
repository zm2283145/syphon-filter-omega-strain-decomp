extern int D_00492C34;
extern char D_005332C0[];
extern char D_00533280[];
extern char D_004BADB8[], D_004BADC0[], D_004BAE08[], D_004BAE58[], D_004BAE80[];
extern void func_0010F388(const char *, ...);
extern int func_00110528(char *, int, int, void *, int, void *, int, void *, void *);
extern int func_003532F8(int, int, int, int);
int ezNetCtlSetProperties(int size)
{
    int *res = (int *)D_005332C0;
    int r;
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE08);
        return -1;
    }
    func_00110528(D_00533280, 0, 0, res, 4, res, 4, 0, 0);
    if (*res == 0) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE58);
        *res = -2;
        return -2;
    }
    func_003532F8(size, *res, 0x1340, 0);
    func_00110528(D_00533280, 1, 0, res, 4, res, 4, 0, 0);
    r = *res;
    func_0010F388(D_004BADB8, D_004BADC0);
    func_0010F388(D_004BAE80, r);
    return r;
}
