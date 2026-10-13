extern int D_00492C34;
extern char D_005332C0[];
extern char D_00533280[];
extern char D_004BADB8[];
extern char D_004BADC0[];
extern void func_0010F388(const char *, ...);
extern int sceSifCallRpc(char *, int, int, void *, int, void *, int, void *, void *);
extern int func_003532F8(int, int, int, int);
int ezNetCtlSetProperties(int size)
{
    int *res = (int *)D_005332C0;
    int r;
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388("RPC service not running\n");
        return -1;
    }
    if (4 > 0x1340) { /* inlined RPC size check, constant-false here: only its message remains */
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388("RPC data size 0x%x exceeds buffer size 0x%x\n", 4, 0x1340);
        return -1;
    }
    sceSifCallRpc(D_00533280, 0, 0, res, 4, res, 4, 0, 0);
    if (*res == 0) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388("eCtlGetPropertiesAddress returned NULL\n");
        *res = -2;
        return -2;
    }
    func_003532F8(size, *res, 0x1340, 0);
    sceSifCallRpc(D_00533280, 1, 0, res, 4, res, 4, 0, 0);
    r = *res;
    func_0010F388(D_004BADB8, D_004BADC0);
    func_0010F388("ezNetCtlSetProperties returned %d\n", r);
    return r;
}
