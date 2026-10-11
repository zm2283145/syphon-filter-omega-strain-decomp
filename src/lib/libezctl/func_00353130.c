extern int D_00492C34;
extern char D_005332C0[];
extern char D_00533280[];
extern char D_004BADB8[], D_004BADC0[], D_004BAE08[];
extern int func_0010F388(const char *, ...);
extern int func_00110528(char *, int, int, void *, int, void *, int, void *, void *);
int func_00353130(void)
{
    int *res = (int *)D_005332C0;
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE08);
        return -1;
    }
    func_00110528(D_00533280, 5, 0, res, 4, res, 4, 0, 0);
    return *res;
}
